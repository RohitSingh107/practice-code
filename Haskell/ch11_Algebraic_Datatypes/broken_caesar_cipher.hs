-- Ch 9 Exercise

module Cipher where

import Data.Char

kcode :: [(Char, Int)]
kcode = zip ['A'..'Z'] [0..25]

excode :: Char -> Int
excode x = head [b | (a,b) <- kcode, a == x] 

encode1 :: String -> String -> [(Char, Char)]
-- encode1 t s = zip [ c | c <- t, c /= ' '] s
encode1 t s = zip t' s'
  where t' = [ c | c <- t, c /= ' ']
        s' = concat $ repeat s

-- encode2 :: Int -> Char -> Char
-- encode2 i c1 = if c1 == ' ' then ' ' else chr (((ord c1) + i) `mod` 122)
-- -- encode2 i c1 = if c1 == ' ' then ' ' else 
--                                         --  ci = ord c1
--                                         --  if ci > 122 

myCaesar :: Int -> Char -> Char
myCaesar num x = code num x
  where code n a 
           | isLower a = codeL n a
           | otherwise = codeU n a
                where codeL n al
                        | ord al > (122 - n) = codeL n (chr $ ord al - 26)
                        | otherwise = chr $ ord al + n

                      codeU n au
                        | ord au > (90 - n) = codeU n (chr $ ord au - 26)
                        | otherwise = chr $ ord au + n
                    

encode :: String -> String -> String -> String
encode _ [] _ = []
encode key (x:xs) full = myCaesar k x : encode key xs full
  where k =  excode $ snd $ head $ [ (a, b) | (a, b) <- encode1 full key, a == x]

-- encode key tex@(x:xs) = myCaesar (excode $ snd $ head $ [ (a, b) | (a, b) <- encode1 tex key, a == x]) x : encode key xs
