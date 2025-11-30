class Solution:
    def subsetXOR(self, n : int):
        ans, r = [], n & 3
        start = 2 if r == 2 else 1
        end = n - 1 if r == 3 else n
        for i in range(start, end + 1):
            if r != 1 or i != n - 1: ans.append(i)
        return ans
