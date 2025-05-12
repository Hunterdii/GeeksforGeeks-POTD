#{ 
 # Driver Code Starts
#Initial Template for Python 3
import heapq


# } Driver Code Ends

class Solution:
    def mostBooked(self, n, A):
        A.sort()
        free = list(range(n))
        heapq.heapify(free)
        used = []
        cnt = [0] * n
        for s, e in A:
            while used and used[0][0] <= s:
                _, i = heapq.heappop(used)
                heapq.heappush(free, i)
            if not free:
                t, i = heapq.heappop(used)
                heapq.heappush(used, (t + e - s, i))
                cnt[i] += 1
            else:
                i = heapq.heappop(free)
                heapq.heappush(used, (e, i))
                cnt[i] += 1
        return cnt.index(max(cnt))



#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    import sys
    input = sys.stdin.read().split()
    it = iter(input)
    t = int(next(it))
    while t > 0:
        t -= 1
        n = int(next(it))
        m = int(next(it))
        meetings = []
        for _ in range(m):
            s = int(next(it))
            e = int(next(it))
            meetings.append([s, e])
        sol = Solution()
        res = sol.mostBooked(n, meetings)
        print(res)
        print("~")
# } Driver Code Ends
