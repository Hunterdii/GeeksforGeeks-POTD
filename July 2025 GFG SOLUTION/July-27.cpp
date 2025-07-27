class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < n; ++i) firstCol |= mat[i][0] == 0;
        for (int j = 0; j < m; ++j) firstRow |= mat[0][j] == 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (!mat[i][0] || !mat[0][j])
                    mat[i][j] = 0;
        if (firstRow) fill(begin(mat[0]), end(mat[0]), 0);
        if (firstCol) for (int i = 0; i < n; ++i) mat[i][0] = 0;
    }
};

2)
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 1), col(m, 1);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 0)
                    row[i] = col[j] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!row[i] || !col[j])
                    mat[i][j] = 0;
    }
};

3)
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool firstRow = false, firstCol = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    if (i == 0) firstRow = true;
                    if (j == 0) firstCol = true;
                    mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < n; i++)
            if (mat[i][0] == 0)
                for (int j = 1; j < m; j++) mat[i][j] = 0;
        
        for (int j = 1; j < m; j++)
            if (mat[0][j] == 0)
                for (int i = 1; i < n; i++) mat[i][j] = 0;
        
        if (firstRow) for (int j = 0; j < m; j++) mat[0][j] = 0;
        if (firstCol) for (int i = 0; i < n; i++) mat[i][0] = 0;
    }
};

4)
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        bool zeroFirstRow = false, zeroFirstCol = false;
        
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) zeroFirstCol = true;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) zeroFirstRow = true;
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }
        
        for (int i = n - 1; i >= 1; i--) {
            for (int j = m - 1; j >= 1; j--) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }
        
        if (zeroFirstCol) for (int i = 0; i < n; i++) mat[i][0] = 0;
        if (zeroFirstRow) for (int j = 0; j < m; j++) mat[0][j] = 0;
    }
};

5)
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int boundary = 0;
        
        for (int i = 0; i < n; i++) if (mat[i][0] == 0) boundary |= 1;
        for (int j = 0; j < m; j++) if (mat[0][j] == 0) boundary |= 2;
        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (mat[i][j] == 0) mat[i][0] = mat[0][j] = 0;
        
        for (int i = 1; i < n; i++) {
            if (mat[i][0] == 0) {
                for (int j = 1; j < m; j++) mat[i][j] = 0;
            }
        }
        
        for (int j = 1; j < m; j++) {
            if (mat[0][j] == 0) {
                for (int i = 1; i < n; i++) mat[i][j] = 0;
            }
        }
        
        if (boundary & 1) for (int i = 0; i < n; i++) mat[i][0] = 0;
        if (boundary & 2) for (int j = 0; j < m; j++) mat[0][j] = 0;
    }
};


6)
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<bool> zeroRows(n, false), zeroCols(m, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (zeroRows[i] || zeroCols[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};
