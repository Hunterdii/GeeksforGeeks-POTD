#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends

class Solution:
    def calculateSpan(self, arr):
        span, st = [], []
        
        for i, price in enumerate(arr):
            days = 1
            while st and arr[st[-1]] <= price:
                days += span[st.pop()]
            span.append(days)
            st.append(i)
        
        return span

#{ 
 # Driver Code Starts.
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.calculateSpan(arr)
        print(*ans)
        print("~")
        t -= 1
# } Driver Code Ends
