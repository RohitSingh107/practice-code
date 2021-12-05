-- Ch3 Exercise

module ListManipulation where

funca :: String -> String
funca x = (++) x "!"

funcb :: String -> Char
funcb x = (!!) x 4

funcc :: String -> String
funcc x = drop 9 x

thirdLetter :: String -> Char
thirdLetter x = (!!) x 2

letterIndex :: Int -> Char
letterIndex x = (!!) "Curry is awesome!" x

rvrs :: String -> String
rvrs x = concat [drop 9 x, drop 5 $ take 9 x, take 5 x]

main :: IO ()
main = print $ rvrs "Curry is awesome"
