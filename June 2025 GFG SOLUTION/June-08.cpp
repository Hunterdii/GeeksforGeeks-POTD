class Solution {
  public:
    string addStrings(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int carry = 0, n = a.size(), m = b.size();
        string res = "";
        for (int i = 0; i < m; ++i) {
            int s = (a[n - 1 - i] - '0') + (b[m - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        for (int i = m; i < n; ++i) {
            int s = (a[n - 1 - i] - '0') + carry;
            res = char(s % 10 + '0') + res;
            carry = s / 10;
        }
        if (carry) res = char(carry + '0') + res;
        return res;
    }

    bool check(string &s, int i, int l1, int l2) {
        string x = s.substr(i, l1), y = s.substr(i + l1, l2);
        if ((x[0] == '0' && l1 > 1) || (y[0] == '0' && l2 > 1)) return false;
        string sum = addStrings(x, y);
        int l3 = sum.size();
        if (i + l1 + l2 + l3 > s.size()) return false;
        if (sum != s.substr(i + l1 + l2, l3)) return false;
        if (i + l1 + l2 + l3 == s.size()) return true;
        return check(s, i + l1, l2, l3);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int l1 = 1; l1 < n; ++l1)
            for (int l2 = 1; l1 + l2 < n; ++l2)
                if (check(s, 0, l1, l2)) return true;
        return false;
    }
};

2)
class Solution {
  public:
    string add(string a, string b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += sum % 10 + '0';
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(string &s, int i, string prev1, string prev2) {
        string sum = add(prev1, prev2);
        if (s.substr(i, sum.size()) != sum) return false;
        if (i + sum.size() == s.size()) return true;
        return dfs(s, i + sum.size(), prev2, sum);
    }

    bool isSumString(string &s) {
        int n = s.size();
        for (int l1 = 1; l1 < n; ++l1)
            for (int l2 = 1; l1 + l2 < n; ++l2) {
                string a = s.substr(0, l1), b = s.substr(l1, l2);
                if ((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1)) continue;
                if (dfs(s, l1 + l2, a, b)) return true;
            }
        return false;
    }
};
