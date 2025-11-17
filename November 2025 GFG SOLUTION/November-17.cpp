class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[i] = max(dp[i], dp[j] + arr[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        map<int, int> mp;
        int ans = 0;
        for (int x : arr) {
            auto it = mp.lower_bound(x);
            int best = 0;
            if (it != mp.begin()) best = prev(it)->second;
            int sum = best + x;
            if (mp[x] < sum) {
                mp[x] = sum;
                auto nxt = mp.upper_bound(x);
                while (nxt != mp.end() && nxt->second <= sum)
                    nxt = mp.erase(nxt);
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};

3)
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int n = sorted.size();
        vector<int> bit(n + 1, 0);
        auto update = [&](int i, int val) {
            for (i++; i <= n; i += i & -i)
                bit[i] = max(bit[i], val);
        };
        auto query = [&](int i) {
            int res = 0;
            for (i++; i > 0; i -= i & -i)
                res = max(res, bit[i]);
            return res;
        };
        int ans = 0;
        for (int x : arr) {
            int idx = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
            int sum = query(idx - 1) + x;
            update(idx, sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};

4)
class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        vector<int> vals = arr;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        vector<int> seg(4 * m, 0);
        function<void(int, int, int, int, int)> update = [&](int idx, int l, int r, int pos, int value) {
            if (l == r) {
                seg[idx] = max(seg[idx], value);
                return;
            }
            int mid = (l + r) / 2;
            if (pos <= mid)
                update(idx * 2, l, mid, pos, value);
            else
                update(idx * 2 + 1, mid + 1, r, pos, value);
            seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
        };
        function<int(int, int, int, int, int)> query = [&](int idx, int l, int r, int ql, int qr) {
            if (qr < l || ql > r) return 0;
            if (ql <= l && r <= qr) return seg[idx];
            int mid = (l + r) / 2;
            return max(
                query(idx * 2, l, mid, ql, qr),
                query(idx * 2 + 1, mid + 1, r, ql, qr)
            );
        };
        int ans = 0;
        for (int x : arr) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            int sum = query(1, 0, m - 1, 0, idx - 1) + x;
            update(1, 0, m - 1, idx, sum);
            ans = max(ans, sum);
        }
        return ans;
    }
};
