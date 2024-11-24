#User function Template for python3

class Solution:
    def minRow(self, n, m, a):
        res = 1
        min_val = math.inf
        for i in range(n):
            count = 0
            for j in range(m):
                if a[i][j] == 1:
                    count += 1
            minn = min(count, min_val)
            if minn != min_val:
                res = i + 1
                min_val = minn
        return res

 # Driver Code Starts
#Initial Template for Python 3

import math
        
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        A=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            A.append(B)
        ob=Solution()
        print(ob.minRow(N,M,A))
# } Driver Code Ends
