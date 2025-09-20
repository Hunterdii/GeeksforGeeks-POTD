class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n = a.size(), res = 0;
        vector<int> l(n, -1), r(n, n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            if (!s.empty()) r[i] = s.top();
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] <= a[i]) s.pop();
            if (!s.empty()) l[i] = s.top();
            s.push(i);
            int len = r[i] - l[i] - 1;
            if (len >= a[i]) res = max(res, len);
        }
        return res;
    }
};
