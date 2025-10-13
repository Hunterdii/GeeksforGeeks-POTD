'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def getMaxSum(self, root):
        def helper(node):
            if not node: return (0, 0)
            l = helper(node.left)
            r = helper(node.right)
            inc = node.data + l[1] + r[1]
            exc = max(l) + max(r)
            return (inc, exc)
        return max(helper(root))
