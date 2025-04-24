//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int ones = 0, twos = 0;
        for (int num : arr) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

2)
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;
        for (auto &p : freq)
            if (p.second == 1) 
                return p.first;
        return 0;
    }
};


3)
class Solution {
  public:
    int getSingle(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), i = 0;
        while (i + 2 < n) {
            if (arr[i] == arr[i+1] && arr[i] == arr[i+2])
                i += 3;
            else
                return arr[i];
        }
        return arr[n-1];
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
        int ans = ob.getSingle(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
