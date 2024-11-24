#User function Template for python3
class Solution:
    def removeDups(self, str):
        fre = [0] * 26 
        result = [] 
        
        for c in str:
            if fre[ord(c) - ord('a')] == 0:
                result.append(c) 
                fre[ord(c) - ord('a')] = 1 
        
        return ''.join(result)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.removeDups(s)

        print(answer)

# } Driver Code Ends
