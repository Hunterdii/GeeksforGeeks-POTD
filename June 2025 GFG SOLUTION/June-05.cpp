class Solution {
  public:
    int countPaths(vector<vector<int>>& E, int V, int S, int D) {
        vector<vector<int>> G(V); vector<int> I(V);
        for (auto& e : E) G[e[0]].push_back(e[1]), I[e[1]]++;
        queue<int> Q; for (int i = 0; i < V; i++) if (!I[i]) Q.push(i);
        vector<int> T, dp(V); dp[D] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop(); T.push_back(u);
            for (int v : G[u]) if (--I[v] == 0) Q.push(v);
        }
        for (int i = V - 1; i >= 0; i--)
            for (int v : G[T[i]]) dp[T[i]] += dp[v];
        return dp[S];
    }
};


2)
class Solution {
  public:
    int dfs(int node, int dest, vector<vector<int>>& graph, vector<int>& memo) {
        if (node == dest) return 1;
        if (memo[node] != -1) return memo[node];
        int paths = 0;
        for (int v : graph[node])
            paths += dfs(v, dest, graph, memo);
        return memo[node] = paths;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> graph(V);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);
        vector<int> memo(V, -1);
        return dfs(src, dest, graph, memo);
    }
};
