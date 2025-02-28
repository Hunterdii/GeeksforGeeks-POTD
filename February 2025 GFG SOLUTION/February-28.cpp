//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int evaluate(vector<string>& arr) {
        stack<int> st;
        for (auto &s : arr) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else st.push(a / b);
            } else st.push(stoi(s));
        }
        return st.top();
    }
};


2)
class Solution {
public:
    int evaluate(vector<string>& arr) {
        vector<int> st;
        for (const string& token : arr) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.back(); st.pop_back();
                int a = st.back(); st.pop_back();
                if (token == "+") st.push_back(a + b);
                else if (token == "-") st.push_back(a - b);
                else if (token == "*") st.push_back(a * b);
                else st.push_back(a / b);
            } else {
                st.push_back(stoi(token));
            }
        }
        return st.back();
    }
};

3)
class Solution {
    int idx;

    int eval(vector<string>& arr) {
        string token = arr[idx--];
        if (isdigit(token.back()) || (token.size() > 1 && isdigit(token[1]))) {
            return stoi(token);
        }
        int b = eval(arr);
        int a = eval(arr);
        if (token == "+") return a + b;
        if (token == "-") return a - b;
        if (token == "*") return a * b;
        return a / b;
    }

public:
    int evaluate(vector<string>& arr) {
        idx = arr.size() - 1;
        return eval(arr);
    }
};


//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
