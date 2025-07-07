class Solution:
    def nextLargerElement(self, arr):
        n = len(arr)
        res = [-1] * n
        st = []
        for i in range(2 * n - 1, -1, -1):
            while st and st[-1] <= arr[i % n]:
                st.pop()
            if i < n and st:
                res[i] = st[-1]
            st.append(arr[i % n])
        return res
