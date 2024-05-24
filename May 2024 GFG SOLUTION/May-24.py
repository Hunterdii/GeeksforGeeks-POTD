
from typing import List

class Solution:
    MOD = 1000000007

    def findWays(self, num: List[int], tar: int) -> int:
        dp = [0] * (tar + 1)
        dp[0] = 2 if num[0] == 0 else 1

        if num[0] != 0 and num[0] <= tar:
            dp[num[0]] = 1

        for ind in range(1, len(num)):
            for target in range(tar, num[ind] - 1, -1):
                dp[target] = (dp[target] + dp[target - num[ind]]) % self.MOD
        
        return dp[tar]

    def countPartitions(self, n: int, d: int, arr: List[int]) -> int:
        total_sum = sum(arr)
        if total_sum < d or (total_sum - d) % 2 != 0:
            return 0
        return self.findWays(arr, (total_sum - d) // 2)

#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        n = int(input())
        
        
        d = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.countPartitions(n, d, arr)
        
        print(res)
        

# } Driver Code Ends
