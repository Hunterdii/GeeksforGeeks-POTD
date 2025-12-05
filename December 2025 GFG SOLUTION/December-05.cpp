class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        int m1 = 0, m2 = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            int nm1 = INT_MAX, nm2 = INT_MAX, nidx = -1;
            for (int j = 0; j < m; j++) {
                int c = costs[i][j] + (j == idx ? m2 : m1);
                if (c < nm1) { nm2 = nm1; nm1 = c; nidx = j; }
                else if (c < nm2) nm2 = c;
            }
            m1 = nm1; m2 = nm2; idx = nidx;
        }
        return m1;
    }
};

2)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<int> dp = costs[0];
        for (int i = 1; i < n; i++) {
            int min1 = *min_element(dp.begin(), dp.end());
            int minIdx = min_element(dp.begin(), dp.end()) - dp.begin();
            int min2 = INT_MAX;
            for (int j = 0; j < m; j++) if (j != minIdx) min2 = min(min2, dp[j]);
            vector<int> ndp(m);
            for (int j = 0; j < m; j++) ndp[j] = costs[i][j] + (j == minIdx ? min2 : min1);
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};

3)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) dp[0][j] = costs[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (k != j) dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

4)
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<int> prev = costs[0];
        for (int i = 1; i < n; i++) {
            vector<int> left(m), right(m), curr(m);
            left[0] = prev[0];
            for (int j = 1; j < m; j++) left[j] = min(left[j-1], prev[j]);
            right[m-1] = prev[m-1];
            for (int j = m-2; j >= 0; j--) right[j] = min(right[j+1], prev[j]);
            for (int j = 0; j < m; j++) {
                int minVal = INT_MAX;
                if (j > 0) minVal = min(minVal, left[j-1]);
                if (j < m-1) minVal = min(minVal, right[j+1]);
                curr[j] = costs[i][j] + minVal;
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
