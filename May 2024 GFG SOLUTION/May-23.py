#User function Template for python3

class Solution:
    def kPalindrome(self, str, n, k):
        prev = [0] * (n + 1)
        curr = [0] * (n + 1)
        
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if str[i - 1] == str[n - j]:
                    curr[j] = prev[j - 1] + 1
                else:
                    curr[j] = max(prev[j], curr[j - 1])
            prev, curr = curr, prev
        
        lps = prev[n]
        minDeletions = n - lps
        return 1 if minDeletions <= k else 0

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        arr = input().split()
        n = int(arr[0])
        k = int(arr[1])
        str = input()

        ob = Solution()
        print(ob.kPalindrome(str, n, k))

# } Driver Code Ends
