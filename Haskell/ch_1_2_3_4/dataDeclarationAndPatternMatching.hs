-- datatypes and pattern matching function

import Data.Tuple

fstm :: (a,b) -> a
fstm  (a,b) = a

sndm :: (a,b) -> b
sndm (a,b) = b

tupFunc :: (Int, [a])
        -> (Int, [a])
        -> (Int, [a])
tupFunc (a,b) (c,d) =
  ((a+c), (b++d))

data Mood = Blah | Woot deriving Show

changeMood :: Mood -> Mood
changeMood Blah = Woot
changeMood x = Blah
