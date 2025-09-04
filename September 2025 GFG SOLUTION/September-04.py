"""
class Node:
    def __init__(self, data):
		self.data = data
		self.next = None
"""

class Solution:
    def reverseKGroup(self, head, k):
        cur, cnt = head, 0
        while cur and cnt < k:
            cur = cur.next; cnt += 1
        if cnt < k:
            prev = None
            while head:
                nxt = head.next; head.next = prev; prev = head; head = nxt
            return prev
        cur = self.reverseKGroup(cur, k)
        while cnt:
            nxt = head.next; head.next = cur; cur = head; head = nxt; cnt -= 1
        return cur
