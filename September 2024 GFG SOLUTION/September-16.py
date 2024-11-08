# User function Template for Python3
class Solution:
    def maxLength(self, s):
        left, right, maxi = 0, 0, 0
        for char in s:
            if char == '(':
                left += 1
            else:
                right += 1
            
            if left == right:
                maxi = max(maxi, 2 * right)
            elif right > left:
                left = right = 0
        left = right = 0 
        for char in reversed(s):
            if char == '(':
                left += 1
            else:
                right += 1
            
            if left == right:
                maxi = max(maxi, 2 * left)
            elif left > right:
                left = right = 0

        return maxi

#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.maxLength(S))

# } Driver Code Ends
