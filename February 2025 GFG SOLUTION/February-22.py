
class Solution:
    def maxLength(self, s):
        l = r = m = 0
        for c in s:
            l += c == '('
            r += c == ')'
            if l == r:
                m = max(m, 2 * r)
            elif r > l:
                l = r = 0
        l = r = 0
        for c in s[::-1]:
            l += c == '('
            r += c == ')'
            if l == r:
                m = max(m, 2 * l)
            elif l > r:
                l = r = 0
        return m

2)
class Solution:
    def maxLength(self, s):
        st=[-1]; m=0
        for i,c in enumerate(s):
            if c=='(':
                st.append(i)
            else:
                st.pop()
                if not st: st.append(i)
                else: m = max(m, i - st[-1])
        return m


#{ 
 # Driver Code Starts
# Initial Template for Python3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.maxLength(S))
        print("~")

# } Driver Code Ends
