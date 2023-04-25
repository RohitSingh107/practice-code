module Main where

import qualified Lib.Sphere as Sphere  
import qualified Lib.Cuboid as Cuboid  
import qualified Lib.Cube as Cube  

main :: IO ()
main = do
  print $ Cube.area 1.0


