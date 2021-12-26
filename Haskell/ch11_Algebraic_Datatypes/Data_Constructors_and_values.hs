-- Data Constructors and values

data PugType = PugData

data HuskyType a = HuskyData

data DogueDeBordeaux doge = DogueDeBordeaux doge

myPug = PugData :: PugType

myHusky :: HuskyType a
myHusky = HuskyData

myOtherHusky :: Num a => HuskyType a
myOtherHusky = HuskyData

myOtherOtherHusky :: HuskyType [[[[Int]]]]
myOtherOtherHusky = HuskyData

myDoge :: DogueDeBordeaux Int
myDoge = DogueDeBordeaux 10

data Doggies a = Husky a | Mastiff a deriving (Eq, Show)


data Price = Price Integer deriving (Eq, Show)

data Size = Size String deriving (Eq, Show)

data Manufacturer =
                   Mini
                 | Mazda
                 | Tata
                 deriving (Eq, Show)

data Airline = PapuAir | CatapultsR'Us deriving (Eq, Show)

data Vehicle = Car Manufacturer Price | Plane Airline Size deriving (Eq, Show)



myCar :: Vehicle
myCar = Car Mini (Price 14000)
urCar :: Vehicle
urCar = Car Mazda (Price 20000)
clownCar :: Vehicle
clownCar = Car Tata (Price 7000)

doge :: Vehicle
doge = Plane PapuAir (Size "Jumbo")
clownPlane :: Vehicle
clownPlane = Plane CatapultsR'Us (Size "Small")

isCar :: Vehicle -> Bool 
isCar a = case a of
                (Car _ _) -> True 
                _ ->  False

isPlane :: Vehicle -> Bool 
isPlane (Plane _ _) = True 
isPlane _ = False

areCars :: [Vehicle] -> [Bool]
areCars = map isCar

getManu :: Vehicle -> Manufacturer
getManu (Car x _) = x