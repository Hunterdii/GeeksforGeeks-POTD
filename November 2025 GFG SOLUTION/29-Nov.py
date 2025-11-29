class Solution:
    def countSetBits(self, n):
        def countBits(n):
            count = 0
            i = 0
            while (1 << i) <= n:
                total_pairs = n + 1
                complete_cycles = total_pairs // (1 << (i + 1))
                count += complete_cycles * (1 << i)
                remainder = total_pairs % (1 << (i + 1))
                count += max(0, remainder - (1 << i))
                i += 1
            return count

        return countBits(n)
