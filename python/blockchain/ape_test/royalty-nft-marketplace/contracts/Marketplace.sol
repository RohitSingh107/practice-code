// SPDX-License-Identifier: MIT
pragma solidity ^0.8.13;

import "@openzeppelin/token/ERC721/IERC721.sol";
import "@openzeppelin/security/ReentrancyGuard.sol";
import "./interfaces/IERC2981.sol";

error Marketplace__ItemNotForSale(address nftAddress, uint256 tokenId);
error Marketplace__NotListed(address nftAddress, uint256 tokenId);
error Marketplace__AlreadyListed(address nftAddress, uint256 tokenId);
error Marketplace__NoProceeds();
error Marketplace__NoRoyalty();
error Marketplace__NotOwner();
error Marketplace__NotApprovedForMarketplace();
error Marketplace__PriceMustBeAboveZero();
error Marketplace__TransferFailed();
error Marketplace__PriceNotMet(
    address nftAddress,
    uint256 tokenId,
    uint256 price
);

contract Marketplace is ReentrancyGuard {
    bytes4 private constant _INTERFACE_ID_ERC2981 = 0x2a55205a;

    mapping(address => mapping(uint256 => Listing)) private s_listings;
    mapping(address => uint256) private s_proceeds;
    mapping(address => uint256) private s_royalties;

    struct Listing {
        uint256 price;
        address seller;
    }

    event RoyaltiesPaid(
        uint256 indexed tokenId,
        uint256 indexed value,
        address indexed nftAddress
    );

    event ItemListed(
        address indexed seller,
        address indexed nftAddress,
        uint256 indexed tokenId,
        uint256 price
    );

    event ItemCanceled(
        address indexed seller,
        address indexed nftAddress,
        uint256 indexed tokenId
    );

    event ItemBought(
        address indexed buyer,
        address indexed nftAddress,
        uint256 indexed tokenId,
        uint256 price
    );

    modifier notListed(
        address nftAddress,
        uint256 tokenId,
        address owner
    ) {
        Listing memory listing = s_listings[nftAddress][tokenId];
        if (listing.price > 0) {
            revert Marketplace__AlreadyListed(nftAddress, tokenId);
        }
        _;
    }

    modifier isListed(address nftAddress, uint256 tokenId) {
        Listing memory listing = s_listings[nftAddress][tokenId];
        if (listing.price <= 0) {
            revert Marketplace__NotListed(nftAddress, tokenId);
        }
        _;
    }

    modifier isOwner(
        address nftAddress,
        uint256 tokenId,
        address spender
    ) {
        IERC721 nft = IERC721(nftAddress);
        address owner = nft.ownerOf(tokenId);
        if (spender != owner) {
            revert Marketplace__NotOwner();
        }
        _;
    }

    function _checkRoyalties(address _contract) internal view returns (bool) {
        bool success = IERC2981(_contract).supportsInterface(
            _INTERFACE_ID_ERC2981
        );
        return success;
    }

    function _deduceRoyalties(
        uint256 tokenId,
        address tokenAddress,
        uint256 grossSaleValue
    ) internal returns (uint256 netSaleAmount) {
        // Get amount of royalties to pays and recipient
        (address royaltiesReceiver, uint256 royaltiesAmount) = IERC2981(
            tokenAddress
        ).royaltyInfo(tokenId, grossSaleValue);

        // Deduce royalties from sale value
        uint256 netSaleValue = grossSaleValue - royaltiesAmount;

        // Transfer royalties to rightholder if not zero
        if (royaltiesAmount > 0) {
            // (bool success, ) = payable(royaltiesReceiver).call{
            //     value: royaltiesAmount
            // }("");
            // if (!success) {
            //     revert Marketplace__TransferFailed();
            // }

            s_royalties[royaltiesReceiver] += royaltiesAmount;
        }

        // Broadcast royalties payment
        emit RoyaltiesPaid(tokenId, royaltiesAmount, tokenAddress);

        return netSaleValue;
    }

    function listItem(
        address nftAddress,
        uint256 tokenId,
        uint256 price
    )
        external
        notListed(nftAddress, tokenId, msg.sender)
        isOwner(nftAddress, tokenId, msg.sender)
    {
        if (price <= 0) {
            revert Marketplace__PriceMustBeAboveZero();
        }
        IERC721 nft = IERC721(nftAddress);
        if (nft.getApproved(tokenId) != address(this)) {
            revert Marketplace__NotApprovedForMarketplace();
        }
        s_listings[nftAddress][tokenId] = Listing(price, msg.sender);
        emit ItemListed(msg.sender, nftAddress, tokenId, price);
    }

    function cancelListing(address nftAddress, uint256 tokenId)
        external
        isOwner(nftAddress, tokenId, msg.sender)
        isListed(nftAddress, tokenId)
    {
        delete (s_listings[nftAddress][tokenId]);
        emit ItemCanceled(msg.sender, nftAddress, tokenId);
    }

    function buyItem(address nftAddress, uint256 tokenId)
        external
        payable
        isListed(nftAddress, tokenId)
        nonReentrant
    {
        Listing memory listedItem = s_listings[nftAddress][tokenId];
        if (msg.value < listedItem.price) {
            revert Marketplace__PriceNotMet(
                nftAddress,
                tokenId,
                listedItem.price
            );
        }
        uint256 saleValue = msg.value;

        if (_checkRoyalties(nftAddress)) {
            saleValue = _deduceRoyalties(tokenId, nftAddress, saleValue);
        }

        s_proceeds[listedItem.seller] += saleValue;

        delete (s_listings[nftAddress][tokenId]);

        IERC721(nftAddress).safeTransferFrom(
            listedItem.seller,
            msg.sender,
            tokenId
        );
        emit ItemBought(msg.sender, nftAddress, tokenId, listedItem.price);
    }

    function updateListing(
        address nftAddress,
        uint256 tokenId,
        uint256 newPrice
    )
        external
        isListed(nftAddress, tokenId)
        nonReentrant
        isOwner(nftAddress, tokenId, msg.sender)
    {
        s_listings[nftAddress][tokenId].price = newPrice;
        emit ItemListed(msg.sender, nftAddress, tokenId, newPrice);
    }

    function withdrawProceeds() external {
        uint256 proceeds = s_proceeds[msg.sender];
        if (proceeds <= 0) {
            revert Marketplace__NoProceeds();
        }
        s_proceeds[msg.sender] = 0;
        (bool success, ) = payable(msg.sender).call{value: proceeds}("");
        if (!success) {
            revert Marketplace__TransferFailed();
        }
    }

    function withdrawRoyalties() external {
        uint256 royalty = s_royalties[msg.sender];
        if (royalty <= 0) {
            revert Marketplace__NoRoyalty();
        }
        s_royalties[msg.sender] = 0;
        (bool success, ) = payable(msg.sender).call{value: royalty}("");
        if (!success) {
            revert Marketplace__TransferFailed();
        }
    }

    function getListing(address nftAddress, uint256 tokenId)
        external
        view
        returns (Listing memory)
    {
        return s_listings[nftAddress][tokenId];
    }

    function getRoyalties(address royaltiesReceiver)
        external
        view
        returns (uint256)
    {
        return s_royalties[royaltiesReceiver];
    }

    function getProceeds(address seller) external view returns (uint256) {
        return s_proceeds[seller];
    }
}
