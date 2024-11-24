//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;
        for (int u : adj[node]) {
            if (!visited[u])
                dfs(u, adj, visited);
        }
    }

    bool isConnected(vector<int> adj[], vector<int> &indegree) {
        vector<bool> visited(26, false);
        int start = -1;

        for (int i = 0; i < 26; ++i) {
            if (indegree[i] > 0) {
                start = i;
                break;
            }
        }

        if (start == -1) return true; 

        dfs(start, adj, visited);
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] > 0 && !visited[i])
                return false;
        }

        return true;
    }

    int isCircle(vector<string> &arr) {
        int N = arr.size();
        vector<int> adj[26], adjr[26];
        vector<int> indegree(26, 0), outdegree(26, 0);
        for (int i = 0; i < N; ++i) {
            int u = arr[i][0] - 'a';
            int v = arr[i].back() - 'a';
            adj[u].push_back(v);
            adjr[v].push_back(u);
            outdegree[u]++;
            indegree[v]++;
        }
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] != outdegree[i])
                return 0;
        }
        if (!isConnected(adj, indegree))
            return 0;
        if (!isConnected(adjr, outdegree))
            return 0;

        return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
