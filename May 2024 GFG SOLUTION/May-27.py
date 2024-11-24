
from typing import List

class Solution:
    def longestSubseq(self, n : int, a : List[int]) -> int:
        dp = {}
        ans = 0

        for x in a:
            len1 = dp.get(x - 1, 0) + 1
            len2 = dp.get(x + 1, 0) + 1
            dp[x] = max(dp.get(x, 0), len1, len2)
            ans = max(ans, dp[x])

        return ans



#{ 
 # Driver Code Starts
class IntArray:

    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  #array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n = int(input())

        a = IntArray().Input(n)

        obj = Solution()
        res = obj.longestSubseq(n, a)

        print(res)

# } Driver Code Ends
