class Solution {
    string d;
    stack<char> r;
public:
    void append(char x) {
        d += x;
        while (!r.empty()) r.pop();
    }
    void undo() {
        if (!d.empty()) {
            r.push(d.back());
            d.pop_back();
        }
    }
    void redo() {
        if (!r.empty()) {
            d += r.top();
            r.pop();
        }
    }
    string read() { return d; }
};

2)
class Solution {
    deque<char> d;
    vector<deque<char>> h;
    int p = 0;
public:
    void append(char x) {
        d.push_back(x);
        h.resize(p + 1);
        h.push_back(d);
        p++;
    }
    void undo() {
        if (p > 0) d = h[--p];
    }
    void redo() {
        if (p < h.size() - 1) d = h[++p];
    }
    string read() {
        return string(d.begin(), d.end());
    }
};

3)
class Solution {
    string d;
    stack<pair<int, char>> u, r;
public:
    void append(char x) {
        d += x;
        u.push({1, x});
        while (!r.empty()) r.pop();
    }
    void undo() {
        if (!u.empty()) {
            auto [op, ch] = u.top();
            u.pop();
            d.pop_back();
            r.push({1, ch});
        }
    }
    void redo() {
        if (!r.empty()) {
            auto [op, ch] = r.top();
            r.pop();
            d += ch;
            u.push({1, ch});
        }
    }
    string read() { return d; }
};

4)
class Solution {
    vector<char> d;
    int len = 0, cap = 0;
public:
    void append(char x) {
        if (len == d.size()) d.push_back(x);
        else d[len] = x;
        len++;
        cap = len;
    }
    void undo() {
        if (len > 0) len--;
    }
    void redo() {
        if (len < cap) len++;
    }
    string read() {
        return string(d.begin(), d.begin() + len);
    }
};

5)
class Solution {
    list<char> d;
    list<char>::iterator curr;
public:
    Solution() { curr = d.end(); }
    void append(char x) {
        d.erase(curr, d.end());
        d.push_back(x);
        curr = d.end();
    }
    void undo() {
        if (curr != d.begin()) curr--;
    }
    void redo() {
        if (curr != d.end()) curr++;
    }
    string read() {
        return string(d.begin(), curr);
    }
};
