#User function Template for python3

class Solution:
    def maxSum(self, arr):

        arr.sort()

        totalSum = 0
        n = len(arr)

        for i in range(n // 2):
            totalSum += abs(arr[n - i - 1] - arr[i])
            totalSum += abs(arr[i] - arr[n - i - 1])

        return totalSum

#{ 
 # Driver Code Starts
#Initial Template for Python 3


def main():
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        ob = Solution()
        ans = ob.maxSum(arr)  # Call maxSum method and store result in ans
        print(ans)  # Print the result
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
