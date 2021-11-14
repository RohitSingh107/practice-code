-- greetIfCool1.hs

module GreetIfCool1 where

greetIfCool :: String -> IO ()
greetIfCool coolness = 
  if cool coolness
    then putStrLn "eyyyyy. What's shakin'?"
  else
    putStrLn "pshhhhh."
  where cool x = 
         x  == "downright frosty yo"


greetIfCool2 :: String -> IO ()
greetIfCool2 coolness2 = 
  if coolness2 == "downright frosty yo"
    then putStrLn "eyyyyy. What's shakin'?"
  else
     putStrLn "pshhhhh."
