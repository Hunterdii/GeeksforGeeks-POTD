class Solution:
    def lcsOf3(self, s1, s2, s3):
        n1, n2, n3 = len(s1), len(s2), len(s3)
        prev = [[0] * (n3 + 1) for _ in range(n2 + 1)]
        curr = [[0] * (n3 + 1) for _ in range(n2 + 1)]
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                for k in range(1, n3 + 1):
                    if s1[i - 1] == s2[j - 1] == s3[k - 1]:
                        curr[j][k] = 1 + prev[j - 1][k - 1]
                    else:
                        curr[j][k] = max(
                            prev[j][k],
                            curr[j - 1][k],
                            curr[j][k - 1]
                        )
            prev, curr = curr, prev
        return prev[n2][n3]
