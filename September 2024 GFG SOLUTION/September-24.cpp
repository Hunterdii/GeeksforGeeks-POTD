//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    string smallestWindow(string s, string p) {
        if (p.length() > s.length()) {
            return "-1";
        }
        vector<int> phash(256, 0);
        for (char ch : p) {
            phash[ch]++;
        }

        vector<int> shash(256, 0);
        int minLength = INT_MAX;
        int startIndex = -1;
        int count = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            shash[ch]++;
            if (phash[ch] != 0 && shash[ch] <= phash[ch]) {
                count++;
            }
            while (count == p.length()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    startIndex = left;
                }
                char leftChar = s[left];
                shash[leftChar]--;
                if (phash[leftChar] != 0 && shash[leftChar] < phash[leftChar]) {
                    count--;
                }
                left++;
            }
        }
        if (startIndex == -1) {
            return "-1";
        }
        return s.substr(startIndex, minLength);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
