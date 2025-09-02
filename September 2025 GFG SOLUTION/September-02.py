'''
class Node:
    def __init__(self, x):
        self.data = x
        self.next = None
'''

class Solution:
    def swapKth(self, head, k):
        if not head: return head
        n, t = 0, head
        while t: n, t = n + 1, t.next
        if k > n or 2 * k - 1 == n: return head
        
        x, y, px, py = head, head, None, None
        for _ in range(k - 1): px, x = x, x.next
        for _ in range(n - k): py, y = y, y.next
        
        if px: px.next = y
        else: head = y
        if py: py.next = x  
        else: head = x
        
        x.next, y.next = y.next, x.next
        return head
