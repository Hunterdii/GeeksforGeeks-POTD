//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int findEquilibrium(vector<int>& arr) {
        long long sum = accumulate(arr.begin(), arr.end(), 0LL), sum2 = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum -= arr[i];
            if (sum == sum2) return i;
            sum2 += arr[i];
        }
        return -1;
    }
};

2)
class Solution {
public:
    int findEquilibrium(vector<int>& arr) {
        for (long long sum = accumulate(arr.begin(), arr.end(), 0LL), sum2 = 0, i = 0; i < arr.size(); sum2 += arr[i++])
            if ((sum -= arr[i]) == sum2) return i;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
