#User function Template for python3

class Solution:
    def pairAndSum(self, n, arr):
        ans = 0
        for i in range(32):
            count = 0
            for j in range(n):
                count += (arr[j] >> i) & 1
            ans += ((count * (count - 1)) // 2) * (1 << i)
        return ans


 # Driver Code Starts
#Initial Template for Python 3

if __name__=='__main__':
    t=int(input())
    for _ in range(t):
        N=int(input())
        Arr=list(map(int,input().strip().split(' ')))
        ob=Solution()
        print(ob.pairAndSum(N,Arr))
# } Driver Code Ends
