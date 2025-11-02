class Solution:
    def maxEdgesToAdd(self, V, edges):
        return V * (V - 1) // 2 - len(edges)
