//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
// } Driver Code Ends

class Solution {
public:
    std::string removeDuplicates(std::string str) {
        std::unordered_set<char> seen;
        std::string result = "";
        
        for (char& c : str) {
            if (seen.find(c) == seen.end()) {
                result += c;
                seen.insert(c);
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
