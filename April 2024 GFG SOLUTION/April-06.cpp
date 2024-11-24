//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
1)
class Solution {
public:
    long long countWays(int n) {
        static vector<long long> dp = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
        if (n <= 10) return dp[n];
        return 1 + (n / 2);
    }
};
2)
class Solution {
  public:
    long long countWays(int n) {
        long long dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + (i % 2 == 0 ? 1 : 0);
        }
        return dp[n];
    }
};
3)
class Solution {
  public:
    long long countWays(int n) {
      return 1+(n/2);
    }
};
4)
class Solution {
  public:
    long long countWays(int n) {
        long long ways = 1 + (n / 2);
        return ways;
    }
};
5)
class Solution {
public:
    long long countWays(int n) {
        if (n <= 1) return 1;
        return 1 + countWays(n - 2);
    }
};

//{ Driver Code Starts.
int main() {
    // taking count of testcases
    int t;
    cin >> t;

    while (t--) {
        // taking stair count
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countWays(n) << endl; // Print the output from our pre computed array
    }
    return 0;
}
// } Driver Code Ends
