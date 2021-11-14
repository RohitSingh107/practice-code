-- Exercise 9.6

module PoemLines where

firstSen = "Tyger Tyger, burning bright\n"
secondSen = "In the forests of the night\n"
thirdSen = "What immortal hand or eye\n"
fourthSen = "Could frame thy fearful\
\ symmetry?"


sentences = firstSen ++ secondSen ++ thirdSen ++ fourthSen
-- putStrLn sentences -- should print
-- Tyger Tyger, burning bright
-- In the forests of the night
-- What immortal hand or eye
-- Could frame thy fearful symmetry?

-- myLines :: String -> [String]
-- myLines xs = undefined 

myLines :: String -> [String]
myLines ('\n':xs) = myLines xs
myLines xs
      | null xs = [] 
      | otherwise =  takeWhile (/='\n') xs : myLines (dropWhile (/='\n') xs)

splitByChar :: Char -> String -> [String]
splitByChar _ [] = []
splitByChar c (x:xs)
  | x == c    = splitByChar c xs
  | otherwise = takeWhile (/=c) (x:xs) : (splitByChar c (dropWhile (/=c) (x:xs)))



shouldEqual = [ "Tyger Tyger, burning bright" , "In the forests of the night" , "What immortal hand or eye" , "Could frame thy fearful symmetry?"]


-- The main function here is a small test
-- to ensure you've written your function
-- correctly.
main :: IO ()
main = print $ "Are they equal? " ++ show (myLines sentences == shouldEqual)