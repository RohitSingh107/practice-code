-- Chapter Exercise

import Data.Char

-- String processing

notThe :: String -> Maybe String
notThe xs = if xs == "The" || xs == "the" then Nothing else Just xs  



replaceThe :: String -> String
replaceThe = unwords . go . words
 where go [] = []
       go (w:ws) = theToA (notThe w) : go ws
                      where 
                            theToA Nothing = "a"
                            theToA (Just x) = x

beginWithVowel :: String -> Bool
beginWithVowel [] = False
beginWithVowel (w:_) = if w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' then True else False


countTheBeforeVowel :: String -> Integer
countTheBeforeVowel xs = go (words xs) 0
  where go (w:ws:wss) c = case notThe w of
                            Nothing -> if beginWithVowel ws then go (ws:wss) (c+1) else go (ws:wss) c
                            Just _ -> go (ws:wss) c
        go _ c = c


isVowel :: Char -> Bool 
isVowel w =  w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u'                      

countVowels :: String -> Integer
countVowels text = go text 0
  where go (x:xs) c
           | isVowel x = go xs (c+1)
           | otherwise = go xs c
        go [] c = c

countVowels' :: String -> Integer
countVowels' = fromIntegral . length . filter isVowel


-- Validate the word
newtype Word' = Word' String deriving (Eq, Show)

-- vowels :: String
-- vowels = "aeiou"

mkWord :: String -> Maybe Word'
mkWord word = (\(x,y) -> if x>y then Nothing else Just (Word' word)) $ go word (0,0)
  where go (x:xs) (v,c) = if isVowel (toLower x) then go xs (v+1, c) else go xs (v, c+1)
        go [] (v,c) = (v,c)

data Nat = Zero
         | Succ Nat
         deriving (Eq, Show)

natToInteger :: Nat -> Integer
natToInteger Zero = 0
natToInteger (Succ nat) = 1 + natToInteger nat

integerToNat :: Integer -> Maybe Nat
integerToNat i
  | i < 0 = Nothing
  | otherwise = Just $ go i
                  where go 0 = Zero
                        go n = Succ (go (n-1))   