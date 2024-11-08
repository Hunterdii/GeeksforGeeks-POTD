//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

/* matrix : given input matrix, you are require
 to change it in place without using extra space */
void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
        for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    
        for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
