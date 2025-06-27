class Solution {
public:
    int getCount(int n) {
        int ans = 0;
        vector<vector<int>> p(4, vector<int>(3, 1)), c(4, vector<int>(3));
        p[3][0] = p[3][2] = 0;
        vector<vector<int>> d = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        for (int k = 2; k <= n; k++) {
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 3; j++) {
                    if (i==3&&(j==0||j==2)) continue;
                    c[i][j] = 0;
                    for (auto &v : d) {
                        int x = i+v[0], y = j+v[1];
                        if (x>=0 && x<4 && y>=0 && y<3) c[i][j] += p[x][y];
                    }
                }
            p = c;
        }
        for (auto &r : p) for (int v : r) ans += v;
        return ans;
    }
};

2)
class Solution {
public:
    int dp[16][4][3];
    
    int dfs(int n, int i, int j) {
        if (i < 0 || i > 3 || j < 0 || j > 2 || (i==3 && j!=1)) return 0;
        if (n == 1) return 1;
        if (dp[n][i][j] != -1) return dp[n][i][j];
        
        vector<pair<int,int>> dir = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;
        for (auto d : dir) 
            res += dfs(n-1, i+d.first, j+d.second);
        
        return dp[n][i][j] = res;
    }
    
    int getCount(int n) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for (int i=0; i<4; ++i)
            for (int j=0; j<3; ++j)
                if (!(i==3 && j!=1))
                    res += dfs(n, i, j);
        return res;
    }
};

3)
class Solution {
public:
    int getCount(int n) {
        vector<vector<int>> adj = {
            {0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6},
            {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9},
            {4, 7, 8}, {5, 7, 8, 9, 0}, {6, 8, 9}
        };
        
        vector<int> dp(10, 1), next(10, 0);
        
        for (int step = 2; step <= n; step++) {
            fill(next.begin(), next.end(), 0);
            for (int digit = 0; digit <= 9; digit++) {
                for (int neighbor : adj[digit]) {
                    next[digit] += dp[neighbor];
                }
            }
            dp = next;
        }
        
        int result = 0;
        for (int count : dp) result += count;
        return result;
    }
};

4)
class Solution {
public:
    int dp[5001][4][3];
    int mod = 1e9+7;
    int dfs(int n, int i, int j) {
        if (i < 0 || i > 3 || j < 0 || j > 2 || (i==3 && j!=1)) return 0;
        if (n == 1) return 1;
        if (dp[n][i][j] != -1) return dp[n][i][j];
        vector<pair<int,int>> dir = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;
        for (auto d : dir) res += dfs(n-1, i+d.first, j+d.second);
        return dp[n][i][j] = res;
    }
    
    int getCount(int n) {
        memset(dp, -1, sizeof(dp));
        int res = 0;
        for (int i=0; i<4; ++i)
            for (int j=0; j<3; ++j)
                if (!(i==3 && j!=1))
                    res += dfs(n, i, j);
        return res;
    }
};

5)
class Solution {
public:
    int getCount(int n) {
        vector<vector<int>> dp(4, vector<int>(3, 1));
        dp[3][0] = dp[3][2] = 0;
        vector<vector<int>> dir = {{0,0}, {0,-1}, {0,1}, {-1,0}, {1,0}};
        
        for (int k = 2; k <= n; k++) {
            vector<vector<int>> next(4, vector<int>(3, 0));
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == 3 && (j == 0 || j == 2)) continue;
                    for (auto d : dir) {
                        int x = i + d[0], y = j + d[1];
                        if (x >= 0 && x < 4 && y >= 0 && y < 3) {
                            next[i][j] += dp[x][y];
                        }
                    }
                }
            }
            dp = next;
        }
        
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
