class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length(), j = 0;
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else if (j) j = lps[j - 1];
            else i++;
        }
        return lps[n - 1];
    }
};

2)
class Solution {
public:
    int getLPSLength(string &s) {
        int b1 = 31, b2 = 37, m1 = 1e9+7, m2 = 1e9+9, n = s.size();
        long long p1 = 1, p2 = 1, h1 = 0, h2 = 0, r1 = 0, r2 = 0;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            h1 = (h1 + (s[i] - 'a' + 1) * p1) % m1;
            h2 = (h2 + (s[i] - 'a' + 1) * p2) % m2;
            r1 = (r1 * b1 + s[n - i - 1] - 'a' + 1) % m1;
            r2 = (r2 * b2 + s[n - i - 1] - 'a' + 1) % m2;
            if (h1 == r1 && h2 == r2) res = i + 1;
            p1 = p1 * b1 % m1;
            p2 = p2 * b2 % m2;
        }
        return res;
    }
};

3)
class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length();
        for (int len = n - 1; len > 0; len--) {
            bool match = true;
            for (int i = 0; i < len; i++) {
                if (s[i] != s[n - len + i]) {
                    match = false;
                    break;
                }
            }
            if (match) return len;
        }
        return 0;
    }
};

4)
class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        int maxLPS = 0;
        for (int i = 1; i < n; i++) {
            if (i + z[i] == n) maxLPS = max(maxLPS, z[i]);
        }
        return maxLPS;
    }
};
