//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int lis(std::vector<int>& arr) {
        std::vector<int> ans;
        for (int num : arr) {
            auto it = std::lower_bound(ans.begin(), ans.end(), num);
            if (it == ans.end()) ans.push_back(num);
            else *it = num;
        }
        return ans.size();
    }
};

2)
class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};


3)
class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> comp;
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        for (int i = 0; i < n; i++) comp[sortedArr[i]] = i + 1;

        vector<int> segTree(n + 1, 0);

        auto query = [&](int idx) {
            int best = 0;
            while (idx > 0) {
                best = max(best, segTree[idx]);
                idx -= idx & -idx;
            }
            return best;
        };

        auto update = [&](int idx, int val) {
            while (idx <= n) {
                segTree[idx] = max(segTree[idx], val);
                idx += idx & -idx;
            }
        };

        int res = 0;
        for (int num : arr) {
            int index = comp[num];
            int best = query(index - 1) + 1;
            update(index, best);
            res = max(res, best);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
