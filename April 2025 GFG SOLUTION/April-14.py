#{ 
 # Driver Code Starts
#Initial Template for Python 3
import sys


# } Driver Code Ends

class Solution:
    @staticmethod
    def findOrder(words):
        from collections import deque, defaultdict
        g = defaultdict(list)
        in_deg = [0] * 26
        seen = [0] * 26
        for w in words:
            for c in w:
                seen[ord(c) - 97] = 1
        for i in range(len(words) - 1):
            a, b = words[i], words[i + 1]
            j, n = 0, min(len(a), len(b))
            while j < n and a[j] == b[j]: j += 1
            if j == n and len(a) > len(b): return ""
            if j < n:
                u, v = ord(a[j]) - 97, ord(b[j]) - 97
                g[u].append(v)
                in_deg[v] += 1
        q = deque(i for i in range(26) if seen[i] and in_deg[i] == 0)
        res = []
        while q:
            u = q.popleft()
            res.append(chr(u + 97))
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0: q.append(v)
        return "".join(res) if sum(seen) == len(res) else ""

#{ 
 # Driver Code Starts.

def validate(original, order):
    char_map = {}
    for word in original:
        for ch in word:
            char_map[ch] = 1

    for ch in order:
        if ch not in char_map:
            return False
        del char_map[ch]

    if char_map:
        return False

    char_index = {ch: i for i, ch in enumerate(order)}

    for i in range(len(original) - 1):
        a, b = original[i], original[i + 1]
        k, n, m = 0, len(a), len(b)
        while k < n and k < m and a[k] == b[k]:
            k += 1
        if k < n and k < m and char_index[a[k]] > char_index[b[k]]:
            return False
        if k != n and k == m:
            return False

    return True

if __name__ == "__main__":
    input_data = sys.stdin.read().strip().split("\n")
    index = 0
    t = int(input_data[index])
    index += 1
    while t > 0:
        words = input_data[index].split()
        index += 1
        original = words[:]

        order = Solution.findOrder(words)

        if order == "":
            print("\"\"")
        else:
            print("true" if validate(original, order) else "false")
        print("~")
        t -= 1

# } Driver Code Ends
