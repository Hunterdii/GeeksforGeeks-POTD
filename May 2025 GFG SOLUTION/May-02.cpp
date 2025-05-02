//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        return *max_element(arr.begin(), arr.end());
    }
};

2)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int mx = arr[0];
        for (int i = 1; i < arr.size(); ++i)
            if (arr[i] > mx) mx = arr[i];
        return mx;
    }
};

3)
class Solution {
    int dc(vector<int>& a, int l, int r) {
        if (l == r) return a[l];
        int m = (l + r) >> 1;
        return max(dc(a, l, m), dc(a, m+1, r));
    }
  public:
    int findMaximum(vector<int> &arr) {
        return dc(arr, 0, arr.size()-1);
    }
};

4)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        return arr.back();
    }
};

5)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int l = 0, r = arr.size() - 1;
        while (r - l > 2) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if (arr[m1] < arr[m2])
                l = m1;
            else
                r = m2;
        }
        return max({arr[l], arr[l+1], arr[r]});
    }
};

6)
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        int low = 0, high = arr.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }
        return arr[low];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
