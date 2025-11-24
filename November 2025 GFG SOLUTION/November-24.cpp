class Solution {
public:
    int secondMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        vector<int> p(V), r(V);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
            return true;
        };
        int mst = 0, ans = INT_MAX;
        vector<array<int, 3>> tree;
        for (auto& e : edges) {
            if (unite(e[0], e[1])) {
                mst += e[2];
                tree.push_back({e[0], e[1], e[2]});
            }
        }
        for (auto& [u, v, w] : tree) {
            fill(p.begin(), p.end(), 0);
            iota(p.begin(), p.end(), 0);
            fill(r.begin(), r.end(), 0);
            int cost = 0, cnt = 0;
            for (auto& e : edges) {
                if ((e[0] == u && e[1] == v) || (e[0] == v && e[1] == u)) continue;
                if (unite(e[0], e[1])) {
                    cost += e[2];
                    if (++cnt == V - 1) break;
                }
            }
            if (cnt == V - 1 && cost > mst) ans = min(ans, cost);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


