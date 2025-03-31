//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int maxPartitions(string &s) {
        int ans = 0, end = 0;
        vector<int> last(26);
        for (int i = 0; i < s.size(); i++) 
            last[s[i] - 'a'] = i;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) ans++;
        }
        return ans;
    }
};

2)
class Solution {
public:
    int maxPartitions(string &s) {
        vector<pair<int, int>> intervals;
        vector<int> first(26, s.size()), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            first[idx] = min(first[idx], i);
            last[idx] = i;
        }
        for (int i = 0; i < 26; i++) {
            if (last[i] != -1)
                intervals.push_back({first[i], last[i]});
        }
        sort(intervals.begin(), intervals.end());
        int count = 0, start = intervals[0].first, end = intervals[0].second;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > end) {
                count++;
                start = intervals[i].first;
                end = intervals[i].second;
            } else {
                end = max(end, intervals[i].second);
            }
        }
        return count + 1;
    }
};

3)
class Solution {
public:
    int maxPartitions(string &s) {
        vector<int> first(26, -1), last(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (first[idx] == -1)
                first[idx] = i;
            last[idx] = i;
        }
        int count = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
                count++;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
