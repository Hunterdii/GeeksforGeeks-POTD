class Solution:
    def computeLPSArray(self, s):
        lps = [0] * len(s)
        len_ = 0
        idx = 1

        while idx < len(s):
            if s[idx] == s[len_]:
                len_ += 1
                lps[idx] = len_
                idx += 1
            else:

                if len_ == 0:
                    lps[idx] = 0
                    idx += 1
                else:

                    len_ = lps[len_ - 1]
        return lps

    def KMPSearch(self, txt, pat, lps, rep):
        n, m = len(txt), len(pat)
        i = j = 0

        while i < n * rep:

            if txt[i % n] == pat[j]:
                i += 1
                j += 1

                if j == m:
                    return True

                    j = lps[j - 1]
            else:

                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False

    def minRepeats(self, s1, s2):

        n, m = len(s1), len(s2)

        lps = self.computeLPSArray(s2)

        x = (m + n - 1) // n

        if self.KMPSearch(s1, s2, lps, x):
            return x

        if self.KMPSearch(s1, s2, lps, x + 1):
            return x + 1

        return -1
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        A = input()
        B = input()

        ob = Solution()
        print(ob.minRepeats(A, B))

# } Driver Code Ends
