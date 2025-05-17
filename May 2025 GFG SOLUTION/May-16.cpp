//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    struct Node {
        int v, r, c;
        bool operator>(const Node& o) const { return v > o.v; }
    };
    vector<int> findSmallestRange(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size(), hi = INT_MIN, lo = 0, r = 1e9;
        priority_queue<Node, vector<Node>, greater<Node>> q;
        for (int i = 0; i < n; i++) q.push({a[i][0], i, 0}), hi = max(hi, a[i][0]);
        while (1) {
            auto x = q.top(); q.pop();
            if (hi - x.v < r - lo) lo = x.v, r = hi;
            if (x.c + 1 == m) break;
            int y = a[x.r][x.c + 1];
            q.push({y, x.r, x.c + 1});
            hi = max(hi, y);
        }
        return {lo, r};
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
