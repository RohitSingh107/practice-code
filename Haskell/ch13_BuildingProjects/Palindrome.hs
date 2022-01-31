module Main where

import Control.Monad
import Data.Char
import System.Exit (exitSuccess)

processString :: String -> Bool
processString x = y == reverse y
  where y = map toLower $ filter isAlpha x


palindrome :: IO ()
palindrome = forever $ do
  putStrLn "Enter the string to check:"
  line1 <- getLine
  case (processString line1) of
    True -> putStrLn  "It's a palindrome!"
    False -> do
      putStrLn "Nope!"
      exitSuccess


main :: IO ()
main = palindrome
