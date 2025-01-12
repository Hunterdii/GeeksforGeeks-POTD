
class Solution:
    def maxWater(self, arr):
        l, r, res, lMax, rMax = 0, len(arr) - 1, 0, 0, 0
        while l < r:
            if arr[l] < arr[r]: res += max(0, lMax - arr[l]); lMax = max(lMax, arr[l]); l += 1
            else: res += max(0, rMax - arr[r]); rMax = max(rMax, arr[r]); r -= 1
        return res
#{ 
 # Driver Code Starts
#Initial template for Python 3

import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxWater(arr))

        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
