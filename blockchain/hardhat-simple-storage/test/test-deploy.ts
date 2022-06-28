import {expect, assert} from "chai";
import {ethers} from "hardhat";
import {SimpleStorage, SimpleStorage__factory} from "../typechain"


describe("SimpleStorage", () => {

	let SimpleStorageFactory: SimpleStorage__factory
	let simpleStorage: SimpleStorage
	beforeEach(async () => {
		SimpleStorageFactory = await ethers.getContractFactory("SimpleStorage") as SimpleStorage__factory
		simpleStorage = await SimpleStorageFactory.deploy()
	})


	it("It shoud start with a favoute num of 0", async () => {
		const currentValue = await simpleStorage.retrive()
		const expectedValue = "0"
		assert.equal(currentValue.toString(), expectedValue)
	})

	it("Should update when we call store", async () => {
		const expectedValue = "7"
		const transactionResponse = await simpleStorage.store(7)
		await transactionResponse.wait(1)

		const currentValue = await simpleStorage.retrive()
		assert.equal(currentValue.toString(), expectedValue)
	})

})
