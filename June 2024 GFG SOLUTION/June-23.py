#User function Template for python3
class Solution:
    def bracketNumbers(self, str):
        op = 0
        result = []
        stack = []

        for c in str:
            if c == '(':
                op += 1
                stack.append(op)
                result.append(op)
            elif c == ')':
                result.append(stack.pop())

        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        S = input()
        ob = Solution()
        answer = ob.bracketNumbers(S)
        for value in answer:
            print(value, end=" ")
        print()

# } Driver Code Ends
