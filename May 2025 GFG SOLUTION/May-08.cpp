//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d1 = arr[1] - arr[0], 
            d2 = arr[n-1] - arr[n-2], 
            d3 = (arr[n-1] - arr[0]) / n;
        int d = (d1==d2 || d1==d3) ? d1 : d2;
        if (d == 0) return arr[0];
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if ((arr[mid] - arr[0]) / d == mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return arr[0] + lo * d;
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
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
