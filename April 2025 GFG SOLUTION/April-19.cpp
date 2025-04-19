//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    int maxXor(vector<int>& a) {
        int max_xor = 0, mask = 0;
        unordered_set<int> s;
        for(int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            s.clear();
            int temp = max_xor | (1 << i);
            for(int num : a) {
                int prefix = num & mask;
                if(s.count(temp ^ prefix)) { max_xor = temp; break; }
                s.insert(prefix);
            }
        }
        return max_xor;
    }
};


2)
class Solution {
    struct T { T* c[2]{}; } *r = new T;
    void i(int x) {
        T* n = r;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (!n->c[b]) n->c[b] = new T;
            n = n->c[b];
        }
    }
    int q(int x) {
        T* n = r;
        int m = 0;
        for (int i = 31; i >= 0; --i) {
            int b = (x >> i) & 1;
            if (n->c[1 - b]) m |= 1 << i, n = n->c[1 - b];
            else n = n->c[b];
        }
        return m;
    }
public:
    int maxXor(vector<int>& a) {
        for (int x : a) i(x);
        int res = 0;
        for (int x : a) res = max(res, q(x));
        return res;
    }
};

3)
class Solution {
public:
    int maxXor(vector<int>& a) {
        int max_val = 0;
        for(int i = 0; i < a.size(); i++)
            for(int j = i + 1; j < a.size(); j++)
                max_val = max(max_val, a[i] ^ a[j]);
        return max_val;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
