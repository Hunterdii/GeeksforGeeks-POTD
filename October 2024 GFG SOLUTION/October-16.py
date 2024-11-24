class Solution:
    def checkSorted(self, arr):
        n = len(arr)
        swapCnt = 0

        for i in range(n):
            if arr[i] == i + 1:
                continue
            while arr[i] != i + 1:
                arr[arr[i] - 1], arr[i] = arr[i], arr[arr[i] - 1]
                swapCnt += 1

        return swapCnt == 2 or swapCnt == 0


#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input().strip())

    for _ in range(t):
        arr = list(map(int, input().split()))

        sol = Solution()
        result = sol.checkSorted(arr)
        if result:
            print("true")
        else:
            print("false")

# } Driver Code Ends
