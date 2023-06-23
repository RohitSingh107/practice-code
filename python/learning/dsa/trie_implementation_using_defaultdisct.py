
from collections import defaultdict, deque
from treelib import Tree # UNNECESSARY
import uuid # UNNECESSARY

def trieNode():
    return defaultdict(trieNode) 

def insert(node, word):
    for c in word:
        node = node[c]
    node[None]

def search(node, word) -> bool:
    for c in word:
        if c in node:
            node = node[c]
        else:
            return False
    return None in node

def starts_with(node, prefix) -> bool:
    for c in prefix:
        if c in node:
            node = node[c]
        else:
            return False
    return True

#################################### EXTRA UNNECESSARY THINGS #################################
def show(node):

    # q = deque([node])
    #
    # tree = Tree()
    #
    # r = "root"
    #
    # tree.create_node(tag = 'root', identifier= r)
    # while q:
    #     u = q.popleft()
    #     for v in u.values():
    #         q.append(v)
    #         tree.create_node(tag= k, identifier= v, parent= u)
    # 
    # tree.show()

    # print(node.keys())
    par = str(uuid.uuid1())
    q = deque([(node, par)])
    tree = Tree()
    tree.create_node(tag = 'root', identifier=par)
    # print(q)
    while q:
        n, p = q.popleft()
        for k in n.keys():
            if k is None:
                continue
            id = str(uuid.uuid1())
            tree.create_node(tag= k, identifier= id, parent= p)
            q.append((n[k], id))
    tree.show()





def main():
    trie = trieNode()
    keys = ["the", "a", "there", "answer", "any", "bye", "their"]
    for key in keys:
        insert(trie, key)
    show(trie)


if __name__ == '__main__':
    main()




