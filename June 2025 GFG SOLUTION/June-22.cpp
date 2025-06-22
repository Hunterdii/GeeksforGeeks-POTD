class Solution {
public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.rbegin(), arr.rend());
        vector<int> dp(n, 1), parent(n, -1);
        int maxIdx = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }
        
        vector<int> result;
        for (int i = maxIdx; i != -1; i = parent[i]) {
            result.push_back(arr[i]);
        }
        return result;
    }
};
