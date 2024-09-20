#User function Template for python3
class Solution:
    def countBuildings(self, height):
        count = 0
        max_height = float('-inf')

        for h in height:
            if h > max_height:
                count += 1
                max_height = h 
        
        return count


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input().strip())
    for _ in range(t):
        height = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countBuildings(height)
        print(ans)

# } Driver Code Ends
