//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
            adj[e[0]].push_back({e[1], e[2]});
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

2)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> g(V);
        for (auto &e : edges) g[e[0]].emplace_back(e[1], e[2]);
        vector<int> d(V, 1e9); d[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, src);
        while (!q.empty()) {
            auto p = q.top(); q.pop();
            if (p.first > d[p.second]) continue;
            for (auto &x : g[p.second])
                if (p.first + x.second < d[x.first])
                    q.emplace(d[x.first] = p.first + x.second, x.first);
        }
        return d;
    }
};


3)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> g(V);
        for (auto &e : edges) g[e[0]].emplace_back(e[1], e[2]);

        vector<int> d(V, 1e9);
        d[src] = 0;
        set<pair<int, int>> st;
        st.emplace(0, src);

        while (!st.empty()) {
            pair<int, int> p = *st.begin();
            int du = p.first;
            int u = p.second;
            st.erase(st.begin());

            for (int i = 0; i < g[u].size(); ++i) {
                int v = g[u][i].first;
                int w = g[u][i].second;

                if (du + w < d[v]) {
                    st.erase({d[v], v});
                    d[v] = du + w;
                    st.emplace(d[v], v);
                }
            }
        }

        return d;
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
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(V, edges, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
