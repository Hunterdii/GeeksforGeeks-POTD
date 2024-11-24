#User function Template for python3
class Solution:
    def rowWithMax1s(self, arr):
        n = len(arr)        
        m = len(arr[0])       
        max_row_index = -1    
        
        r = 0   
        c = m - 1 
        
        while r < n and c >= 0:
            if arr[r][c] == 1:
                max_row_index = r 
                c -= 1            
            else:
                r += 1            
        
        return max_row_index

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, m = list(map(int, input().strip().split()))

        inputLine = list(map(int, input().strip().split()))
        arr = [[0 for j in range(m)] for i in range(n)]

        for i in range(n):
            for j in range(m):
                arr[i][j] = inputLine[i * m + j]
        ob = Solution()
        ans = ob.rowWithMax1s(arr)
        print(ans)
        tc -= 1

# } Driver Code Ends
