class Solution:
    def checkRedundancy(self, s):
        st = []
        for c in s:
            if c == ')':
                op = False
                while st[-1] != '(':
                    if st.pop() in '+-*/': op = True
                st.pop()
                if not op: return True
            elif c == '(' or c in '+-*/':
                st.append(c)
        return False
