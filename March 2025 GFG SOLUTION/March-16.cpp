//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0, farthest = 0, end = 0;
        if (n == 1) return 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + arr[i]);
            if (i == end) {
                jumps++;
                end = farthest;
                if (end >= n - 1) return jumps;
            }
        }
        return -1;
    }
};

2)
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (j + arr[j] >= i && dp[j] != INT_MAX)
                    dp[i] = min(dp[i], dp[j] + 1);
        return dp[n-1] == INT_MAX ? -1 : dp[n-1];
    }
};


3)
class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(0);
        visited[0] = true;
        int jumps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int i = q.front();
                q.pop();
                for (int j = 1; j <= arr[i]; j++) {
                    int next = i + j;
                    if (next >= n - 1) return jumps + 1;
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            jumps++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
