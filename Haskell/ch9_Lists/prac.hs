-- practice

module Practice where

safeTail :: [a] -> Maybe [a]
safeTail []     = Nothing
safeTail (x:[]) = Nothing
safeTail (_:xs) = Just xs

mySum :: Num a => [a] -> a
mySum [] = 0
mySum (x : xs) = x + mySum xs


myWords :: String -> [String]
myWords (' ':xs) = myWords xs
myWords xs
      | null xs = [] 
      | otherwise =  (takeWhile (/=' ') xs) : myWords (dropWhile (/=' ') xs)


myFilter :: String -> [String]
myFilter xs = filter f w
  where w = myWords xs
        f e = case e of
                "the" -> False
                "a" -> False
                "an" -> False
                _ -> True

myFilter' :: String -> [String]
myFilter' = filter (\x -> not $ elem x ["the", "a", "an"]) . myWords


zip' :: [a] -> [b] -> [(a,b)]
zip' _ [] = []
zip' [] _  = []
zip' (x:xs) (x':xs') = (x,x') : zip' xs xs'

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ _ [] = []
zipWith' _ [] _ = []
zipWith' f (x:xs) (x':xs') = (f x x') : zipWith' f xs xs' 

zip'' :: [a] -> [b] -> [(a,b)]
zip'' = zipWith' (,) 




 
