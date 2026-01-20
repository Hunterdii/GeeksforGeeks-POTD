class Solution:
    def removeKdig(self, s, k):
        stk = []
        for c in s:
            while stk and k and stk[-1] > c:
                stk.pop()
                k -= 1
            if stk or c != '0':
                stk.append(c)
        while stk and k:
            stk.pop()
            k -= 1
        return ''.join(stk) if stk else '0'
