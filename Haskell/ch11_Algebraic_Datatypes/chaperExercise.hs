-- Language Exercises

import Data.Char

capitalizeWord :: String -> String
capitalizeWord [] = []
capitalizeWord (t:r) =  toTitle t : r

splitSentence :: String -> [String]
splitSentence [] = []
splitSentence sentence = (sen ++ ". ") : splitSentence part
  where sen = takeWhile (/= '.') sentence
        part = drop 2 $ dropWhile (/= '.') sentence



capitalizeParagraph :: String -> String
capitalizeParagraph paragraph = init $ concatMap capitalizeWord (splitSentence paragraph)

-- Hutton's Razor
data Expr = Lit Integer
          | Add Expr Expr

eval :: Expr -> Integer
eval (Lit i) = i
eval (Add e1 e2) = eval e1 + eval e2

printExpr :: Expr -> String
printExpr (Lit i) = show i
printExpr (Add e1 e2) = printExpr e1 ++ " + " ++ printExpr e2 


-- Phone exercise

type Digit = Char
type Presses = Int

-- data DaPhone = One [Digit]
--              | Two [Digit]
--              | Three [Digit]
--              | Four [Digit]
--              | Five [Digit]
--              | Six [Digit]
--              | Seven [Digit]
--              | Eight [Digit]
--              | Nine [Digit]
--              | Star [Digit]
--              | Zerro [Digit]
--              | Hash [Digit]
--              deriving (Show, Eq)
             


-- phone :: [DaPhone]
-- phone = [ One "1"
--         , Two "abc2"
--         , Three "def3"
--         , Four "ghi4"
--         , Five "jkl5"
--         , Six "mno6"
--         , Seven "pqrs7"
--         , Eight "tuv8"
--         , Nine "wxyz9"
--         , Star "^*"
--         , Zerro "+ 0"
--         , Hash ".,#" ]


-- convo :: [String]
-- convo =
--   ["Wanna play 20 questions",
--   "Ya",
--   "U 1st haha",
--   "Lol ok. Have u ever tasted alcohol",
--   "Lol ya",
--   "Wow ur cool haha. Ur turn",
--   "Ok. Do u think I am pretty Lol",
--   "Lol ya",
--   "Just making sure rofl ur turn"]

-- -- reverseTaps :: DaPhone -> Char -> [(Digit, Presses)]
-- reverseTaps ( bs) c
--   | isLower c = c

--   | isUpper c = c


