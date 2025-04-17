//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        int res = INT_MAX;
        for (int i = 0; i < V; ++i) {
            vector<int> dist(V, 1e9), par(V, -1);
            dist[i] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, i});
            while (!pq.empty()) {
                pair<int,int> top = pq.top(); pq.pop();
                int d = top.first, u = top.second;
                for (int j = 0; j < adj[u].size(); ++j) {
                    int v = adj[u][j].first, w = adj[u][j].second;
                    if (dist[v] > d + w) {
                        dist[v] = d + w;
                        par[v] = u;
                        pq.push({dist[v], v});
                    } else if (par[u] != v && par[v] != u)
                        res = min(res, dist[u] + dist[v] + w);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends
