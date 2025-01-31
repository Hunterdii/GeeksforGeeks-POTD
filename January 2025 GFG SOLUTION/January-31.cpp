//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void solveSudoku(vector<vector<int>> &board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j])
                    row[i] |= 1 << board[i][j], col[j] |= 1 << board[i][j], box[i / 3 * 3 + j / 3] |= 1 << board[i][j];
        solve(board, row, col, box, 0, 0);
    }

private:
    bool solve(vector<vector<int>> &board, vector<int> &row, vector<int> &col, vector<int> &box, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(board, row, col, box, i + 1, 0);
        if (board[i][j]) return solve(board, row, col, box, i, j + 1);
        for (int num = 1; num <= 9; num++) {
            int mask = 1 << num, idx = i / 3 * 3 + j / 3;
            if (row[i] & mask || col[j] & mask || box[idx] & mask) continue;
            board[i][j] = num, row[i] |= mask, col[j] |= mask, box[idx] |= mask;
            if (solve(board, row, col, box, i, j + 1)) return true;
            board[i][j] = 0, row[i] &= ~mask, col[j] &= ~mask, box[idx] &= ~mask;
        }
        return false;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
