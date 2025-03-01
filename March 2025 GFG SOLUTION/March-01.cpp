//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    string decodedString(string &s) {
        stack<string> str;
        stack<int> num;
        string cur = "", temp;
        int n = 0;

        for (char c : s) {
            if (isdigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') { str.push(cur); num.push(n); cur = ""; n = 0; }
            else if (c == ']') {
                temp = cur;
                cur = str.top(); str.pop();
                for (int i = 0, x = num.top(); i < x; i++) cur += temp;
                num.pop();
            } else cur += c;
        }
        return cur;
    }
};


2)
#include <deque>

class Solution {
public:
    string decodedString(string &s) {
        deque<string> str;
        deque<int> num;
        string cur;
        int n = 0;

        for (char c : s) {
            if (isdigit(c)) n = n * 10 + (c - '0');
            else if (c == '[') { str.push_back(cur); num.push_back(n); cur = ""; n = 0; }
            else if (c == ']') {
                string temp = cur;
                cur = str.back(); str.pop_back();
                for (int i = 0; i < num.back(); i++) cur += temp;
                num.pop_back();
            } else cur += c;
        }
        return cur;
    }
};

3)
class Solution {
    int idx = 0;

    string decode(string &s) {
        string cur = "";
        int n = 0;

        while (idx < s.length()) {
            if (isdigit(s[idx])) n = n * 10 + (s[idx++] - '0');
            else if (s[idx] == '[') {
                idx++;
                string temp = decode(s);
                while (n--) cur += temp;
                n = 0;
            } else if (s[idx] == ']') {
                idx++;
                return cur;
            } else cur += s[idx++];
        }
        return cur;
    }

public:
    string decodedString(string &s) {
        idx = 0;
        return decode(s);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
