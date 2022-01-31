module Main where

import System.IO

type Name = String
type Age = Integer

data Person = Person Name Age deriving Show

data PersonInvalid =
    NameEmpty
  | AgeTooLow
  | PersonInvalidUnknown String
  deriving (Eq, Show)

mkPerson :: Name
         -> Age
         -> Either PersonInvalid Person

mkPerson name age
  | name /= "" && age > 0 =
      Right $ Person name age
  | name == "" = Left NameEmpty
  | not (age > 0) = Left AgeTooLow
  | otherwise =
      Left $ PersonInvalidUnknown $
        "Name was: " ++ show name ++
        " Age was: " ++ show age

gimmePerson :: IO ()
gimmePerson = do
  hSetBuffering stdout NoBuffering
  putStr "Enter your name:"
  name <- getLine
  putStr "Enter the age:"
  age <- getLine
  case mkPerson name (read age :: Integer) of
    (Left er) -> do
      putStrLn "An error occurred as below"
      print er
    (Right p) -> do
      putStrLn "Yay! Sucessfully got a person"
      print p 

main :: IO ()
main = gimmePerson
