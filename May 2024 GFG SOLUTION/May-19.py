
from typing import List

class Solution:
    def findClosest(self, n: int, k: int, arr: List[int]) -> int:
        from bisect import bisect_left
        r = bisect_left(arr, k)
        l = r - 1
        if l < 0:
            return arr[r]
        else:
            diff1 = abs(k - arr[r]) if r < n else float('inf')
            diff2 = abs(k - arr[l])
            if diff1 <= diff2:
                return arr[r]
            return arr[l]


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
        
        
        k = int(input())
        
        
        arr=IntArray().Input(n)
        
        obj = Solution()
        res = obj.findClosest(n, k, arr)
        
        print(res)
        

# } Driver Code Ends
