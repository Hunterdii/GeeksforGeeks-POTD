class Solution:
    def singleNum(self, arr):
        x = 0
        for n in arr: x ^= n
        a = b = 0
        for n in arr:
            (a, b) = (a ^ n, b) if n & (x & -x) else (a, b ^ n)
        return [a, b] if a < b else [b, a]


#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))

        ob = Solution()
        ans = ob.singleNum(arr)

        print(" ".join(map(str, ans)))
        tc -= 1
        print("~")

# } Driver Code Ends
