class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(V, LLONG_MAX), ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;
        pq.push({0, 0});
        const int MOD = 1e9 + 7;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[V - 1];
    }
};

2)
class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(V, LLONG_MAX);
        vector<long long> paths(V, 0);
        map<long long, vector<int>> levels;
        dist[0] = 0;
        paths[0] = 1;
        levels[0].push_back(0);
        const int MOD = 1e9 + 7;
        while (!levels.empty()) {
            auto it = levels.begin();
            long long d = it->first;
            vector<int> nodes = it->second;
            levels.erase(it);
            for (int u : nodes) {
                if (d > dist[u]) continue;
                for (auto [v, w] : adj[u]) {
                    long long nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        paths[v] = paths[u];
                        levels[nd].push_back(v);
                    }
                    else if (nd == dist[v]) {
                        paths[v] = (paths[v] + paths[u]) % MOD;
                    }
                }
            }
        }
        return paths[V - 1];
    }
};

3)
class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist, ways;
    const int MOD = 1e9+7;
    void dfs(int u, long long d) {
        if (d > dist[u]) return;
        if (d < dist[u]) {
            dist[u] = d;
            ways[u] = 1;
        } else {
            ways[u]++;
        }
        for (auto [v, w] : adj[u]) {
            dfs(v, d + w);
        }
    }
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        adj.assign(V, {});
        dist.assign(V, LLONG_MAX);
        ways.assign(V, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, 0);
        return ways[V - 1] % MOD;
    }
};

