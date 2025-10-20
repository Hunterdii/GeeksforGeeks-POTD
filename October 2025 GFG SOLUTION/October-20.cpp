class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> p(n);
        for (int i = 0; i < n; i++) p[i] = {arr[i], i};
        sort(p.begin(), p.end());
        vector<long> c(n + 1);
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) 
                c[i] += c[j] * c[i - j - 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[p[i].second] = c[i] * c[n - i - 1];
        return res;
    }
};

2)
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> idx(n);
        for (int i = 0; i < n; i++) idx[i] = {arr[i], i};
        sort(idx.begin(), idx.end());
        vector<long> f(2 * n + 1);
        f[0] = 1;
        for (int i = 1; i <= 2 * n; i++) f[i] = f[i - 1] * i;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long left = f[2 * i] / (f[i] * f[i + 1]);
            long right = f[2 * (n - i - 1)] / (f[n - i - 1] * f[n - i]);
            ans[idx[i].second] = left * right;
        }
        return ans;
    }
};

3)
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int>, int> m;
        for (int i = 0; i < n; i++) m[{arr[i], i}] = i;
        sort(arr.begin(), arr.end());
        unordered_map<int,long> cat;
        function<long(int)> getCat = [&](int x) {
            if (x <= 1) return 1L;
            if (cat.count(x)) return cat[x];
            long val = 0;
            for (int i = 0; i < x; i++) val += getCat(i) * getCat(x - i - 1);
            return cat[x] = val;
        };
        vector<int> res(n);
        int pos = 0;
        for (auto& [p, idx] : m) {
            res[idx] = getCat(pos) * getCat(n - pos - 1);
            pos++;
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) { return arr[i] < arr[j]; });
        auto catalan = [](int k) {
            if (k <= 1) return 1L;
            long c = 1;
            for (int i = 0; i < k; i++) c = c * (2 * k - i) / (i + 1);
            return c / (k + 1);
        };
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[ord[i]] = catalan(i) * catalan(n - i - 1);
        return res;
    }
};
