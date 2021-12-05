-- Ch4 Exercises
-- From Correcting Syntax

module Exercise where

x = (+)

f :: [Char] -> Int
f xs = w `x` 1
  where  w = length xs

g :: (a,b) -> a
g y = fst y
-- or
-- g (a,b) = a
