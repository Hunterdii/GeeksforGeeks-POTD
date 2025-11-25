class Solution:
    def subarrayXor(self, arr):
        xor_sum = 0
        n = len(arr)
        for i in range(n):
            if ((i + 1) * (n - i)) & 1: xor_sum ^= arr[i]
        return xor_sum
