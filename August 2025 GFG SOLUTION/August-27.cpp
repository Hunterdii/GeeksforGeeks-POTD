class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int c = 0, n = a.size();
        for (int k = n - 1; k >= 2; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (a[i] + a[j] > a[k]) {
                    c += j - i;
                    --j;
                } else ++i;
            }
        }
        return c;
    }
};

2)
class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 2; i < a.size(); ++i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (a[l] + a[r] > a[i]) {
                    res += r - l;
                    --r;
                } else ++l;
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int countTriangles(vector<int>& a) {
        sort(a.begin(), a.end());
        int cnt = 0, n = a.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                int sum = a[i] + a[j];
                int k = upper_bound(a.begin() + j + 1, a.end(), sum - 1) - a.begin();
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
};

4)
class Solution {
public:
    int countTriangles(vector<int>& a) {
        int cnt = 0, n = a.size();
        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    if (a[i] + a[j] > a[k] && 
                        a[i] + a[k] > a[j] && 
                        a[j] + a[k] > a[i]) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
