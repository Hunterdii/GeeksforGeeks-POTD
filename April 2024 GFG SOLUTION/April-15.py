#User function Template for python3
# User function Template for python3
class Solution:
    def countElements(self, a, b, n, query, q):
        b.sort()
        ans = []
        
        for i in range(q):
            count = self.upperBound(b, a[query[i]])
            ans.append(count)
        
        return ans
    
    def upperBound(self, arr, target):
        low, high = 0, len(arr)
        
        while low < high:
            mid = low + (high - low) // 2
            
            if arr[mid] <= target:
                low = mid + 1
            else:
                high = mid
        
        return low

 # Driver Code Starts
#Initial Template for Python 3

t = int(input())
for _ in range(0, t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    q = int(input())
    query = []
    ob = Solution()
    for i in range(q):
        query.append(int(input()))
    ans = ob.countElements(a, b, n, query, q)
    for i in range(q):
        print(ans[i])

# } Driver Code Ends
