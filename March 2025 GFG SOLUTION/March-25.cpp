//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<int>> dpT(n, vector<int>(n, 0)), dpF(n, vector<int>(n, 0));
        for (int i = 0; i < n; i += 2) dpT[i][i] = (s[i] == 'T'), dpF[i][i] = (s[i] == 'F');
        for (int len = 2; len < n; len += 2) 
            for (int i = 0; i < n - len; i += 2) {
                int j = i + len;
                for (int k = i + 1; k < j; k += 2) {
                    int lt = dpT[i][k - 1], lf = dpF[i][k - 1], rt = dpT[k + 1][j], rf = dpF[k + 1][j];
                    if (s[k] == '&') dpT[i][j] += lt * rt, dpF[i][j] += lt * rf + lf * rt + lf * rf;
                    else if (s[k] == '|') dpT[i][j] += lt * rt + lt * rf + lf * rt, dpF[i][j] += lf * rf;
                    else dpT[i][j] += lt * rf + lf * rt, dpF[i][j] += lt * rt + lf * rf;
                }
            }
        return dpT[0][n - 1];
    }
};

2)
class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<int>> T(n, vector<int>(n)), F(n, vector<int>(n));
        for (int i = 0; i < n; i += 2) T[i][i] = s[i] == 'T', F[i][i] = s[i] == 'F';
        for (int l = 2; l < n; l += 2)
            for (int i = 0; i < n - l; i += 2) 
                for (int k = i + 1, j = i + l; k < j; k += 2) {
                    int lt = T[i][k - 1], lf = F[i][k - 1], rt = T[k + 1][j], rf = F[k + 1][j];
                    if (s[k] == '&') T[i][j] += lt * rt, F[i][j] += lt * rf + lf * rt + lf * rf;
                    else if (s[k] == '|') T[i][j] += lt * rt + lt * rf + lf * rt, F[i][j] += lf * rf;
                    else T[i][j] += lt * rf + lf * rt, F[i][j] += lt * rt + lf * rf;
                }
        return T[0][n - 1];
    }
};

3)
class Solution {
  public:
    unordered_map<string, int> dp;

    int solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) return isTrue ? (s[i] == 'T') : (s[i] == 'F');
        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.count(key)) return dp[key];

        int ways = 0;
        for (int k = i + 1; k < j; k += 2) {
            int lt = solve(s, i, k - 1, true);
            int lf = solve(s, i, k - 1, false);
            int rt = solve(s, k + 1, j, true);
            int rf = solve(s, k + 1, j, false);

            if (s[k] == '&') ways += isTrue ? lt * rt : lt * rf + lf * rt + lf * rf;
            else if (s[k] == '|') ways += isTrue ? lt * rt + lt * rf + lf * rt : lf * rf;
            else if (s[k] == '^') ways += isTrue ? lt * rf + lf * rt : lt * rt + lf * rf;
        }
        return dp[key] = ways;
    }

    int countWays(string s) {
        return solve(s, 0, s.size() - 1, true);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
