class Solution:
    def asciirange(self, s):
        result = []
        positions = {}
        
        for i, char in enumerate(s):
            if char not in positions:
                positions[char] = [i, i]
            else:
                positions[char][1] = i
        
        for char in sorted(positions.keys()):
            first, last = positions[char]
            if last > first:
                total = sum(ord(s[j]) for j in range(first + 1, last))
                if total:
                    result.append(total)
        
        return result
