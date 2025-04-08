//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs(adj, v, vis);
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c))
                adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        dfs(adj, c, vis);
        return !vis[d];
    }
};


2)
class Solution {
    int timer;
    bool dfs(int u, int p, vector<int> adj[], vector<int> &tin, vector<int> &low, int c, int d) {
        tin[u] = low[u] = ++timer;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (!tin[v]) {
                if (dfs(v, u, adj, tin, low, c, d)) return true;
                low[u] = min(low[u], low[v]);
                if ((u == c && v == d || u == d && v == c) && low[v] > tin[u]) return true;
            } else low[u] = min(low[u], tin[v]);
        }
        return false;
    }
public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V], tin(V), low(V);
        for (auto &e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        timer = 0;
        for (int i = 0; i < V; i++)
            if (!tin[i] && dfs(i, -1, adj, tin, low, c, d))
                return true;
        return false;
    }
};


3)
class Solution {
public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c))
                adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<bool> vis(V, false);
        stack<int> st;
        st.push(c);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (int v : adj[u]) if (!vis[v]) st.push(v);
        }
        return !vis[d];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
