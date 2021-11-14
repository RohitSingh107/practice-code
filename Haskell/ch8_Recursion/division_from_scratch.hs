-- Divion using subtraction

module DivisionFromScratch where

-- type Numerator   = Integer 
-- type Denominator = Integer 
-- type Quotient    = Integer

-- dividedBy :: Numerator
--           -> Denominator
--           -> Quotient
dividedBy :: Integral a => a -> a -> (a,a)
dividedBy num 0 = error "divide by zero"
dividedBy num denom = go (abs num) (abs denom) 0
  where go n   d count
         | n < d = (count, n)
         | otherwise = 
             go (n- d) d (count+1)

data DividedResult =
    Result Integer 
  | DividedByZero deriving Show

dividedBy' :: Integral a => a -> a -> DividedResult
dividedBy' num denom = go num denom 0
  where go n d count
          | d == 0 = DividedByZero
          | d < 0 = case dividedBy' n (abs d) of
                      DividedByZero -> DividedByZero
                      Result r -> Result (negate r)
          | n < 0 = case dividedBy' (abs n) d of 
                      DividedByZero -> DividedByZero
                      Result r -> Result (negate r)
          | n < d = Result count
          | otherwise = go (n - d) d (count +1)

