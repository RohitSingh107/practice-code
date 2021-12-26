-- Algerbaic DataTypes (Product)

data QuantumBool = QuantumTrue
                 | QuantumFalse
                 | QuantumBoth
                 deriving (Eq, Show)

data TwoQs = MkTwoQs QuantumBool QuantumBool deriving (Eq, Show)

type TwoQs' = (QuantumBool, QuantumBool)

-- Record Syntax

-- data Person = MkPerson String Int deriving (Eq, Show)

-- sample data
-- jm = MkPerson "julie" 108
-- ca = MkPerson "chris" 16

-- name' :: Person -> String
-- name' (MkPerson s _) = s

data Person = 
  Person { name :: String
         , age :: Int}
         deriving (Eq, Show)
