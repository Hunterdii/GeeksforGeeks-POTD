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
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int ans = 0;
        vector<int> visited(v + 1, 0);

        vector<vector<int>> adj(v + 1);
        for (int i = 0; i < e; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0) {
                int vertices = 0;
                int edgesCount = 0;

                stack<int> stk;
                stk.push(i);
                visited[i] = 1;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    vertices++;
                    edgesCount += adj[node].size();

                    for (int neighbor : adj[node]) {
                        if (visited[neighbor] == 0) {
                            stk.push(neighbor);
                            visited[neighbor] = 1;
                        }
                    }
                }

                edgesCount /= 2;
                if (edgesCount == (vertices * (vertices - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends
