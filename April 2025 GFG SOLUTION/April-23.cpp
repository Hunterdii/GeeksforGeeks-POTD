//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        int x = 0;
        for (int n : arr) x ^= n;
        int mask = x & -x;
        int a = 0, b = 0;
        for (int n : arr) {
            if (n & mask) a ^= n;
            else b ^= n;
        }
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
};


2)
class Solution {
  public:
    vector<int> singleNum(vector<int>& A) {
        int x = 0, a = 0, b = 0;
        for (int n : A) x ^= n;
        for (int n : A) (n & (x & -x) ? a : b) ^= n;
        return a < b ? vector<int>{a, b} : vector<int>{b, a};
    }
};


3)
class Solution {
  public:
    vector<int> singleNum(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<int> res;
        int i = 0, n = a.size();
        while (i < n - 1) {
            if (a[i] != a[i + 1]) {
                res.push_back(a[i++]);
            } else {
                i += 2;
            }
        }
        if (res.size() < 2) res.push_back(a[n - 1]);
        sort(res.begin(), res.end());
        return res;
    }
};


4)
class Solution {
  public:
    vector<int> singleNum(vector<int>& a) {
        unordered_map<int, int> freq;
        for (int x : a) freq[x]++;
        vector<int> res;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            if (it->second == 1) res.push_back(it->first);
        sort(res.begin(), res.end());
        return res;
    }
};


5)
class Solution {
  public:
    vector<int> singleNum(vector<int>& a) {
        int x = 0, m, p = 0, q = 0;
        for (int n : a) x ^= n;
        m = x & -x;
        for (int n : a) (n & m ? p : q) ^= n;
        return p < q ? vector<int>{p, q} : vector<int>{q, p};
    }
};




//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
