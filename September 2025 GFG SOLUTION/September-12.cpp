class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        int ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] >= k) {
                int mn = min(a[0] + k, a[i] - k);
                int mx = max(a[n-1] - k, a[i-1] + k);
                ans = min(ans, mx - mn);
            }
        }
        return ans;
    }
};

2)
class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), diff = a[n-1] - a[0];
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - k < 0) continue;
            int maxVal = max(a[i] + k, a[n-1] - k);
            int minVal = min(a[0] + k, a[i+1] - k);
            diff = min(diff, maxVal - minVal);
        }
        return diff;
    }
};

3)
class Solution {
public:
    int getMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < k) continue;
            ans = min(ans, max(a[i-1] + k, a[n-1] - k) - min(a[0] + k, a[i] - k));
        }
        return ans;
    }
};
