class Solution:
    def findUnique(self, arr):
        r = 0
        for x in arr: r ^= x
        return r

#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.findUnique(arr)
        print(ans)
        print("~")
# } Driver Code Ends
