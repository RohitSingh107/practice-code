-- where Penguns Live

data WherePenguinsLive = 
   Galapagos
 | Antartica
 | Australia
 | SouthAfrica
 | SouthAmerica
 deriving (Eq, Show)

data Penguin = 
  Peng WherePenguinsLive
  deriving (Eq, Show)


isSouthAfrica :: WherePenguinsLive -> Bool
isSouthAfrica SouthAfrica = True
isSouthAfrica _            = False

gimmeWhereTheyLive :: Penguin -> WherePenguinsLive
gimmeWhereTheyLive (Peng whereitlives) = whereitlives


humboldt = Peng SouthAfrica
gentoo = Peng Antartica
macaroni = Peng Antartica
little	= Peng Australia
galapagos = Peng Galapagos

galapagosPenguin :: Penguin -> Bool
galapagosPenguin (Peng Galapagos) = True
galapagosPenguin _                = False

antarcticPenguin :: Penguin -> Bool
antarcticPenguin (Peng Antartica) = True
antarcticPenguin _                = False

antarcticOrGalapagos :: Penguin -> Bool
antarcticOrGalapagos p =
     (galapagosPenguin p)
  || (antarcticPenguin p)
