class Solution:
    MOD = 10**9 + 7

    def power(self, x, y):
        res = 1
        while y:
            if y & 1:
                res = res * x % self.MOD
            x = x * x % self.MOD
            y >>= 1
        return res

    def nCr(self, n: int, r: int) -> int:
        if r > n:
            return 0
        fact = [1] * (n+1)
        for i in range(1, n+1):
            fact[i] = fact[i-1] * i % self.MOD
        inv = [1] * (n+1)
        inv[n] = self.power(fact[n], self.MOD-2)
        for i in range(n, 0, -1):
            inv[i-1] = inv[i] * i % self.MOD
        return fact[n] * inv[r] % self.MOD * inv[n-r] % self.MOD

#{ 
 # Driver Code Starts
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        r = int(input())
        ob = Solution()
        print(ob.nCr(n, r))
        print("~")
# } Driver Code Ends
