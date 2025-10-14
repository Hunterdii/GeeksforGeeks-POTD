"""
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
"""

class Solution:
    def nodeSum(self, root, l, r):
        if not root: return 0
        if root.data < l: return self.nodeSum(root.right, l, r)
        if root.data > r: return self.nodeSum(root.left, l, r)
        return root.data + self.nodeSum(root.left, l, r) + self.nodeSum(root.right, l, r)
