class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};

2)
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) dp[i][j] = 0;
                else {
                    if (i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                    if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
        for (int i = n-1; i >= 0; i--)
            for (int j = m-1; j >= 0; j--) {
                if (i < n-1) dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                if (j < m-1) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            }
        return dp;
    }
};

3)
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1e9));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int x = 0; x < n; x++)
                    for (int y = 0; y < m; y++)
                        if (grid[x][y] == 1)
                            res[i][j] = min(res[i][j], abs(i-x) + abs(j-y));
        return res;
    }
};

4)
class Solution {
public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1) {
                        ans[nr][nc] = dist;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return ans;
    }
};
