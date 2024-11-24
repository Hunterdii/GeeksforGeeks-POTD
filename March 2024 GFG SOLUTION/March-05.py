#User function Template for python3

class Solution:
    # Function to find the maximum index difference.
    def maxIndexDiff(self, a, n):
        left_min = [0] * n
        right_max = [0] * n
        
        left_min[0] = a[0]
        for i in range(1, n):
            left_min[i] = min(left_min[i - 1], a[i])
        
        right_max[n - 1] = a[n - 1]
        for i in range(n - 2, -1, -1):
            right_max[i] = max(right_max[i + 1], a[i])
        
        max_diff = 0
        i = j = 0
        while i < n and j < n:
            if left_min[i] <= right_max[j]:
                max_diff = max(max_diff, j - i)
                j += 1
            else:
                i += 1
        
        return max_diff
#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            n=int(input())
            
            arr=[int(x) for x in input().strip().split()]
            ob=Solution()
            print(ob.maxIndexDiff(arr,n))
            
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends
