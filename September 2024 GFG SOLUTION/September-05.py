#User function Template for python3
class Solution:
    def missingNumber(self, n, arr):
        xor_total = 0
        for i in range(1, n + 1):
            xor_total ^= i
        xor_array = 0
        for num in arr:
            xor_array ^= num
        return xor_total ^ xor_array


#{ 
 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    arr = list(map(int, input().split()))
    s = Solution().missingNumber(n, arr)
    print(s)

# } Driver Code Ends
