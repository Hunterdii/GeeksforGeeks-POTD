class Solution:
    def nearlySorted(self, arr, k):
        import heapq
        h = arr[:min(k + 1, len(arr))]
        heapq.heapify(h)
        idx = 0
        for i in range(k + 1, len(arr)):
            arr[idx] = heapq.heappop(h)
            heapq.heappush(h, arr[i])
            idx += 1
        while h:
            arr[idx] = heapq.heappop(h)
            idx += 1
