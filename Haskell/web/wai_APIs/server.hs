{-# LANGUAGE OverloadedStrings #-}
import Network.Wai
import Network.Wai.Conduit
import Network.Wai.Handler.Warp
import Network.HTTP.Types
import Data.Aeson
import Data.Aeson.Parser (json)
import Data.Aeson.Types
import Data.Conduit
import Data.Conduit.Attoparsec (sinkParser)
import UnliftIO.Exception
import qualified Data.ByteString.Lazy.Char8 as BL8

newtype Body = Body Int

instance ToJSON Body where
  toJSON (Body i) = object ["hello" .= i]
instance FromJSON Body where
  parseJSON = withObject "Body" $ \o -> Body <$> o .: "hello"

main :: IO ()
main = run 3000 $ \req send -> do
  putStrLn "Request Received..."
  eres <- tryAnyDeep $ do
    val <- runConduit
         $ sourceRequestBody req
        .| sinkParser json
    -- this is still bad! But tryAnyDeep hides it
    let Success (Body i) = fromJSON val
    return i
  send $ case eres of
    Left e -> responseLBS
      status500
      [("Content-Type", "text/plain")]
      $ BL8.pack $ "Exception occurred: " ++ show e
    Right i -> responseBuilder
      status200
      [("Content-Type", "application/json")]
      $ fromEncoding $ toEncoding $ Body $ i + 1

