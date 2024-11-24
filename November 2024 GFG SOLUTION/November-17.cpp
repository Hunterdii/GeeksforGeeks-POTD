//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

1)
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

2)
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        std::reverse(arr.begin(), arr.end());
    }
};

3)
class Solution {
public:
    void reverseArray(std::vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            arr[left] ^= arr[right];
            arr[right] ^= arr[left];
            arr[left] ^= arr[right];
            left++;
            right--;
        }
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
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
