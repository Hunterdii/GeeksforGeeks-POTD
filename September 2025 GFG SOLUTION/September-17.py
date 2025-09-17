class Solution:
    def decodedString(self, s):
        st_str, st_num = [], []
        curr, num = "", 0
        
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                st_str.append(curr)
                st_num.append(num)
                curr, num = "", 0
            elif c == ']':
                temp = curr
                curr = st_str.pop()
                cnt = st_num.pop()
                curr += temp * cnt
            else:
                curr += c
        return curr
