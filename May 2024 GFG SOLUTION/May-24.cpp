//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    const int MOD = 1000000007;

    int findWays(vector<int>& num, int tar) {
        int n = num.size();
        vector<int> dp(tar + 1, 0);
        
        dp[0] = 1; // Base case: there's one way to make sum 0

        for (int ind = 0; ind < n; ind++) {
            for (int target = tar; target >= num[ind]; target--) {
                dp[target] = (dp[target] + dp[target - num[ind]]) % MOD;
            }
        }
        return dp[tar];
    }

    int countPartitions(int n, int d, vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum < d || (sum - d) % 2 != 0) {
            return 0;
        }
        return findWays(arr, (sum - d) / 2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends
