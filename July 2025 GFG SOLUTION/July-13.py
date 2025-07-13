import bisect
class Solution:
    def nonLisMaxSum(self, arr):
        dp, s = [], []
        total = sum(arr)
        for x in arr:
            i = bisect.bisect_left(dp, x)
            if i == len(dp):
                dp.append(x)
                s.append((s[-1] if s else 0) + x)
            else:
                dp[i] = x
                s[i] = (s[i-1] if i else 0) + x
        return total - s[-1]

