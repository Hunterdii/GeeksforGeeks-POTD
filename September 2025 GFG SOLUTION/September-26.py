class Solution:    
    def rotateDeque(self, dq, type, k):
        n = len(dq)
        if n == 0 or k % n == 0: return
        k %= n
        
        if type == 1:
            for _ in range(k):
                dq.appendleft(dq.pop())
        else:
            for _ in range(k):
                dq.append(dq.popleft())
