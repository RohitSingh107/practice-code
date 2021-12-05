-- Database Processing

import Data.Time

data DatabaseItem = DbString String
                  | DbNumber Integer
                  | DbDate UTCTime
                  deriving (Eq, Ord, Show)

theDatabase :: [DatabaseItem]
theDatabase = 
    [ DbDate (UTCTime (fromGregorian 1911 5 1) (secondsToDiffTime 34123))
    , DbNumber 9001
    , DbString "Hello World!"
    , DbDate (UTCTime (fromGregorian 1921 5 1 ) (secondsToDiffTime 34123))
    ]


filterDbDate :: [DatabaseItem] -> [UTCTime]
filterDbDate = foldr concDate []
  where concDate (DbDate x) y = x : y
        concDate _ y          = y


-- fr cd [] [a,b,c,d]

-- cd a (cd b (cd c (fr cd d [])))

-- cd a (cd b (cd c d))

-- cd a (cd b [c])

-- cd a [c]

-- [a, c]

filterDbNumber :: [DatabaseItem] -> [Integer]
filterDbNumber = foldr concNum []
  where concNum (DbNumber x) y = x : y
        concNum _ y            = y


mostRecent :: [DatabaseItem] -> UTCTime
mostRecent = foldr maxDate (UTCTime (ModifiedJulianDay 0) 0)
  where maxDate (DbDate x) y = max x y
        maxDate _ y = y


sumDb :: [DatabaseItem] -> Integer
sumDb = foldr sd 0
  where sd (DbNumber x) y = x + y
        sd _ y = y


avgDb :: [DatabaseItem] -> Double
avgDb db = fromIntegral (sumDb db) / fromIntegral (length (filterDbNumber db))
-- avgDb db = (/) (fromIntegral s) c
--   where s = sumDb db
--         c = foldr countInt 0 db
--           where countInt (DbNumber x) y = y +1
--                 countInt _ y = y

