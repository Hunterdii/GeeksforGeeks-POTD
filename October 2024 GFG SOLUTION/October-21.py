#User function Template for python3
class Solution:
    def power(self, x, y, p):
        result = 1
        x = x % p
        while y > 0:
            if y & 1:
                result = (result * x) % p
            y >>= 1
            x = (x * x) % p
        return result

    def countgroup(self, arr): 
        mod = 1000000007
        n = len(arr)
        xs = 0
        for num in arr:
            xs ^= num
        if xs == 0:
            return (self.power(2, n - 1, mod) - 1 + mod) % mod
        return 0



#{ 
 # Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    while t > 0:
        arr = list(map(int, input().split()))
        ob = Solution()
        res = ob.countgroup(arr)
        print(res)
        t -= 1

# } Driver Code Ends
