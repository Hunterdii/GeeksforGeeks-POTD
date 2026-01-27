class Solution:
    def isWordExist(self, b, w):
        def search(r, c, idx):
            if idx == len(w): return True
            if r < 0 or c < 0 or r >= len(b) or c >= len(b[0]) or b[r][c] != w[idx]: return False
            tmp, b[r][c] = b[r][c], '*'
            res = search(r + 1, c, idx + 1) or search(r - 1, c, idx + 1) or search(r, c + 1, idx + 1) or search(r, c - 1, idx + 1)
            b[r][c] = tmp
            return res
        
        return any(search(i, j, 0) for i in range(len(b)) for j in range(len(b[0])))
