//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int l =0, r = arr.size() - 1, ans = 0;
        while (l < r){
            if (arr[l] + arr[r] < target) ans += (r - l), l++;
            else r--;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr.size() - 1, ans = 0;
        while (l < r) (arr[l] + arr[r] < target) ? ans += (r - l), l++ : r--;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
