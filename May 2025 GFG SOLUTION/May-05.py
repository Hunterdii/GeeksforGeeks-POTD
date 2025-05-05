#{ 
 # Driver Code Starts

# } Driver Code Ends

class Solution:
    def findTarget(self, arr, target):
        for i in range(len(arr)):
            if arr[i] == target: return i
        return -1


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())  # Number of test cases

    for _ in range(t):
        arr = list(map(int, input().strip().split()))  # Read the array
        target = int(input().strip())  # Read the target

        sln = Solution()
        ans = sln.findTarget(arr, target)
        print(ans)
        print("~")
# } Driver Code Ends
