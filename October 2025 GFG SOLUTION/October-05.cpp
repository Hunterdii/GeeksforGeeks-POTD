class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> res;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return res;
        string p = "";
        solve(0, 0, m, n, p, res);
        return res;
    }
    
    void solve(int i, int j, vector<vector<int>>& m, int n, string p, vector<string>& res) {
        if (i == n-1 && j == n-1) {
            res.push_back(p);
            return;
        }
        m[i][j] = 0;
        if (i+1 < n && m[i+1][j]) solve(i+1, j, m, n, p+'D', res);
        if (j-1 >= 0 && m[i][j-1]) solve(i, j-1, m, n, p+'L', res);
        if (j+1 < n && m[i][j+1]) solve(i, j+1, m, n, p+'R', res);
        if (i-1 >= 0 && m[i-1][j]) solve(i-1, j, m, n, p+'U', res);
        m[i][j] = 1;
    }
};

2)
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> ans;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        dfs(0, 0, m, vis, "", ans, n);
        return ans;
    }
    
    void dfs(int r, int c, vector<vector<int>>& m, vector<vector<int>>& vis, string path, vector<string>& ans, int n) {
        if (r == n-1 && c == n-1) {
            ans.push_back(path);
            return;
        }
        vis[r][c] = 1;
        if (r+1 < n && !vis[r+1][c] && m[r+1][c]) dfs(r+1, c, m, vis, path+'D', ans, n);
        if (c-1 >= 0 && !vis[r][c-1] && m[r][c-1]) dfs(r, c-1, m, vis, path+'L', ans, n);
        if (c+1 < n && !vis[r][c+1] && m[r][c+1]) dfs(r, c+1, m, vis, path+'R', ans, n);
        if (r-1 >= 0 && !vis[r-1][c] && m[r-1][c]) dfs(r-1, c, m, vis, path+'U', ans, n);
        vis[r][c] = 0;
    }
};

3)
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> result;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return result;
        helper(0, 0, "", m, result);
        return result;
    }
    
    void helper(int x, int y, string path, vector<vector<int>>& m, vector<string>& result) {
        int n = m.size();
        if (x == n-1 && y == n-1) {
            result.push_back(path);
            return;
        }
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};
        m[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n && m[nx][ny]) {
                helper(nx, ny, path + dir[i], m, result);
            }
        }
        m[x][y] = 1;
    }
};

4)
class Solution {
public:
    vector<string> ratInMaze(vector<vector<int>>& m) {
        vector<string> paths;
        int n = m.size();
        if (!m[0][0] || !m[n-1][n-1]) return paths;
        search(0, 0, 0, "", m, paths, n);
        return paths;
    }
    
    void search(int r, int c, int mask, string curr, vector<vector<int>>& m, vector<string>& paths, int n) {
        if (r == n-1 && c == n-1) {
            paths.push_back(curr);
            return;
        }
        int pos = r * n + c;
        mask |= (1 << pos);
        int dr[] = {1, 0, 0, -1}, dc[] = {0, -1, 1, 0};
        string d = "DLRU";
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            int npos = nr * n + nc;
            if (nr >= 0 && nc >= 0 && nr < n && nc < n && m[nr][nc] && !(mask & (1 << npos))) {
                search(nr, nc, mask, curr + d[i], m, paths, n);
            }
        }
    }
};
