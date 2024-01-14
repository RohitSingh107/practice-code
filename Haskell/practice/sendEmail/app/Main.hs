{-# LANGUAGE OverloadedStrings #-}
import Network.HaskellNet.SMTP (authenticate, sendMail, closeSMTP)
import Network.HaskellNet.Auth (UserName, Password, AuthType (LOGIN))
import Network.Mail.Mime (Address, simpleMail', simpleMail, Mail (Mail, mailFrom, mailTo, mailCc, mailBcc, mailHeaders, mailParts), htmlPart, plainPart, addAttachments)
import System.Exit (die)
import Network.HaskellNet.SMTP.SSL (doSMTPSSL, doSMTPSTARTTLS, Settings (Settings, sslPort, sslMaxLineLength, sslLogToConsole, sslDisableCertificateValidation), doSMTPSSLWithSettings, connectSMTPSSL)
import Data.Text (Text)
import qualified Data.Text.Internal.Lazy as LT
import Configuration.Dotenv (loadFile, defaultConfig)
import System.Environment (getEnv)

-- | Your settings
server :: String
server       = "smtp.gmail.com"

username :: UserName
username     = "rohitsingh.mait@gmail.com"


authType :: AuthType
authType     = LOGIN

from :: Address
from         = "rohitsingh.mait@gmail.com"

to :: Address
to           = "RohitSinghEmail@protonmail.com"

subject :: Text
subject      = "Network.HaskellNet.SMTP Test :)"

plainBody :: LT.Text
plainBody    = "This is plain body"

htmlBody :: LT.Text
htmlBody     = "<html><head></head><body><h1>Hello <i>world, This is html body!</i></h1></body></html>"

attachments :: [(Text, FilePath)]
attachments = [("application/pdf", "./attachments/Resume-P.pdf"), ("text/plain", "./app/Main.hs"), ("image/jpeg", "./attachments/0042.jpg")] -- https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types/Common_types

mySettings :: Settings
mySettings = Settings {
    sslPort = 465 -- 465 for ssl, 587 for tls for gmail
  , sslMaxLineLength = 10000
  , sslLogToConsole = True
  , sslDisableCertificateValidation = False
} 


withSMTPSSL :: IO ()
withSMTPSSL = doSMTPSSL server $ \conn -> do
   putStrLn "Sending Email"

   password <- getEnv "PASS"

   authSucceed <- authenticate authType username password conn -- (2)

   putStrLn $ "authSucceess : " <> show authSucceed

   if authSucceed
   then do
     let mail = simpleMail'
           to
           from
           subject
           plainBody
     sendMail mail conn -- (3)
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."



withSMTPSTARTTLS :: IO ()
withSMTPSTARTTLS = doSMTPSTARTTLS server $ \conn -> do
   putStrLn "Sending Email"

   password <- getEnv "PASS"
   authSucceed <- authenticate authType username password conn -- (2)

   putStrLn $ "authSucceess : " <> show authSucceed

   if authSucceed
   then do
     let mail = simpleMail'
           to
           from
           subject
           plainBody
     sendMail mail conn -- (3)
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."


withSMTPSSLWithSettings :: IO ()
withSMTPSSLWithSettings = doSMTPSSLWithSettings server mySettings $ \conn -> do
   putStrLn "Sending Email"
   password <- getEnv "PASS"
  
   -- putStrLn $ "password : " <> password

   authSucceed <- authenticate authType username password conn

   putStrLn $ "authSucceess : " <> show authSucceed

   if authSucceed
   then do
     let mail = simpleMail'
           to
           from
           subject
           plainBody
     sendMail mail conn -- (3)
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."




htmlBodyEmail :: IO ()
htmlBodyEmail = doSMTPSSL server $ \conn -> do
   putStrLn "Sending Email"
   password <- getEnv "PASS"

   authSucceed <- authenticate authType username password conn

   putStrLn $ "authSucceess : " <> show authSucceed

   if authSucceed
   then do
     mail <- simpleMail
           to
           from
           subject
           plainBody
           htmlBody
           []
     sendMail mail conn 
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."


attachmentsEmail :: IO ()
attachmentsEmail = doSMTPSSL server $ \conn -> do
   putStrLn "Sending Email"
   password <- getEnv "PASS"

   authSucceed <- authenticate authType username password conn

   putStrLn $ "authSucceess : " <> show authSucceed

   if authSucceed
   then do
     mail <- simpleMail
           to
           from
           subject
           plainBody
           htmlBody
           attachments
     sendMail mail conn 
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."



customExample :: IO ()
customExample = do

  password <- getEnv "PASS"
  let newMail = Mail {
      mailFrom = from
    , mailTo = [to]
    , mailCc = []
    , mailBcc = []
    , mailHeaders = [("Subject", subject)]
    , mailParts = [[htmlPart htmlBody, plainPart plainBody]]
  } 
  newMail' <- addAttachments attachments newMail
  conn <- connectSMTPSSL server
  authSucceed <- authenticate authType username password conn
  putStrLn $ "Sucess :" <> show authSucceed


  if authSucceed
   then do
     sendMail newMail' conn
     putStrLn "Email sent successfully :)"
   else die "Authentication failed."

  closeSMTP conn

main :: IO ()
main = do
  loadFile defaultConfig
  withSMTPSSLWithSettings
