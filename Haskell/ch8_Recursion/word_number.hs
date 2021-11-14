-- Ch 8 Exercise Word Number

module WordNumber where

import Data.List (intersperse)

digitToWord :: Int -> String
digitToWord 1 = "one"
digitToWord 2 = "two"
digitToWord 3 = "three"
digitToWord 4 = "four"
digitToWord 5 = "five"
digitToWord 6 = "six"
digitToWord 7 = "seven"
digitToWord 8 = "eight"
digitToWord 9 = "nine"
digitToWord 0 = "zero"
digitToWord _ = "Enter valid Integer"


digits :: Int -> [Int]
digits 0 = []
digits x = digits (x `div` 10) ++ [x `mod` 10]

-- digits 75
-- digits (75 div 10) ++ [75 mod 10]
-- digits 7 ++ [5]
-- (digits (7 div 10) ++ [7 mod 10]) ++ [5]
-- (digits 0 ++ [7]) ++ [5]
-- ([] ++ [7]) ++ [5] 

wordNumber :: Int -> String
wordNumber n = concat $ intersperse "-" $ map digitToWord $ digits n
-- wordNumber = concat . intersperse "-" . map digitToWord . digits


