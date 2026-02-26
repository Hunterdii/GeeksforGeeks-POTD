class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < s1.size(); i++) {
            if (m1[s1[i]] != m2[s2[i]]) return false;
            m1[s1[i]] = m2[s2[i]] = i + 1;
        }
        return true;
    }
};

2)
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s1.size(); i++) {
            if (m1.count(s1[i]) && m1[s1[i]] != s2[i]) return false;
            if (m2.count(s2[i]) && m2[s2[i]] != s1[i]) return false;
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
        return true;
    }
};

3)
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        vector<int> map(26, -1);
        vector<bool> used(26, false);
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            if (map[a] == -1) {
                if (used[b]) return false;
                map[a] = b;
                used[b] = true;
            } else if (map[a] != b) return false;
        }
        return true;
    }
};

4)
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        string m1(256, 0), m2(256, 0);
        for (int i = 0; i < s1.size(); i++) {
            if (m1[s1[i]] != m2[s2[i]]) return false;
            m1[s1[i]] = m2[s2[i]] = s2[i];
        }
        return true;
    }
};
