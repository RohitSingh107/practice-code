module Main where

import Prelude

import Effect (Effect)
import Halogen.Aff as HA
import Halogen.VDom.Driver (runUI)
-- import HelloPureScript (component)
-- import Counter (component)
-- import RandomNumber (component)
import HTTPRequest (component)

main :: Effect Unit
main =
  HA.runHalogenAff do
    body <- HA.awaitBody
    void $ runUI component unit body

