class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int mx = 0;
                for (int di = -1; di <= 1; di++) {
                    int ni = i + di;
                    if (ni >= 0 && ni < n) mx = max(mx, mat[ni][j + 1]);
                }
                mat[i][j] += mx;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, mat[i][0]);
        return res;
    }
};

2)
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> prev(n), curr(n);
        for (int i = 0; i < n; i++) prev[i] = mat[i][m - 1];
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                curr[i] = mat[i][j] + max({
                    i > 0 ? prev[i - 1] : 0,
                    prev[i],
                    i < n - 1 ? prev[i + 1] : 0
                });
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

3)
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        auto get = [&](int i, int j) { return (i >= 0 && i < n) ? mat[i][j] : 0; };
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                mat[i][j] += max({get(i - 1, j + 1), get(i, j + 1), get(i + 1, j + 1)});
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, mat[i][0]);
        return res;
    }
};

4)
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int j = m - 2; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                int a = (i > 0) ? mat[i - 1][j + 1] : 0;
                int b = mat[i][j + 1];
                int c = (i < n - 1) ? mat[i + 1][j + 1] : 0;
                mat[i][j] += (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
            }
        }
        int res = mat[0][0];
        for (int i = 1; i < n; i++) {
            res = (mat[i][0] > res) ? mat[i][0] : res;
        }
        return res;
    }
};

5)
class Solution {
public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (j == m - 1) return mat[i][j];
            if (memo[i][j] != -1) return memo[i][j];
            
            int maxNext = 0;
            for (int di = -1; di <= 1; di++) {
                int ni = i + di;
                if (ni >= 0 && ni < n) {
                    maxNext = max(maxNext, dfs(ni, j + 1));
                }
            }
            return memo[i][j] = mat[i][j] + maxNext;
        };
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, dfs(i, 0));
        }
        return res;
    }
};
