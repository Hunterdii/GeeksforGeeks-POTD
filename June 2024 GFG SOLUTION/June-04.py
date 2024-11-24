#User function Template for python3
class Solution:
    def binaryNextNumber(self, s):
        s = s.lstrip('0')
        if not s:
            s = '0'
        n = len(s)
        carry = True
        char_array = list(s)
        for i in range(n - 1, -1, -1):
            if char_array[i] == '0':
                char_array[i] = '1'
                carry = False
                break
            else:
                char_array[i] = '0'
        if carry:
            s = '1' + ''.join(char_array)
        else:
            s = ''.join(char_array)
        
        return s


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        ans = ob.binaryNextNumber(S)
        print(ans)

# } Driver Code Ends