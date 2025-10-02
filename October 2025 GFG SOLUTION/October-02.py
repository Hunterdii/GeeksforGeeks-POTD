class Solution:
    def combinationSum(self, n, k):
        if n < k or n > 9 * k: return []
        res = []
        def bt(start, rem, left, cur):
            if left == 0:
                if rem == 0: res.append(cur[:])
                return
            for i in range(start, 10):
                if rem < i: break
                cur.append(i)
                bt(i + 1, rem - i, left - 1, cur)
                cur.pop()
        bt(1, n, k, [])
        return res
