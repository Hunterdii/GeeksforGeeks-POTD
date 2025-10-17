'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def transformTree(self, root):
        self.s = 0
        def f(n):
            if not n: return
            f(n.right)
            temp = n.data
            n.data = self.s
            self.s += temp
            f(n.left)
        f(root)
