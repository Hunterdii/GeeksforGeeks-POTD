//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {

            return -1;
        }

        int first = INT_MIN, second = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > first) {
                second = first;  
                first = arr[i];   
            } else if (arr[i] > second) {
                second = arr[i];  
            }
        }

        return first + second;
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
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends
