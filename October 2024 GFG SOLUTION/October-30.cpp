//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_set<int> numSet(arr.begin(), arr.end()); // Using set for unique elements
        int count = 0;

        for (int x : numSet) {
            if (numSet.find(x + k) != numSet.end()) {
                count += count_if(arr.begin(), arr.end(), [x](int n){ return n == x; }) * 
                         count_if(arr.begin(), arr.end(), [x, k](int n){ return n == x + k; });
            }
        }

        return count;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
