class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        const int INF = 1e9;
        vector<vector<int>> d(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) d[i][i] = 0;
        for (int i = 0; i < transform.size(); i++) 
            d[transform[i][0] - 'a'][transform[i][1] - 'a'] = min(d[transform[i][0] - 'a'][transform[i][1] - 'a'], cost[i]);
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;
            int mn = INF, a = s[i] - 'a', b = t[i] - 'a';
            for (int c = 0; c < 26; c++)
                if (d[a][c] < INF && d[b][c] < INF)
                    mn = min(mn, d[a][c] + d[b][c]);
            if (mn == INF) return -1;
            res += mn;
        }
        return res;
    }
};

2)
class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        vector<vector<pair<int,int>>> g(26);
        for (int i = 0; i < transform.size(); i++)
            g[transform[i][0] - 'a'].push_back({transform[i][1] - 'a', cost[i]});
        auto dijkstra = [&](int src) {
            vector<int> dist(26, 1e9);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            dist[src] = 0;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w] : g[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;
            auto d1 = dijkstra(s[i] - 'a'), d2 = dijkstra(t[i] - 'a');
            int mn = 1e9;
            for (int c = 0; c < 26; c++) mn = min(mn, d1[c] + d2[c]);
            if (mn == 1e9) return -1;
            res += mn;
        }
        return res;
    }
};
