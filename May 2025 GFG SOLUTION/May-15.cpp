//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countSubstring(string &s) {
        long long cnt[256]={}, ans=0;
        for(char c:s) cnt[(unsigned char)c]++;
        for(int i=0;i<256;i++)
            ans += cnt[i]*(cnt[i]+1)/2;
        return (int)ans;
    }
};

2)
class Solution {
  public:
    int countSubstring(string &s) {
        array<int, 26> cnt = {};
        for (char c : s) cnt[c - 'a']++;
        long long ans = 0;
        for (int f : cnt) ans += 1LL * f * (f + 1) / 2;
        return (int)ans;
    }
};

3)
class Solution {
  public:
    int countSubstring(string &s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        long long ans = 0;
        for (auto it = freq.begin(); it != freq.end(); ++it)
            ans += 1LL * it->second * (it->second + 1) / 2;
        return (int)ans;
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

        cout << ob.countSubstring(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
