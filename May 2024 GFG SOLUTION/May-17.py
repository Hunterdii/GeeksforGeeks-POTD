
from typing import List

class Solution:
    def findPair(self, n: int, x: int, arr: List[int]) -> int:
        seen = set()
        
        for i in range(n):
            if (arr[i] - x) in seen or (arr[i] + x) in seen:
                return 1
            seen.add(arr[i])
        
        return -1
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

        x = int(input())

        arr = IntArray().Input(n)

        obj = Solution()
        res = obj.findPair(n, x, arr)

        print(res)

# } Driver Code Ends
