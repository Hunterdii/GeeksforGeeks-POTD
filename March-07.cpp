//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestSubstring(string S, int N) {
        // code here
        int maxLen = 0;
        string ans = "-1";
        int i = 0, j = 0;
    
        while (i < N && j < N) {
            string subString = S.substr(i, j - i + 1);
    
            if (S.find(subString, j + 1) != string::npos) {
                int len = subString.length();
                if (len > maxLen) {
                    maxLen = len;
                    ans = subString;
                }
            } else {
                i++;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
