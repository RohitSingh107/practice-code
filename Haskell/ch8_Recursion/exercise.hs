-- Ch 8 Exercise

module Exercise where

cattyConny :: String -> String -> String
cattyConny x y = x ++ " mrow " ++ y

flippy :: String -> String -> String
flippy = flip cattyConny

appedCatty :: String -> String 
appedCatty = cattyConny "woops"

frappe :: String -> String
frappe = flippy "haha"

-- 5. "pink mrow haha mrow green mrow woops mrow blue"
-- 6. "are mrow Pugs mrow awesome"

-- Recursion
-- dividedby 15 2 =
    -- go 15 2 0
    -- go 13 2 1
    -- go 11 2 2
    -- go 9  2 3
    -- go 7  2 4
    -- go 5  2 5
    -- go 3  2 6
    -- go 1  2 7
    -- | 1 < 2 = (7. 1)

addNumRec :: (Eq a, Num a) => a -> a
addNumRec 1 = 1
addNumRec n =
    n + addNumRec (n-1)




-- mulNumRec :: (Integral a) => a -> a -> a -- Broken
-- mulNumRec x y = go x y 0
--   where go x1 y1 c
        --   | c == y1 = x1
        --   | otherwise =
            --   go (x1 + x1) y1 (c + 1)


mulNumRec :: (Integral a) => a -> a -> a
mulNumRec 0 _ = 0
mulNumRec _ 0 = 0
mulNumRec x y = go x y y
    where go b c d
            | d == 1 = x
            | otherwise = x + go b c (d - 1)

-- mulNumRec 5 3
-- go 5 3 3
-- 5 + go 5 3 2
-- 5 + 5 + go 5 3 1
-- 5 + 5 + 5(| d == 1 = 5)

-- McCarthy 91

mc91 :: (Integral a) => a -> a
mc91 n 
  | n > 100 = n - 10
  | otherwise = mc91 $ mc91 $ n+11
