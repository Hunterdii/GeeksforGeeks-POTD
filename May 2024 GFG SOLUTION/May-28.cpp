//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
public:
    int findMinCost(int index, vector<int>& cost, int weight, vector<vector<int>>& memo) {
        if (weight == 0) {
            return 0;
        }
        if (index >= cost.size() || index + 1 > weight) {
            return INT_MAX;
        }
        if (memo[index][weight] != -1) {
            return memo[index][weight];
        }

        int includeCurrent = INT_MAX;
        if (cost[index] != -1 && index + 1 <= weight) {
            int result = findMinCost(index, cost, weight - (index + 1), memo);
            if (result != INT_MAX) {
                includeCurrent = cost[index] + result;
            }
        }
        int excludeCurrent = findMinCost(index + 1, cost, weight, memo);

        memo[index][weight] = min(includeCurrent, excludeCurrent);
        return memo[index][weight];
    }

    int minimumCost(int n, int w, vector<int>& cost) {
        vector<vector<int>> memo(n + 1, vector<int>(w + 1, -1));
        int result = findMinCost(0, cost, w, memo);

        return result == INT_MAX ? -1 : result;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends
