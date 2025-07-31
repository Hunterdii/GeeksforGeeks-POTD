from collections import defaultdict

class Solution:
    def powerfulInteger(self, intervals, k):
        events = defaultdict(int)
        for start, end in intervals:
            events[start] += 1
            events[end + 1] -= 1
        
        count, result = 0, -1
        for pos in sorted(events.keys()):
            if events[pos] > 0:
                count += events[pos]
                if count >= k:
                    result = pos
            else:
                if count >= k:
                    result = pos - 1
                count += events[pos]
        return result
