'''
class Node:
    def __init__(self, val):
        self.data = val
        self.right = None
        self.left = None

'''

class Solution:
    def constructTree(self, pre, post):
        self.idx = 0
        return self.build(pre, post, 0, len(post) - 1)
    
    def build(self, pre, post, l, r):
        root = Node(pre[self.idx])
        self.idx += 1
        if l != r and self.idx < len(pre):
            pos = post.index(pre[self.idx], l, r + 1)
            root.left = self.build(pre, post, l, pos)
            root.right = self.build(pre, post, pos + 1, r - 1)
        return root
