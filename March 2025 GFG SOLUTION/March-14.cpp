//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
            for (int j = coin; j <= sum; j++)
                dp[j] += dp[j - coin];
        return dp[sum];
    }
};

2)
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][sum];
    }
};

3)
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int sum) {
        if (sum == 0) return 1;
        if (i < 0 || sum < 0) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(coins, i - 1, sum) + solve(coins, i, sum - coins[i]);
    }

    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(coins, n - 1, sum);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
