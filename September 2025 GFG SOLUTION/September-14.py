class Solution:
    def startStation(self, gas, cost):
        total = curr = start = 0
        for i in range(len(gas)):
            diff = gas[i] - cost[i]
            total += diff
            curr += diff
            if curr < 0: start, curr = i + 1, 0
        return start if total >= 0 else -1
