class Solution:
    def longestCommonSum(self, arr1, arr2):
        n = len(arr1)
        sum1 = sum2 = res = 0
        diff_map = {}
        for i in range(n):
            sum1 += arr1[i]
            sum2 += arr2[i]
            diff = sum1 - sum2
            if diff == 0:
                res = i + 1
            elif diff in diff_map:
                res = max(res, i - diff_map[diff])
            else:
                diff_map[diff] = i
        return res
