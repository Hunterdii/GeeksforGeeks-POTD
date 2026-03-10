class Solution {
public:
    string largestSwap(string &s) {
        int last[10];
        fill(last, last + 10, -1);
        for (int i = 0; i < (int)s.size(); i++) last[s[i] - '0'] = i;
        for (int i = 0; i < (int)s.size(); i++)
            for (int d = 9; d > s[i] - '0'; d--)
                if (last[d] > i) { swap(s[i], s[last[d]]); return s; }
        return s;
    }
};

2)
class Solution {
public:
    string largestSwap(string &s) {
        char mx = '0'; int mxi = -1, l = -1, r = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] > mx) { mx = s[i]; mxi = i; }
            else if (s[i] < mx) { l = i; r = mxi; }
        }
        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};

3)
class Solution {
public:
    string largestSwap(string &s) {
        int cnt[10] = {};
        for (char c : s) cnt[c - '0']++;
        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i] - '0']--;
            for (int d = 9; d > s[i] - '0'; d--) {
                if (!cnt[d]) continue;
                for (int j = s.size() - 1; j > i; j--) {
                    if (s[j] - '0' == d) { swap(s[i], s[j]); return s; }
                }
            }
        }
        return s;
    }
};
