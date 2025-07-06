class Solution:
    def topKSumPairs(self, a, b, k):
        n = len(a)
        a.sort()
        b.sort()
        pq = [(-(a[-1] + b[-1]), n - 1, n - 1)]
        vis = {(n - 1, n - 1)}
        res = []
        while len(res) < k:
            s, i, j = heapq.heappop(pq)
            res.append(-s)
            if i > 0 and (i - 1, j) not in vis:
                vis.add((i - 1, j))
                heapq.heappush(pq, (-(a[i - 1] + b[j]), i - 1, j))
            if j > 0 and (i, j - 1) not in vis:
                vis.add((i, j - 1))
                heapq.heappush(pq, (-(a[i] + b[j - 1]), i, j - 1))
        return res
