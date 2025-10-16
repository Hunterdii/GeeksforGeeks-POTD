'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def removekeys(self, root, l, r):
        if not root: return None
        root.left = self.removekeys(root.left, l, r)
        root.right = self.removekeys(root.right, l, r)
        if root.data < l: return root.right
        if root.data > r: return root.left
        return root
