class Solution:
    def getLastMoment(self, n, left, right):
        return max([0] + left + [n - x for x in right])

2)
class Solution:
    def getLastMoment(self, n, left, right):
        max_left_time = max(left or [0])
        max_right_time = n - min(right or [n])
        return max(max_left_time, max_right_time)

3)
class Solution:
    def getLastMoment(self, n, left, right):
        ans = 0
        for x in left: ans = max(ans, x)
        for x in right: ans = max(ans, n - x)
        return ans
