class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int res = INT_MAX;
        for (int i = 0; i + m <= a.size(); i++)
            res = min(res, a[i + m - 1] - a[i]);
        return res;
    }
};

2)
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(), a.end());
        int res = a[m - 1] - a[0];
        for (int i = m; i < a.size(); i++)
            res = min(res, a[i] - a[i - m + 1]);
        return res;
    }
};

3)
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        if (m > n) return -1;
        sort(a.begin(), a.end());
        int left = 0, right = m - 1, res = INT_MAX;
        while (right < n) {
            res = min(res, a[right] - a[left]);
            left++; right++;
        }
        return res;
    }
};

4)
class Solution {
public:
    int findMinDiff(vector<int>& a, int m) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = INT_MAX;
        for (int i = 0; i <= n - m; i++)
            ans = min(ans, a[i + m - 1] - a[i]);
        return ans;
    }
};
