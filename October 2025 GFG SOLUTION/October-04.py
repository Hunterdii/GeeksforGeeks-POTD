class Solution:
    def findExpr(self, s, target):
        res = []
        def dfs(i, val, prev, path):
            if i == len(s):
                if val == target: res.append(path)
                return
            for j in range(i, len(s)):
                if j > i and s[i] == '0': break
                cur = int(s[i:j+1])
                if i == 0: dfs(j + 1, cur, cur, str(cur))
                else:
                    dfs(j + 1, val + cur, cur, path + '+' + str(cur))
                    dfs(j + 1, val - cur, -cur, path + '-' + str(cur))
                    dfs(j + 1, val - prev + prev * cur, prev * cur, path + '*' + str(cur))
        dfs(0, 0, 0, '')
        return res
