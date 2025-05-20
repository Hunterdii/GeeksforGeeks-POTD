class Solution:
    def minTime(self, root, target):
        self.ans = 0
        def dfs(r):
            if not r: return (0, -1)
            l0, l1 = dfs(r.left)
            r0, r1 = dfs(r.right)
            h = max(l0, r0) + 1
            d = -1
            if r.data == target:
                d = 0
                self.ans = max(self.ans, h-1)
            elif l1 >= 0:
                d = l1 + 1
                self.ans = max(self.ans, r0 + d)
            elif r1 >= 0:
                d = r1 + 1
                self.ans = max(self.ans, l0 + d)
            return (h, d)
        dfs(root)
        return self.ans
