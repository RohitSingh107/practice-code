-- 9.6 Exercise

module ThyFearfulSymmetry where

myWords :: String -> [String]
myWords (' ':xs) = myWords xs
myWords xs
      | length xs ==0 = [] 
      | otherwise =  (takeWhile (/=' ') xs) : myWords (dropWhile (/=' ') xs)




splitByChar :: Char -> String -> [String]
splitByChar _ [] = []
splitByChar c (x:xs)
  | x == c    = splitByChar c xs
  | otherwise = takeWhile (/=c) (x:xs) : (splitByChar c (dropWhile (/=c) (x:xs)))
