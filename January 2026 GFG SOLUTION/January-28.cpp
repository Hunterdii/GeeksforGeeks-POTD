class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        unordered_map<int, int> lf, rf;
        function<void(int, int, int, unordered_map<int, int>&)> gen = [&](int i, int e, int s, unordered_map<int, int>& f) {
            if (i == e) { f[s]++; return; }
            gen(i + 1, e, s + arr[i], f);
            gen(i + 1, e, s, f);
        };
        gen(0, m, 0, lf);
        gen(m, n, 0, rf);
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};

2)
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        unordered_map<int, int> lf, rf;
        for (int mask = 0; mask < (1 << m); mask++) {
            int s = 0;
            for (int i = 0; i < m; i++) if (mask & (1 << i)) s += arr[i];
            lf[s]++;
        }
        for (int mask = 0; mask < (1 << (n - m)); mask++) {
            int s = 0;
            for (int i = 0; i < n - m; i++) if (mask & (1 << i)) s += arr[m + i];
            rf[s]++;
        }
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};

3)
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        map<int, int> lf, rf;
        lf[0] = 1;
        for (int i = 0; i < m; i++) {
            map<int, int> temp = lf;
            for (auto& [s, c] : lf) temp[s + arr[i]] += c;
            lf = temp;
        }
        rf[0] = 1;
        for (int i = m; i < n; i++) {
            map<int, int> temp = rf;
            for (auto& [s, c] : rf) temp[s + arr[i]] += c;
            rf = temp;
        }
        for (auto& [s, c] : lf) if (rf.count(k - s)) res += c * rf[k - s];
        return res;
    }
};

4)
class Solution {
public:
    int countSubset(vector<int>& arr, int k) {
        int n = arr.size(), m = n / 2, res = 0;
        vector<int> lv, rv;
        for (int mask = 0; mask < (1 << m); mask++) {
            int s = 0;
            for (int i = 0; i < m; i++) if (mask & (1 << i)) s += arr[i];
            lv.push_back(s);
        }
        for (int mask = 0; mask < (1 << (n - m)); mask++) {
            int s = 0;
            for (int i = 0; i < n - m; i++) if (mask & (1 << i)) s += arr[m + i];
            rv.push_back(s);
        }
        sort(rv.begin(), rv.end());
        for (int s : lv) {
            int t = k - s;
            res += upper_bound(rv.begin(), rv.end(), t) - lower_bound(rv.begin(), rv.end(), t);
        }
        return res;
    }
};
