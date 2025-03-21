//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int prev2 = 0, prev1 = 0;
        for (int num : arr) {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};

2)
class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        vector<int> dp(n, 0);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], arr[i] + dp[i-2]);
        }
        return dp[n-1];
    }
};

3)
class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& arr, int index) {
        if (index < 0) return 0;
        if (dp[index] != -1) return dp[index];
        return dp[index] = max(solve(arr, index - 1), arr[index] + solve(arr, index - 2));
    }

    int findMaxSum(vector<int>& arr) {
        dp.assign(arr.size(), -1);
        return solve(arr, arr.size() - 1);
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
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
