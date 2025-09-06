'''
class Node:
    def __init__(self, data): 
        self.data = data
        self.next = None
'''

class Solution:
    def lengthOfLoop(self, head):
        s = f = head
        while f and f.next:
            s = s.next
            f = f.next.next
            if s == f:
                length = 0
                while True:
                    f = f.next
                    length += 1
                    if s == f:
                        break
                return length
        return 0


2)
class Solution:
    def lengthOfLoop(self, head):
        s, f = head, head
        while f and f.next:
            s, f = s.next, f.next.next
            if s == f:
                cnt = 1
                while s.next != f:
                    s, cnt = s.next, cnt + 1
                return cnt
        return 0
