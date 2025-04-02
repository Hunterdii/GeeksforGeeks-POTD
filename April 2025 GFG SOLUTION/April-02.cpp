//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        queue<int> q;
        
        q.push(0);
        vis[0] = true;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            res.push_back(v);
            
            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = true;
                    q.push(u);
                }
            }
        }
        return res;
    }
};

2)
class Solution {
public:
    void bfsUtil(queue<int>& q, vector<vector<int>>& adj, vector<int>& res, vector<bool>& vis) {
        if (q.empty()) return;
        int v = q.front();
        q.pop();
        res.push_back(v);
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        }
        bfsUtil(q, adj, res, vis);
    }
    
    vector<int> bfs(vector<vector<int>>& adj) {
        vector<int> res;
        vector<bool> vis(adj.size(), false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        bfsUtil(q, adj, res, vis);
        return res;
    }
};


3)
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                queue<int> q;
                q.push(i);
                vis[i] = true;
                while (!q.empty()) {
                    int v = q.front();
                    q.pop();
                    res.push_back(v);
                    for (int u : adj[v]) {
                        if (!vis[u]) {
                            vis[u] = true;
                            q.push(u);
                        }
                    }
                }
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> res;
        vector<int> vis(V, 0);
        deque<int> q;
        
        vis[0] = 1;
        q.push_back(0);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop_front();
            res.push_back(v);
            
            for (int u : adj[v]) {
                if (!vis[u]) {
                    vis[u] = 1;
                    q.push_back(u);
                }
            }
        }
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
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

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
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
