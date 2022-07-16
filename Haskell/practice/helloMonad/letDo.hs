module Main where

f1 = do 
  putStrLn "Enter the Name"
  name <- getLine
  putStrLn $ "Hello " ++ name


f2 = do
  putStrLn "Enter the Marks"
  marks <- getLine
  putStrLn $ "Your marks are " ++ marks

f3 = do
  putStrLn "Enter an integer: "
  s <- getLine
  let number = (read s :: Int) + 2
  putStrLn "Result is "
  putStrLn $ "Number plus 2 = " ++ show number

main :: IO ()
main = do
  f1
  f2
  f3

  -- f1 >> f2 >> f3
