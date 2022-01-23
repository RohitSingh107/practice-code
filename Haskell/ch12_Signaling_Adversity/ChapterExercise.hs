-- Chapter Exercise

-- String processing

notThe :: String -> Maybe String
notThe xs = if xs == "The" || xs == "the" then Nothing else Just xs  



replaceThe :: String -> String
replaceThe = unwords . go . words
 where go [] = []
       go (w:ws) = theToA (notThe w) : go ws
                      where 
                            theToA Nothing = "a"
                            theToA (Just x) = x

beginWithVowel :: String -> Bool
beginWithVowel [] = False
beginWithVowel (w:_) = if w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' then True else False

-- countTheBeforeVowel :: String -> Integer
-- countTheBeforeVowel xs = go $ words xs
--   where go (w:ws:wss) = case notThe w of
--                           Nothing -> if 
                           
