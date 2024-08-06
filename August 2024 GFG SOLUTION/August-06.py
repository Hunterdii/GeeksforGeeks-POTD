#User function Template for python3
class Solution:
    def isValid(self, str):
        n = len(str)
        segments = 0
        num = 0
        length = 0

        for i in range(n):
            if str[i] == '.':
                if length == 0 or length > 3 or num > 255:
                    return False
                segments += 1
                num = 0
                length = 0
            elif str[i].isdigit():
                if length == 0 and str[i] == '0' and (i + 1 < n and str[i + 1] != '.'):
                    return False
                num = num * 10 + int(str[i])
                length += 1
            else:
                return False

        if length == 0 or length > 3 or num > 255:
            return False
        segments += 1

        return segments == 4




#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends
