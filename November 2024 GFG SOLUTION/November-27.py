#User function Template for python3
class Solution:
    def missingNumber(self, arr):
        n = len(arr)
        for i in range(n):
            while arr[i] > 0 and arr[i] <= n and arr[i] != arr[arr[i] - 1]:
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
        for i in range(n):
            if arr[i] != i + 1:
                return i + 1
        return n + 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):
        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.missingNumber(arr))
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
