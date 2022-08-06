import { Character, GetCharacterResults } from "../../types";
import Image from "next/image";
import { imageLoader } from "../../imageLoader";
import { GetServerSideProps } from "next";
import { useRouter } from "next/router";
import Layout from "../../components/Layout";
import { ReactNode } from "react";
import styles from "../../styles/Character.module.css";

function CharacterPage({ character }: { character: Character }) {
  const router = useRouter();
  console.log(router.query.id);
  return (
    <div className={styles.container}>
      <h1>{character.name}</h1>

      <Image
        loader={imageLoader}
        unoptimized
        src={character.image}
        alt={character.name}
        width="200px"
        height="200px"
      />
    </div>
  );
}

CharacterPage.getLayout = function getLayout(page: ReactNode) {
  return <Layout>{page}</Layout>;
};

export const getServerSideProps: GetServerSideProps = async (context) => {
  const res = await fetch(
    `https://rickandmortyapi.com/api/character/${context.query.id}`
  );
  const character = await res.json();
  return {
    props: {
      character,
    },
  };
};

export default CharacterPage;
