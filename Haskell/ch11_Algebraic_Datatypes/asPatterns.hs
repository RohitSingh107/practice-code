-- As Patterns

import Data.Char

f :: Show a => (a, b) -> IO (a, b)
f t@(a, _) = do
    print a
    return t

doubleUp :: [a] -> [a]
doubleUp [] = []
doubleUp xs@(x:_) = x : xs


isSubseqOf :: (Eq a) => [a]  -> [a] -> Bool
isSubseqOf [] _ = True
isSubseqOf _ [] = False
isSubseqOf aas@(a:as) (b:bs) = 
    if a == b
        then isSubseqOf as bs
    else isSubseqOf aas bs

-- isSubseqOf :: (Eq a) => [a] -> [a] -> Bool
-- isSubseqOf [] _ = True
-- isSubseqOf (x:xs) txt@(t:ts) = elem x txt && isSubseqOf xs txt


capitalizeWord :: String -> (String, String)
capitalizeWord [] = ([], [])
capitalizeWord word@(t:r) =  (word, toTitle t : r)

capitalizeWords :: String -> [(String, String)]
-- capitalizeWords sentence = map capitalizeWord (words sentence)
capitalizeWords sentence = map (\word@(t:r) -> (word, toTitle t : r))  (words sentence)