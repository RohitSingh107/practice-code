-- Chapter Exercise

-- Unfolds

myIterate :: (a -> a) -> a -> [a]
myIterate f x = x : myIterate f (f x) 

myUnfoldr :: (b -> Maybe (a, b)) -> b -> [a]
myUnfoldr f x = case f x of
                  Just (a, b) -> a : myUnfoldr f b
                  Nothing -> []

betterIterate :: (a -> a) -> a -> [a]
betterIterate f = myUnfoldr (\b -> Just (b, f b))


-- Binary Tree Unfolding

data BinaryTree a = Leaf
                  | Node (BinaryTree a) a (BinaryTree a)
                  deriving (Eq, Ord, Show)

unfold :: (a -> Maybe (a,b,a)) -> a -> BinaryTree b
unfold f a = 
    case f a of
        Nothing -> Leaf
        Just (ln, r, rn) -> Node (unfold f ln) r (unfold f rn)


treeBuild :: Integer -> BinaryTree Integer
treeBuild n = unfold (f n) 0
  where f :: Integer -> Integer -> Maybe (Integer, Integer, Integer)
        f n i 
          | n > i = Just (i + 1, i, i + 1)
          | otherwise = Nothing
    



