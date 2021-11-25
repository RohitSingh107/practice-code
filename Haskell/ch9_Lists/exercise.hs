-- CH 9 Exercise

module Exercise where

import Data.Char

filtUpp :: [Char] -> [Char]
filtUpp = filter isUpper 

capitalize :: [Char] -> [Char]
capitalize (x:xs) = toTitle x : xs

capitalizeFull :: [Char] -> [Char]
capitalizeFull [] = []
capitalizeFull (x:xs) = toTitle x : capitalizeFull xs

onlyF :: [Char] -> Char
onlyF = toTitle . head