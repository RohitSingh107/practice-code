-- print3.hs

module Print3 where

myGreeting :: String
myGreeting = "hello" ++ " World!"

hello :: [Char]
hello = "hello"

world :: String
world = "world!"

main :: IO ()
main = do 
  putStrLn secondGreeting
  putStrLn myGreeting
  where secondGreeting = 
          concat [hello, " second  ", world]
