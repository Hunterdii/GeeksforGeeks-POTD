class Solution {
public:
    bool isPalinSent(string s) {
        auto valid = [](char c){ return isalnum(c); };
        for (int i = 0, j = s.size()-1; i < j;) {
            if (!valid(s[i])) ++i;
            else if (!valid(s[j])) --j;
            else if (tolower(s[i++]) != tolower(s[j--])) return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalinSent(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;
            if (tolower(s[l++]) != tolower(s[r--])) return false;
        }
        return true;
    }
};

2)
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean;
        for (char c : s) if (isalnum(c)) clean += tolower(c);
        int n = clean.size();
        for (int i = 0; i < n / 2; i++)
            if (clean[i] != clean[n - 1 - i]) return false;
        return true;
    }
};

3)
class Solution {
public:
    bool isPalinSent(string &s) {
        return check(s, 0, s.size() - 1);
    }
private:
    bool check(string &s, int l, int r) {
        while (l < r && !isalnum(s[l])) l++;
        while (l < r && !isalnum(s[r])) r--;
        if (l >= r) return true;
        return tolower(s[l]) == tolower(s[r]) && check(s, l + 1, r - 1);
    }
};

4)
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean = s;
        clean.erase(remove_if(clean.begin(), clean.end(), 
                  [](char c) { return !isalnum(c); }), clean.end());
        transform(clean.begin(), clean.end(), clean.begin(), ::tolower);
        return equal(clean.begin(), clean.begin() + clean.size() / 2, clean.rbegin());
    }
};

5)
class Solution {
public:
    bool isPalinSent(string &s) {
        string clean, reversed;
        for (char c : s) {
            if (isalnum(c)) {
                char lower = tolower(c);
                clean += lower;
                reversed = lower + reversed;
            }
        }
        return clean == reversed;
    }
};

6)
class Solution {
public:
    bool isPalinSent(string s) {
        string t;
        for (char c : s) if (isalnum(c)) t += tolower(c);
        string r = t; reverse(r.begin(), r.end());
        return t == r;
    }
};
