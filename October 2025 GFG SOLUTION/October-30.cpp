class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        function<void(int, int)> dfs = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != '-') return;
            g[i][j] = 'O';
            dfs(i + 1, j); dfs(i - 1, j); dfs(i, j + 1); dfs(i, j - 1);
        };
        for (int i = 0; i < m; i++) { dfs(i, 0); dfs(i, n - 1); }
        for (int j = 0; j < n; j++) { dfs(0, j); dfs(m - 1, j); }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};

2)
class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (g[i][j] == 'O') { g[i][j] = '-'; if (i == 0 || i == m - 1 || j == 0 || j == n - 1) q.push({i, j}); }
        }
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (g[x][y] != '-') continue;
            g[x][y] = 'O';
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && g[nx][ny] == '-') q.push({nx, ny});
            }
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};

3)
class Solution {
    vector<int> p;
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) { p[find(a)] = find(b); }
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        p.resize(m * n + 1);
        iota(p.begin(), p.end(), 0);
        int dummy = m * n;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
            if (g[i][j] == 'O') {
                int idx = i * n + j;
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) unite(idx, dummy);
                if (i > 0 && g[i - 1][j] == 'O') unite(idx, (i - 1) * n + j);
                if (j > 0 && g[i][j - 1] == 'O') unite(idx, i * n + j - 1);
            }
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
            if (g[i][j] == 'O' && find(i * n + j) != find(dummy)) g[i][j] = 'X';
    }
};

4)
class Solution {
public:
    void fill(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == 'O') g[i][j] = '-';
        stack<pair<int,int>> st;
        for (int i = 0; i < m; i++) { if (g[i][0] == '-') st.push({i, 0}); if (g[i][n - 1] == '-') st.push({i, n - 1}); }
        for (int j = 0; j < n; j++) { if (g[0][j] == '-') st.push({0, j}); if (g[m - 1][j] == '-') st.push({m - 1, j}); }
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (!st.empty()) {
            auto [x, y] = st.top(); st.pop();
            if (x < 0 || x >= m || y < 0 || y >= n || g[x][y] != '-') continue;
            g[x][y] = 'O';
            for (int k = 0; k < 4; k++) st.push({x + dx[k], y + dy[k]});
        }
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (g[i][j] == '-') g[i][j] = 'X';
    }
};
