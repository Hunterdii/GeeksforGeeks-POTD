class Solution:
    def nextFreqGreater(self, arr):
        freq = {}
        for x in arr: freq[x] = freq.get(x, 0) + 1
        res = [-1] * len(arr)
        st = []
        for i in range(len(arr) - 1, -1, -1):
            while st and freq[arr[st[-1]]] <= freq[arr[i]]: st.pop()
            if st: res[i] = arr[st[-1]]
            st.append(i)
        return res
