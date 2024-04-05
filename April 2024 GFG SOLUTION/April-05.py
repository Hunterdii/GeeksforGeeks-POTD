#User function Template for python3

class Solution:
    def min_operations(self, nums):
        n = len(nums)
        dp = [0] * n
        m = 0        

        for i in range(n):
            dp[i] = max(((dp[j] + 1) for j in range(i) if nums[j] < nums[i] and nums[i] - nums[j] > (i - j - 1)), default=1)
            m = max(m, dp[i])
        return n - m

#{ 

 # Driver Code Starts
#Initial Template for Python 3


if __name__ == '__main__':
    T=int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        ob = Solution();
        ans = ob.min_operations(nums)
        print(ans)

# } Driver Code Ends
