class Solution:
    def cntCoprime(self, arr):
        mx = max(arr)
        cnt, div, mu = [0] * (mx + 1), [0] * (mx + 1), [1] * (mx + 1)
        vis = [False] * (mx + 1)
        
        for x in arr:
            cnt[x] += 1
        
        for i in range(2, mx + 1):
            if not vis[i]:
                for j in range(i, mx + 1, i):
                    mu[j] *= -1
                    vis[j] = True
                for j in range(i * i, mx + 1, i * i):
                    mu[j] = 0
        
        for i in range(1, mx + 1):
            for j in range(i, mx + 1, i):
                div[i] += cnt[j]
        
        ans = 0
        for i in range(1, mx + 1):
            if mu[i] and div[i] > 1:
                ans += mu[i] * div[i] * (div[i] - 1) // 2
        
        return ans
