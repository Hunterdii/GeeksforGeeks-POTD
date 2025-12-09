class Solution:
    def countSubs(self, s):
        class Node:
            def __init__(self):
                self.c = [None] * 26
        root, cnt, n = Node(), 0, len(s)
        for i in range(n):
            cur = root
            for j in range(i, n):
                idx = ord(s[j]) - ord('a')
                if not cur.c[idx]:
                    cur.c[idx] = Node()
                    cnt += 1
                cur = cur.c[idx]
        return cnt
