class Solution:
    def minJumps(self, arr):
        n, jumps, far, end = len(arr), 0, 0, 0
        for i in range(n - 1):
            far = max(far, i + arr[i])
            if i == end:
                jumps += 1
                end = far
            if end >= n - 1:
                return jumps
        return -1
