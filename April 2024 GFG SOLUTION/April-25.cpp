//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int findMaxSum(int N, int M, std::vector<std::vector<int>>& Mat) {
        if (N < 3 || M < 3) {
            return -1;
        }

        int ans = std::numeric_limits<int>::min();

        for (int i = 0; i < N - 2; ++i) {
            for (int j = 0; j < M - 2; ++j) {
                int sum = Mat[i][j] + Mat[i][j + 1] + Mat[i][j + 2] +
                          Mat[i + 1][j + 1] +
                          Mat[i + 2][j] + Mat[i + 2][j + 1] + Mat[i + 2][j + 2];

                ans = std::max(ans, sum);
            }
        }

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends
