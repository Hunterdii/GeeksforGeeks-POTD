class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0;
        for (char c : s2) {
            if (i < s1.size() && s1[i] == c) {
                i++;
            }
        }
        return i == s1.size();
    }
};

2)
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        auto it1 = s1.begin(), it2 = s2.begin();
        while (it1 != s1.end() && it2 != s2.end()) {
            if (*it1 == *it2) {
                it1++;
            }
            it2++;
        }
        return it1 == s1.end();
    }
};

3)
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        
        return i == n;
    }
};

4)
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        return helper(s1, s2, 0, 0);
    }
private:
    bool helper(string& s1, string& s2, int i, int j) {
        if (i == s1.size()) return true;
        if (j == s2.size()) return false;
        if (s1[i] == s2[j]) {
            return helper(s1, s2, i + 1, j + 1);
        }
        return helper(s1, s2, i, j + 1);
    }
};

5)
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        size_t pos = 0;
        for (char c : s1) {
            pos = s2.find(c, pos);
            if (pos == string::npos) return false;
            pos++; 
        }
        return true;
    }
};
