module Counter (component) where

import Prelude

import Effect.Aff.Class (class MonadAff)
import Halogen as H
import Halogen.HTML as HH
import Halogen.HTML.Events as HE
import Halogen.HTML.Properties as HP
import Web.Event.Event (Event)
import Web.Event.Event as Event

type State = Array String
data Action = AddText String | Submit Event | Clear

component :: forall query input output m. MonadAff m => H.Component query input output m
component = H.mkComponent
  { initialState
  , render
  , eval: H.mkEval H.defaultEval { handleAction = handleAction }
  }

initialState :: forall input. input -> State
initialState _ = []

render :: forall m. State -> H.ComponentHTML Action () m
render s = HH.div_
  [ HH.form [ HE.onSubmit \ev -> Submit ev ]
      [ HH.h1_ [ HH.text "Welcome to my program" ]
      , HH.label_
          [ HH.div_ [ HH.text "Enter the text" ]
          , HH.input
              [ HE.onValueChange \str -> AddText str
              ]
          ]
      , HH.button [ HP.type_ HP.ButtonSubmit ] [ HH.text "Submit" ]

      ]
  , HH.div_ [ HH.h2_ [ HH.text "History:" ], HH.ol_ (map (\t -> HH.li_ [ HH.text t ]) s) ]
  ]

handleAction :: forall output m. MonadAff m => Action -> H.HalogenM State Action () output m Unit
handleAction = case _ of
  Clear -> H.modify_ \_ -> []
  AddText msg -> H.modify_ \state -> [ msg ] <> state
  Submit event -> do
    H.liftEffect $ Event.preventDefault event
-- Can also do other stuffs other than just stopping refresh page
