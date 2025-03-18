//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : arr)
            for (int j = target; j >= num; --j)
                dp[j] = dp[j] || dp[j - num];
        return dp[target];
    }
};

2)
class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2;
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= arr[i-1]) dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
            }
        }
        return dp[n][target];
    }
};


3)
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(vector<int>& arr, int i, int target) {
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        if (dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = solve(arr, i - 1, target) || solve(arr, i - 1, target - arr[i]);
    }

    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        int target = sum / 2, n = arr.size();
        dp.assign(n, vector<int>(target + 1, -1));
        return solve(arr, n - 1, target);
    }
};


4)
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(vector<int>& arr, int i, int sum) {
        if (sum == 0) return true;
        if (i < 0 || sum < 0) return false;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(arr, i - 1, sum) || solve(arr, i - 1, sum - arr[i]);
    }

    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 2) return false;
        dp.assign(arr.size(), vector<int>(sum / 2 + 1, -1));
        return solve(arr, arr.size() - 1, sum / 2);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
