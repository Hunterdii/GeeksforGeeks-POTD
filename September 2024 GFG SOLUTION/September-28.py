#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
class Solution:
    def minimizeCost(self, k, arr):
        n = len(arr)
        dp = [-1] * n
        dp[0] = 0
        
        for i in range(1, n):
            min_v = float('inf')
            for j in range(1, k+1):
                if i - j >= 0:
                    curr = dp[i - j] + abs(arr[i] - arr[i - j])
                    min_v = min(curr, min_v)
            dp[i] = min_v
            
        return dp[n - 1]

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        k= int(input())
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.minimizeCost(k,arr)
        print(res)
        t -= 1


# } Driver Code Ends
