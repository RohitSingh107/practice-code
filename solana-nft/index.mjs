import { ThirdwebSDK } from "@thirdweb-dev/sdk/solana";
import { createThirdwebSDK } from "@thirdweb-dev/sdk/solana/server";
// const privateKey =
//   "5r3mNTF1SArszbr4NSVZoWSxQDPTGW5zD3sW1Ghbrx42b3XEbNhcdBhEhZ1Lhp9MM66X1WpG4SaaE2GDhUZZpL7G";

// const sdk = ThirdwebSDK.fromPrivateKey("devnet", privateKey);

// create the SDK using the default path for the Solana CLI keypair
const sdk = createThirdwebSDK("devnet");
// console.log(sdk);

const program = await sdk.getProgram(
  "EJpLyTeE8XHG9CeREeHd6pr6hNhaRnTRJx4Z5DPhEJJ6",
  "nft-collection"
);

// Get all the NFTs that have been minted on this contract
const nfts = await program.getAll();

console.log(nfts);
console.log(nfts[0].metadata.name);
console.log(nfts[0].owner);

console.log(program);
