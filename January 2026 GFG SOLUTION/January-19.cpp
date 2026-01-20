class Solution {
public:
    string removeKdig(string &s, int k) {
        string res;
        for (char c : s) {
            while (res.size() && k && res.back() > c) {
                res.pop_back();
                k--;
            }
            if (res.size() || c != '0') res += c;
        }
        while (res.size() && k--) res.pop_back();
        return res.empty() ? "0" : res;
    }
};

2)
class Solution {
public:
    string removeKdig(string &s, int k) {
        deque<char> dq;
        for (char c : s) {
            while (!dq.empty() && k && dq.back() > c) {
                dq.pop_back();
                k--;
            }
            if (!dq.empty() || c != '0') dq.push_back(c);
        }
        while (!dq.empty() && k--) dq.pop_back();
        string res(dq.begin(), dq.end());
        return res.empty() ? "0" : res;
    }
};

3)
class Solution {
public:
    string removeKdig(string &s, int k) {
        vector<char> v;
        for (char c : s) {
            while (!v.empty() && k && v.back() > c) {
                v.pop_back();
                k--;
            }
            if (!v.empty() || c != '0') v.push_back(c);
        }
        while (!v.empty() && k--) v.pop_back();
        return v.empty() ? "0" : string(v.begin(), v.end());
    }
};

4)
class Solution {
public:
    string removeKdig(string &s, int k) {
        int w = 0;
        for (int i = 0; i < s.size(); i++) {
            while (w > 0 && k && s[w - 1] > s[i]) {
                w--;
                k--;
            }
            if (w > 0 || s[i] != '0') s[w++] = s[i];
        }
        w = max(0, w - k);
        return w ? s.substr(0, w) : "0";
    }
};
