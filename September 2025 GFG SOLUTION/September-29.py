class Solution:
    def maxSubarrSum(self, arr, a, b):
        n, res = len(arr), float('-inf')
        pre = [0] * (n + 1)
        for i in range(n): pre[i + 1] = pre[i] + arr[i]
        dq = []
        for i in range(a, n + 1):
            l, r = max(0, i - b), i - a
            while dq and pre[dq[-1]] >= pre[r]: dq.pop()
            dq.append(r)
            while dq and dq[0] < l: dq.pop(0)
            res = max(res, pre[i] - pre[dq[0]])
        return res
