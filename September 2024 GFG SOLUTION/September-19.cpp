//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string reverseWords(string str) {
        string result = "";
        int n = str.length();
        int end = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (str[i] == '.') {
                result.append(str.substr(i + 1, end - i)).append(".");
                end = i - 1; 
            }
        }
        result.append(str.substr(0, end + 1));

        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
