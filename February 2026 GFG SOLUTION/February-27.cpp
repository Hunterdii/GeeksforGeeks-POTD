class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                pre[i][j] = mat[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        for (int sz = 1; sz <= min(n, m); sz++)
            for (int i = sz; i <= n; i++)
                for (int j = sz; j <= m; j++)
                    if (pre[i][j] - pre[i-sz][j] - pre[i][j-sz] + pre[i-sz][j-sz] == x)
                        cnt++;
        return cnt;
    }
};

2)
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), res = 0;
        vector<vector<int>> rowPre = mat;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                rowPre[i][j] += rowPre[i][j - 1];
        
        for (int sz = 1; sz <= min(n, m); sz++) {
            for (int c = 0; c <= m - sz; c++) {
                int sum = 0;
                for (int r = 0; r < n; r++) {
                    int rowSum = rowPre[r][c + sz - 1] - (c > 0 ? rowPre[r][c - 1] : 0);
                    sum += rowSum;
                    if (r >= sz - 1) {
                        if (sum == x) res++;
                        sum -= rowPre[r - sz + 1][c + sz - 1] - (c > 0 ? rowPre[r - sz + 1][c - 1] : 0);
                    }
                }
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int sz = 1; i + sz <= n && j + sz <= m; sz++) {
                    int sum = 0;
                    for (int r = i; r < i + sz; r++)
                        for (int c = j; c < j + sz; c++)
                            sum += mat[r][c];
                    if (sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};

4)
class Solution {
public:
    int countSquare(vector<vector<int>>& mat, int x) {
        int n = mat.size(), m = mat[0].size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int sz = 1; i + sz <= n && j + sz <= m; sz++) {
                    for (int k = j; k < j + sz; k++)
                        sum += mat[i + sz - 1][k];
                    for (int k = i; k < i + sz - 1; k++)
                        sum += mat[k][j + sz - 1];
                    if (sum == x) cnt++;
                }
            }
        }
        return cnt;
    }
};
