//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0) q.push(i);
        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            count++;
            for (int v : adj[u])
                if (--indegree[v] == 0) q.push(v);
        }
        return count != V;
    }
};


2)
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        vector<int> in(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), in[e[1]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!in[i]) q.push(i);
        int c = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); c++;
            for (int v : g[u]) if (--in[v] == 0) q.push(v);
        }
        return c != V;
    }
};


3)
class Solution {
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false), inStack(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int u = st.top();
                    if (!vis[u]) {
                        vis[u] = inStack[u] = true;
                    }
                    bool found = false;
                    for (int v : g[u]) {
                        if (!vis[v]) {
                            st.push(v);
                            found = true;
                            break;
                        } else if (inStack[v]) {
                            return true;
                        }
                    }
                    if (!found) {
                        inStack[u] = false;
                        st.pop();
                    }
                }
            }
        }
        return false;
    }
};

4)
class Solution {
    bool dfs(int u, vector<vector<int>>& g, vector<bool>& vis, vector<bool>& recStack) {
        vis[u] = recStack[u] = true;
        for (int v : g[u]) {
            if (!vis[v] && dfs(v, g, vis, recStack))
                return true;
            else if (recStack[v])
                return true;
        }
        recStack[u] = false;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false), recStack(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i] && dfs(i, g, vis, recStack))
                return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
