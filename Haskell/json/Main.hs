{-# LANGUAGE OverloadedStrings #-}
import Control.Applicative
import Data.Aeson
import Data.Text (Text)

-- Same type as before, but without the Generic instance.
data Person = Person { name :: Text, age :: Int } deriving Show

-- We expect a JSON object, so we fail at any non-Object value.
instance FromJSON Person where
    parseJSON (Object v) = Person <$> v .: "name" <*> v .: "age"
    parseJSON _ = empty

instance ToJSON Person where
    toJSON (Person name age) = object ["name" .= name, "age" .= age]

-- The main function is unchanged from before.
main :: IO ()
main = do
    putStrLn $ "Encode: " ++ (show (encode (Person { name = "Joe", age = 12 })))
    putStrLn $ "Decode: " ++
        (show (decode "{ \"name\": \"Joe\", \"age\": 12 }" :: Maybe Person))
