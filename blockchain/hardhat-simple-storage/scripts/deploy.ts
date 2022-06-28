import {BigNumber, ContractTransaction} from "ethers";
import { ethers, run, network } from "hardhat";

async function main() {

	const SimpleStorageFactory = await ethers.getContractFactory(
		"SimpleStorage"
	)

	console.log("Deploying contract...")
	const simpleStorage = await SimpleStorageFactory.deploy()
	await simpleStorage.deployed()

	console.log(`Deployed contract to: ${simpleStorage.address}`)

	// console.log(network.config)
	
	if(network.config.chainId === 4 && process.env.ETHERSCAN_API_KEY){
		await simpleStorage.deployTransaction.wait(6)
		await verify(simpleStorage.address, [])
	}

	const currentValue : BigNumber = await simpleStorage.retrive()
	console.log(`Current value is: ${currentValue}`)


	// Updating currentValue
	const transactionResponse : ContractTransaction = await simpleStorage.store(7)
	await transactionResponse.wait(1)
	const updatedValue : BigNumber = await simpleStorage.retrive()
	console.log(updatedValue)
}


const verify = async (contractAddress : string, args: any[]) => {
	console.log("Verifying Contract...")
	try {
		await run("verify:verify", { // No space after colon
			address: contractAddress,
			constructorArguments: args,
		})
	} catch(e: any){
		if(e.message.toLowerCase().includes("already verified")){
			console.log("Already verified!")
		}
		else{
			console.log(e)
		}
	}
}





main()
.then(() => process.exit(0))
.catch((error) => {
	console.error(error)
	process.exit(1)
})

