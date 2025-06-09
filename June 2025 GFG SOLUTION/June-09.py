class Solution:
    def dfs(self, root, l, r):
        if not root: return False
        if not root.left and not root.right and l == r: return True
        return self.dfs(root.left, l, root.data - 1) or self.dfs(root.right, root.data + 1, r)

    def isDeadEnd(self, root):
        return self.dfs(root, 1, float('inf'))
