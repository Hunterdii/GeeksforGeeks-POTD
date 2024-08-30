#User function Template for python3

class Solution:
    def __init__(self):
        self.result = []
        self.row = [0] * 10
    
    def place(self, r, c):
        for prev in range(c):
            if self.row[prev] == r or abs(self.row[prev] - r) == abs(prev - c):
                return False
        return True

    def bt(self, c, n):
        if c == n:
            self.result.append([self.row[i] + 1 for i in range(n)])
            return
        for i in range(n):
            if self.place(i, c):
                self.row[c] = i
                self.bt(c + 1, n)

    def nQueen(self, n):
        self.result = []
        self.bt(0, n)
        return self.result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        
        ob = Solution()
        ans = ob.nQueen(n)
        if(len(ans) == 0):
            print("-1")
        else:
            for i in range(len(ans)):
                print("[",end="")
                for j in range(len(ans[i])):
                    print(ans[i][j],end = " ")
                print("]",end = " ")
            print()
                
# } Driver Code Ends
