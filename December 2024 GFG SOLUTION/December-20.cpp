//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        int rows = mat.size(), cols = mat[0].size();
        int top = 0, left = 0, bottom = rows - 1, right = cols - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                result.push_back(mat[top][i]);
            top++;
            for (int i = top; i <= bottom; ++i)
                result.push_back(mat[i][right]);
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(mat[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(mat[i][left]);
                left++;
            }
        }
        return result;
    }
};

2)
class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        int top = 0, left = 0, bottom = mat.size() - 1, right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; result.push_back(mat[top][i++]));
            top++;
            for (int i = top; i <= bottom; result.push_back(mat[i++][right]));
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; result.push_back(mat[bottom][i--]));
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; result.push_back(mat[i--][left]));
            left++;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
