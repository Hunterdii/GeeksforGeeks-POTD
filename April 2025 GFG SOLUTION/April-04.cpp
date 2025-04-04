//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> p(V, -1);
        function<int(int)> f = [&](int x){ return p[x] < 0 ? x : p[x] = f(p[x]); };
        for(auto &e : edges){
            int a = f(e[0]), b = f(e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
};

2)
class Solution {
public:
    bool dfs(int u, int parent, vector<vector<int>>& g, vector<bool>& vis) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v] ? dfs(v, u, g, vis) : v != parent)
                return true;
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i] && dfs(i, -1, g, vis))
                return true;
        return false;
    }
};


3)
class Solution {
public:
    int find(vector<int>& p, int x) {
        while(p[x] >= 0)
            x = p[x];
        return x;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> p(V, -1);
        for(auto &e : edges){
            int a = find(p, e[0]), b = find(p, e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
