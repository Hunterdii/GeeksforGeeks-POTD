struct Manacher {
    vector<int> d;
    Manacher(const string &s) {
        string t = "@";
        for (char c : s) t += "#", t += c;
        t += "#$";
        int n = t.size(), l = 0, r = 0;
        d.assign(n, 0);
        for (int i = 1; i < n - 1; i++) {
            if (i < r) d[i] = min(r - i, d[l + r - i]);
            while (t[i - d[i] - 1] == t[i + d[i] + 1]) d[i]++;
            if (i + d[i] > r) l = i - d[i], r = i + d[i];
        }
    }
    int get(int i) { return d[2 * i + 2]; }
};

class Solution {
public:
    int maxSum(string s) {
        int n = s.size();
        Manacher M(s);
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) {
            int len = M.get(i);
            L[i + len / 2] = max(L[i + len / 2], len);
            R[i - len / 2] = max(R[i - len / 2], len);
        }
        for (int i = n - 2; i >= 0; i--) L[i] = max(L[i], L[i + 1] - 2);
        for (int i = 1; i < n; i++) L[i] = max(L[i], L[i - 1]);
        for (int i = 1; i < n; i++) R[i] = max(R[i], R[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) R[i] = max(R[i], R[i + 1]);
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, L[i] + R[i + 1]);
        return ans;
    }
};

2)
class Solution {
public:
    int maxSum(string s) {
        int n = s.size();
        vector<int> L(n, 1), R(n, 1);
        for (int c = 0; c < n; c++) {
            int l = c, r = c;
            while (l >= 0 && r < n && s[l] == s[r]) {
                L[r] = max(L[r], r - l + 1);
                R[l] = max(R[l], r - l + 1);
                l--; r++;
            }
        }
        for (int i = n - 2; i >= 0; i--) L[i] = max(L[i], L[i + 1] - 2);
        for (int i = 1; i < n; i++) L[i] = max(L[i], L[i - 1]);
        for (int i = 1; i < n; i++) R[i] = max(R[i], R[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) R[i] = max(R[i], R[i + 1]);
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, L[i] + R[i + 1]);
        return ans;
    }
};

3)
class Solution {
public:
    int maxSum(string& s) {
        int n = s.size();
        vector<int> left(n, 1), right(n, 1), rad(n);
        
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(rad[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            rad[i] = k--;
            if (i + k > r) l = i - k, r = i + k;
        }
        
        for (int i = 0; i < n; i++) {
            int len = rad[i] * 2 - 1;
            int end = i + rad[i] - 1;
            if (end < n) left[end] = max(left[end], len);
        }
        
        for (int i = n - 2; i >= 0; i--) left[i] = max(left[i], left[i + 1] - 2);
        for (int i = 1; i < n; i++) left[i] = max(left[i], left[i - 1]);
        
        for (int i = n - 1; i >= 0; i--) {
            int len = rad[i] * 2 - 1;
            int start = i - rad[i] + 1;
            if (start >= 0) right[start] = max(right[start], len);
        }
        
        for (int i = 1; i < n; i++) right[i] = max(right[i], right[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) right[i] = max(right[i], right[i + 1]);
        
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, left[i] + right[i + 1]);
        return ans;
    }
};
