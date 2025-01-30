//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n < 4 && n != 1) return {};
        vector<vector<int>> res;
        vector<int> row(n);

        auto solve = [&](auto&& self, int c, int cols, int d1, int d2) -> void {
            if (c == n) { res.push_back(row); return; }
            for (int r = 0, pos = 1; r < n; ++r, pos <<= 1) 
                if (!(cols & pos || d1 & (pos << c) || d2 & (pos << (n - 1 - c)))) 
                    row[c] = r + 1, self(self, c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)));
        };

        solve(solve, 0, 0, 0, 0);
        return res;
    }
};

2)
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n == 2 || n == 3) return {};
        vector<vector<int>> result;
        vector<int> row(n);

        auto solve = [&](auto&& self, int c, int cols, int d1, int d2) -> void {
            if (c == n) { result.push_back(row); return; }
            for (int pos = ((1 << n) - 1) & ~(cols | d1 | d2); pos; pos &= pos - 1) {
                int r = __builtin_ctz(pos);
                row[c] = r + 1;
                self(self, c + 1, cols | (1 << r), (d1 | (1 << r)) << 1, (d2 | (1 << r)) >> 1);
            }
        };

        solve(solve, 0, 0, 0, 0);
        return result;
    }
};

3)
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n == 2 || n == 3) return {};
        vector<vector<int>> result;
        vector<int> row(n);

        function<void(int, vector<bool>&, vector<bool>&, vector<bool>&)> solve = [&](int c, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2) {
            if (c == n) { result.push_back(row); return; }
            for (int r = 0; r < n; r++) {
                if (cols[r] || d1[c - r + n - 1] || d2[c + r]) continue;
                row[c] = r + 1;
                cols[r] = d1[c - r + n - 1] = d2[c + r] = true;
                solve(c + 1, cols, d1, d2);
                cols[r] = d1[c - r + n - 1] = d2[c + r] = false;
            }
        };

        vector<bool> cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
        solve(0, cols, d1, d2);
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
