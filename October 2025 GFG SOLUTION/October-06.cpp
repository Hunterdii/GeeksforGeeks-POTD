class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> b(n, vector<int>(n, -1));
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        function<bool(int, int, int)> solve = [&](int x, int y, int s) {
            if (s == n * n) return true;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                    b[nx][ny] = s;
                    if (solve(nx, ny, s + 1)) return true;
                    b[nx][ny] = -1;
                }
            }
            return false;
        };
        b[0][0] = 0;
        return solve(0, 0, 1) ? b : vector<vector<int>>();
    }
};

2)
class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> b(n, vector<int>(n, -1));
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        auto deg = [&](int x, int y) {
            int c = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) c++;
            }
            return c;
        };
        function<bool(int, int, int)> solve = [&](int x, int y, int s) {
            b[x][y] = s;
            if (s == n * n - 1) return true;
            int minDeg = 9, minIdx = -1;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                    int d = deg(nx, ny);
                    if (d < minDeg) minDeg = d, minIdx = i;
                }
            }
            if (minIdx != -1) {
                if (solve(x + dx[minIdx], y + dy[minIdx], s + 1)) return true;
            }
            b[x][y] = -1;
            return false;
        };
        return solve(0, 0, 0) ? b : vector<vector<int>>();
    }
};

3)
class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        vector<vector<int>> b(n, vector<int>(n, -1));
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        stack<tuple<int, int, int, int>> st;
        b[0][0] = 0;
        st.push({0, 0, 1, 0});
        while (!st.empty()) {
            auto [x, y, s, dir] = st.top();
            st.pop();
            if (s == n * n) return b;
            bool found = false;
            for (int i = dir; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                    b[nx][ny] = s;
                    st.push({x, y, s, i + 1});
                    st.push({nx, ny, s + 1, 0});
                    found = true;
                    break;
                }
            }
            if (!found && s > 1) b[x][y] = -1;
        }
        return {};
    }
};

4)
class Solution {
public:
    vector<vector<int>> knightTour(int n) {
        if (n < 5) {
            vector<vector<int>> b(n, vector<int>(n, -1));
            int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
            function<bool(int, int, int)> solve = [&](int x, int y, int s) {
                if (s == n * n) return true;
                for (int i = 0; i < 8; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                        b[nx][ny] = s;
                        if (solve(nx, ny, s + 1)) return true;
                        b[nx][ny] = -1;
                    }
                }
                return false;
            };
            b[0][0] = 0;
            return solve(0, 0, 1) ? b : vector<vector<int>>();
        }
        vector<vector<int>> b(n, vector<int>(n, -1));
        int dx[] = {2, 1, -1, -2, -2, -1, 1, 2}, dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
        function<bool(int, int, int)> solve = [&](int x, int y, int s) {
            if (s == n * n) return true;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && b[nx][ny] == -1) {
                    b[nx][ny] = s;
                    if (solve(nx, ny, s + 1)) return true;
                    b[nx][ny] = -1;
                }
            }
            return false;
        };
        b[0][0] = 0;
        return solve(0, 0, 1) ? b : vector<vector<int>>();
    }
};
