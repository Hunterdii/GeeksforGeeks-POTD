class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.length() - 1, j = tar.length() - 1;
        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i--; j--;
            } else {
                i -= 2;
            }
        }
        return j < 0;
    }
};


