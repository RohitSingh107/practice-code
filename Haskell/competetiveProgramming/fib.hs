import qualified Data.Vector.Unboxed.Mutable as V

dp = V.replicate 10 ^ 5 (-1 :: Int)

fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n = do

  -- | (V.read dp n /= -1 -> V.read dp n
  -- | otherwise -> 7
  --   -- let ans = fib (n - 1) + fib (n - 2)
  --   -- V.write dp n ans
  --   -- return V.read dp n

main :: IO ()
main = do
  print "Enter the number"
  s <- getLine

  let n = read s :: Integer

  print $ show $ fib n
