class Solution:
    def canAttend(self, arr):
        arr.sort()
        for i in range(1, len(arr)):
            if arr[i - 1][1] > arr[i][0]: return False
        return True
