-- Typeclass Instances

data DayOfWeek =
  Mon | Tue | Wed | Thu | Fri | Sat | Sun deriving Show

instance Eq DayOfWeek where
  (==) Mon Mon = True
  (==) Tue Tue = True
  (==) Wed Wed = True
  (==) Thu Thu = True
  (==) Fri Fri = True
  (==) Sat Sat = True
  (==) Sun Sun = True
  (==) _ _     = False

instance Ord DayOfWeek where --making Fri always greatest and others equal
  compare Fri Fri = EQ
  compare Fri _   = GT
  compare _ Fri   = LT
  compare _ _ = EQ

-- Day of week and numerical day of month

data Date =
  Date DayOfWeek Int deriving Show

instance Eq Date where
  (==) (Date weekday dayOfMonth)
       (Date weekday' dayOfMonth') =
       weekday == weekday'
       && dayOfMonth == dayOfMonth'
 
data Identity a = Identity a

instance Ord a => Eq (Identity a) where
  (==) (Identity v) (Identity v') = v == v'


data Mood = Blah

instance Show Mood where
  show _ = "Something else"



