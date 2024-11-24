//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int minRepeats(string s1, string s2) {
        int repeat = 1;
        string repeatedStr = s1;

        while (repeatedStr.length() < s2.length()) {
            repeatedStr += s1;
            repeat++;
        }

        if (repeatedStr.find(s2) != string::npos)
            return repeat;

        repeatedStr += s1;
        repeat++;

        if (repeatedStr.find(s2) != string::npos)
            return repeat;

        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends
