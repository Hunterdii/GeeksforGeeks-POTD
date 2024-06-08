class Solution:
    def findExtra(self, n, a, b):
        low, high = 0, n - 1
        while low <= high:
            mid = (low + high) // 2
            if mid < len(b) and a[mid] == b[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return low


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        print(Solution().findExtra(n, a, b))

# } Driver Code Ends
