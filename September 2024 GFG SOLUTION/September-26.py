#User function Template for python3
class Solution:
    def maxStep(self, arr):
        c = 0  
        m = 0  
        for i in range(1, len(arr)):
            if arr[i] > arr[i - 1]:
                c += 1  
            else:
                m = max(m, c)  
                c = 0  
        return max(m, c)  


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


def main():
    T = int(input())
    while (T > 0):

        arr = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.maxStep(arr))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
