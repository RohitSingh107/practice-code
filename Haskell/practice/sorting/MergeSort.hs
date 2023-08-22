module MergeSort (mergeSort) where

import Data.Vector (Vector)
import qualified Data.Vector as V

mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort arr = merge (mergeSort left) (mergeSort right)
  where
    mid = length arr `div` 2
    (left, right) = splitAt mid arr
    merge :: Ord a => [a] -> [a] -> [a]
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
      | x < y = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

mergeSortV :: Ord a => Vector a -> Vector a
mergeSortV v
  | V.length v == 1 = v
  | otherwise = merge (mergeSortV left) (mergeSortV right)
    where
      mid = V.length v `div` 2
      (left, right) = V.splitAt mid v
      merge :: Ord a => Vector a -> Vector a -> Vector a
      merge x y
        | V.null x = y
        | V.null y = x
        | V.head x < V.head y = V.head x `V.cons` merge (V.tail x) y
        | otherwise = V.head y `V.cons` merge x (V.tail y)


