--Scans Exercise

fibs = 1 : scanl (+) 1 fibs

fibsN x = fibs !! x

fibs20 = take 20 fibs

fibsl100 = takeWhile (<100) fibs

factList :: [Integer]
factList = scanl (*) 1 [1..]

factorial :: Int -> Integer
factorial = (!!) factList
