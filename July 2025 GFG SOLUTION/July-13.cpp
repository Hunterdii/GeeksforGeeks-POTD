class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int idx = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                *it = x;
                sums[idx] = (idx ? sums[idx - 1] : 0) + x;
            }
        }
        return total - sums.back();
    }
};

2)
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> tails, prefixSum;
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int x : arr) {
            auto it = lower_bound(tails.begin(), tails.end(), x);
            int pos = it - tails.begin();
            if (it == tails.end()) {
                tails.push_back(x);
                prefixSum.push_back((prefixSum.empty() ? 0 : prefixSum.back()) + x);
            } else {
                tails[pos] = x;
                prefixSum[pos] = (pos ? prefixSum[pos - 1] : 0) + x;
            }
        }
        return total - prefixSum.back();
    }
};

3)
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), minSum(n);
        int total = accumulate(arr.begin(), arr.end(), 0);
        for (int i = 0; i < n; i++) {
            minSum[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    minSum[i] = minSum[j] + arr[i];
                } else if (arr[j] < arr[i] && dp[j] + 1 == dp[i]) {
                    minSum[i] = min(minSum[i], minSum[j] + arr[i]);
                }
            }
        }
        int maxLen = *max_element(dp.begin(), dp.end());
        int minLisSum = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                minLisSum = min(minLisSum, minSum[i]);
            }
        }
        return total - minLisSum;
    }
};

4)
class Solution {
public:
    int nonLisMaxSum(vector<int>& arr) {
        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        
        vector<int> dp, sums;
        int total = accumulate(arr.begin(), arr.end(), 0);
        
        for (int x : arr) {
            auto it = lower_bound(dp.begin(), dp.end(), x);
            int pos = it - dp.begin();
            if (it == dp.end()) {
                dp.push_back(x);
                sums.push_back((sums.empty() ? 0 : sums.back()) + x);
            } else {
                dp[pos] = x;
                sums[pos] = (pos ? sums[pos - 1] : 0) + x;
            }
        }
        
        return total - sums.back();
    }
};
