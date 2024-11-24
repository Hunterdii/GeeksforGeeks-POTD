#{ 
 # Driver Code Starts

# } Driver Code Ends

class Solution:
    def rearrange(self, arr):
        n = len(arr)
        result = [-1] * n  
        for i in range(n):
            if 0 <= arr[i] < n:
                result[arr[i]] = arr[i]
        
        return result

#{ 
 # Driver Code Starts.
def main():
    t = int(input())
    for _ in range(t):
        input_str = input()
        arr = list(map(int, input_str.split()))
        solution = Solution()
        ans = solution.rearrange(arr)
        print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
# } Driver Code Ends
