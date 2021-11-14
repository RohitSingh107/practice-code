-- print3Broken.hs

module Print3 where

printSecond :: IO ()
printSecond = do
  putStrLn greeting

main :: IO ()
main = do 
  putStrLn greeting
  printSecond

greeting = "Yarrrrr"
