class Solution:
    def minSoldiers(self, arr, k):
        import heapq
        need, costs = (len(arr) + 1) // 2, []
        for x in arr: heapq.heappush(costs, 0 if x % k == 0 else k - x % k)
        return sum(heapq.heappop(costs) for _ in range(need))
