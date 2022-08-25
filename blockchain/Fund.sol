pragma solidity >=0.8 .13;

contract Fund {
    address public immutable i_fund_manager;
    uint256 public immutable i_minimumContribution;
    uint256 public immutable i_deadline;
    uint256 public immutable i_target;
    uint256 public s_raisedAmount;
    uint256 public s_totalContributors;
    mapping(address => uint256) public s_contributors;

    struct Request {
        string description;
        address payable recipient;
        uint256 value;
        bool completed;
        uint256 noOfVoters;
        mapping(address => bool) voters;
    }
    mapping(uint256 => Request) public s_requests;
    uint256 public s_numRequests;

    constructor(uint256 _target, uint256 _deadline) {
        i_target = _target;
        i_deadline = block.timestamp + _deadline;
        i_minimumContribution = 100 wei;
        i_fund_manager = msg.sender;
    }

    function fundEth() public payable {
        require(block.timestamp < i_deadline, "Deadline has passed!");
        require(
            msg.value >= i_minimumContribution,
            "Minimum contribution is not met"
        );

        if (s_contributors[msg.sender] == 0) {
            s_totalContributors++;
        }

        s_contributors[msg.sender] += msg.value;
        s_raisedAmount += msg.value;
    }

    function getContractBalance() public view returns (uint256) {
        return address(this).balance;
    }

    function refund() public {
        require(
            block.timestamp > i_deadline && s_raisedAmount < i_target,
            "Not Eligible for refund"
        );
        address payable _to = payable(msg.sender);
        (bool success, ) = _to.call{value: s_contributors[_to]}("");
        require(success, "Failed to refund!");
        s_contributors[_to] = 0;
    }

    function createRequest(
        string memory _description,
        address payable _recipient,
        uint256 _value
    ) public onlyManager {
        Request storage newRequest = s_requests[s_numRequests];
        s_numRequests++;
        newRequest.description = _description;
        newRequest.recipient = _recipient;
        newRequest.value = _value;
        newRequest.completed = false;
        newRequest.noOfVoters = 0;
    }

    modifier onlyManager() {
        require(
            msg.sender == i_fund_manager,
            "Only manager can call this function"
        );
        _;
    }

    function voteRequest(uint256 _requestNo) public {
        require(s_contributors[msg.sender] > 0, "You must be contributor");
        Request storage thisRequest = s_requests[_requestNo];
        require(
            thisRequest.voters[msg.sender] == false,
            "You have already voted this request"
        );
        thisRequest.voters[msg.sender] = true;
        thisRequest.noOfVoters++;
    }

    function makePayment(uint256 _requestNo) public onlyManager {
        require(s_raisedAmount >= i_target, "Not enough funds collected");
        Request storage thisRequest = s_requests[_requestNo];
        require(
            thisRequest.completed == false,
            "The request has benn completed"
        );
        require(
            thisRequest.noOfVoters > s_totalContributors / 2,
            "Majority does not support this request"
        );

        address payable _to = payable(thisRequest.recipient);
        (bool success, ) = _to.call{value: thisRequest.value}("");
        require(success, "Failed to refund!");
        thisRequest.completed = true;
    }
}
