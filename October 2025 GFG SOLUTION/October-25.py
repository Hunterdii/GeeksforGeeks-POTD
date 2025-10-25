class Solution:
    def minOperations(self, arr):
        import heapq
        s = sum(arr)
        t = s / 2
        h = [-x for x in arr]
        heapq.heapify(h)
        ops = 0
        while s > t:
            x = -heapq.heappop(h)
            s -= x / 2
            heapq.heappush(h, -x / 2)
            ops += 1
        return ops
