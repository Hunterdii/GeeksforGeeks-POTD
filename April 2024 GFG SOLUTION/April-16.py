
from typing import List

class Solution:
    def minimizeDifference(self, n: int, k: int, arr: List[int]) -> int:
      
        
        post_max = [0] * n
        post_min = [0] * n

        post_min[-1] = arr[-1]
        post_max[-1] = arr[-1]
        for i in range(n - 2, -1, -1):
            post_max[i] = max(arr[i], post_max[i + 1])
            post_min[i] = min(arr[i], post_min[i + 1])
            
        min_diff = post_max[k] - post_min[k]
        p_min = arr[0]
        p_max = arr[0]

        for i in range(1, n - k):
            curr_min = max(p_max, post_max[i + k]) - min(p_min, post_min[i + k])
            min_diff = min(min_diff, curr_min)
            p_max = max(arr[i], p_max)
            p_min = min(arr[i], p_min)
        
        min_diff = min(min_diff, p_max - p_min)

        return min_diff






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
        res = obj.minimizeDifference(n, k, arr)
        
        print(res)
        

# } Driver Code Ends
