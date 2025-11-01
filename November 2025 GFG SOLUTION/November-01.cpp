class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]), d[p[0]]++;
        queue<int> q;
        vector<int> r;
        for(int i = 0; i < n; i++) if(!d[i]) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop(); r.push_back(u);
            for(int v : g[u]) if(!--d[v]) q.push(v);
        }
        return r.size() == n ? r : vector<int>{};
    }
};

2)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]);
        vector<int> s(n), r;
        function<bool(int)> dfs = [&](int u) {
            if(s[u]) return s[u] == 2;
            s[u] = 1;
            for(int v : g[u]) if(!dfs(v)) return false;
            s[u] = 2; r.push_back(u);
            return true;
        };
        for(int i = 0; i < n; i++) if(!s[i] && !dfs(i)) return {};
        reverse(r.begin(), r.end());
        return r;
    }
};

3)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        vector<int> d(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]), d[p[0]]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++) if(!d[i]) pq.push(i);
        vector<int> r;
        while(!pq.empty()) {
            int u = pq.top(); pq.pop(); r.push_back(u);
            for(int v : g[u]) if(!--d[v]) pq.push(v);
        }
        return r.size() == n ? r : vector<int>{};
    }
};

4)
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(n);
        for(auto& p : prerequisites) g[p[1]].push_back(p[0]);
        vector<int> c(n), r;
        function<bool(int)> go = [&](int u) {
            c[u] = 1;
            for(int v : g[u]) 
                if(c[v] == 1 || (c[v] == 0 && !go(v))) return false;
            c[u] = 2; r.push_back(u);
            return true;
        };
        for(int i = 0; i < n; i++) if(!c[i] && !go(i)) return {};
        reverse(r.begin(), r.end());
        return r;
    }
};
