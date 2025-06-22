class Solution:
    def largestSubset(self, arr):
        n = len(arr)
        arr.sort(reverse=True)
        dp = [1] * n
        parent = [-1] * n
        max_idx = 0
        for i in range(1, n):
            for j in range(i):
                if arr[j] % arr[i] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    parent[i] = j
            if dp[i] > dp[max_idx]:
                max_idx = i
        result = []
        i = max_idx
        while i != -1:
            result.append(arr[i])
            i = parent[i]
        return result
