module Main where

import System.IO
import Control.Exception (SomeException, catch)

catchAny :: IO a -> (SomeException -> IO a) -> IO a
catchAny = Control.Exception.catch 

-- safeFileReader :: FilePath -> IO String
-- safeFileReader fPath = do
--   entireFileAsString <- catchAny (readFile fPath)  (\error -> do
--     putStrLn $ "You got an Error: " ++ show error 
--     return "File not Found")
--   return entireFileAsString

-- safeFileReader :: FilePath -> IO String
-- safeFileReader fPath = do
--   entireFileAsString <- catchAny (readFile fPath) $ \error -> do
--     putStrLn $ "Error: " ++ show error 
--     return ""
--   return entireFileAsString



safeFileReader :: FilePath -> IO String
safeFileReader fPath = do 
  catchAny (readFile fPath) $ \error -> do
    putStrLn $ "Error: " ++ show error
    return ""


main :: IO ()
main = do
  fContents <- safeFileReader "temp.txt"
  print fContents
  print $ words fContents
