
module Main where

-- main :: IO Bool
main :: IO ()
main = do 
          c' <- getChar

          c  <- getChar
          
          -- return (c == c')
          if c == c'
            then putStrLn "True"
          else return ()
