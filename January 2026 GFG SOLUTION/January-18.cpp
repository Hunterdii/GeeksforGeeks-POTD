class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && freq[arr[st.top()]] <= freq[arr[i]]) st.pop();
            if (!st.empty()) res[i] = arr[st.top()];
            st.push(i);
        }
        return res;
    }
};

2)
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(arr.size(), -1);
        stack<int> st;
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && freq[arr[i]] > freq[arr[st.top()]]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

3)
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        vector<int> res(arr.size(), -1);
        stack<pair<int, int>> st;
        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top().second <= freq[arr[i]]) st.pop();
            if (!st.empty()) res[i] = st.top().first;
            st.push({arr[i], freq[arr[i]]});
        }
        return res;
    }
};

4)
class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && freq[arr[st.top()]] < freq[arr[i]]) {
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
