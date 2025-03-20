class Solution:
    def maxProfit(self, a):
        b1, s1, b2, s2 = float('inf'), 0, float('inf'), 0
        for p in a:
            b1, s1, b2, s2 = min(b1, p), max(s1, p - b1), min(b2, p - s1), max(s2, p - b2)
        return s2

#{ 
 # Driver Code Starts
#Initial template for Python 3
import math


def main():
    t = int(input())
    while (t > 0):

        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.maxProfit(arr))
        t -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
