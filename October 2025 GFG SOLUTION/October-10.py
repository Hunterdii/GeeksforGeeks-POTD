'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def zigZagTraversal(self, root):
        res = []
        if not root: return res
        q = deque([root])
        ltr = True
        while q:
            sz = len(q)
            lvl = [0] * sz
            for i in range(sz):
                node = q.popleft()
                idx = i if ltr else sz - 1 - i
                lvl[idx] = node.data
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            ltr = not ltr
            res.extend(lvl)
        return res
