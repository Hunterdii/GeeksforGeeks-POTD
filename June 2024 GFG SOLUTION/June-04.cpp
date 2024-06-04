//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string binaryNextNumber(string s) {
        s.erase(0, s.find_first_not_of('0'));
        if (s.empty()) s = "0";
        int n = s.size();
        bool carry = true;
        for (int i = n - 1; i >= 0 && carry; --i) {
            if (s[i] == '0') {
                s[i] = '1';
                carry = false;
            } else {
                s[i] = '0';
            }
        }
        if (carry) {
            s = '1' + s;
        }
        return s;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends