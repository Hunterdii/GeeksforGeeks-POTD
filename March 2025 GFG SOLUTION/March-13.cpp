//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<int> dp(W + 1);
        for (int i = 0; i < wt.size(); i++)
            for (int j = W; j >= wt[i]; j--)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        return dp[W];
    }
};

2)
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1));

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= W; j++) 
                dp[i][j] = (wt[i - 1] <= j) 
                          ? max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]) 
                          : dp[i - 1][j];

        return dp[n][W];
    }
};

3)
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int> &val, vector<int> &wt, int i, int W) {
        if (i < 0 || W == 0) return 0;
        if (dp[i][W] != -1) return dp[i][W];

        int pick = (wt[i] <= W) ? val[i] + solve(val, wt, i - 1, W - wt[i]) : 0;
        int notPick = solve(val, wt, i - 1, W);

        return dp[i][W] = max(pick, notPick);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        dp.assign(wt.size(), vector<int>(W + 1, -1));
        return solve(val, wt, wt.size() - 1, W);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
