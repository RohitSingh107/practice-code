import { ethers } from "ethers"
import * as fs from "fs-extra"
import "dotenv/config"

async function main() : Promise<void> {
	// console.log("Hi")
	// let variable = 5
	// console.log(variable)
	// HTTP://127.0.0.1:7545
	
	// Connection to provider
	const provider : ethers.providers.JsonRpcProvider = new ethers.providers.JsonRpcProvider(process.env.RPC_URL!);

	// Our wallet
	const wallet : ethers.Wallet = new ethers.Wallet(
		process.env.PRIVATE_KEY!,
		provider
	)
	// const encryptedJson = fs.readFileSync("./.encryptedKey.json", "utf8")
	// let wallet = ethers.Wallet.fromEncryptedJsonSync(encryptedJson, process.env.PRIVATE_KEY_PASSWORD)

	// wallet = await wallet.connect(provider)

	const abi = fs.readFileSync("./SimpleStorage_sol_SimpleStorage.abi", "utf8");

	const binary = fs.readFileSync("./SimpleStorage_sol_SimpleStorage.bin", "utf8")


	const contractFactory : ethers.ContractFactory = new ethers.ContractFactory(abi, binary, wallet)
	console.log("Deploying, Please wait")
	const contract : ethers.Contract = await contractFactory.deploy()
	// console.log(contract)

	const transactionReceipt : ethers.providers.TransactionReceipt  = await contract.deployTransaction.wait(1)
	
	console.log("here is Deployement transaction (transaction response): ")
	console.log(contract.deployTransaction)

	console.log("Here is transaction receipt");
	
	console.log(transactionReceipt)

	console.log("lets depliy with only transaction data!")

	console.log("\nInteracting with contract")

	console.log(`Cotract Addrress: ${contract.address}`);

	const currentFavoriteNumber = await contract.retrive();
	console.log(`Current favorite number is ${currentFavoriteNumber.toString()}`)
	
	const transactionResponse = await contract.store("77")
	const transactionReceipt2 = await transactionResponse.wait(1)
	const updatedFavoriteNumber = await contract.retrive();
	console.log(`Updated favorite number is: ${updatedFavoriteNumber}`)
	// console.log(process.env.PRIVATE_KEY)
	
	
}

main()
.then(() => process.exit(0))
.catch((error) => {
	console.error(error)
	process.exit(1)
})

