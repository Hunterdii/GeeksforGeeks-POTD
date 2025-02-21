//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty() || (st.top() == '(' && c != ')') || (st.top() == '{' && c != '}') || (st.top() == '[' && c != ']')) 
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

2)
class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else if (st.empty() || abs(st.top() - c) > 2) return false;
            else st.pop();
        }
        return st.empty();
    }
};

3)
class Solution {
  public:
    bool isBalanced(string& s) {
        unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;
        for (char c : s) {
            if (m.count(c)) {
                if (st.empty() || st.top() != m[c]) return false;
                st.pop();
            } else st.push(c);
        }
        return st.empty();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
