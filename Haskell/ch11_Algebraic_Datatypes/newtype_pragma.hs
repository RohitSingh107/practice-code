
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE FlexibleInstances #-}

newtype Cows = Cows Int deriving (Eq, Show)

tooManyGoats :: Goats -> Bool
tooManyGoats (Goats n) = n > 42


class TooMany a where
  tooMany :: a -> Bool

instance TooMany Int where
  tooMany n = n > 42

newtype Goats = Goats Int deriving (Eq, Show, TooMany)

instance TooMany (Int, String) where
  tooMany (i, _) = tooMany i

instance TooMany (Int, Int) where
  tooMany (x, y) = tooMany (x + y)

instance (Num a, TooMany a) => TooMany (a,a) where
  tooMany (x, y) = tooMany (x * y)

  
