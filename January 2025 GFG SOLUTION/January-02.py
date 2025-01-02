#User function Template for python3
class Solution:
    def countSubarrays(self, arr, k):
        prefix_sum_count = {0: 1}
        sum_, count = 0, 0

        for num in arr:
            sum_ += num
            count += prefix_sum_count.get(sum_ - k, 0)
            prefix_sum_count[sum_] = prefix_sum_count.get(sum_, 0) + 1

        return count
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
        res = ob.countSubarrays(arr, k)
        print(res)
        print("~")

# } Driver Code Ends
