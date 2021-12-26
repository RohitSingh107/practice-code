-- 11.9 newtype

-- newtype Goats = Goats Int deriving (Eq, Show)

newtype Cows = Cows Int deriving (Eq, Show)

tooManyGoats :: Goats -> Bool
tooManyGoats (Goats n) = n > 42


class TooMany a where
  tooMany :: a -> Bool

instance TooMany Int where
  tooMany n = n > 42

newtype Goats = Goats Int deriving (Eq, Show)

instance TooMany Goats where
  tooMany (Goats n) = tooMany n

  
