class Solution:
    def reverseQueue(self, q):
        s = []
        while q:
            s.append(q.popleft())
        while s:
            q.append(s.pop())
