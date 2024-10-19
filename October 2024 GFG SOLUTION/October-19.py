#User function Template for python3
class Solution:
    def roundToNearest(self, num_str: str) -> str:
        n = len(num_str)
        if n == 0:
            return num_str  

        last_digit = int(num_str[-1])  

        if last_digit <= 5:
            return num_str[:-1] + '0'  
        else:
            num_str = num_str[:-1] + '0'  
            i = n - 2

            while i >= 0:
                if num_str[i] != '9':
                    return num_str[:i] + chr(ord(num_str[i]) + 1) + num_str[i + 1:]  
                num_str = num_str[:i] + '0' + num_str[i + 1:]  
                i -= 1

            return '1' + num_str  
            
#{ 
 # Driver Code Starts
#Initial Template for Python 3
for _ in range(0, int(input())):
    num_str = input()
    ob = Solution()
    res = ob.roundToNearest(num_str)
    print(res)

# } Driver Code Ends
