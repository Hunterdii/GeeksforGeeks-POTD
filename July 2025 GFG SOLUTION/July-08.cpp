class Solution {
public:
    vector<int> findGreater(vector<int>& a) {
        unordered_map<int, int> f;
        for (int x : a) f[x]++;
        vector<int> r(a.size(), -1);
        stack<int> s;
        for (int i = 0; i < a.size(); i++) {
            while (!s.empty() && f[a[i]] > f[a[s.top()]]) {
                r[s.top()] = a[i];
                s.pop();
            }
            s.push(i);
        }
        return r;
    }
};


2)
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        stack<pair<int, int>> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top().second <= freq[arr[i]]) {
                s.pop();
            }
            if (!s.empty()) res[i] = s.top().first;
            s.push({arr[i], freq[arr[i]]});
        }
        return res;
    }
};


3)
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        int minVal = *min_element(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> freq(maxVal - minVal + 1, 0);
        for (int x : arr) freq[x - minVal]++;
        vector<int> res(n, -1);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && freq[arr[i] - minVal] > freq[arr[s.top()] - minVal]) {
                res[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};


4)
class Solution {
public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && freq[arr[i]] > freq[arr[dq.back()]]) {
                res[dq.back()] = arr[i];
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res;
    }
};
