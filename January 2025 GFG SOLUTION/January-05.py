#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


# } Driver Code Ends
#User function Template for python3
class Solution:
    def countPairs(self, arr, target):
        arr.sort()
        l, r, ans = 0, len(arr) - 1, 0
        while l < r:
            if arr[l] + arr[r] < target: ans += (r - l); l += 1
            else: r -= 1
        return ans
#{ 
 # Driver Code Starts.

def main():
    T = int(input())
    while (T > 0):

        A = [int(x) for x in input().strip().split()]

        k = int(input())
        ob = Solution()
        print(ob.countPairs(A, k))
        print('~')
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
