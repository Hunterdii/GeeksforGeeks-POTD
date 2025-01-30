#User function Template for python3
class Solution:
    def nQueen(self, n):
        if n < 4 and n != 1:
            return []
        res = []
        row = [0] * n

        def solve(c, cols, d1, d2):
            if c == n:
                res.append([r + 1 for r in row])
                return
            for r in range(n):
                pos = 1 << r
                if not (cols & pos or d1 & (pos << c) or d2 & (pos << (n - 1 - c))):
                    row[c] = r
                    solve(c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)))

        solve(0, 0, 0, 0)
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())

        ob = Solution()
        ans = ob.nQueen(n)
        if (len(ans) == 0):
            print("-1")
        else:
            ans.sort()
            for i in range(len(ans)):
                print("[", end="")
                for j in range(len(ans[i])):
                    print(ans[i][j], end=" ")
                print("]", end=" ")
            print()

        print("~")

# } Driver Code Ends
