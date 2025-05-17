import heapq
class Solution:
    def findSmallestRange(self, a):
        n, m = len(a), len(a[0])
        hi = max(row[0] for row in a)
        q = [(a[i][0], i, 0) for i in range(n)]
        heapq.heapify(q)
        lo, r = 0, float('inf')
        while True:
            x, i, j = heapq.heappop(q)
            if hi - x < r - lo: lo, r = x, hi
            if j + 1 == m: break
            y = a[i][j + 1]
            heapq.heappush(q, (y, i, j + 1))
            hi = max(hi, y)
        return [lo, r]


#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())
for _ in range(t):
    n = int(input())
    k = int(input())
    arr = []
    for _ in range(k):
        arr.append(list(map(int, input().strip().split())))
    r = Solution().findSmallestRange(arr)
    print(r[0], r[1])
    print("~")

# } Driver Code Ends
