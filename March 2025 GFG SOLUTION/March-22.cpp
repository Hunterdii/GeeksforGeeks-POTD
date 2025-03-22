//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxVal(int x, int y, vector<int>& arr) {
        int prev2 = arr[x], prev1 = max(arr[x], arr[x + 1]);
        for (int j = x + 2; j <= y; j++) {
            int curr = max(arr[j] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int maxValue(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];
        return max(maxVal(0, n - 2, arr), maxVal(1, n - 1, arr));
    }
};

2)
class Solution {
public:
    int maxVal(int x, int y, vector<int>& arr) {
        int a = arr[x], b = max(arr[x], arr[x + 1]);
        for (int j = x + 2; j <= y; j++) tie(a, b) = make_pair(b, max(arr[j] + a, b));
        return b;
    }

    int maxValue(vector<int>& arr) {
        return arr.size() == 1 ? arr[0] : max(maxVal(0, arr.size() - 2, arr), maxVal(1, arr.size() - 1, arr));
    }
};


3)
class Solution {
public:
    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto robRange = [&](int l, int r) {
            int prev2 = 0, prev1 = 0;
            for (int i = l; i <= r; i++) {
                int curr = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = curr;
            }
            return prev1;
        };

        return max(robRange(0, n - 2), robRange(1, n - 1));
    }
};

4)
class Solution {
public:
    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        auto robRange = [&](int l, int r) {
            vector<int> dp(r - l + 2, 0);
            dp[1] = nums[l];

            for (int i = l + 1; i <= r; i++) {
                dp[i - l + 1] = max(dp[i - l], dp[i - l - 1] + nums[i]);
            }
            return dp.back();
        };

        return max(robRange(0, n - 2), robRange(1, n - 1));
    }
};


5)
class Solution {
public:
    int robRange(vector<int>& nums, int i, int r, vector<int>& dp) {
        if (i > r) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(robRange(nums, i + 1, r, dp), nums[i] + robRange(nums, i + 2, r, dp));
    }

    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        return max(robRange(nums, 0, n - 2, dp1), robRange(nums, 1, n - 1, dp2));
    }
};

6)
class Solution {
public:
    int rob(vector<int>& nums, int l, int r) {
        if (l > r) return 0;
        vector<int> dp(nums.size(), 0);
        dp[l] = nums[l];
        if (l + 1 <= r) dp[l + 1] = max(nums[l], nums[l + 1]);
        for (int i = l + 2; i <= r; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[r];
    }
    
    int maxValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
