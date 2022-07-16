module Main where

squareToCurly :: String -> String
squareToCurly  = map f
  where f :: Char -> Char
        f '[' = '{'
        f ']' = '}'
        f c = c

main :: IO ()
main = do

  putStrLn "Enter the String"
  s <- getLine
  putStrLn $ squareToCurly s


