class Solution:
    def rearrange(self, arr, x):
        arr.sort(key=lambda val: abs(val - x))
