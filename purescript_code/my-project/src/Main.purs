module Main where

import Prelude

import Effect (Effect)
import Halogen as H
import Halogen.Aff as HA
import Halogen.HTML as HH
import Halogen.HTML.Events as HE
import Halogen.VDom.Driver (runUI)

type State = String
data Action = Submit

main :: Effect Unit
main =
  HA.runHalogenAff do
    body <- HA.awaitBody
    void $ runUI component unit body

component :: forall query input output m. H.Component query input output m
component = H.mkComponent
  { initialState
  , render
  , eval: H.mkEval H.defaultEval { handleAction = handleAction }
  }

initialState :: forall i. i -> State
initialState _ = ""

render :: forall m. State -> HH.ComponentHTML Action () m
render s = HH.div_
  [ HH.div_ [ HH.button [ HE.onClick \_ -> Submit ] [ HH.text "Click Me" ] ]
  , HH.div_
      [ HH.text case s of
          "" -> ""
          _ -> s
      ]
  ]

handleAction :: forall output m. Action -> H.HalogenM State Action () output m Unit
handleAction = case _ of
  Submit -> H.modify_ \_ -> "Hello Purescript Halogen"

