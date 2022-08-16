fix :: (a -> a) -> a
fix f = let x = f x in x

memoize :: (Int -> a) -> (Int -> a)
memoize f = (map f [0 ..] !!)

fib :: (Int -> Integer) -> Int -> Integer
fib f 0 = 1
fib f 1 = 1
fib f n = f (n - 1) + f (n - 2)

fibMemo = fix (memoize . fib)


main :: IO()
main = do

  putStrLn "Enter the number: "
  i <- getLine

  let num = read i :: Int

  print $ fibMemo (num -1 )

  -- print $ fibMemo $ (-) 1000 1
