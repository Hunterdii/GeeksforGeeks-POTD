#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3
# User function Template for python3

class Solution:
    def isAdditiveSequence(self, n):
        size = len(n)
        
        for j in range(min(10, size - 2)):
            prev1 = int(n[:j + 1])
            
            for k in range(j + 1, min(10, size - 1)):
                prev2 = int(n[j + 1:k + 1])
                
                f = 0
                i = k + 1
                while i < size:
                    sum_ = prev1 + prev2
                    sum_size = len(str(sum_))
                    if i + sum_size - 1 >= size:
                        f = 1
                        break
                    num = int(n[i:i + sum_size])
                    if num != sum_:
                        f = 1
                        break
                    prev1, prev2 = prev2, num
                    i += sum_size
                
                if not f:
                    return 1
        
        return 0

# Driver Code Starts.

if _name_ == "_main_":
    sol = Solution()
    t = int(input())
    for _ in range(t):
        s = input()
        print(sol.isAdditiveSequence(s))

# Driver Code Ends

# return 1 in case of True and 0 in case of False
