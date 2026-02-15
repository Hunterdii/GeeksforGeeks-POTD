class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        auto canPaint = [&](int t) {
            int cnt = 1, sum = 0;
            for (int x : arr) {
                if (x > t) return false;
                if (sum + x > t) cnt++, sum = x;
                else sum += x;
            }
            return cnt <= k;
        };
        while (l < r) {
            int m = l + (r - l) / 2;
            canPaint(m) ? r = m : l = m + 1;
        }
        return l;
    }
};

2)
class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int l = 0, r = 0;
        for (int x : arr) l = max(l, x), r += x;
        while (l < r) {
            int m = l + (r - l) / 2, p = 1, s = 0;
            bool valid = true;
            for (int x : arr) {
                if (x > m) { valid = false; break; }
                s + x > m ? (p++, s = x) : (s += x);
            }
            valid && p <= k ? r = m : l = m + 1;
        }
        return l;
    }
};

3)
class Solution {
public:
    bool check(vector<int>& arr, int t, int k) {
        int p = 1, s = 0;
        for (int x : arr) {
            if (x > t) return false;
            s + x > t ? (p++, s = x) : (s += x);
        }
        return p <= k;
    }
    int solve(vector<int>& arr, int k, int l, int r) {
        if (l >= r) return l;
        int m = l + (r - l) / 2;
        return check(arr, m, k) ? solve(arr, k, l, m) : solve(arr, k, m + 1, r);
    }
    int minTime(vector<int>& arr, int k) {
        return solve(arr, k, *max_element(arr.begin(), arr.end()), 
                     accumulate(arr.begin(), arr.end(), 0));
    }
};

4)
class Solution {
public:
    int minTime(vector<int>& arr, int k) {
        int n = arr.size(), lo = 0, hi = 0;
        for (int i = 0; i < n; i++) lo = max(lo, arr[i]), hi += arr[i];
        int ans = hi;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1, painters = 1, sum = 0, i = 0;
            while (i < n && painters <= k) {
                if (arr[i] > mid) { painters = k + 1; break; }
                sum + arr[i] <= mid ? sum += arr[i++] : (painters++, sum = 0);
            }
            painters <= k ? (ans = mid, hi = mid - 1) : (lo = mid + 1);
        }
        return ans;
    }
};
