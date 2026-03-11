class Solution:
    def sumSubMins(self, arr):
        n, mod = len(arr), 10**9 + 7
        res, st = 0, []
        left, right = [-1] * n, [n] * n
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]: st.pop()
            if st: left[i] = st[-1]
            st.append(i)
        st = []
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] > arr[i]: st.pop()
            if st: right[i] = st[-1]
            st.append(i)
        for i in range(n):
            res = (res + arr[i] * (i - left[i]) * (right[i] - i)) % mod
        return res
