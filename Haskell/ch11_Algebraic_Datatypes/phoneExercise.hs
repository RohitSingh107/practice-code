-- Phone Exercise 

import Data.List
import Data.Char

type Digit = Char 

type Presses = Int 

data Button = Button Digit [Char]

newtype DaPhone = Daphone [Button]

phone :: DaPhone
phone = Daphone [one, two, three, four, five, six, seven, eight, nine, star, zero, hash]
  where 
      one = Button '1' "1"
      two = Button '2' "abc2"
      three = Button '3' "def3"
      four = Button '4' "ghi4"
      five = Button '5' "jkl5"
      six = Button '6' "mno6"
      seven = Button '7' "pqrs7"
      eight = Button '8' "tuv8"
      nine = Button '9' "wxyz9"
      star = Button '*' "^"
      zero = Button '0' "+ 0"
      hash = Button '#' ".,#"


convo :: [String]
convo =
  ["Wanna play 20 questions",
  "Ya",
  "U 1st haha",
  "Lol ok. Have u ever tasted alcohol",
  "Lol ya",
  "Wow ur cool haha. Ur turn",
  "Ok. Do u think I am pretty Lol",
  "Lol ya",
  "Just making sure rofl ur turn"]

reverseTaps :: DaPhone -> Char -> [(Digit, Presses)]
reverseTaps (Daphone buttons) c = 
    if isUpper c
        then ('*', 1) : taps buttons (toLower c)
    else taps buttons c
    where 
        taps bs c = [buttonTaps (button bs c) c]
        buttonTaps (Button d cs) c = (d, maybe (error "boom") succ $ c `elemIndex` cs)
        button bs c = head $ dropWhile (not . include c) $ bs
        include c (Button _ cs) = c `elem` cs

cellPhonesDead :: DaPhone -> String -> [(Digit, Presses)]
cellPhonesDead _ [] = []
cellPhonesDead p (c:cs) = reverseTaps p c ++ cellPhonesDead p cs

fingerTaps :: [(Digit, Presses)] -> Presses
fingerTaps = sum . map snd

mostPopular :: Ord a => [a] -> a
mostPopular = head . last . sortOn length . group .sort

mostPopularLetter :: String -> Char
mostPopularLetter = mostPopular

cost :: DaPhone -> Char -> Presses
cost p = fingerTaps . reverseTaps p

coolestWord :: [String] -> String 
coolestWord = mostPopular . foldMap words