-- Ch9 Exercise Ciphers

module Cipher where

import Data.Char

myCaesar :: String -> String 
myCaesar [] = []
myCaesar (x:xs) = code x : myCaesar xs
  where code a 
           | isLower a = codeL a
           | otherwise = codeU a
                where codeL al
                        | ord al > 119 = codeL (chr $ ord al - 26)
                        | otherwise = chr $ ord al +3

                      codeU au
                        | ord au > 87 = codeU (chr $ ord au - 26)
                        | otherwise = chr $ ord au +3

myCaesar' :: Int -> String -> String 
myCaesar' _ [] = []
myCaesar' num (x:xs) = code num x : myCaesar' num xs
  where code n a 
           | isLower a = codeL n a
           | otherwise = codeU n a
                where codeL n al
                        | ord al > (122 - n) = codeL n (chr $ ord al - 26)
                        | otherwise = chr $ ord al + n

                      codeU n au
                        | ord au > (90 - n) = codeU n (chr $ ord au - 26)
                        | otherwise = chr $ ord au + n
                    
          
unCaesar :: String -> String 
unCaesar [] = []
unCaesar (x:xs) = decode x : unCaesar xs
  where decode a
             | isLower a = decodeL a
             | otherwise = decodeU a
                  where decodeL al
                          | ord al < 100 = decodeL (chr $ ord al + 26)
                          | otherwise = chr $ ord al - 3
                        
                        -- decodeU '#' = ' '
                        decodeU au
                          | au == chr (32 + 3) = chr $ ord au - 3
                          | ord au < 68 = decodeU (chr $ ord au + 26)
                          | otherwise = chr $ ord au - 3
unCaesar' :: Int -> String -> String 
unCaesar' _ [] = []
unCaesar' num (x:xs) = decode num x : unCaesar' num xs
  where decode n a
             | isLower a = decodeL n a
             | otherwise = decodeU n a
                  where decodeL n al
                          | ord al < (97 + n) = decodeL n (chr $ ord al + 26)
                          | otherwise = chr $ ord al - n
                        
                        -- decodeU '#' = ' '
                        decodeU n au
                          | au == chr (32 + n) = chr $ ord au - n
                          | ord au < (65 + n) = decodeU n (chr $ ord au + 26)
                          | otherwise = chr $ ord au - n

                        