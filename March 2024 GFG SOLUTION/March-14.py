# User function Template for python3
class Solution:
    def largestSubsquare(self, n, a):
        v1 = [[0 for _ in range(n)] for _ in range(n)]
        v2 = [[0 for _ in range(n)] for _ in range(n)]

        # col
        for i in range(n):
            sum_val = 0
            for j in range(n - 1, -1, -1):
                if a[i][j] == 'O':
                    sum_val = 0
                    v1[i][j] = 0
                else:
                    sum_val += 1
                    v1[i][j] = sum_val

        # rows
        maxi = 10002
        for j in range(n):
            sum_val = 0
            for i in range(n - 1, -1, -1):
                if a[i][j] == 'O':
                    sum_val = 0
                else:
                    sum_val += 1
                    v2[i][j] = sum_val

        # finding max submatrix
        ans = 0
        for i in range(n):
            for j in range(n):
                if a[i][j] == 'O':
                    continue

                size = min(v1[i][j], v2[i][j])

                while size > ans:
                    if v1[i + size - 1][j] >= size and v2[i][j + size - 1] >= size:
                        ans = size

                    size -= 1
        return ans
 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        n=int(input())
        a=[]
        for i in range(n):
            s=list(map(str,input().strip().split()))
            a.append(s)
        ob=Solution()
        print(ob.largestSubsquare(n,a))
# } Driver Code Ends
