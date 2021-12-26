-- Chapter Exercises

-- Warm-up and review

stops :: String
stops = "pbtdkg"

vowels :: String
vowels = "aeiou"

nouns :: [String]
nouns = ["He", "She", "Me", "They", "Rohit"]

verbs :: [String]
verbs = ["Sleep", "Walk", "Code", "Drink", "Swim"]


sVs :: String -> String -> [(Char, Char, Char)]
sVs x y = [(s, v, s2) | s <- x, v <- y, s2 <- x]

sVsp :: String -> String -> [(Char, Char, Char)]
sVsp x y = filter (\a ->
                        case a of 
                        ('p', _, _) -> True
                        _          -> False)
                        (sVs x y)

sVsp' :: String -> String -> [(Char, Char, Char)]
sVsp' x y = [('p', v, s) | v <- y, s <- x]

nVn :: [String] -> [String] -> [(String, String, String)]
nVn x y = [(n, v, n2) | n <- x, v <- y, n2 <- x]

seekritFunc :: String -> Double
seekritFunc x = cc / wc
  where cc = fromIntegral (sum (map length (words x)))
        wc = fromIntegral (length (words x))


-- Rewriting functions using folds

myOr :: [Bool] -> Bool
myOr = foldr (||) False

myAny :: (a -> Bool) -> [a] -> Bool
myAny f = foldr ((||) . f) False
-- myAny f = foldr (\x y -> f x || y) False
-- myAny f = foldr (||) False . map f

myElem :: Eq a => a -> [a] -> Bool
myElem e = foldr ((||) . (==e)) False

myReverse :: [a] -> [a]
myReverse = foldl (flip (:)) []

myMap :: (a -> b) -> [a] -> [b]
myMap f = foldr ((:) . f) []

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter f = foldr (\x y -> 
                           if f x 
                             then x : y
                           else y) 
                           []

squish :: [[a]] -> [a]
squish = foldr (++) []

squishMap :: (a -> [b]) -> [a] -> [b]
squishMap f = foldr ((++) . f) []

squishAgain :: [[a]] -> [a]
squishAgain = squishMap id

myMaximumBy :: (a -> a -> Ordering) -> [a] -> a
myMaximumBy f ls = foldr (\x y ->
                                 case f x y of
                                   GT -> x
                                   _ -> y) (last ls) ls

myMinimumBy :: (a -> a -> Ordering) -> [a] -> a
myMinimumBy f ls = foldr (\x y ->
                                 case f x y of
                                   LT -> x
                                   _ -> y) (last ls) ls
