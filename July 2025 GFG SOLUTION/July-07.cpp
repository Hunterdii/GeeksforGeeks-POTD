class Solution {
public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) st.pop();
            if (i < n && !st.empty()) res[i] = st.top();
            st.push(arr[i % n]);
        }
        return res;
    }
};


2)
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            int idx = i % n;
            while (!stk.empty() && stk.top() <= arr[idx]) {
                stk.pop();
            }
            if (i < n) res[idx] = stk.empty() ? -1 : stk.top();
            stk.push(arr[idx]);
        }
        return res;
    }
};


3)
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<pair<int, int>> stk;
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (!stk.empty() && stk.top().first < arr[idx]) {
                res[stk.top().second] = arr[idx];
                stk.pop();
            }
            if (i < n) stk.push({arr[idx], idx});
        }
        return res;
    }
};


4)
class Solution {
public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 0; i < 2 * n; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i % n]) {
                res[stk.top()] = arr[i % n];
                stk.pop();
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
};
