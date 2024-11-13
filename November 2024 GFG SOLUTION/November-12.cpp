//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
1)
class Solution {
public:
    bool canAttend(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return a[0] < b[0];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }

        return true;
    }
};

2)
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][1] > arr[i + 1][0])
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
