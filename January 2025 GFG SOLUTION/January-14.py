# User function Template for python3
class Solution:
    def findEquilibrium(self, arr):
        total, prefix = sum(arr), 0
        for i, val in enumerate(arr):
            total -= val
            if prefix == total:
                return i
            prefix += val
        return -1




#{ 
 # Driver Code Starts
#Initial Template for Python 3
import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]

        ob = Solution()

        print(ob.findEquilibrium(arr))
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
