#User function Template for python3
class Solution:
    def sameOccurrence(self, arr, x, y):
        diffCount = {}  
        diff = 0        
        result = 0

        diffCount[0] = 1

        for i in arr:
            if i == x:
                diff += 1  
            elif i == y:
                diff -= 1  

            result += diffCount.get(diff, 0)

            diffCount[diff] = diffCount.get(diff, 0) + 1

        return result
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        x = int(input().strip())
        y = int(input().strip())
        ob = Solution()
        ans = ob.sameOccurrence(arr, x, y)
        print(ans)
        tc -= 1

# } Driver Code Ends
