'''
class Node:

    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def findMedian(self, root):
        n, c = 0, root
        while c:
            if not c.left:
                n += 1
                c = c.right
            else:
                p = c.left
                while p.right and p.right != c:
                    p = p.right
                if not p.right:
                    p.right = c
                    c = c.left
                else:
                    p.right = None
                    n += 1
                    c = c.right
        k, med, c = (n + 1) // 2, -1, root
        while c:
            if not c.left:
                med += 1
                if med == k - 1:
                    return c.data
                c = c.right
            else:
                p = c.left
                while p.right and p.right != c:
                    p = p.right
                if not p.right:
                    p.right = c
                    c = c.left
                else:
                    p.right = None
                    med += 1
                    if med == k - 1:
                        return c.data
                    c = c.right
        return -1
