-- Normal Form


-- data Fiction = Fiction deriving Show
-- data NonFiction = NonFiction deriving Show

-- data BookType = FictionBook Fiction
              -- | NonFictionBook NonFiction
              -- deriving Show

type AuthorName = String

-- data Author = Author (AuthorName, BookType)

data Author = Fiction AuthorName
            | NonFiction AuthorName
            deriving (Eq, Show)

data Expr =
    Number Int
  | Add Expr Expr
  | Minus Expr
  | Mult Expr Expr
  | Divide Expr Expr


-- type Number = Int
-- type Add = (Expr, Expr)
-- type Minus = Expr
-- type Mult = (Expr, Expr)
-- type Divide = (Expr, Expr)
-- 
-- type Expr =
  -- Either Number
    -- (Either Add
      -- (Either Minus
        -- (Either Mult Divide)))

 
