class Solution {
public:
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto bfs = [&](int src) {
            vector<int> d(V, -1);
            queue<int> q;
            q.push(src);
            d[src] = 0;
            int far = src, maxD = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                        if (d[v] > maxD) {
                            maxD = d[v];
                            far = v;
                        }
                    }
                }
            }
            return make_pair(far, maxD);
        };
        auto [end1, _] = bfs(0);
        auto [end2, diam] = bfs(end1);
        return diam;
    }
};

2)
class Solution {
public:
    int res = 0;
    int dfs(int u, int p, vector<vector<int>>& adj) {
        int m1 = 0, m2 = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int d = dfs(v, u, adj) + 1;
                if (d > m1) m2 = m1, m1 = d;
                else if (d > m2) m2 = d;
            }
        }
        res = max(res, m1 + m2);
        return m1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj);
        return res;
    }
};

3)
class Solution {
public:
    pair<int, int> bfs(int s, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> d(n, -1);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        int node = s, dist = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (d[v] < 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    if (d[v] > dist) dist = d[v], node = v;
                }
            }
        }
        return {node, dist};
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return bfs(bfs(0, adj).first, adj).second;
    }
};

4)
class Solution {
public:
    int maxDiam = 0;
    int height(int u, int p, vector<vector<int>>& adj) {
        int h1 = 0, h2 = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int h = height(v, u, adj);
                if (h > h1) h2 = h1, h1 = h;
                else if (h > h2) h2 = h;
            }
        }
        maxDiam = max(maxDiam, h1 + h2);
        return h1 + 1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        height(0, -1, adj);
        return maxDiam;
    }
};
