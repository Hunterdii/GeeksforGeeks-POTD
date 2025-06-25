class Solution:
    def sameFreq(self, s: str) -> bool:
        from collections import Counter
        freq = Counter(s)
        count = Counter(freq.values())
        if len(count) == 1:
            return True
        if len(count) == 2:
            (f1, c1), (f2, c2) = count.items()
            return (f1 == 1 and c1 == 1) or (f2 == 1 and c2 == 1) or \
                   (abs(f1 - f2) == 1 and ((f1 > f2 and c1 == 1) or (f2 > f1 and c2 == 1)))
        return False
