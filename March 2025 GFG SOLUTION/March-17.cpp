//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int num : arr)
            for (int j = sum; j >= num; --j)
                dp[j] = dp[j] || dp[j - num];
        return dp[sum];
    }
};


2)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= n; i++) dp[i][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= arr[i - 1]) 
                    dp[i][j] = dp[i][j] || dp[i - 1][j - arr[i - 1]];
            }
        }
        return dp[n][sum];
    }
};


3)
class Solution {
  public:
    vector<vector<int>> dp;
    bool solve(vector<int>& arr, int i, int sum) {
        if (sum == 0) return true;
        if (i < 0 || sum < 0) return false;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(arr, i - 1, sum) || solve(arr, i - 1, sum - arr[i]);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(arr, n - 1, sum);
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
