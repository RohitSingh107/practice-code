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


countTheBeforeVowel :: String -> Integer
countTheBeforeVowel xs = go (words xs) 0
  where go (w:ws:wss) c = case notThe w of
                            Nothing -> if beginWithVowel ws then go (ws:wss) (c+1) else go (ws:wss) c
                            Just _ -> go (ws:wss) c
        go _ c = c


isVowel :: Char -> Bool 
isVowel w =  w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u'                      

countVowels :: String -> Integer
countVowels text = go text 0
  where go (x:xs) c
           | isVowel x = go xs (c+1)
           | otherwise = go xs c
        go [] c = c

countVowels' :: String -> Integer
countVowels' = fromIntegral . length . filter isVowel