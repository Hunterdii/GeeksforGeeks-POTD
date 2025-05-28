class Solution:
    def ValidCorner(self, mat):
        n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(i + 1, n):
                if sum(mat[i][k] & mat[j][k] for k in range(m)) > 1:
                    return True
        return False

2)
class Solution:
    def ValidCorner(self, mat):
        n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(i + 1, n):
                cnt = sum(mat[i][k] & mat[j][k] for k in range(m))
                if cnt > 1:
                    return True
        return False
