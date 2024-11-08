#User function Template for python3
class Solution:
    def getMinDiff(self, arr, k):
        n = len(arr)
        if n == 1:
            return 0
        arr.sort()
        ans = arr[-1] - arr[0]
        smallest = arr[0] + k
        largest = arr[-1] - k
        for i in range(n - 1):
            minVal = min(smallest, arr[i + 1] - k)
            maxVal = max(largest, arr[i] + k)
            if minVal < 0:
                continue
            ans = min(ans, maxVal - minVal)

        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        k = int(input())
        # n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.getMinDiff(arr, k)
        print(ans)
        tc -= 1

# } Driver Code Ends
