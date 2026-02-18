class Solution {
    int merge(vector<int>& a, int l, int m, int r) {
        vector<int> t(a.begin() + l, a.begin() + r + 1);
        int i = 0, j = m - l + 1, k = l, cnt = 0, lsz = m - l + 1;
        while (i < lsz && j < (int)t.size())
            t[i] <= t[j] ? a[k++] = t[i++] : (cnt += lsz - i, a[k++] = t[j++]);
        while (i < lsz) a[k++] = t[i++];
        while (j < (int)t.size()) a[k++] = t[j++];
        return cnt;
    }
    int sort(vector<int>& a, int l, int r) {
        if (l >= r) return 0;
        int m = (l + r) / 2;
        return sort(a, l, m) + sort(a, m + 1, r) + merge(a, l, m, r);
    }
public:
    int inversionCount(vector<int>& arr) { return sort(arr, 0, arr.size() - 1); }
};

2)
class Solution {
    int bit[100005] = {};
    void update(int i, int n) { for (; i <= n; i += i & -i) bit[i]++; }
    int query(int i) { int s = 0; for (; i > 0; i -= i & -i) s += bit[i]; return s; }
public:
    int inversionCount(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        auto compress = [&](int x) { return lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1; };
        memset(bit, 0, sizeof(bit));
        for (int i = n - 1; i >= 0; i--) {
            int v = compress(arr[i]);
            cnt += query(v - 1);
            update(v, sorted.size());
        }
        return cnt;
    }
};

3)
class Solution {
    vector<int> seg;
    void update(int node, int s, int e, int i) {
        if (s == e) { seg[node]++; return; }
        int m = (s + e) / 2;
        i <= m ? update(2*node, s, m, i) : update(2*node+1, m+1, e, i);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
    int query(int node, int s, int e, int l, int r) {
        if (r < s || e < l) return 0;
        if (l <= s && e <= r) return seg[node];
        int m = (s + e) / 2;
        return query(2*node, s, m, l, r) + query(2*node+1, m+1, e, l, r);
    }
public:
    int inversionCount(vector<int>& arr) {
        int n = arr.size(), cnt = 0;
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();
        seg.assign(4 * m, 0);
        for (int i = 0; i < n; i++) {
            int v = lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() + 1;
            cnt += query(1, 1, m, v + 1, m);
            update(1, 1, m, v);
        }
        return cnt;
    }
};
