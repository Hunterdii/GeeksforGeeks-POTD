class Solution:
    def maxArea(self, mat):
        n, m, res = len(mat), len(mat[0]), 0
        h = [0] * m
        for i in range(n):
            for j in range(m):
                h[j] = h[j] + 1 if mat[i][j] else 0
            st = []
            for j in range(m + 1):
                cur = 0 if j == m else h[j]
                while st and h[st[-1]] > cur:
                    tp = st.pop()
                    w = j if not st else j - st[-1] - 1
                    res = max(res, h[tp] * w)
                st.append(j)
        return res
