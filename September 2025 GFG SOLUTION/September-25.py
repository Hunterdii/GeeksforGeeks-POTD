class Solution:
    def generateBinary(self, n):
        return [bin(i)[2:] for i in range(1, n + 1)]
