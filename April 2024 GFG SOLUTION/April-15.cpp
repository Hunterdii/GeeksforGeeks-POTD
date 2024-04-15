//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

1)
class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        sort(b.begin(), b.end());
        vector<int> ans;
        ans.reserve(q); // Reserve memory for the result vector to avoid dynamic resizing
        
        for (int i = 0; i < q; ++i) {
            int count = upper_bound(b.begin(), b.end(), a[query[i]]) - b.begin();
            ans.push_back(count);
        }
        return ans;
    }
};


2)
class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        sort(b.begin(), b.end());
        vector<int> ans;
        for(auto it : query) {
            int count = binarySearch(b, a[it]);
            ans.push_back(count);
        }
        return ans;
    }
    
    int binarySearch(const vector<int>& b, int target) {
        int low = 0, high = b.size() - 1;
        int count = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (b[mid] <= target) {
                count = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return count;
    }
};
//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
