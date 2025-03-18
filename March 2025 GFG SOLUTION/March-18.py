class Solution:
    def equalPartition(self, arr):
        s = sum(arr)
        if s % 2: return False
        target, dp = s // 2, [False] * (s // 2 + 1)
        dp[0] = True
        for num in arr:
            for j in range(target, num - 1, -1):
                dp[j] |= dp[j - num]
        return dp[target]


#{ 
 # Driver Code Starts
import sys

input = sys.stdin.readline

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        if ob.equalPartition(arr):
            print("true")
        else:
            print("false")
        print("~")

# } Driver Code Ends
