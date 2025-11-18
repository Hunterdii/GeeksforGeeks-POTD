class Solution {
public:
    int minCostPath(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto [d, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return d;
            if (d > dist[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nd = max(d, abs(mat[nx][ny] - mat[x][y]));
                    if (nd < dist[nx][ny]) {
                        dist[nx][ny] = nd;
                        pq.push({nd, nx, ny});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};

2)
class Solution {
public:
    bool canReach(vector<vector<int>>& mat, int maxCost) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int,int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == m - 1) return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if (abs(mat[nx][ny] - mat[x][y]) <= maxCost) {
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }
    
    int minCostPath(vector<vector<int>>& mat) {
        int lo = 0, hi = 1e9, ans = hi;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canReach(mat, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

3)
class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({0, 0, 0});
        cost[0][0] = 0;
        while (!pq.empty()) {
            auto [c, x, y] = pq.top(); pq.pop();
            if (x == n - 1 && y == m - 1) return c;
            if (c > cost[x][y]) continue;
            for (auto [dx, dy] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int nc = max(c, abs(mat[nx][ny] - mat[x][y]));
                    if (nc < cost[nx][ny]) {
                        cost[nx][ny] = nc;
                        pq.push({nc, nx, ny});
                    }
                }
            }
        }
        return cost[n - 1][m - 1];
    }
};

4)
class Solution {
public:
    int minCostPath(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        dp[0][0] = 0;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (dp[i][j] == 1e9) continue;
                    for (auto [di, dj] : vector<pair<int,int>>{{-1,0},{1,0},{0,-1},{0,1}}) {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            int newCost = max(dp[i][j], abs(mat[ni][nj] - mat[i][j]));
                            if (newCost < dp[ni][nj]) {
                                dp[ni][nj] = newCost;
                                changed = true;
                            }
                        }
                    }
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
