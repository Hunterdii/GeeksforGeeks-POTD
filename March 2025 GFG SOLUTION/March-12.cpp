//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0], b = cost[1];
        for (int i = 2; i < cost.size(); i++)
            tie(a, b) = make_tuple(b, cost[i] + min(a, b));
        return min(a, b);
    }
};

2)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0], b = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int temp = b;
            b = cost[i] + min(a, b);
            a = temp;
        }
        return min(a, b);
    }
};

3)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < n; i++)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 1], dp[n - 2]);
    }
};


4)
class Solution {
  public:
    vector<int> dp;
    int solve(vector<int>& cost, int i) {
        if (i < 0) return 0;
        if (i == 0 || i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(solve(cost, i - 1), solve(cost, i - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.assign(cost.size(), -1);
        int n = cost.size();
        return min(solve(cost, n - 1), solve(cost, n - 2));
    }
};


5)
class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = 2; i < cost.size(); i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
