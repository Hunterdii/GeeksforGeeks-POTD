#User function Template for python3

class Solution:
    def findMaxSum(self, N, M, Mat):
        if N < 3 or M < 3:
            return -1

        ans = float('-inf')

        for i in range(N - 2):
            for j in range(M - 2):
                sum = Mat[i][j] + Mat[i][j + 1] + Mat[i][j + 2] + \
                      Mat[i + 1][j + 1] + \
                      Mat[i + 2][j] + Mat[i + 2][j + 1] + Mat[i + 2][j + 2]

                ans = max(ans, sum)

        return ans


 # Driver Code Starts
#Initial Template for Python 3

import math
      
if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N,M=map(int,input().strip().split(" "))
        Mat=[]
        for i in range(N):
            B=list(map(int,input().strip().split(" ")))
            Mat.append(B)
        ob=Solution()
        ans=ob.findMaxSum(N,M,Mat)
        print(ans) 
# } Driver Code Ends
