-- Fibonacci using scanl

fibs = 1 : scanl (+) 1 fibs

-- fibs = 1 : 1 : scanl (+) (1+1) fibs
-- 
-- fibs = 1 : 1 : 2 : scanl (+) (1+1+1) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : scanl (+) (1+1+1+2) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : 5 : scanl (+) (1+1+1+2+3) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : 5 : 8 : scanl (+) (1+1+1+2+3+5) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : 5 : 8 : 13 : scanl (+) (1+1+1+2+3+3+5+8) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : 5 : 8 : 13 : 21 : scanl (+) (1+1+1+2+3+5+8+13) fibs
-- 
-- fibs = 1 : 1 : 2 : 3 : 5 : 8 : 13 : 21 : 34 : scanl (+) (1+1+1+2+3+5+8+13+21) fibs
-- 
-- ...


fibsN x = fibs !! x
