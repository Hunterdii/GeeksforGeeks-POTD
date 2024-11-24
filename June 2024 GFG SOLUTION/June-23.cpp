//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
public:
    vector<int> bracketNumbers(string& str) {
        int op = 0;
        vector<int> v;
        vector<int> st;
        
        for (auto& c : str) {
            if (c == '(') {
                op++;
                st.push_back(op);
                v.push_back(op);
            } else if (c == ')') {
                v.push_back(st.back());
                st.pop_back();
            }
        }
        return v;
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

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
