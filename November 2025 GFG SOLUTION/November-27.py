class Solution:
    def subsetXORSum(self, arr):
        orVal = 0
        for x in arr: orVal |= x
        return orVal << (len(arr) - 1)
