
class Solution:
    def maxWater(self, arr):
        l, r, res = 0, len(arr) - 1, 0
        while l < r:
            res = max(res, (r - l) * (arr[l] if arr[l] < arr[r] else arr[r]))
            l, r = (l + 1, r) if arr[l] < arr[r] else (l, r - 1)
        return res


2)
class Solution:
    def maxWater(self, arr):
        l, r, res = 0, len(arr) - 1, 0
        while l < r:
            res = max(res, (r - l) * min(arr[l], arr[r]))
            if arr[l] < arr[r]:
                l += 1
            else:
                r -= 1
        return res
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
