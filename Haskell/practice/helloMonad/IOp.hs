module Main where

ex1 = putStrLn "Enter an integer number: " >> getLine

ex2 n = do
  let number = (read n :: Int) + 2
  putStrLn $ "NUmber plus 2 = " ++ show number 

main = ex1 >>= ex2 -- >>= evaluates (unwraps) and pipe the output of ex1


