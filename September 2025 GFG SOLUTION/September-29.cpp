class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        deque<int> dq;
        for (int i = a; i <= n; i++) {
            int left = i - b, right = i - a;
            while (!dq.empty() && dq.front() < left) dq.pop_front();
            while (!dq.empty() && pre[dq.back()] >= pre[right]) dq.pop_back();
            dq.push_back(right);
            res = max(res, pre[i] - pre[dq.front()]);
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size();
        for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
        int res = arr[a - 1];
        multiset<int> s;
        s.insert(0);
        for (int i = a; i < n; i++) {
            if (i >= b) s.erase(s.find(i - b - 1 >= 0 ? arr[i - b - 1] : 0));
            s.insert(i - a >= 0 ? arr[i - a] : 0);
            res = max(res, arr[i] - *s.begin());
        }
        return res;
    }
};

3)
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];
        deque<int> dq;
        for (int i = a; i <= n; i++) {
            int l = max(0, i - b), r = i - a;
            while (!dq.empty() && pre[dq.back()] >= pre[r]) dq.pop_back();
            dq.push_back(r);
            while (!dq.empty() && dq.front() < l) dq.pop_front();
            res = max(res, pre[i] - pre[dq.front()]);
        }
        return res;
    }
};

4)
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), ans = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        deque<pair<int, int>> dq;
        dq.push_back({0, 0});
        for (int i = a; i <= n; i++) {
            while (!dq.empty() && dq.front().second < i - b) dq.pop_front();
            ans = max(ans, p[i] - dq.front().first);
            if (i < n) {
                while (!dq.empty() && dq.back().first >= p[i - a + 1]) dq.pop_back();
                dq.push_back({p[i - a + 1], i - a + 1});
            }
        }
        return ans;
    }
};

5)
class Solution {
    vector<int> seg;
    void build(vector<int>& p, int i, int l, int r) {
        if (l == r) { seg[i] = p[l]; return; }
        int m = (l + r) / 2;
        build(p, 2 * i, l, m);
        build(p, 2 * i + 1, m + 1, r);
        seg[i] = min(seg[2 * i], seg[2 * i + 1]);
    }
    int query(int i, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return INT_MAX;
        if (ql <= l && r <= qr) return seg[i];
        int m = (l + r) / 2;
        return min(query(2 * i, l, m, ql, qr), query(2 * i + 1, m + 1, r, ql, qr));
    }
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), ans = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        seg.resize(4 * (n + 1));
        build(p, 1, 0, n);
        for (int i = a; i <= n; i++) {
            int minPre = query(1, 0, n, max(0, i - b), i - a);
            ans = max(ans, p[i] - minPre);
        }
        return ans;
    }
};

6)
class Solution {
public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        int n = arr.size(), res = INT_MIN;
        vector<int> p(n + 1);
        for (int i = 0; i < n; i++) p[i + 1] = p[i] + arr[i];
        for (int len = a; len <= b; len++) {
            for (int i = 0; i + len <= n; i++) {
                res = max(res, p[i + len] - p[i]);
            }
        }
        return res;
    }
};
