"""
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None
"""

class Solution:
    def reverse(self, head):
        if not head or not head.next: return head
        curr = head
        while curr:
            curr.next, curr.prev = curr.prev, curr.next
            if not curr.prev: return curr
            curr = curr.prev
        return head
