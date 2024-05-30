module RandomNumber (component) where

import Prelude

import Data.Maybe (Maybe(..), maybe)
import Effect.Aff.Class (class MonadAff)
import Effect.Random (random)
import Halogen as H
import Halogen.HTML as HH
import Halogen.HTML.Events as HE

type State = Maybe Number
data Action = Regenerate

component :: forall query input output m. MonadAff m => H.Component query input output m
component = H.mkComponent
  { initialState
  , render
  , eval: H.mkEval H.defaultEval { handleAction = handleAction }
  }

initialState :: forall i. i -> State
initialState _ = Nothing

render :: forall m. State -> H.ComponentHTML Action () m
render s = HH.div_
  [ HH.h1_ [ HH.text "Random Number Generator" ]
  , HH.p_ [ HH.text ("Current Value: " <> value) ]
  , HH.button [ HE.onClick \_ -> Regenerate ] [ HH.text "Regenerate" ]
  ]
  where
  value = maybe "No Number Generated" show s

handleAction :: forall output m. MonadAff m => Action -> H.HalogenM State Action () output m Unit
handleAction = case _ of
  Regenerate -> do
    n <- H.liftEffect random
    H.modify_ \_ -> Just n
