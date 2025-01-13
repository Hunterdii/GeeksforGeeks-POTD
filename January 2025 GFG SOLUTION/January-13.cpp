//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, area = 0;
        while (l < r) {
            area = max(area, min(arr[l], arr[r]) * (r - l));
            arr[l] < arr[r] ? ++l : --r;
        }
        return area;
    }
};

2)
class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0;
        while (l < r) res = max(res, (r - l) * (arr[l] < arr[r] ? arr[l++] : arr[r--]));
        return res;
    }
};

3)
class Solution {
public:
    int maxWater(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, res = 0;
        while (l < r) {
            res = max(res, (r - l) * min(arr[l], arr[r]));
            if (arr[l] < arr[r])
                l++;
            else
                r--;
        }
        return res;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
