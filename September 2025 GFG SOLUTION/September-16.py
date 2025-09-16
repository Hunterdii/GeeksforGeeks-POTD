class Solution:
    def evaluatePostfix(self, arr):
        st = []
        for t in arr:
            if t in "+-*/^" and len(t) == 1:
                b, a = st.pop(), st.pop()
                if t == '/':
                    st.append(a // b)
                else:
                    st.append(a + b if t == '+' else a - b if t == '-' else 
                             a * b if t == '*' else a ** b)
            else:
                st.append(int(t))
        return st[-1]
