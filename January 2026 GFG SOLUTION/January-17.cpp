class Solution {
public:
    bool checkRedundancy(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                bool op = false;
                while (st.top() != '(') {
                    char top = st.top(); st.pop();
                    if (top == '+' || top == '-' || top == '*' || top == '/') op = true;
                }
                st.pop();
                if (!op) return true;
            } else if (c == '(' || c == '+' || c == '-' || c == '*' || c == '/') {
                st.push(c);
            }
        }
        return false;
    }
};

2)
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                bool hasOp = false;
                while (st.top() != '(') {
                    char t = st.top();
                    st.pop();
                    if (t == '+' || t == '-' || t == '*' || t == '/') hasOp = true;
                }
                st.pop();
                if (!hasOp) return true;
            } else {
                st.push(c);
            }
        }
        return false;
    }
};

3)
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ')') {
                st.push(s[i]);
            } else {
                int elems = 0;
                while (!st.empty() && st.top() != '(') {
                    st.pop();
                    elems++;
                }
                if (!st.empty()) st.pop();
                if (elems <= 1) return true;
            }
        }
        return false;
    }
};

4)
class Solution {
public:
    bool checkRedundancy(string &s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                char top = st.top();
                st.pop();
                int cnt = 0;
                while (top != '(') {
                    if (top == '+' || top == '-' || top == '*' || top == '/') cnt++;
                    top = st.top();
                    st.pop();
                }
                if (cnt == 0) return true;
            } else {
                st.push(ch);
            }
        }
        return false;
    }
};
