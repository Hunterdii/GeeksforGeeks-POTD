//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(const string& str) {
        int n = str.size();
        if (n == 0) return 0;
        vector<int> lpsArr(n, 0);
        int j = 0;  
        for (int i = 1; i < n; i++) {
            while (j > 0 && str[i] != str[j]) {
                j = lpsArr[j - 1];
            }
            if (str[i] == str[j]) {
                j++;
            }
            lpsArr[i] = j;
        }

        return lpsArr[n - 1];
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
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends
