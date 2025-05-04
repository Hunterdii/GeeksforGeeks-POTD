//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        int n = s.size(), i = 0, j = 0, d = all.size(), c = 0, res = n;
        vector<int> freq(256, 0);
        while (j < n) {
            if (++freq[s[j++]] == 1) c++;
            while (c == d) {
                res = min(res, j - i);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
};

2)
class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        unordered_map<char, int> freq;
        int d = all.size(), c = 0, i = 0, res = s.size();
        for (int j = 0; j < s.size(); ++j) {
            if (++freq[s[j]] == 1) c++;
            while (c == d) {
                res = min(res, j - i + 1);
                if (--freq[s[i++]] == 0) c--;
            }
        }
        return res;
    }
};


3)
class Solution {
  public:
    int findSubString(string& s) {
        unordered_set<char> all(s.begin(), s.end());
        unordered_map<char, int> last;
        int res = s.size(), count = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            last[s[j]]++;
            while (last.size() == all.size()) {
                res = min(res, j - i + 1);
                if (--last[s[i]] == 0) last.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};
//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
