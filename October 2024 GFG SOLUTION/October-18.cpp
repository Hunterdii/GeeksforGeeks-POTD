//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
1)
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int xr = 0;
        for (int num : arr) {
            xr ^= num; 
        }
        return xr;
    }
};

2)
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        int xr = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i]; 
        }
        return xr; 
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends