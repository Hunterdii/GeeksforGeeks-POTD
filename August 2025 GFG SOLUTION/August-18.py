class Solution:
    def hIndex(self, citations):
        n = len(citations)
        bucket = [0] * (n + 1)
        
        for c in citations:
            bucket[min(c, n)] += 1
        
        count = 0
        for i in range(n, -1, -1):
            count += bucket[i]
            if count >= i:
                return i
        return 0
