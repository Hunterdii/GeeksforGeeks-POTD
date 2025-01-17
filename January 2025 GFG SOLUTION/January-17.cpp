//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size(), product = 1, zeroCount = count(arr.begin(), arr.end(), 0);
        if (zeroCount > 1) return vector<int>(n, 0);
        for (int x : arr) if (x) product *= x;
        for (int i = 0; i < n; i++) arr[i] = zeroCount ? (arr[i] ? 0 : product) : product / arr[i];
        return arr;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
