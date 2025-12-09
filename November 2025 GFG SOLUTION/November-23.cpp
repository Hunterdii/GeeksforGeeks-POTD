class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, int> row, col;
        int comp = 0;
        for (auto& s : stones) {
            if (!row.count(s[0])) row[s[0]] = comp++;
            if (!col.count(~s[1])) col[~s[1]] = comp++;
            int r = row[s[0]], c = col[~s[1]];
            if (r != c) {
                for (auto& p : row) if (p.second == c) p.second = r;
                for (auto& p : col) if (p.second == c) p.second = r;
            }
        }
        unordered_set<int> unique;
        for (auto& p : row) unique.insert(p.second);
        for (auto& p : col) unique.insert(p.second);
        return n - unique.size();
    }
};

2)
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> rows, cols;
        for (int i = 0; i < n; i++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        vector<bool> vis(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int j : rows[stones[curr][0]])
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                for (int j : cols[stones[curr][1]])
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
            }
            comp++;
        }
        return n - comp;
    }
};

3)
class Solution {
    void dfs(int i, vector<bool>& vis, vector<vector<int>>& stones) {
        vis[i] = true;
        for (int j = 0; j < stones.size(); j++) {
            if (!vis[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])) {
                dfs(j, vis, stones);
            }
        }
    }
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, stones);
                comp++;
            }
        }
        return n - comp;
    }
};

4)
class Solution {
    int find(int x, vector<int>& p) {
        return p[x] < 0 ? x : p[x] = find(p[x], p);
    }
    void unite(int x, int y, vector<int>& p) {
        x = find(x, p); y = find(y, p);
        if (x != y) p[x] = y;
    }
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> p(20002, -1);
        for (auto& s : stones) unite(s[0], s[1] + 10001, p);
        unordered_set<int> roots;
        for (auto& s : stones) roots.insert(find(s[0], p));
        return n - roots.size();
    }
};
