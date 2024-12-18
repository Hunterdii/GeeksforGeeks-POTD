//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1; 
        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
        while (low < high) {
            int mid = (low + high) / 2, students = 1, sum = 0;
            for (int pages : arr) {
                if (sum + pages > mid) students++, sum = pages;
                else sum += pages;
            }
            (students > k ? low : high) = mid + (students > k);
        }
        return low;
    }
};

2)
class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1; 
        int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
        while (low < high) {
            int mid = (low + high) / 2, students = 1, sum = 0;
            for (int pages : arr) {
                if ((sum += pages) > mid) students++, sum = pages;
            }
            if (students > k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
