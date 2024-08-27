class Solution:
    def findMaxDiff(self, arr):
        n = len(arr)
        s = []
        maxDiff = 0
        l = [0] * n
        r = [0] * n
        for i in range(n):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            l[i] = 0 if not s else arr[s[-1]]
            s.append(i)
        s.clear()
        for i in range(n - 1, -1, -1):
            while s and arr[s[-1]] >= arr[i]:
                s.pop()
            r[i] = 0 if not s else arr[s[-1]]
            s.append(i)
        for i in range(n):
            maxDiff = max(maxDiff, abs(l[i] - r[i]))

        return maxDiff
#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        print(ob.findMaxDiff(arr))

# } Driver Code Ends
