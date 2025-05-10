//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        unordered_map<int, int> m;
        int s = 0, r = 0;
        for (int i = 0; i < a.size(); ++i) {
            s += a[i] > k ? 1 : -1;
            if (s > 0) r = i + 1;
            else if (m.count(s - 1)) r = max(r, i - m[s - 1]);
            m.insert({s, i});
        }
        return r;
    }
};

2)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        vector<int> P(n+1, 0), st;
        for (int i = 0; i < n; ++i)
            P[i+1] = P[i] + (arr[i] > k ? 1 : -1);
        for (int i = 0; i <= n; ++i)
            if (st.empty() || P[i] < P[st.back()])
                st.push_back(i);
        for (int i = n; i >= 0; --i) {
            while (!st.empty() && P[i] > P[st.back()]) {
                res = max(res, i - st.back());
                st.pop_back();
            }
        }
        return res;
    }
};

3)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int,int> firstIdx;
        int s = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            s += (arr[i] > k ? 1 : -1);
            if (s > 0) {
                res = i + 1;
            } else {
                if (!firstIdx.count(s)) firstIdx[s] = i;
                auto it = firstIdx.find(s-1);
                if (it != firstIdx.end())
                    res = max(res, i - it->second);
            }
        }
        return res;
    }
};

4)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int,int> firstIdx;
        int s = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            s += (arr[i] > k ? 1 : -1);
            if (s > 0) {
                res = i + 1;
            } else {
                if (!firstIdx.count(s)) firstIdx[s] = i;
                if (firstIdx.count(s - 1))
                    res = max(res, i - firstIdx[s - 1]);
            }
        }
        return res;
    }
};

5)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size(), res = 0;
        vector<int> P(n + 1, 0), st;
        for (int i = 0; i < n; ++i)
            P[i + 1] = P[i] + (arr[i] > k ? 1 : -1);
        for (int i = 0; i <= n; ++i)
            if (st.empty() || P[i] < P[st.back()])
                st.push_back(i);
        for (int i = n; i >= 0; --i) {
            while (!st.empty() && P[i] > P[st.back()]) {
                res = max(res, i - st.back());
                st.pop_back();
            }
        }
        return res;
    }
};

6)
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int, int> firstIdx;
        int s = 0, res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            s += (arr[i] > k ? 1 : -1);
            if (s > 0) {
                res = i + 1;
            } else {
                if (!firstIdx.count(s)) firstIdx[s] = i;
                auto it = firstIdx.find(s - 1);
                if (it != firstIdx.end())
                    res = max(res, i - it->second);
            }
        }
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
