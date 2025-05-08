class Solution:
    def findMissing(self, a):
        n = len(a)
        d1 = a[1] - a[0]; d2 = a[-1] - a[-2]; d3 = (a[-1] - a[0]) // n
        d = d1 if (d1==d2 or d1==d3) else d2
        if d == 0: return a[0]
        lo, hi = 0, n-1
        while lo <= hi:
            mid = (lo + hi) // 2
            if (a[mid]-a[0])//d == mid: lo = mid + 1
            else: hi = mid - 1
        return a[0] + lo * d



#{ 
 # Driver Code Starts
#Initial Template for Python 3
import sys
import math


def main():
    input = sys.stdin.read
    data = input().strip().split('\n')

    t = int(data[0])
    solution = Solution()

    for i in range(1, t + 1):
        arr = list(map(int, data[i].split()))
        print(solution.findMissing(arr))
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
