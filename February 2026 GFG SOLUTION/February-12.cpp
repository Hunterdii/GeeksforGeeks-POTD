class Solution {
public:
    bool check(vector<int> &a, int k, int w, int h) {
        int n = a.size();
        vector<int> add(n);
        for (int i = 0; i < n; i++) {
            int cur = a[i] + (i > 0 ? add[i - 1] : 0);
            if (i >= w) cur -= add[i - w];
            if (cur < h) {
                int need = h - cur;
                if (need > k) return false;
                k -= need;
                add[i] = (i > 0 ? add[i - 1] : 0) + need;
            } else {
                add[i] = i > 0 ? add[i - 1] : 0;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &a, int k, int w) {
        int lo = *min_element(a.begin(), a.end());
        int hi = lo + k, ans = lo;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(a, k, w, mid)) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};

2)
class Solution {
public:
    bool isPossible(vector<int> &arr, int k, int w, int maxHeight) {
        int n = arr.size();
        vector<int> water(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) water[i] = water[i - 1];
            int currHeight = arr[i] + water[i];
            if (i >= w) currHeight -= water[i - w];
            if (currHeight < maxHeight) {
                int add = maxHeight - currHeight;
                water[i] += add;
                k -= add;
                if (k < 0) return false;
            }
        }
        return true;
    }
    
    int maxMinHeight(vector<int> &arr, int k, int w) {
        int n = arr.size();
        int low = arr[0];
        for (int i = 1; i < n; i++) low = min(low, arr[i]);
        int high = low + k, ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, w, mid)) ans = max(ans, mid), low = mid + 1;
            else high = mid - 1;
        }
        return ans;
    }
};

3)
class Solution {
public:
    int maxMinHeight(vector<int> &a, int k, int w) {
        int n = a.size(), minVal = a[0];
        for (int x : a) minVal = min(minVal, x);
        int l = minVal, r = minVal + k, ans = minVal;
        while (l <= r) {
            int m = (l + r) / 2;
            vector<long long> wtr(n);
            long long used = 0, sum = 0;
            bool ok = true;
            for (int i = 0; i < n && ok; i++) {
                if (i >= w) sum -= wtr[i - w];
                long long need = max(0LL, m - a[i] - sum);
                if (used + need > k) ok = false;
                else {
                    wtr[i] = need;
                    sum += need;
                    used += need;
                }
            }
            if (ok) ans = m, l = m + 1;
            else r = m - 1;
        }
        return ans;
    }
};
