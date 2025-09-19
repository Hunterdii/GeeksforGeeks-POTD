class Solution:
    def minParentheses(self, s):
        open = close = 0
        for c in s:
            if c == '(':
                open += 1
            elif c == ')':
                if open > 0:
                    open -= 1
                else:
                    close += 1
        return open + close
