'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def kthSmallest(self, root, k): 
        s, n, c = [], root, 0
        while n or s:
            while n:
                s.append(n)
                n = n.left
            n = s.pop()
            c += 1
            if c == k: return n.data
            n = n.right
        return -1
