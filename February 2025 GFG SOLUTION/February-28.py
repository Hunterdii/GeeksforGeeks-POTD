#{ 
 # Driver Code Starts
#Initial Template for Python 3


# } Driver Code Ends


class Solution:
    def evaluate(self, arr):
        st = []
        for s in arr:
            if s in {"+", "-", "*", "/"}:
                b, a = st.pop(), st.pop()
                if s == "+": st.append(a + b)
                elif s == "-": st.append(a - b)
                elif s == "*": st.append(a * b)
                else: st.append(int(a / b))  # Division rounding towards zero
            else:
                st.append(int(s))
        return st[-1]


#{ 
 # Driver Code Starts.

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = input().split()
        solution = Solution()
        print(solution.evaluate(arr))
        print("~")

# } Driver Code Ends
