class Solution:
    # Function to find the maximum number of books
    def max_Books(self, n, k, arr):
        max_sum = 0
        current_sum = 0

        for i in range(n):
            if arr[i] <= k:
                current_sum += arr[i]
                max_sum = max(max_sum, current_sum)
            else:
                current_sum = 0

        return max_sum

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        temp = list(map(int, input().strip().split()))
        n = temp[0]
        k = temp[1]
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.max_Books(n, k, arr))
# Contributed by:Harshit Sidhwa

# } Driver Code Ends
