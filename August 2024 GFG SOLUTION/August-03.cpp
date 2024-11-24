//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int potential_celebrity = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[potential_celebrity][i] == 1) {
                potential_celebrity = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != potential_celebrity && (mat[potential_celebrity][i] == 1 || mat[i][potential_celebrity] == 0)) {
                return -1;
            }
        }

        return potential_celebrity;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
