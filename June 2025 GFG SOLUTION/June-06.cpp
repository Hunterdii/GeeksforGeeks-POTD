class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int d = 256, q = 101, m = pat.length(), n = txt.length();
        int ph = 0, th = 0, h = 1;
        vector<int> res;
        for (int i = 0; i < m - 1; i++) h = (h * d) % q;
        for (int i = 0; i < m; i++) {
            ph = (d * ph + pat[i]) % q;
            th = (d * th + txt[i]) % q;
        }
        for (int i = 0; i <= n - m; i++) {
            if (ph == th) {
                bool match = true;
                for (int j = 0; j < m; j++)
                    if (txt[i + j] != pat[j]) { match = false; break; }
                if (match) res.push_back(i + 1);
            }
            if (i < n - m) {
                th = (d * (th - txt[i] * h) + txt[i + m]) % q;
                if (th < 0) th += q;
            }
        }
        return res;
    }
};

// 2) ### ⚠️ Warning: TLE on Large Inputs
// #### ✅ Test Cases Passed: 1111 / 1115
// ##### ❌ Result: Time Limit Exceeded (TLE) 

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int m = pat.length(), n = txt.length();
        vector<int> res;
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && txt[i + j] == pat[j]) j++;
            if (j == m) res.push_back(i + 1);
        }
        return res;
    }
};
