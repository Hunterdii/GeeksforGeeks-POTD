'''
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    def getKClosest(self, root, target, k):
        in_order, stack, curr = [], [], root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            in_order.append(curr.data)
            curr = curr.right
        n, l, r, pos = len(in_order), 0, len(in_order) - 1, 0
        while l <= r:
            m = (l + r) // 2
            if in_order[m] <= target:
                pos, l = m, m + 1
            else:
                r = m - 1
        res, l, r = [], pos, pos + 1
        while k:
            if r >= n or (l >= 0 and abs(in_order[l] - target) <= abs(in_order[r] - target)):
                res.append(in_order[l])
                l -= 1
            else:
                res.append(in_order[r])
                r += 1
            k -= 1
        return res
