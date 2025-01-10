//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int cnt = 0;
        for (int i = arr.size() - 1; i >= 2; --i)
            for (int l = 0, r = i - 1; l < r; arr[l] + arr[r] > arr[i] ? cnt += r-- - l : ++l);
        return cnt;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends
