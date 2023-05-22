{-# LANGUAGE OverloadedStrings #-}
import Network.Wai
import Network.HTTP.Types
import Network.Wai.Handler.Warp (run)
import Data.Aeson
-- import Data.ByteString (ByteString)
--
-- app :: Application
-- app _ respond = do
--     putStrLn "I've done some IO here"
--     respond $ responseLBS
--         status200
--         [("Content-Type", "text/plain")]
--         "Hello Hasklell Web!"
app :: Application
app request respond = do
    putStrLn "I've done some IO here"
    let path = pathInfo request
    putStrLn $ show path
    let response = case path of 
          [] -> homePageHandler
          ["hello"] -> helloHandler
          _ -> notFoundHandler
    respond response

homePageHandler :: Response
homePageHandler = responseLBS status200 [("Content-Type", "text/plain")] "My Home Page"
-- homePageHandler = responseLBS status200 [("Content-Type", "application/json")] jsonR 
  -- where jsonR = encode [""]

helloHandler :: Response
helloHandler = responseLBS status200 [("Content-Type", "text/plain")] "Hello Web with Haskell!"

notFoundHandler :: Response
notFoundHandler = responseLBS status404 [("Content-Type", "text/plain")] "Not Found"

-- getNameHandler::ByteString -> Response
-- getNameHandler userName = undefined 

main :: IO ()
main = do
    putStrLn "http://localhost:8080/"
    run 8080 app
