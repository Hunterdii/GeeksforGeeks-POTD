'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None
'''

class Solution:
    def distCandy(self, root):
        self.moves = 0
        def dfs(n):
            if not n: return 0
            bal = n.data - 1 + dfs(n.left) + dfs(n.right)
            self.moves += abs(bal)
            return bal
        dfs(root)
        return self.moves
