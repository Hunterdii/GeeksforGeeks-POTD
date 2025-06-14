'''
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None
'''
class Solution:
    def isSymmetric(self, root):
        if not root:
            return True
        s1, s2 = [root.left], [root.right]
        while s1 and s2:
            a, b = s1.pop(), s2.pop()
            if not a and not b:
                continue
            if not a or not b or a.data != b.data:
                return False
            s1.extend([a.left, a.right])
            s2.extend([b.right, b.left])
        return not s1 and not s2

2)
class Solution:
    def isSym(self,a,b):
        if not a or not b: return a is b
        if a.data!=b.data: return False
        return self.isSym(a.left,b.right) and self.isSym(a.right,b.left)
    def isSymmetric(self, root):
        return root is None or self.isSym(root.left,root.right)
