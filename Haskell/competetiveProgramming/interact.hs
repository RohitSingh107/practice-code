import Control.Monad (replicateM_)

addOk :: String -> String
addOk s = "Ok" ++ s

mf :: Int -> Int -> Int
mf x y = x + y

mulTen :: Int -> Int
mulTen x = x * 10

-- main :: IO ()
-- main =
--   interact $
--     unlines
--       . map (show . (\xs -> mf (xs !! 0) (xs !! 1)) . map read . words)
--       . drop 1
--       . lines

main :: IO ()
main = do
  content <- getLine

  let n = read content :: Int

  replicateM_ n $ do
    inp <- getLine
    let arg = map read $ words inp
    print $ show $ mf (arg !! 0) (arg !! 1)

-- 5
-- 4 5
-- 1 2
-- 3 7
-- 55 3
-- 78 41
