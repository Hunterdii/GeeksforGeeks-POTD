class Solution {
public:
    string caseSort(string &s) {
        int l[26] = {0}, u[26] = {0};
        for (char c : s) (c & 32) ? l[c - 97]++ : u[c - 65]++;
        int i = 0, j = 0;
        for (char &c : s) {
            if (c & 32) {
                while (!l[i]) i++;
                c = i + 97;
                l[i]--;
            } else {
                while (!u[j]) j++;
                c = j + 65;
                u[j]--;
            }
        }
        return s;
    }
};


2)
class Solution {
public:
    string caseSort(string &s) {
        int lower[26] = {0}, upper[26] = {0};
        for (char ch : s) {
            if (islower(ch)) lower[ch - 'a']++;
            else upper[ch - 'A']++;
        }
        int l = 0, u = 0;
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                while (lower[l] == 0) l++;
                s[i] = 'a' + l;
                lower[l]--;
            } else {
                while (upper[u] == 0) u++;
                s[i] = 'A' + u;
                upper[u]--;
            }
        }
        return s;
    }
};


3)
class Solution {
public:
    string caseSort(string &s) {
        vector<char> lower, upper;
        for (char c : s) {
            if (islower(c)) lower.push_back(c);
            else upper.push_back(c);
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int l = 0, u = 0;
        for (char &c : s) {
            if (islower(c)) c = lower[l++];
            else c = upper[u++];
        }
        return s;
    }
};


4)
class Solution {
public:
    string caseSort(string &s) {
        int freq[128] = {0};
        string result = s;
        for (char c : s) freq[c]++;
        
        for (int i = 0; i < s.length(); i++) {
            if (islower(s[i])) {
                for (int j = 'a'; j <= 'z'; j++) {
                    if (freq[j] > 0) {
                        result[i] = j;
                        freq[j]--;
                        break;
                    }
                }
            } else {
                for (int j = 'A'; j <= 'Z'; j++) {
                    if (freq[j] > 0) {
                        result[i] = j;
                        freq[j]--;
                        break;
                    }
                }
            }
        }
        return result;
    }
};
