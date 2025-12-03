class Solution:
    def tsp(self, cost):
        n = len(cost)
        ALL = (1 << n) - 1

        # dp[mask][u] = min cost to start at 0, visit set 'mask', and end at city u
        dp = [[float('inf')] * n for _ in range(1 << n)]
        dp[1][0] = 0  # only city 0 visited, at city 0

        for mask in range(1 << n):
            for u in range(n):
                if dp[mask][u] == float('inf'):
                    continue
                if not (mask & (1 << u)):
                    continue
                # try to go to an unvisited city v
                nxt_mask_base = mask
                for v in range(n):
                    if mask & (1 << v):  # already visited
                        continue
                    new_mask = nxt_mask_base | (1 << v)
                    cand = dp[mask][u] + cost[u][v]
                    if cand < dp[new_mask][v]:
                        dp[new_mask][v] = cand

        # complete the tour: return to city 0
        ans = float('inf')
        for u in range(n):
            ans = min(ans, dp[ALL][u] + cost[u][0])
        return ans
