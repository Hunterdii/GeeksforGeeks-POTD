#User function Template for python3
class Solution:
    def productExceptSelf(self, arr):
        product, zero_count = 1, arr.count(0)
        if zero_count > 1:
            return [0] * len(arr)
        for x in arr:
            if x != 0:
                product *= x
        return [product if x == 0 else 0 if zero_count else product // x for x in arr]

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())

    for _ in range(t):

        arr = [int(x) for x in input().split()]

        ans = Solution().productExceptSelf(arr)
        print(*ans)
        print("~")

# } Driver Code Ends
