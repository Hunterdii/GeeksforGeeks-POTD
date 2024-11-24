#User function Template for python3

class Solution:
    def armstrongNumber(self, n):
        original = n
        sum = 0
        while n > 0:
            digit = n % 10
            sum += digit ** 3
            n //= 10
        return "true" if sum == original else "false"



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        n = input()
        n=int(n)
        ob = Solution()
        print(ob.armstrongNumber(n))
# } Driver Code Ends
