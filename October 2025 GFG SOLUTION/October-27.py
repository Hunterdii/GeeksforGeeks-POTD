class Solution:
    def kSmallestPair(self, arr1, arr2, k):
        res = []
        pq = [(arr1[i] + arr2[0], i, 0) for i in range(min(len(arr1), k))]
        heapq.heapify(pq)
        while k and pq:
            s, i, j = heapq.heappop(pq)
            res.append([arr1[i], arr2[j]])
            if j + 1 < len(arr2): heapq.heappush(pq, (arr1[i] + arr2[j + 1], i, j + 1))
            k -= 1
        return res
