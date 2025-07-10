class Solution:
    def longestString(self, words):
        words.sort(key=len)
        st = set()
        res = ""
        for w in words:
            if len(w) == 1 or w[:-1] in st:
                st.add(w)
                if len(w) > len(res) or (len(w) == len(res) and w < res):
                    res = w
        return res
