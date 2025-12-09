class Solution {
public:
    int countSubs(string& s) {
        int cnt = 0, n = s.length();
        struct Node { Node* c[26] = {}; };
        Node* root = new Node();
        for (int i = 0; i < n; i++) {
            Node* cur = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!cur->c[idx]) {
                    cur->c[idx] = new Node();
                    cnt++;
                }
                cur = cur->c[idx];
            }
        }
        return cnt;
    }
};

2)
class Solution {
public:
    int countSubs(string& s) {
        unordered_set<string> st;
        for (int i = 0; i < s.length(); i++)
            for (int j = i; j < s.length(); j++)
                st.insert(s.substr(i, j - i + 1));
        return st.size();
    }
};

3)
class Solution {
public:
    int countSubs(string& s) {
        int n = s.length();
        vector<string> suf;
        for (int i = 0; i < n; i++) suf.push_back(s.substr(i));
        sort(suf.begin(), suf.end());
        int cnt = n * (n + 1) / 2;
        for (int i = 1; i < n; i++) {
            int lcp = 0;
            while (lcp < min(suf[i].length(), suf[i - 1].length()) && 
                   suf[i][lcp] == suf[i - 1][lcp]) lcp++;
            cnt -= lcp;
        }
        return cnt;
    }
};

4)
class Solution {
public:
    int countSubs(string& s) {
        struct T { T* ch[26] = {}; };
        T* r = new T();
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            T* p = r;
            for (int j = i; j < s.size(); j++) {
                if (!p->ch[s[j] - 'a']) {
                    p->ch[s[j] - 'a'] = new T();
                    res++;
                }
                p = p->ch[s[j] - 'a'];
            }
        }
        return res;
    }
};
