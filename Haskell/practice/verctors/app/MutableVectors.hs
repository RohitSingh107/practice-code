#!/usr/bin/env stack

--{- stack
--  script
--  --package random
--  --package vector
--  --package http-client,http-conduit
---}

module MutableVectors where

import           Control.Monad               (replicateM_)
import           Data.Vector.Unboxed         (freeze)
import qualified Data.Vector.Unboxed.Mutable as V
import           System.Random               (randomRIO)

main :: IO ()
main = do
  v0 <- V.replicate 10 (0 :: Int)

  replicateM_ (10 ^ 6) $ do
    i <- randomRIO (0, 9)
    oldCount <- V.read v0 i

    V.write v0 i (oldCount + 1)

  ivector <- freeze v0

  print ivector
