//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    bool matSearch(vector<vector<int>>& mat, int x) {
        int r = 0, c = mat[0].size() - 1;
        while (r < mat.size() && c >= 0) {
            if (mat[r][c] == x) return true;
            else if (mat[r][c] > x) c--;
            else r++;
        }
        return false;
    }
};

2)
class Solution {
public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        for (int r = 0, c = arr[0].size() - 1; r < arr.size() && c >= 0; )
            if (arr[r][c] == x) return true;
            else if (arr[r][c] > x) c--;
            else r++;
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
