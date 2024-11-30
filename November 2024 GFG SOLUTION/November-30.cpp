//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.length() != s2.length()) return false;
        int counts[26] = {0}; 
        for (int i = 0; i < s1.length(); i++) {
            counts[s1[i] - 'a']++;  
            counts[s2[i] - 'a']--;  
        }
        for (int count : counts) {
            if (count != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends
