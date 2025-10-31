class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (int i = 0; i < V; i++) {
            vector<int> d(V, -1), p(V, -1);
            queue<int> q;
            d[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        p[v] = u;
                        q.push(v);
                    } else if (p[u] != v) res = min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

2)
class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (int i = 0; i < V; i++) {
            vector<int> d(V, -1);
            queue<int> q;
            d[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    } else if (d[v] >= d[u]) res = min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

3)
class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (auto &e : edges) {
            vector<int> d(V, -1);
            queue<int> q;
            d[e[0]] = 0;
            q.push(e[0]);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if ((u == e[0] && v == e[1]) || (u == e[1] && v == e[0])) continue;
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (d[e[1]] != -1) res = min(res, d[e[1]] + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};
