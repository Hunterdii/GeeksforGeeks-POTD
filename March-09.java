class Solution {
public:
    char nthCharacter(string s, int r, int n) {
        int len = s.length();
        for (int i = 0; i < r; i++) {
            string temp = s;
            for (int j = 0; j < len; j++) {
                if (temp[j / 2] == '0')
                    s[j] = '0' + (j % 2);
                else
                    s[j] = '1' - (j % 2);
            }
        }
        return s[n];
    }
};
