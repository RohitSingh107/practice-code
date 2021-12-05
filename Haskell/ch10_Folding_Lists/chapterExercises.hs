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
