//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int kthSmallest(std::vector<int> &arr, int k) {
        int min_element = *std::min_element(arr.begin(), arr.end());
        int max_element = *std::max_element(arr.begin(), arr.end());
        int range = max_element - min_element + 1;
        
        std::vector<int> freq(range, 0);
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i] - min_element]++;
        }
        
        int count = 0;
        for (int i = 0; i < range; i++) {
            count += freq[i];
            if (count >= k) {
                return i + min_element;
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
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
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
