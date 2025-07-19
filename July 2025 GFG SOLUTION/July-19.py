from math import prod, factorial
from collections import Counter
class Solution:
    def vowelCount(self, s):
        freq = Counter(c for c in s if c in 'aeiou')
        vals = list(freq.values())
        return prod(vals) * factorial(len(vals)) if vals else 0
