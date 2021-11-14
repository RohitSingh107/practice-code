-- 9.5 Exercise

module EFT where

eftBool :: Bool -> Bool -> [Bool]
eftBool True False = []
eftBool False True = [False, True]
eftBool False False = [False]
eftBool True True = [True]



eftOrd :: Ordering -> Ordering -> [Ordering]
eftOrd GT GT = [GT]
eftOrd GT _ = []
eftOrd s t
      | s == t = [t]
      | otherwise = s : eftOrd (succ s) t



eftInt :: Int -> Int -> [Int]
eftInt s t
      | s == t = [s]
      | otherwise = eftInt s (pred t) ++ [t]



eftChar :: Char -> Char -> [Char]
eftChar s t 
      | s == t = [t]
      | otherwise = s : eftChar (succ s) t


--eftChar a d
-- go a d
-- [a] ++ go b d
-- [a] ++ [b] ++ go c d
-- [a] ++ [b] ++ [c] ++ go d d
-- [a] ++ [b] ++ [c] ++ [d]


