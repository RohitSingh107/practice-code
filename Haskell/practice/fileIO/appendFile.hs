module Main where

import System.IO
import Data.Char (toUpper)

main = do
  putStrLn "Enter a line of text for test:"
  s <- getLine
  putStrLn $ "As upper case: \t" ++ map toUpper s
  appendFile "temp.txt" $ s ++ "\n"
  main
