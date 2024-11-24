#User function Template for python3

class Solution:
    def countMin(self, str):
        n = len(str)
        table = [[0] * n for _ in range(n)]
        
        for gap in range(1, n):
            for l in range(n - gap):
                h = l + gap
                if str[l] == str[h]:
                    table[l][h] = table[l + 1][h - 1]
                else:
                    table[l][h] = min(table[l][h - 1], table[l + 1][h]) + 1
        
        return table[0][n - 1]
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    t = int(input())

    for _ in range(t):
        Str = input()

        solObj = Solution()

        print(solObj.countMin(Str))

# } Driver Code Ends
