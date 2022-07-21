module Main where


import System.Random

randomList :: Int -> [Int]
randomList n = take n $ randoms (mkStdGen 42) :: [Int]



main :: IO ()
main = do
  putStrLn "How much numbers are needed"
  s <- getLine
  let i = (read s :: Int)

  print $ randomList i
