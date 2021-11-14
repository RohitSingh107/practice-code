-- practice

module Practice where

f'' :: (a,b) -> (c,d) -> ((b,d), (a,c))
f'' (a,b) (c,d) = ((b,d), (a,c))

g :: Num a => (a,a) -> a
g (x,y) = x + y

h :: (a,b,c) -> c
h (_, _, x) = x

i :: (a, b,c) -> a
i (x, _, _) = x


f :: (a,b,c) -> (d,e,f) -> ((a,d), (c,f))
f (a,b,c) (d,e,f) = ((a,d), (c,f))

pal xs = 
  case y of 
    True -> "yes"
    False -> "no"
  where y = xs == reverse xs

functionC x y = 
  case x > y of
    True -> x
    False -> y

ifEvenAdd2 n =
  case even n of
    True -> n+2
    False -> n

nums x = 
  case compare x 0 of
    LT -> -1
    GT -> 1
    EQ -> 0

myFlip :: (a -> b -> c) -> b -> a -> c
myFlip f = \ x -> \ y -> f y x





