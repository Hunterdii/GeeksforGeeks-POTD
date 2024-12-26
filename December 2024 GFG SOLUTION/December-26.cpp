//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function template for C++
2)
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < arr.size(); i++) {
            int numberToFind = target - arr[i];
            if (hash.find(numberToFind) != hash.end()) {
                return true;
            }
            hash[arr[i]] = i;
        }
        return false;
    }
};

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(target - num)) return true;
            seen.insert(num);
        }
        return false;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
