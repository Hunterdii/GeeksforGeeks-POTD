class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int l = 0, r = a.back() - a[0], ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = a[0];
            for (int i = 1; i < a.size() && cnt < k; i++)
                if (a[i] - last >= m) cnt++, last = a[i];
            cnt >= k ? ans = m, l = m + 1 : r = m - 1;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int lo = 1, hi = (a.back() - a[0]) / (k - 1), res = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int picked = 1, pos = a[0];
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - pos >= mid) {
                    picked++;
                    pos = a[i];
                    if (picked == k) break;
                }
            }
            if (picked >= k) res = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return res;
    }
};

3)
class Solution {
public:
    int maxMinDiff(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int left = 0, right = a.back() - a[0], answer = 0;
        auto canAchieve = [&](int minDiff) {
            int count = 1, lastPicked = 0;
            for (int i = 1; i < a.size(); i++) {
                if (a[i] - a[lastPicked] >= minDiff) {
                    count++;
                    lastPicked = i;
                    if (count == k) return true;
                }
            }
            return false;
        };
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAchieve(mid)) answer = mid, left = mid + 1;
            else right = mid - 1;
        }
        return answer;
    }
};
