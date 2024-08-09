#User function Template for python3

class Solution:
    def Maximize(self, arr): 
        mod = 10**9 + 7
        arr.sort()  # Sort the array
        ans = 0
        n = len(arr)

        for i in range(n):
            ans = (ans + arr[i] * i) % mod

        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        A = list(map(int, input().strip().split()))
        # k = int(input())
        ob = Solution()
        print(ob.Maximize(A))

# } Driver Code Ends
