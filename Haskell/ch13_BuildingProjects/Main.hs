module Main where

import Cipher
import System.IO


main :: IO ()
main = do

    hSetBuffering stdout NoBuffering 
    putStrLn "It's a cipher\n"
    
    putStrLn "Enter the Integer: "
    int <- getLine
   
    putStrLn "Enter the String: "
    text <- getLine

    myCaesar' (read int :: Int) text

    return ()