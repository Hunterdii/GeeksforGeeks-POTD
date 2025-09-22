class Solution:
    def maxOfMins(self, a):
        n = len(a)
        ans, mx, st = [], [0] * (n + 1), []
        
        for i in range(n + 1):
            while st and (i == n or a[st[-1]] >= a[i]):
                mid = st.pop()
                w = i - (st[-1] if st else -1) - 1
                mx[w] = max(mx[w], a[mid])
            st.append(i)
        
        ans = mx[1:n+1]
        for i in range(n - 2, -1, -1):
            ans[i] = max(ans[i], ans[i + 1])
        return ans
