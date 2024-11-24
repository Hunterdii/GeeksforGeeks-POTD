#User function Template for python3
class Solution:
    def minSum(self, arr):
        arr.sort()
        num1, num2 = "", ""
        toggle = True

        for num in arr:
            if toggle:
                if not (num == 0 and not num1):
                    num1 += str(num)
            else:
                if not (num == 0 and not num2):
                    num2 += str(num)
            toggle = not toggle

        if not num1:
            num1 = "0"
        if not num2:
            num2 = "0"

        return self.findSum(num1, num2)

    def findSum(self, str1, str2):
        n1, n2 = len(str1), len(str2)
        carry = 0
        result = []

        for i in range(max(n1, n2)):
            digit1 = int(str1[n1 - i - 1]) if i < n1 else 0
            digit2 = int(str2[n2 - i - 1]) if i < n2 else 0
            total = digit1 + digit2 + carry
            result.append(str(total % 10))
            carry = total // 10

        if carry:
            result.append(str(carry))

        return ''.join(result[::-1])


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.minSum(arr)
        print(ans)
        tc -= 1

        print("~")

# } Driver Code Ends
