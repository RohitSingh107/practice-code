{-# LANGUAGE NoMonomorphismRestriction #-}

module Exercise where

-- simple example
example = 1

bigNum = (^) 5
wahoo = bigNum $ 10

x = print 
y = print "woohoo!" 
z = x "hello world" 

a = (+) 
b = 5 
c = a 10 
d = c 200 

functionH :: [a] -> a
functionH (x:_) = x

functionC :: Ord a => a -> a -> Bool
functionC x y =
  if (x > y) then True else False

functionS :: (a, b) -> b
functionS (x,y) = y

-- Given a type, write function

i :: a -> a
i x = x

c''' :: a -> b -> a
c''' x y = x

c'' :: b -> a -> b
c'' x y = x

c' :: a -> b -> b
c' x y = y

r :: [a] -> [a]
r x = tail x

r' :: [a] -> [a]
r' x = reverse x

co :: (b -> c) -> (a -> b) -> a -> c
co bTOc aTOb x = bTOc $ aTOb x

a'' :: (a -> c) -> a -> a
a'' ac x = x

a' :: (a -> b) -> a -> b
a' ab x = ab x
