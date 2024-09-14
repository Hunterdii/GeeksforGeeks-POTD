//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    void rearrange(vector<int> &arr) {
        int n = arr.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 0) {
                pos.push_back(arr[i]);
            } else {
                neg.push_back(arr[i]);
            }
        }
        int i = 0, j = 0, k = 0;
        bool toggle = true; 
        while (i < pos.size() && j < neg.size()) {
            if (toggle) {
                arr[k++] = pos[i++];
            } else {
                arr[k++] = neg[j++];
            }
            toggle = !toggle;
        }
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        while (j < neg.size()) {
            arr[k++] = neg[j++];
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
