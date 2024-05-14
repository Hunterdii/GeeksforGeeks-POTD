//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends



class Solution {
public:
    int MinimumEffort(int rows, int columns, std::vector<std::vector<int>>& heights) {
        std::priority_queue<std::pair<int,std::pair<int,int>>,
                            std::vector<std::pair<int,std::pair<int,int>>>,
                            std::greater<std::pair<int,std::pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        std::vector<std::vector<int>> dist(n, std::vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if (newr < n && newr >= 0 && newc < m && newc >= 0) {
                    int neweffort = std::max(std::abs(heights[row][col] - heights[newr][newc]), diff);
                    if (neweffort < dist[newr][newc]) {
                        dist[newr][newc] = neweffort;
                        pq.push({dist[newr][newc], {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
