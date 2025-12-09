class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int comp = V, e = edges.size();
        if (e < V - 1) return -1;
        vector<int> p(V);
        for (int i = 0; i < V; i++) p[i] = i;
        for (auto &ed : edges) {
            int x = findp(p, ed[0]), y = findp(p, ed[1]);
            if (x != y) { p[x] = y; --comp; }
        }
        return comp - 1;
    }
    int findp(vector<int> &p, int x) {
        return p[x] == x ? x : p[x] = findp(p, p[x]);
    }
};

2)
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        int comp = 0;
        function<void(int)> dfs = [&](int u) { vis[u] = 1; for (int v : g[u]) if (!vis[v]) dfs(v); };
        for (int i = 0; i < V; i++) if (!vis[i]) ++comp, dfs(i);
        int extra = edges.size() - (V - comp);
        return extra >= comp - 1 ? comp - 1 : -1;
    }
};

3)
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        int comp = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ++comp;
                queue<int> q; q.push(i); vis[i] = 1;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
                }
            }
        }
        int extra = edges.size() - (V - comp);
        return extra >= comp - 1 ? comp - 1 : -1;
    }
};

4)
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        if (edges.size() < V - 1) return -1;
        vector<int> p(V);
        iota(p.begin(), p.end(), 0);
        int comp = V;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            while (p[x] != x) x = p[x];
            while (p[y] != y) y = p[y];
            if (x != y) p[x] = y, --comp;
        }
        return comp - 1;
    }
};
