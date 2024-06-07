#User function Template for python3
class Solution:
    def maxOccured(self, n, l, r, maxx):
        a = [0] * (maxx + 2)
        for i in range(n):
            a[l[i]] += 1
            if r[i] + 1 <= maxx:
                a[r[i] + 1] -= 1
        
        maxCount = a[0]
        result = 0
        for i in range(1, maxx + 1):
            a[i] += a[i - 1]
            if a[i] > maxCount:
                maxCount = a[i]
                result = i
        
        return result

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

A = [0] * 1000000


def main():

    T = int(input())

    while (T > 0):

        global A
        A = [0] * 1000000

        n = int(input())

        l = [int(x) for x in input().strip().split()]
        r = [int(x) for x in input().strip().split()]

        maxx = max(r)
        ob = Solution()
        print(ob.maxOccured(n, l, r, maxx))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
