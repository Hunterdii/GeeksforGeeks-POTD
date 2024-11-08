#User function Template for python3
import heapq

class Solution:
    def max_of_subarrays(self, k, arr):
        res = []
        maxHeap = []  

        for i in range(len(arr)):
            heapq.heappush(maxHeap, (-arr[i], i))
            while maxHeap[0][1] <= i - k:
                heapq.heappop(maxHeap)
            if i >= k - 1:
                res.append(-maxHeap[0][0])

        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys
from collections import deque

#Contributed by : Nagendra Jha

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        res = ob.max_of_subarrays(k, arr)
        for i in range(len(res)):
            print(res[i], end=" ")
        print()

# } Driver Code Ends
