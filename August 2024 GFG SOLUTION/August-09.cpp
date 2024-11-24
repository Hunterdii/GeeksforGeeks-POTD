//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int mod = 1e9 + 7;

    int Maximize(vector<int>& arr) {
        sort(arr.begin(), arr.end()); 
        unsigned long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i) {
            ans = (ans + arr[i] * 1ULL * i) % mod;
        }

        return ans;
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends
