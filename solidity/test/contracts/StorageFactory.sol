// SPDX-License-Identifier: MIT

pragma solidity ^0.8.8;

import "./SimpleStorage.sol";

contract StorageFactory{

    // SimpleStorage public simpleStorage;
    SimpleStorage[] public simpleStorageArray;

    function createSimpleStorageContractFactory() public {
        SimpleStorage simpleStorage = new SimpleStorage();
        simpleStorageArray.push(simpleStorage);
    }

    function sfStore(uint256 _simpleStorageIndex, uint256 _simpleStorageNumber) public{
        simpleStorageArray[_simpleStorageIndex].store(_simpleStorageNumber);
    }

    function sfGet(uint256 _simpleStorageIndex) public view returns(uint256){
        SimpleStorage simpleStorage = simpleStorageArray[_simpleStorageIndex];
        return simpleStorage.retrive();
    }

}
