class Solution {
public:
    string decodedString(string& s) {
        stack<pair<string, int>> st;
        string curr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                st.push({curr, num});
                curr = "";
                num = 0;
            } else if (c == ']') {
                auto [prev, cnt] = st.top();
                st.pop();
                string temp = curr;
                for (int i = 1; i < cnt; i++) curr += temp;
                curr = prev + curr;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};

2)
class Solution {
public:
    string decodedString(string& s) {
        int idx = 0;
        return decode(s, idx);
    }
    
private:
    string decode(string& s, int& i) {
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i++] - '0';
                }
                i++; 
                string sub = decode(s, i);
                i++; 
                while (num--) res += sub;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    string decodedString(string& s) {
        stack<string> strSt;
        stack<int> numSt;
        string curr = "";
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                strSt.push(curr);
                numSt.push(num);
                curr = "";
                num = 0;
            } else if (c == ']') {
                string temp = curr;
                curr = strSt.top();
                strSt.pop();
                int cnt = numSt.top();
                numSt.pop();
                while (cnt--) curr += temp;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};

4)
class Solution {
public:
    string decodedString(string& s) {
        stack<pair<stringstream, int>> st;
        stringstream curr;
        int num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            } else if (c == '[') {
                st.push({move(curr), num});
                curr = stringstream();
                num = 0;
            } else if (c == ']') {
                string temp = curr.str();
                curr = move(st.top().first);
                int cnt = st.top().second;
                st.pop();
                while (cnt--) curr << temp;
            } else {
                curr << c;
            }
        }
        return curr.str();
    }
};


