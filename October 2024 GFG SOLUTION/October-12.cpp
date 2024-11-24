//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

1)
class Solution {
  public:
    int pairWithMaxSum(const vector<int>& arr) {
        int n = arr.size();

        if (n < 2) return -1;

        int maxSum = arr[0] + arr[1];  

        for (int i = 1; i < n - 1; ++i) {
            maxSum = max(maxSum, arr[i] + arr[i + 1]);
        }

        return maxSum;
    }
};

2)
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2)
            return -1;
        int maxSum = arr[0] + arr[1]; 
        for (int i = 1; i < n - 1; ++i) {
            int currentSum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, currentSum); 
        }

        return maxSum;
    }
};

3)
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        if (arr.size() < 2)
            return -1;
        
        int maxSum = arr[0] + arr[1];
        for (int i = 1; i < arr.size() - 1; ++i)
            maxSum = max(maxSum, arr[i] + arr[i + 1]);

        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends
