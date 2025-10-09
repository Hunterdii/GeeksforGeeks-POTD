'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def postOrder(self, root):
        res = []
        curr = root
        while curr:
            if not curr.right:
                res.append(curr.data)
                curr = curr.left
            else:
                pred = curr.right
                while pred.left and pred.left != curr:
                    pred = pred.left
                if not pred.left:
                    res.append(curr.data)
                    pred.left = curr
                    curr = curr.right
                else:
                    pred.left = None
                    curr = curr.left
        res.reverse()
        return res
