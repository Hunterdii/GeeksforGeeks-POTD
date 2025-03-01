class Solution:
    def decodedString(self, s: str) -> str:
        str_st, num_st, cur, n = [], [], "", 0

        for c in s:
            if c.isdigit():
                n = n * 10 + int(c)
            elif c == "[":
                str_st.append(cur)
                num_st.append(n)
                cur, n = "", 0
            elif c == "]":
                cur = str_st.pop() + cur * num_st.pop()
            else:
                cur += c
        return cur


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        s = input()

        ob = Solution()
        print(ob.decodedString(s))
        print("~")

# } Driver Code Ends
