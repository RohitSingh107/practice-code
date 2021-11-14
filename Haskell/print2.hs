-- print2.hs

module Print2 where

main :: IO ()

main = do 
  putStr "Count for four"
  putStrLn "One, Two"
  putStrLn ", three, and"
  putStr " four!"
