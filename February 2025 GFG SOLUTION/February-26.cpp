//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n);
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            while (!s.empty() && (i == n || arr[s.top()] >= arr[i])) {
                int j = s.top();
                s.pop();
                len[j] = s.empty() ? i : i - s.top() - 1;
            }
            if (i < n) s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = max(res[i], res[i + 1]);
        return res;
    }
};


2)
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n), len(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            len[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }
        s = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            len[i] += s.empty() ? n - i - 1 : s.top() - i - 1;
            s.push(i);
        }
        for (int i = 0; i < n; i++) res[len[i] - 1] = max(res[len[i] - 1], arr[i]);
        for (int i = n - 2; i >= 0; i--) res[i] = max(res[i], res[i + 1]);
        return res;
    }
};

3)
class Solution {
public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, INT_MIN);
        vector<int> left(n), right(n);
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && arr[dq.back()] >= arr[i]) dq.pop_back();
            left[i] = dq.empty() ? i + 1 : i - dq.back();
            dq.push_back(i);
        }

        dq.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!dq.empty() && arr[dq.back()] > arr[i]) dq.pop_back();
            right[i] = dq.empty() ? n - i : dq.back() - i;
            dq.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            int len = left[i] + right[i] - 1;
            res[len - 1] = max(res[len - 1], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--) 
            res[i] = max(res[i], res[i + 1]);

        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
