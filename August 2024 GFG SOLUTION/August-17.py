#User function Template for python3

class Solution:
    def productExceptSelf(self, nums):
        n = len(nums)
        left_product = [1] * n
        result = [1] * n
        for i in range(1, n):
            left_product[i] = left_product[i - 1] * nums[i - 1]
        right_product_acc = 1
        for i in range(n - 1, -1, -1):
            result[i] = left_product[i] * right_product_acc
            right_product_acc *= nums[i]

        return result


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)

# } Driver Code Ends
