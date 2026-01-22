class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        long long res = 0;
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || a[s.top()] > a[i])) {
                int j = s.top(); s.pop();
                int k = s.empty() ? -1 : s.top();
                res -= (long long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || a[s.top()] < a[i])) {
                int j = s.top(); s.pop();
                int k = s.empty() ? -1 : s.top();
                res += (long long)a[j] * (i - j) * (j - k);
            }
            s.push(i);
        }
        return res;
    }
};

2)
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        vector<int> lMin(n), rMin(n), lMax(n), rMax(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            lMin[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] > a[i]) s.pop();
            rMin[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            lMax[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] < a[i]) s.pop();
            rMax[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long long)a[i] * lMax[i] * rMax[i];
            res -= (long long)a[i] * lMin[i] * rMin[i];
        }
        return res;
    }
};

3)
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        auto calc = [&](bool isMax) {
            long long res = 0;
            stack<int> s;
            for (int i = 0; i <= n; i++) {
                while (!s.empty() && (i == n || (isMax ? a[s.top()] < a[i] : a[s.top()] > a[i]))) {
                    int j = s.top(); s.pop();
                    int k = s.empty() ? -1 : s.top();
                    res += (long long)a[j] * (i - j) * (j - k);
                }
                s.push(i);
            }
            return res;
        };
        return calc(true) - calc(false);
    }
};

4)
class Solution {
public:
    long long subarrayRanges(vector<int>& a) {
        int n = a.size();
        long long res = 0;
        stack<int> s;
        vector<long long> dp(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] >= a[i]) s.pop();
            int l = s.empty() ? -1 : s.top();
            dp[i] = (i - l) * (long long)a[i];
            if (!s.empty()) dp[i] += dp[l];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res -= dp[i];
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            int l = s.empty() ? -1 : s.top();
            dp[i] = (i - l) * (long long)a[i];
            if (!s.empty()) dp[i] += dp[l];
            s.push(i);
        }
        for (int i = 0; i < n; i++) res += dp[i];
        return res;
    }
};
