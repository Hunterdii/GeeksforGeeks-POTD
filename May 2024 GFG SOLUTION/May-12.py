#User function Template for python3


class Solution:
    def minSteps(self, d):
        if d == 0:
            return 0
        
        sum_val = 0
        move = 1
        while sum_val < d or (sum_val - d) % 2 != 0:
            sum_val += move
            move += 1
        
        return move - 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        d = int(input())

        ob = Solution()
        print(ob.minSteps(d))

# } Driver Code Ends
