//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string addBinary(const string& s1, const string& s2) {
        int i = s1.size() - 1, j = s2.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }

        reverse(result.begin(), result.end());
        size_t first_non_zero = result.find_first_not_of('0');
        return (first_non_zero != string::npos) ? result.substr(first_non_zero) : "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
