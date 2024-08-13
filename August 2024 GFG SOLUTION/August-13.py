#User function Template for python3


#Complete this function
class Solution:
    def floorSqrt(self, n): 
        if n == 0 or n == 1:
            return n

        start, end, ans = 1, n, 0
        while start <= end:
            mid = start + (end - start) // 2
            square = mid * mid

            if square == n:
                return mid
            if square < n:
                ans = mid
                start = mid + 1
            else:
                end = mid - 1

        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):

        x = int(input())

        print(Solution().floorSqrt(x))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends