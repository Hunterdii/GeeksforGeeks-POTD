class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) return h;
        }
        return 0;
    }
};

2)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), lo = 0, hi = n, ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (int c : citations) {
                if (c >= mid) cnt++;
            }
            if (cnt >= mid) ans = mid, lo = mid + 1;
            else hi = mid - 1;
        }
        return ans;
    }
};

3)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) freq[n]++;
            else freq[citations[i]]++;
        }
        int s = 0;
        for (int i = n; i >= 0; i--) {
            s += freq[i];
            if (s >= i) return i;
        }
        return 0;
    }
};

4)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1) h = i + 1;
            else break;
        }
        return h;
    }
};
