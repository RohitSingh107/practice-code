-- Ch7 Exercise

module Exercise where

tensDigit :: Integral a => a -> a
tensDigit x = d
  where xLast = x `div` 10
        d     = xLast `mod` 10

tensDigit' :: Integral a => a -> a
tensDigit' x = d
  where y = fst  . divMod x
        z = y 10
        e = snd . divMod z
        d = e 10
        
           
hunsDigit :: Integral a => a -> a
hunsDigit x = d2
  where (xlast, _) = divMod x 100
        (_ , d2)   = divMod xlast 10


foldBool :: a -> a -> Bool -> a
foldBool x y b = 
  case b of
    True -> y
    False -> x
  
foldBool' :: a -> a -> Bool -> a
foldBool' x y b
  | b = y
  | otherwise = x

foldBool'' :: a -> a -> Bool -> a
foldBool'' x _ False = x
foldBool'' _ y True = y

g :: (a -> b) -> (a, c) -> (b, c)
g f (a,c) = (f a, c)

-- Arith4
-- id :: a -> a
-- id x = x
roundTrip :: (Show a, Read a) => a -> a
roundTrip = read . show

roundTrip' :: (Show a, Read b) => a -> b
roundTrip' = read . show


main = do
  print (roundTrip 4)
  print (id 4)
  print ((roundTrip' 4) :: Int)




