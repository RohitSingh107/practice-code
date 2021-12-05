-- Ch 4 Exercise

module Ch4Exercise where

myAbs :: Integer -> Integer
myAbs x = if x >= 0 then x else negate x
  
isPalindrome :: (Eq a) => [a] -> Bool
isPalindrome x = x == reverse x

f :: (a,b) -> (c,d) -> ((b,d), (a,c))
f x y = ((snd x, snd y), (fst x, fst y)) 
