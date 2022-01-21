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



