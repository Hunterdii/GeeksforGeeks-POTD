class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        vector<int> left(n), right(n), st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] >= arr[i]) st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.back()] > arr[i]) st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }
        for (int i = 0; i < n; i++)
            res = (res + (long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        return res;
    }
};

2)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 0), right(n), st;
        for (int i = 0; i < n; i++) right[i] = i;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] < arr[st.back()]) {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int r = right[i];
            dp[i] = r == i ? (n - i) * arr[i] : (r - i) * arr[i] + dp[r];
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};

3)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        vector<pair<int,int>> st;
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[i] < st.back().first)) {
                auto [val, idx] = st.back();
                st.pop_back();
                int left = st.empty() ? -1 : st.back().second;
                res = (res + (long)val * (idx - left) * (i - idx)) % mod;
            }
            if (i < n) st.push_back({arr[i], i});
        }
        return res;
    }
};

4)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size(), mod = 1e9 + 7;
        long res = 0;
        
        for (int i = 0; i < n; i++) {
            int minVal = arr[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, arr[j]);
                res = (res + minVal) % mod;
            }
        }
        
        return res;
    }
};
