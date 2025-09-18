class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
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

2)
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= arr[i % n]) stk.pop();
            if (i < n && !stk.empty()) res[i] = stk.top();
            stk.push(arr[i % n]);
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int pass = 0; pass < 2; pass++) {
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && arr[stk.top()] < arr[i]) {
                    res[stk.top()] = arr[i];
                    stk.pop();
                }
                if (pass == 0) stk.push(i);
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        int remaining = n;
        for (int i = 0; i < 2 * n && remaining > 0; i++) {
            while (!stk.empty() && arr[stk.top()] < arr[i % n]) {
                res[stk.top()] = arr[i % n];
                stk.pop();
                remaining--;
            }
            if (i < n) stk.push(i);
        }
        return res;
    }
};
