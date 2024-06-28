#User function Template for python3
class Solution:
    def is_palindrome(self, arr):
        n = len(arr)
        for i in range(n // 2):
            if arr[i] != arr[n - 1 - i]:
                return False
        return True

    def pattern(self, arr):
        n = len(arr)

        for i in range(n):
            if self.is_palindrome(arr[i]):
                return "{} R".format(i)

        for j in range(n):
            col = [arr[i][j] for i in range(n)]
            if self.is_palindrome(col):
                return "{} C".format(j)

        return "-1"
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    ob = Solution()
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        a = list()
        c = 0
        for i in range(0, n):
            X = list()
            for j in range(0, n):
                X.append(arr[c])
                c += 1
            a.append(X)
        ans = ob.pattern(a)
        print(ans)

# } Driver Code Ends
