//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        nth_element(p.begin(), p.begin() + k, p.end(), [](auto&a, auto&b){
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
        return {p.begin(), p.begin()+k};
    }
};

2)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (auto& a : p) {
            int d = a[0] * a[0] + a[1] * a[1];
            pq.push({d, a});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (!pq.empty()) res.push_back(pq.top().second), pq.pop();
        return res;
    }
};


3)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        sort(p.begin(), p.end(), [](auto& a, auto& b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return vector<vector<int>>(p.begin(), p.begin() + k);
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
