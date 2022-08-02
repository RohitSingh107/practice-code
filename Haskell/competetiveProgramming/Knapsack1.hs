import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.Maybe
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VM
import GhcPrelude (print)

readInt = fst . fromJust . BS.readInteger

readIntList = map readInt . BS.words

getIntList = readIntList <$> BS.getLine

go _ 0 _ _ _ = 0
go (-1) _ _ _ _ = 0
go i wtl wt val dp2d = do
  d1 <- VM.read dp2d i
  x <- VM.read d1 wtl
  if x /= (-1)
    then do
      let max_value = go (i -1) (wtl)
      let max_value2 = go (i -1) (wtl - (wt VU.! i)) + (val VU.! i)
      VM.write d1 wtl max_value2
      y <- VM.read wtl
      return y
    else return x

solve ind wt_left wt val = do
  dp1 <- VM.replicate 100005 (-1 :: Int)
  dp2d <- VM.replicate 105 dp1
  go ind wt_left

main = do
  -- [n, k] <- getIntList
  -- hs <- map fromIntegral <$> getIntList
  print $ solve 2 8 (VU.fromList [3, 4, 5]) (VU.fromList [30, 50, 60])

-- let hs' = VU.fromList hs

-- print $ solve (fromIntegral n) (fromIntegral k) hs'
