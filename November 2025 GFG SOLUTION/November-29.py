class Solution:
    def countSetBits(self, n):
        ans = 0
        while n:
            x = n.bit_length() - 1
            if x == 0:
                ans += 1
                break
            ans += x * (1 << (x - 1)) + (n - (1 << x) + 1)
            n -= 1 << x
        return ans
