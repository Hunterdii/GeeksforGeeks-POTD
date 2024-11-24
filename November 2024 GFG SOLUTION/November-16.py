#User function Template for python3
class Solution:
    def pushZerosToEnd(self, arr):
        n = len(arr)
        nonZeroIndex = 0

        for i in range(n):
            if arr[i] != 0:
                arr[nonZeroIndex], arr[i] = arr[i], arr[nonZeroIndex]
                nonZeroIndex += 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ob.pushZerosToEnd(arr)
        for x in arr:
            print(x, end=" ")
        print()
        tc -= 1
# } Driver Code Ends
