'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
'''

class Solution:
    def mergeSort(self, h):
        if not h or not h.next: return h
        s, f = h, h.next
        while f and f.next:
            s, f = s.next, f.next.next
        r = s.next
        s.next = None
        return self.merge(self.mergeSort(h), self.mergeSort(r))
    
    def merge(self, a, b):
        if not a: return b
        if not b: return a
        if a.data <= b.data:
            a.next = self.merge(a.next, b)
            return a
        b.next = self.merge(a, b.next)
        return b
