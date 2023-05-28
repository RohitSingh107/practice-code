{-# LANGUAGE OverloadedStrings #-}
import Network.Wai
import Network.HTTP.Types
import Network.Wai.Handler.Warp (run)
import Data.Aeson
import Data.Map     (fromList)
import qualified Data.ByteString.Lazy.Char8 as LBS
-- import qualified Data.ByteString as BS

app :: Application
app request respond = do
    putStrLn "I've done some IO here"
    let path = pathInfo request
    -- putStrLn $ show $ queryString request
    putStrLn $ show path
    let response = case path of 
          [] -> homePageHandler
          ["hello"] -> helloHandler
          ["helo"] -> heloRedirectHandler
          ["file"] -> filePageHandler
          ["svg"] -> svgHandler
          ["name"] -> nameHandler request
          _ -> notFoundHandler
    respond response

homePageHandler :: Response
homePageHandler = responseFile status200 [("Content-Type", "text/html")] "./index.html" Nothing

jsonExHandler :: Response
jsonExHandler = responseLBS status200 [("Content-Type", "application/json")] jsonR 
  where jsonR = encode $ fromList [
                                   ("k1" :: String, (fromList [
                                                     ("k1.1" :: String, "v1.1" :: String), ("k1.2", "v1.2")]) )
                                  ,("k2" :: String, (fromList [
                                        ("k2.1" :: String, "v2.1" :: String), ("k2.2", "v2.2")]) )
                                  ] 
helloHandler :: Response
helloHandler = responseLBS status200 [("Content-Type", "text/plain")] "Hello Haskell!"

heloRedirectHandler :: Response
heloRedirectHandler = responseLBS status303 [("Location", "/hello")] "Redirecting to Hello Page"

filePageHandler :: Response
filePageHandler = responseFile status200 [("Content-Type", "text/plain")] "./Main.hs" Nothing

svgHandler :: Response
svgHandler = responseFile status200 [("Content-Type", "image/svg+xml; charset=utf-8")] "./tmp.svg" Nothing

nameHandler :: Request -> Response
nameHandler req = responseLBS status200 [("Content-Type", "text/plain")] res
  where res = processRequest (queryString req)
            where processRequest :: Query -> LBS.ByteString
                  processRequest qp = 
                      case lookup "name" qp of 
                      Nothing -> "Name parameter not found" 
                      Just (Just name) -> "Hello, " <> LBS.fromStrict name <> " the Haskeller!"


notFoundHandler :: Response
notFoundHandler = responseLBS status404 [("Content-Type", "text/plain")] "Not Found"

main :: IO ()
main = do
    putStrLn "http://localhost:8080/"
    run 8080 app
