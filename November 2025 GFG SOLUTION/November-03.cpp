class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> out(V), safe(V);
        vector<vector<int>> g(V);
        for (auto& e : edges) out[e[0]]++, g[e[1]].push_back(e[0]);
        queue<int> q;
        for (int i = 0; i < V; i++) if (!out[i]) q.push(i), safe[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (!safe[v] && --out[v] == 0) q.push(v), safe[v] = 1;
        }
        vector<int> res;
        for (int i = 0; i < V; i++) if (safe[i]) res.push_back(i);
        return res;
    }
};

2)
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<int> col(V), res;
        for (int i = 0; i < V; i++) if (!col[i]) dfs(i, adj, col);
        for (int i = 0; i < V; i++) if (col[i] == 2) res.push_back(i);
        return res;
    }
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& col) {
        if (col[u]) return col[u] == 2;
        col[u] = 1;
        for (int v : adj[u]) if (!dfs(v, adj, col)) return false;
        col[u] = 2;
        return true;
    }
};

3)
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> rev(V);
        vector<int> deg(V);
        for (auto& e : edges) rev[e[1]].push_back(e[0]), deg[e[0]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!deg[i]) q.push(i);
        vector<int> ans;
        while (q.size()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int prev : rev[node]) if (--deg[prev] == 0) q.push(prev);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

4)
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> back(V);
        vector<int> cnt(V);
        for (auto& e : edges) back[e[1]].push_back(e[0]), cnt[e[0]]++;
        vector<bool> vis(V);
        queue<int> q;
        for (int i = 0; i < V; i++) if (cnt[i] == 0) q.push(i), vis[i] = 1;
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int pre : back[cur]) if (!vis[pre] && --cnt[pre] == 0) q.push(pre), vis[pre] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < V; i++) if (vis[i]) ans.push_back(i);
        return ans;
    }
};
