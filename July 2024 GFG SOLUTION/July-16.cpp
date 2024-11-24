//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    string printString(const string &str, char ch, int count) {
        int occ = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ch) {
                occ++;
            }
            if (occ == count) {
                if (i + 1 < str.size()) {
                    return str.substr(i + 1);
                } else {
                    return "";
                }
            }
        }
        return "";
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends
