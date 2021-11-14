-- Exercise Ch6
import Data.List

data Person = Person Bool deriving Show

printPerson :: Person -> IO ()
printPerson person = putStrLn (show person)

data Mood = Blah | Woot deriving (Eq, Show)

settleDown x = if x == Woot
                 then Blah
                 else x

type Subject = String
type Verb = String
type Object = String

data Sentence =
  Sentence Subject Verb Object
  deriving (Eq, Show)

s1 = Sentence "dogs" "drools"
s2 = Sentence "Julie" "loves" "dogs"

data Rocks = 
  Rocks String deriving (Eq, Ord, Show) 

data Yeah = 
  Yeah Bool deriving (Eq, Ord, Show)

data Papu = 
  Papu Rocks Yeah 
  deriving (Eq, Ord, Show)


phew = Papu (Rocks "chases") (Yeah True)

truth = Papu (Rocks "chomskydoz")
             (Yeah True)

equalityForeall :: Papu -> Papu -> Bool
equalityForeall p p' = p == p'

comparePapus :: Papu -> Papu -> Bool
comparePapus p p' = p > p'


i :: Num a => a
i = 1

f :: Fractional a => a
f = 1.0

g :: Fractional a => a
g = 1.0

h :: RealFrac a => a
h = 1.0

freud :: Ord a => a -> a
freud x = x

freud' :: Int -> Int
freud' x = x


myX = 1 :: Int

sigmund :: a -> Int
sigmund x = myX

sigmund' :: Num a => a -> Int
sigmund' x = myX

jung :: [Int] -> Int
jung xs = head (sort xs)

young :: Ord a => [a] -> a
young xs = head (sort xs)


mySort :: [Char] -> [Char]
mySort = sort

signifier :: [Char] -> Char
signifier xs = head (mySort xs)


-- Type-Kwon-Do Two: Electric Typealoo

chk :: Eq b => (a -> b) -> a -> b -> Bool
chk aTOb a b = b == aTOb a

arith :: Num b
      => (a -> b)
      -> Integer
      -> a
      -> b
arith aTOb int a = aTOb a + fromInteger i



