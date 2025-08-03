class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> diff(n, vector<int>(m, 0));
        
        for (auto& op : opr) {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            diff[r1][c1] += val;
            if (c2 + 1 < m) diff[r1][c2 + 1] -= val;
            if (r2 + 1 < n) diff[r2 + 1][c1] -= val;
            if (r2 + 1 < n && c2 + 1 < m) diff[r2 + 1][c2 + 1] += val;
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                diff[i][j] += diff[i][j - 1];
        
        for (int j = 0; j < m; j++)
            for (int i = 1; i < n; i++)
                diff[i][j] += diff[i - 1][j];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] += diff[i][j];
        
        return mat;
    }
};

2)
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<long long>> d(n + 1, vector<long long>(m + 1, 0));
        
        for (const auto& op : opr) {
            long long v = op[0];
            int r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] += (i ? d[i-1][j] : 0) + (j ? d[i][j-1] : 0) - (i && j ? d[i-1][j-1] : 0);
                mat[i][j] += d[i][j];
            }
        }
        return mat;
    }
};

3)
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        for (auto& op : opr) {
            int val = op[0], r1 = op[1], c1 = op[2], r2 = op[3], c2 = op[4];
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    mat[i][j] += val;
                }
            }
        }
        return mat;
    }
};

4)
class Solution {
public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat, vector<vector<int>>& opr) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> d(n + 1, vector<int>(m + 1, 0));
        
        for (auto& q : opr) {
            int v = q[0], r1 = q[1], c1 = q[2], r2 = q[3], c2 = q[4];
            d[r1][c1] += v;
            d[r1][c2 + 1] -= v;
            d[r2 + 1][c1] -= v;
            d[r2 + 1][c2 + 1] += v;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i) d[i][j] += d[i - 1][j];
                if (j) d[i][j] += d[i][j - 1];
                if (i && j) d[i][j] -= d[i - 1][j - 1];
                mat[i][j] += d[i][j];
            }
        }
        return mat;
    }
};
