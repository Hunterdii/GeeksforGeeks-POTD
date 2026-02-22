class Solution:
    def subarrayXor(self, arr, k):
        mp = {0: 1}
        xor_sum = cnt = 0
        for x in arr:
            xor_sum ^= x
            cnt += mp.get(xor_sum ^ k, 0)
            mp[xor_sum] = mp.get(xor_sum, 0) + 1
        return cnt
