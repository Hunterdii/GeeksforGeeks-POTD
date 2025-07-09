class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        return res;
    }
};

2)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<pair<int, long long>> st;
        long long res = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top().first] >= arr[i])) {
                int idx = st.top().first;
                long long sum = st.top().second;
                st.pop();
                int left = st.empty() ? idx + 1 : idx - st.top().first;
                int right = i - idx;
                res = (res + arr[idx] * left * right) % MOD;
            }
            if (i < n) {
                long long sum = st.empty() ? (i + 1) * arr[i] : st.top().second + (i - st.top().first) * arr[i];
                st.push({i, sum});
            }
        }
        return res;
    }
};


3)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        long long res = 0;
        
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] > arr[i])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? mid + 1 : mid - st.top();
                int right = i - mid;
                res = (res + (long long)arr[mid] * left * right) % MOD;
            }
            if (i < n) st.push(i);
        }
        return res;
    }
};


4)
class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<long long> dp(n);
        stack<int> st;
        long long res = 0;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) {
                dp[i] = (i + 1) * arr[i];
            } else {
                int j = st.top();
                dp[i] = dp[j] + (i - j) * arr[i];
            }
            st.push(i);
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};
