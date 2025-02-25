#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends


class Solution:
    def getMaxArea(self, arr):
        stack, n, res = [], len(arr), 0
        for i in range(n + 1):
            while stack and (i == n or arr[stack[-1]] >= arr[i]):
                h = arr[stack.pop()]
                w = i if not stack else i - stack[-1] - 1
                res = max(res, h * w)
            stack.append(i)
        return res

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.getMaxArea(arr)
        print(res)
        print("~")
        t -= 1


# } Driver Code Ends
