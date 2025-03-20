//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (!n) return 0;
        vector<int> l(n), r(n);
        int mn = p[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, p[i]);
            l[i] = max(l[i - 1], p[i] - mn);
        }
        int mx = p[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, p[i]);
            r[i] = max(r[i + 1], mx - p[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, l[i] + r[i]);
        return ans;
    }
};

2)
class Solution {
  public:
    int maxProfit(vector<int>& a) {
        int b1 = INT_MAX, s1 = 0, b2 = INT_MAX, s2 = 0;
        for (int p : a) {
            b1 = min(b1, p);
            s1 = max(s1, p - b1);
            b2 = min(b2, p - s1);
            s2 = max(s2, p - b2);
        }
        return s2;
    }
};


3)
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int t = 1; t <= 2; t++) {
            int maxDiff = -prices[0];
            for (int d = 1; d < prices.size(); d++) {
                dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t-1][d] - prices[d]);
            }
        }
        return dp[2][prices.size()-1];
    }
};


4)
class Solution {
  public:
    int dp[100005][3][2];

    int solve(vector<int>& prices, int i, int t, int h) {
        if (i == prices.size() || t == 0) return 0;
        if (dp[i][t][h] != -1) return dp[i][t][h];

        int doNothing = solve(prices, i + 1, t, h);
        int doTrade = h ? (prices[i] + solve(prices, i + 1, t - 1, 0)) : (-prices[i] + solve(prices, i + 1, t, 1));

        return dp[i][t][h] = max(doNothing, doTrade);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 2, 0);
    }
};


5)
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0);
        
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }
        
        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }

        for (int i = 0; i < n; i++)
            maxProfit = max(maxProfit, left[i] + right[i]);

        return maxProfit;
    }
};


6)
class Solution {
  public:
    int maxProfit(vector<int>& a) {
        int b1 = 1e9, s1 = 0, b2 = 1e9, s2 = 0;
        for (int p : a)
            b1 = min(b1, p), s1 = max(s1, p - b1), b2 = min(b2, p - s1), s2 = max(s2, p - b2);
        return s2;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
