#User function Template for python3
class Solution:
    def sortByFreq(self, arr):
        freq_map = {}
        for num in arr:
            freq_map[num] = freq_map.get(num, 0) + 1
        sorted_items = sorted(freq_map.items(), key=lambda x: (-x[1], x[0]))
        result = []
        for num, freq in sorted_items:
            result.extend([num] * freq)

        return result



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

        arr = list(map(int, input().strip().split()))
        l = Solution().sortByFreq(arr)
        print(*l)

# } Driver Code Ends
