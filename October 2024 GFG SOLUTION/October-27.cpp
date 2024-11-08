//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
1)
class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        sort(arr.begin(), arr.end()); 

        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == arr[i]) {
                    return true;
                }
                else if (sum < arr[i]) {
                    left++; 
                } else {
                    right--; 
                }
            }
        }
        return false; 
    }
};

2)
class Solution {
public:
    bool findTriplet(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        sort(arr.begin(), arr.end()); 

        for (int i = n - 1; i >= 2; --i) {
            int target = arr[i];
            int left = 0, right = i - 1;

            while (left < right) {
                int sum = arr[left] + arr[right];

                if (sum == target) return true;
                if (sum < target)
                    ++left; 
                else
                    --right; 
            }
        }
        return false; 
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
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
