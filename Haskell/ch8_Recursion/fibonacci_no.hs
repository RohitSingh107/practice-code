-- Fibonachi Numbers

module Fibonacci where

fibonacci :: (Eq a, Num a, Num p) => a -> p
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci x = fibonacci (x-1) + fibonacci (x-2)

