class Solution {
public:
    string maxSubseq(string &s, int k) {
        deque<char> dq;
        int toRemove = k;
        for (char c : s) {
            while (!dq.empty() && toRemove && dq.back() < c) {
                dq.pop_back();
                toRemove--;
            }
            dq.push_back(c);
        }
        string res;
        for (int i = 0; i < s.length() - k; ++i) res += dq[i];
        return res;
    }
};

2)
class Solution {
public:
    string maxSubseq(string &s, int k) {
        stack<char> st;
        int toRemove = k;
        for (char c : s) {
            while (!st.empty() && toRemove && st.top() < c) {
                st.pop();
                toRemove--;
            }
            st.push(c);
        }
        while (toRemove--) st.pop();
        string res;
        while (!st.empty()) res = st.top() + res, st.pop();
        return res;
    }
};

3)
class Solution {
public:
    string maxSubseq(string &s, int k) {
        int n = s.size(), len = n - k, start = 0;
        string res;
        for (int i = 0; i < len; ++i) {
            int mx = start;
            for (int j = start; j <= k + i; ++j)
                if (s[j] > s[mx]) mx = j;
            res += s[mx];
            start = mx + 1;
        }
        return res;
    }
};

4)
class Solution {
public:
    string maxSubseq(string &s, int k) {
        int n = s.length(), toRemove = k;
        string res;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res += c;
        }
        res.resize(n - k);
        return res;
    }
};

5)
class Solution {
public:
    string maxSubseq(string &s, int k) {
        vector<char> res;
        int toRemove = k;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res.push_back(c);
        }
        res.resize(s.length() - k);
        return string(res.begin(), res.end());
    }
};
