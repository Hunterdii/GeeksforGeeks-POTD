//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int myAtoi(char *s) {
        int idx = 0, sign = 1;
        long res = 0;

        while (s[idx] == ' ') idx++;

        if (s[idx] == '-' || s[idx] == '+') {
            sign = (s[idx++] == '-') ? -1 : 1;
        }

        while (s[idx] >= '0' && s[idx] <= '9') {
            res = res * 10 + (s[idx++] - '0');

            if (res * sign > INT_MAX) return INT_MAX;
            if (res * sign < INT_MIN) return INT_MIN;
        }

        return static_cast<int>(res * sign);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
