//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
    stack<int> s, minStack;
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) minStack.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() == minStack.top()) minStack.pop();
        s.pop();
    }

    int peek() {
        return s.empty() ? -1 : s.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};


2)
class Solution {
    stack<int> s, m;
public:
    void push(int x) { s.push(x), m.push(m.empty() ? x : min(x, m.top())); }
    void pop() { if (!s.empty()) s.pop(), m.pop(); }
    int peek() { return s.empty() ? -1 : s.top(); }
    int getMin() { return m.empty() ? -1 : m.top(); }
};

3)
class Solution {
    stack<pair<int, int>> s;
public:
    void push(int x) { s.push({x, s.empty() ? x : min(x, s.top().second)}); }
    void pop() { if (!s.empty()) s.pop(); }
    int peek() { return s.empty() ? -1 : s.top().first; }
    int getMin() { return s.empty() ? -1 : s.top().second; }
};


4)
class Solution {
    stack<long long> s;
    long long minVal;
public:
    void push(int x) {
        if (s.empty()) { minVal = x; s.push(x); }
        else if (x < minVal) { s.push(2LL * x - minVal); minVal = x; }
        else s.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (s.top() < minVal) minVal = 2 * minVal - s.top();
        s.pop();
    }

    int peek() { return s.empty() ? -1 : (s.top() < minVal ? minVal : s.top()); }

    int getMin() { return s.empty() ? -1 : minVal; }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
