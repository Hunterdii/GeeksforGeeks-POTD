//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V), result;
        stack<int> s;
        s.push(0);
        while (!s.empty()) {
            int node = s.top(); s.pop();
            if (!visited[node]) {
                visited[node] = 1;
                result.push_back(node);
                for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it)
                    if (!visited[*it]) s.push(*it);
            }
        }
        return result;
    }
};

2)
class Solution {
public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int v = st.top();
                    st.pop();
                    if (!vis[v]) {
                        vis[v] = true;
                        res.push_back(v);
                        for (int j = adj[v].size() - 1; j >= 0; j--) {
                            int u = adj[v][j];
                            if (!vis[u])
                                st.push(u);
                        }
                    }
                }
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    void dfsUtil(int v, vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis) {
        vis[v] = true;
        res.push_back(v);
        for (int u : adj[v]) {
            if (!vis[u])
                dfsUtil(u, adj, res, vis);
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfsUtil(i, adj, res, vis);
        }
        return res;
    }
};


4)
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res, vis(V, 0);
        function<void(int)> traverse = [&](int v) {
            vis[v] = 1;
            res.push_back(v);
            for (int u : adj[v])
                if (!vis[u]) traverse(u);
        };
        for (int i = 0; i < V; i++)
            if (!vis[i]) traverse(i);
        return res;
    }
};


5)
class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> res, vis(adj.size());
        function<void(int)> dfs = [&](int v) {
            vis[v] = 1, res.push_back(v);
            for (int u : adj[v]) if (!vis[u]) dfs(u);
        };
        for (int i = 0; i < adj.size(); i++) if (!vis[i]) dfs(i);
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
