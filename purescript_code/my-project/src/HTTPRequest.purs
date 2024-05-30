module HTTPRequest (component) where

import Prelude

import Affjax.ResponseFormat as AXRF
import Affjax.Web as AX
import Data.Either (hush)
import Data.Maybe (Maybe(..))
import Effect.Aff.Class (class MonadAff)
import Effect.Console (log)
import Halogen as H
import Halogen.HTML as HH
import Halogen.HTML.Events as HE
import Halogen.HTML.Properties as HP
import Web.Event.Event (Event)
import Web.Event.Event as Event

type State =
  { loading :: Boolean
  , username :: String
  , result :: Maybe String
  }

data Action = SetUsername String | MakeRequest Event

initialState :: forall i. i -> State
initialState _ =
  { loading: false
  , username: ""
  , result: Nothing
  }

render :: forall m. State -> H.ComponentHTML Action () m
render s = HH.div_
  [ HH.form [ HE.onSubmit \ev -> MakeRequest ev ]
      [ HH.h1_ [ HH.text "Lookup github username" ]
      , HH.label_ [ HH.text "Enter username", HH.input [ HP.value s.username, HE.onValueInput \str -> SetUsername str ] ]
      , HH.button [ HP.disabled s.loading, HP.type_ HP.ButtonSubmit ] [ HH.text "Fetch Info" ]
      , HH.p_ [ HH.text $ if s.loading then "Working..." else "" ]
      , HH.div_
          case s.result of
            Nothing -> []
            Just res ->
              [ HH.h2_ [ HH.text "Response" ]
              , HH.pre_ [ HH.code_ [ HH.text res ] ]
              ]

      ]
  ]

handleAction :: forall output m. MonadAff m => Action -> H.HalogenM State Action () output m Unit
handleAction = case _ of
  SetUsername username -> do
    H.modify_ _ { username = username, result = Nothing }

  MakeRequest event -> do
    H.liftEffect $ Event.preventDefault event

    H.liftEffect $ log "Fetch Button is clicked"

    H.modify_ _ { loading = true }
    username <- H.gets _.username

    response <- H.liftAff $ AX.get AXRF.string $ "https://api.github.com/users/" <> username
    H.modify_ _ { loading = false, result = map _.body (hush response) }

component :: forall query input output m. MonadAff m => H.Component query input output m
component = H.mkComponent
  { initialState
  , render
  , eval: H.mkEval H.defaultEval { handleAction = handleAction }
  }
