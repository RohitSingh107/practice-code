-- Ch 9 Exercise

module StdFuncs where

myAnd :: [Bool] -> Bool 
myAnd [] = True
myAnd (x:xs) =
    if x == False
        then False
    else myAnd xs

myAnd' :: [Bool] -> Bool
myAnd' [] = True
myAnd' (x:xs) = x && myAnd' xs

myOr :: [Bool] -> Bool
myOr [] = False
myOr (x:xs) = x || myOr xs

myAny :: (a -> Bool) -> [a] -> Bool
myAny _ [] = False
myAny f (x:xs) = f x || myAny f xs

myElem :: Eq a => a -> [a] ->  Bool
myElem _ [] = False
myElem e (x:xs) = e == x || myElem e xs

myElem' :: Eq a => a -> [a] -> Bool
myElem' e = myAny (==e)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myReverse xs ++ [x]
-- myReverse xs = last xs: myReverse (init xs)

squish :: [[a]] -> [a]
squish xs = [y | x <- xs, y <- x]

squishMap :: (a -> [b]) -> [a] -> [b]
squishMap _ [] = []
squishMap f (x:xs) = f x ++ squishMap f xs 

squishAgain :: [[a]] -> [a]
squishAgain = squishMap id

myMaximumBy :: (a -> a -> Ordering) -> [a] -> a
myMaximumBy f (x:[]) = x
myMaximumBy f (x:xs) = case f x lx of
                         LT -> lx
                         EQ -> x
                         GT -> x
                       where lx = myMaximumBy f xs

myMinimumBy :: (a -> a -> Ordering) -> [a] -> a
myMinimumBy f (x:[]) = x
myMinimumBy f (x:xs) = case f x lx of
                         LT -> x
                         EQ -> x
                         GT -> lx
                       where lx = myMinimumBy f xs

myMaximum :: (Ord a) => [a] -> a
myMaximum = myMaximumBy compare

myMinimum :: (Ord a) => [a] -> a
myMinimum = myMinimumBy compare

