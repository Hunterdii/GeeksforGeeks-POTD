
from typing import List

class Solution:
    def maxSquare(self, n: int, m: int, mat: List[List[int]]) -> int:
        dp = [0] * m
        maxsize = 0
        prev = 0

        for i in range(n):
            for j in range(m):
                temp = dp[j]
                if i == 0 or j == 0:
                    dp[j] = mat[i][j]
                elif mat[i][j] == 1:
                    dp[j] = min(dp[j], dp[j - 1], prev) + 1
                else:
                    dp[j] = 0
                maxsize = max(maxsize, dp[j])
                prev = temp

        return maxsize



#{ 
 # Driver Code Starts
class IntMatrix:

    def __init__(self) -> None:
        pass

    def Input(self, n, m):
        matrix = []
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix

    def Print(self, arr):
        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):

        n, m = map(int, input().split())

        mat = IntMatrix().Input(n, m)

        obj = Solution()
        res = obj.maxSquare(n, m, mat)

        print(res)

# } Driver Code Ends
