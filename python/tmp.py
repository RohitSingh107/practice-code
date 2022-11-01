def map_trees(trees, func):
    if all(trees):
        return Tree(val=func(*[tree.val for tree in trees]), 
                    left=map_trees([tree.left for tree in trees], func), 
                    right=map_trees([tree.right for tree in trees], func))
    else:
        return None
