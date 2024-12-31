 #User function Template for python3
 
class Solution:
    def longestConsecutive(self, arr):
        num_set = set(arr)
        longest = 0

        for num in num_set:
            if num - 1 not in num_set:
                current, count = num, 1
                while current + 1 in num_set:
                    current += 1
                    count += 1
                longest = max(longest, count)

        return longest


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        a = list(map(int, input().strip().split()))
        print(Solution().longestConsecutive(a))
        print("~")
# } Driver Code Ends
