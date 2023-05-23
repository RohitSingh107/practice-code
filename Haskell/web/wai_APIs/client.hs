{-# LANGUAGE OverloadedStrings #-}
import Data.Aeson
import Network.HTTP.Simple

main :: IO ()
main = do
  let req = setRequestMethod "POST"
          $ setRequestBodyJSON (object ["hello" .= (1 :: Int)])
            "http://localhost:3000"
  res <- httpJSON req
  print (res :: Response Value)
