#User function template for Python 3

class Solution:
    def majorityElement(self, a):
        count = cand = 0
        for v in a:
            if not count:
                cand = v
            count += 1 if v == cand else -1
        return cand if sum(1 for v in a if v == cand) > len(a)//2 else -1
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math
from sys import stdin


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]

        obj = Solution()
        print(obj.majorityElement(arr))
        print("~")
        t -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
