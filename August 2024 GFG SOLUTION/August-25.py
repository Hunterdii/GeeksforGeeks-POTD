#User function Template for python3

class Solution:
    def countPairs(self, arr, brr):
        N = len(brr)
        NoOfY = [0] * 5
        
        for y in brr:
            if y < 5:
                NoOfY[y] += 1
        
        brr.sort()
        total_pairs = 0
        
        for x in arr:
            if x == 0:
                continue
            if x == 1:
                total_pairs += NoOfY[0]
                continue
            
            idx = self.upper_bound(brr, x)
            count = N - idx
            count += (NoOfY[0] + NoOfY[1])
            
            if x == 2:
                count -= (NoOfY[3] + NoOfY[4])
            if x == 3:
                count += NoOfY[2]
            
            total_pairs += count
        
        return total_pairs
    
    def upper_bound(self, arr, x):
        lo, hi = 0, len(arr)
        while lo < hi:
            mid = (lo + hi) // 2
            if arr[mid] <= x:
                lo = mid + 1
            else:
                hi = mid
        return lo

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Initial Template for Python 3

import atexit
import io
import sys
import bisect

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        # M, N = map(int, input().strip().split())
        a = list(map(int, input().strip().split()))
        b = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.countPairs(a, b))
        #code here

# } Driver Code Ends
