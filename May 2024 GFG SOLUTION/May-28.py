
from typing import List

class Solution:
    def findMinCost(self, index: int, cost: List[int], weight: int, memo: List[List[int]]) -> int:
        if weight == 0:
            return 0
        if index >= len(cost) or index + 1 > weight:
            return float('inf')
        if memo[index][weight] != -1:
            return memo[index][weight]

        includeCurrent = float('inf')
        if cost[index] != -1 and index + 1 <= weight:
            result = self.findMinCost(index, cost, weight - (index + 1), memo)
            if result != float('inf'):
                includeCurrent = cost[index] + result
        
        excludeCurrent = self.findMinCost(index + 1, cost, weight, memo)
        
        memo[index][weight] = min(includeCurrent, excludeCurrent)
        return memo[index][weight]

    def minimumCost(self, n: int, w: int, cost: List[int]) -> int:
        memo = [[-1] * (w + 1) for _ in range(n + 1)]
        result = self.findMinCost(0, cost, w, memo)
        return -1 if result == float('inf') else result
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

        w = int(input())

        cost = IntArray().Input(n)

        obj = Solution()
        res = obj.minimumCost(n, w, cost)

        print(res)

# } Driver Code Ends
