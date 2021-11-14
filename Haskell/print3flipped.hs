-- print3.hs

module Print3 where

myGreeting :: String
myGreeting = (++) "hello" " World!"

hello :: [Char]
hello = "hello"

world :: String
world = "world!"

main :: IO ()
main = do 
  putStrLn myGreeting
  putStrLn secondGreeting
    where secondGreeting = 
            (++) hello $ (++) " " world
