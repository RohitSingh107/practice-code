import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe
import qualified Data.Vector as V
import qualified Data.Vector.Unboxed as VU

readInt = fst . fromJust . BS.readInteger

readIntList = map readInt . BS.words

getIntList = readIntList <$> BS.getLine

-- solve :: Int -> Int -> [Int] -> Int
-- solve n k hs = dp !! (n - 1)
--   where
--     jumpCost from to = abs (hs !! from - hs !! to)

--     dp = 0 : fmap (\i -> minimum [dp !! (i - j) + jumpCost (i - j) i | j <- [1 .. k], i - j >= 0]) [1 .. n]

-- solve :: Int -> Int -> VU.Vector Int -> Int
-- solve n k v = dp ! (n -1)
--   where
--     dp = VU.constructN n f
--     f u
--       | i == 0 = 0
--       | i > 0 = VU.minimum . VU.map (\(d, h) -> d + abs (h - v ! i)) . VU.drop (i - k) $ VU.zip u v
--       where
--         i = VU.length u

solve :: Int -> Int -> VU.Vector Int -> Int
solve n k h = dp V.! (n - 1)
  where
    cost i j = abs (h VU.! i - h VU.! j)
    dp :: V.Vector Int
    dp = V.generate n recur
    recur :: Int -> Int
    recur 0 = 0
    -- recur i = minimum $ map jump [(i - 1), (i - 2) .. (max 0 (i - k))]
    recur i = minimum [dp V.! (i - j) + cost (i - j) i | j <- [1 .. k], i - j >= 0]

main = do
  [n, k] <- getIntList
  hs <- map fromIntegral <$> getIntList

  let hs' = VU.fromList hs

  print $ solve (fromIntegral n) (fromIntegral k) hs'
