class Solution:
    def sumSubMins(self, arr):
        MOD = 10**9 + 7
        n = len(arr)
        left = [0] * n
        right = [0] * n
        st = []
        for i in range(n):
            while st and arr[st[-1]] >= arr[i]:
                st.pop()
            left[i] = i + 1 if not st else i - st[-1]
            st.append(i)
        st.clear()
        for i in range(n - 1, -1, -1):
            while st and arr[st[-1]] > arr[i]:
                st.pop()
            right[i] = n - i if not st else st[-1] - i
            st.append(i)
        return sum(arr[i] * left[i] * right[i] for i in range(n)) % MOD
