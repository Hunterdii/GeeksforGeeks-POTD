class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, w = 0, p = 0, e = 0;
        for (int s = 0; s < n; s++) {
            while (e < n && a[e] - a[s] <= k) w += a[e++];
            int r = max(0, (t - p - w) - (n - e) * (a[s] + k));
            res = min(res, p + r);
            if (e == s) e++; else w -= a[s];
            p += a[s];
        }
        return res;
    }
};

2)
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, l = 0, r = 0, w = 0, p = 0;
        while (l < n) {
            while (r < n && a[r] - a[l] <= k) w += a[r++];
            res = min(res, p + max(0, (t - p - w) - (n - r) * (a[l] + k)));
            w -= a[l], p += a[l++];
            if (r <= l && r < n) w += a[r++];
        }
        return res;
    }
};

3)
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), t = accumulate(a.begin(), a.end(), 0), res = t, p = 0, w = 0;
        deque<int> d;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= k) d.push_back(a[j]), w += a[j++];
            res = min(res, p + max(0, (t - p - w) - (n - j) * (a[i] + k)));
            if (!d.empty()) w -= d.front(), d.pop_front();
            p += a[i];
        }
        return res;
    }
};

4)
class Solution {
public:
    int minimumCoins(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<int> pf(n + 1, 0);
        for (int i = 0; i < n; i++) pf[i + 1] = pf[i] + a[i];
        int res = pf[n];
        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && a[j] - a[i] <= k) j++;
            res = min(res, pf[i] + max(0, (pf[n] - pf[j]) - (n - j) * (a[i] + k)));
        }
        return res;
    }
};
