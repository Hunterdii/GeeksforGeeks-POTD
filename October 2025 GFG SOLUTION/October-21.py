class Solution:
    def topKFreq(self, arr, k):
        freq = {}
        maxFreq = 0
        for x in arr:
            freq[x] = freq.get(x, 0) + 1
            maxFreq = max(maxFreq, freq[x])
        buckets = [[] for _ in range(maxFreq + 1)]
        for num, f in freq.items():
            buckets[f].append(num)
        res = []
        for i in range(maxFreq, 0, -1):
            buckets[i].sort(reverse=True)
            for x in buckets[i]:
                res.append(x)
                if len(res) == k:
                    return res
        return res

2)
from collections import Counter
class Solution:
    def topKFreq(self, a, k):
        f=Counter(a)
        return [x for x,_ in sorted(f.items(),key=lambda x:(-x[1],-x[0]))[:k]]
