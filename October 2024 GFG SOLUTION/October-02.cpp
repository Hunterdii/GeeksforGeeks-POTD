//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int rotateDelete(vector<int> &arr) {
        int i = 1;
        int n = arr.size();
        while (i < (n / 2) + 1) {
            rotate(arr.begin(), arr.end() - 1, arr.end());
            arr.erase(arr.begin() + (arr.size() - i));
            i++;
        }
        return arr[0];
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
