//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {
// public:
//     int findMaxDiff(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> l(n, 0), r(n, 0);
//         stack<int> s;
//         for (int i = 0; i < n; i++) {
//             while (!s.empty() && arr[s.top()] >= arr[i]) {
//                 s.pop();
//             }
//             l[i] = s.empty() ? 0 : arr[s.top()];
//             s.push(i);
//         }
//         while (!s.empty()) {
//             s.pop();
//         }
//         for (int i = n - 1; i >= 0; i--) {
//             while (!s.empty() && arr[s.top()] >= arr[i]) {
//                 s.pop();
//             }
//             r[i] = s.empty() ? 0 : arr[s.top()];
//             s.push(i);
//         }
//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             ans = max(ans, abs(l[i] - r[i]));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int findMaxDiff(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        int maxDiff = 0;
        vector<int> l(n, 0);
        vector<int> r(n, 0);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            l[i] = s.empty() ? 0 : arr[s.top()];
            s.push(i);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            r[i] = s.empty() ? 0 : arr[s.top()];
            s.push(i);
        }
        for (int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(l[i] - r[i]));
        }

        return maxDiff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
