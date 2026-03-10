class Solution:
    def countSubarrays(self, arr):
        st, ans, n = [], 0, len(arr)
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] >= arr[i]: st.pop()
            ans += ((st[-1] if st else n) - i)
            st.append(i)
        return ans
