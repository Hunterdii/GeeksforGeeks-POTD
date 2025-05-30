'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def findMaxFork(self, root, k):
        if not root:
            return -1
        if root.data == k:
            return k
        if root.data < k:
            x = self.findMaxFork(root.right, k)
            return root.data if x == -1 else x
        return self.findMaxFork(root.left, k)

2)
class Solution:
    def findMaxFork(self, root, k):
        res = -1
        while root:
            if root.data == k:
                return k
            if root.data < k:
                res = root.data
                root = root.right
            else:
                root = root.left
        return res
