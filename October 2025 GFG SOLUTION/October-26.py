import heapq

class Solution:
    def minCost(self, arr):
        heapq.heapify(arr)
        res = 0
        while len(arr) > 1:
            sum_val = heapq.heappop(arr) + heapq.heappop(arr)
            res += sum_val
            heapq.heappush(arr, sum_val)
        return res
