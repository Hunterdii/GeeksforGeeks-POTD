#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends
#User function Template for python3
import math

class Solution:
    def countIntervals(self, x, v):
        ret = 0
        for i in range(len(v) - 1):
            ret += math.ceil((v[i + 1] - v[i]) / x) - 1
        return ret

    def findSmallestMaxDist(self, stations, K):
        stations.sort()
        n = len(stations)
        l = 1e-9
        h = stations[-1] - stations[0]

        while (h - l) > 1e-6:
            mid = l + (h - l) / 2.0
            intervals = self.countIntervals(mid, stations)
            if intervals > K:
                l = mid
            else:
                h = mid
        return h


#{ 
 # Driver Code Starts.
import math
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        stations = list(map(int, input().split()))
        K = int(input())
        ob = Solution()
        print('%.2f' % ob.findSmallestMaxDist(stations, K))
# } Driver Code Ends
