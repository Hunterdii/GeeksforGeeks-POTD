class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int mx = arr[0], mn = arr[0], r = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int a = mx * arr[i], b = mn * arr[i];
            mx = max({a, b, arr[i]});
            mn = min({a, b, arr[i]});
            r = max(r, mx);
        }
        return r;
    }
};

2)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), pref = 1, suff = 1, res = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (!pref) pref = 1;
            if (!suff) suff = 1;
            pref *= arr[i];
            suff *= arr[n - 1 - i];
            res = max(res, max(pref, suff));
        }
        return res;
    }
};

3)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), res = arr[0], prod = 0;
        for (int i = 0; i < n; i++) {
            prod = prod ? prod * arr[i] : arr[i];
            res = max(res, prod);
        }
        prod = 0;
        for (int i = n - 1; i >= 0; i--) {
            prod = prod ? prod * arr[i] : arr[i];
            res = max(res, prod);
        }
        return res;
    }
};

4)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int currMax = arr[0], currMin = arr[0], res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) swap(currMax, currMin);
            currMax = max(arr[i], currMax * arr[i]);
            currMin = min(arr[i], currMin * arr[i]);
            res = max(res, currMax);
        }
        return res;
    }
};

5)
class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size(), prod = 1, res = INT_MIN, cnt = 0;
        for (int i = 0; i < n; i++) {
            prod *= arr[i];
            res = max(res, prod);
            if (!arr[i]) {
                prod = 1;
                cnt = 0;
            } else if (arr[i] < 0) {
                cnt++;
            }
        }
        prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            prod *= arr[i];
            res = max(res, prod);
            if (!arr[i]) prod = 1;
        }
        return res;
    }
};
