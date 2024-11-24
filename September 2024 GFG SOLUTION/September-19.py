# User function Template for python3

class Solution:
    def reverseWords(self, str):
        result = []
        n = len(str)
        end = n - 1

        for i in range(n - 1, -1, -1):
            if str[i] == '.':
                result.append(str[i+1:end+1])
                result.append('.')
                end = i - 1
        result.append(str[:end+1])

        return ''.join(result)


#{ 
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        s = str(input())
        obj = Solution()
        print(obj.reverseWords(s))

# } Driver Code Ends
