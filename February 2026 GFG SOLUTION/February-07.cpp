class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), sum = 0, val = 0, res;
        for (int i = 0; i < n; i++) sum += arr[i], val += i * arr[i];
        res = val;
        for (int i = 1; i < n; i++) {
            val += sum - n * arr[n - i];
            res = max(res, val);
        }
        return res;
    }
};

2)
class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), total = accumulate(arr.begin(), arr.end(), 0);
        int curr = 0, res;
        for (int i = 0; i < n; i++) curr += i * arr[i];
        res = curr;
        for (int i = 0; i < n - 1; i++) {
            curr = curr + total - n * arr[n - 1 - i];
            res = max(res, curr);
        }
        return res;
    }
};

3)
class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size(), s = 0, v = 0;
        for (int i = 0; i < n; i++) s += arr[i], v += i * arr[i];
        int mx = v;
        for (int i = n - 1; i > 0; i--) {
            v += s - n * arr[i];
            mx = max(mx, v);
        }
        return mx;
    }
};
