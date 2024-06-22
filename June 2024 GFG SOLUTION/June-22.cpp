//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    long long ExtractNumber(string sentence) {
        long long num = -1;
        long long currentNum = 0;
        bool validNum = true;
        bool hasDigit = false;

        for (char c : sentence) {
            if (isdigit(c)) {
                hasDigit = true;
                if (c - '0' > 8) {
                    validNum = false;
                }
                currentNum = currentNum * 10 + (c - '0');
            } else {
                if (hasDigit && validNum && currentNum > num) {
                    num = currentNum;
                }
                currentNum = 0;
                validNum = true;
                hasDigit = false;
            }
        }
        if (hasDigit && validNum && currentNum > num) {
            num = currentNum;
        }

        return num;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
