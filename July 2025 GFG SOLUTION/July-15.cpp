class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        const char* p = s.c_str();
        while (*p) r = (r * 10 + *p++ - '0') % 13;
        return !r;
    }
};


2)
class Solution {
public:
    bool divby13(string &s) {
        int rem = 0, pow = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            rem = (rem + (s[i] - '0') * pow) % 13;
            pow = (pow * 10) % 13;
        }
        return rem == 0;
    }
};


3)
class Solution {
public:
    bool divby13(string &s) {
        int mod = 0;
        for (size_t i = 0; i < s.size(); mod = (mod * 10 + s[i++] - 48) % 13);
        return mod == 0;
    }
};


4)
class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            r = (r * 10 + s[i] - '0') % 13;
        }
        return !r;
    }
};


5)
class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        for (char c : s) {
            r = (r * 10 + c - '0') % 13;
        }
        return r == 0;
    }
};
