import "../styles/globals.css";
import type { AppProps } from "next/app";
import { GetStaticProps, NextPage } from "next";
import Layout from "../components/Layout";
import { ReactElement, ReactNode } from "react";

type NextPageWithLayout = NextPage & {
  getLayout?: (page: ReactElement) => ReactNode;
};

type AppPropsWithLayout = AppProps & {
  Component: NextPageWithLayout;
};

function MyApp({ Component, pageProps }: AppPropsWithLayout) {
  const getLayout = Component.getLayout ?? ((page) => page);
  // return getLayout(<Component {...pageProps} />);
  return <Component {...pageProps} />;
}
export default MyApp;
