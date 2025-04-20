//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        int slow = arr[0], fast = arr[0];
        do {
            slow = arr[slow];
            fast = arr[arr[fast]];
        } while (slow != fast);
        fast = arr[0];
        while (slow != fast) {
            slow = arr[slow];
            fast = arr[fast];
        }
        return slow;
    }
};


2)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        int s = a[0], f = a[0];
        do { 
            s = a[s];
            f = a[a[f]];
        } while (s != f);
        f = a[0];
        while (s != f) { 
            s = a[s];
            f = a[f];
        }
        return s;
    }
};


3)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        for (int i = 0; i < a.size(); i++) {
            int idx = abs(a[i]);
            if (a[idx] < 0) return idx;
            a[idx] = -a[idx];
        }
        return -1;
    }
};


4)
class Solution {
  public:
    int findDuplicate(vector<int>& a) {
        unordered_set<int> s;
        for (int x : a)
            if (!s.insert(x).second) return x;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.findDuplicate(arr);

        cout << (result) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
