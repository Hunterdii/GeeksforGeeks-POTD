class Solution:
    def nthRowOfPascalTriangle(self, n):
        row, v = [], 1
        for i in range(n):
            row.append(v)
            v = v * (n-1-i) // (i+1)
        return row


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':

    tc = int(input())
    while tc > 0:
        n = int(input())
        ob = Solution()
        ans = ob.nthRowOfPascalTriangle(n)
        for x in ans:
            print(x, end=" ")
        print()
        tc = tc - 1
        print("~")
# } Driver Code Ends
