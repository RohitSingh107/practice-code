// SPDX-License-Identifier: MIT

pragma solidity ^0.8.8;

import "./SimpleStorage.sol";

contract ExtraStorage is SimpleStorage {
    function store(uint256 _favotiteNumber) public override {
        favotiteNumber = _favotiteNumber + 5;
    }
}
