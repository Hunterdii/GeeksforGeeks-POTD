#User function Template for python3
class Solution:
    def addBinary(self, s1, s2):
        i, j = len(s1) - 1, len(s2) - 1
        carry = 0
        result = []

        while i >= 0 or j >= 0 or carry > 0:
            sum_ = carry
            if i >= 0:
                sum_ += int(s1[i])
                i -= 1
            if j >= 0:
                sum_ += int(s2[j])
                j -= 1
            result.append(str(sum_ % 2))
            carry = sum_ // 2

        result.reverse()
        result_str = ''.join(result)
        first_non_zero = result_str.find('1')
        return result_str[first_non_zero:] if first_non_zero != -1 else "0"
        
        #{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        a = input().strip()
        b = input().strip()
        ob = Solution()
        answer = ob.addBinary(a, b)

        print(answer)
        print("~")

# } Driver Code Ends
