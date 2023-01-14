import {
  Metaplex,
  keypairIdentity,
  bundlrStorage,
} from "@metaplex-foundation/js";
import { Connection, clusterApiUrl, Keypair, PublicKey } from "@solana/web3.js";

(async () => {
  // const address = "94gjhowSM4p2ssz8s2twaBJFmScv1cYuRftrxcwtvBwQ";
  // const address = "EJpLyTeE8XHG9CeREeHd6pr6hNhaRnTRJx4Z5DPhEJJ6";
  const address = "CUS3BZfL6QAbHbsoqUbF5XM2wnmAbfEfZ79bqBd6wCM4";

  const owner = new PublicKey(address);

  const connection = new Connection(
    "https://solana-mainnet.g.alchemy.com/v2/IUWjjcz4eVsRuQLvGgKgH2PLagGR1exG"
  );
  const wallet = Keypair.generate();

  const metaplex = Metaplex.make(connection)
    .use(keypairIdentity(wallet))
    .use(bundlrStorage());

  const myNfts = await metaplex.nfts().findAllByOwner({
    owner: owner,
  });

  console.log(myNfts);
  console.log(myNfts.length);
})();
