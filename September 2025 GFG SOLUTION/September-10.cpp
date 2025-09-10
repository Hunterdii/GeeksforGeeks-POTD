class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size(), l = -1, r = -1, maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[maxIdx]) maxIdx = i;
            else if (s[i] < s[maxIdx]) l = i, r = maxIdx;
        }
        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};


2)
class Solution {
public:
    string largestSwap(string &s) {
        vector<int> last(10, -1);
        for (int i = 0; i < s.size(); i++) last[s[i] - '0'] = i;
        for (int i = 0; i < s.size(); i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }
        return s;
    }
};
