//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& a) {
        int n = a.size(), ans = 0, u = 0;
        vector<bool> vis(n);
        vector<int> d(n, 1e9);
        d[0] = 0;
        for (int i = 0; i < n; ++i) {
            int m = 1e9, idx = -1;
            for (int j = 0; j < n; ++j)
                if (!vis[j] && d[j] < m) m = d[j], idx = j;
            vis[idx] = 1;
            ans += m;
            for (int j = 0; j < n; ++j)
                if (!vis[j])
                    d[j] = min(d[j], abs(a[idx][0] - a[j][0]) + abs(a[idx][1] - a[j][1]));
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends
