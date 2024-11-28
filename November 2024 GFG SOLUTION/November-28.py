#User function template for Python
class Solution:
    def myAtoi(self, s: str) -> int:
        idx, sign, res = 0, 1, 0

        while idx < len(s) and s[idx] == ' ':
            idx += 1

        if idx < len(s) and (s[idx] == '-' or s[idx] == '+'):
            sign = -1 if s[idx] == '-' else 1
            idx += 1

        while idx < len(s) and '0' <= s[idx] <= '9':
            res = res * 10 + (ord(s[idx]) - ord('0'))
            idx += 1

            if res * sign > 2**31 - 1:
                return 2**31 - 1
            if res * sign < -2**31:
                return -2**31

        return sign * res


#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = input()
        ob = Solution()
        print(ob.myAtoi(s))
        print("~")

# } Driver Code Ends
