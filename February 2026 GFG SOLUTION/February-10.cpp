class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        int l = 1, r = *max_element(arr.begin(), arr.end()), ans = r;
        while (l <= r) {
            int m = l + (r - l) / 2, h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) ans = m, r = m - 1;
            else l = m + 1;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int kokoEat(vector<int>& arr, int k) {
        long long sum = 0;
        int mx = 0;
        for (int x : arr) sum += x, mx = max(mx, x);
        int l = (sum + k - 1) / k, r = mx;
        while (l < r) {
            int m = l + (r - l) / 2;
            long long h = 0;
            for (int x : arr) h += (x + m - 1) / m;
            if (h <= k) r = m;
            else l = m + 1;
        }
        return l;
    }
};
