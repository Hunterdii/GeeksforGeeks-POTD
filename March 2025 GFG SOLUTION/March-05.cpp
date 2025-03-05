//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function template in C++

class Solution {
  public:
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int res = 1;
        for (auto &w : words) {
            dp[w] = 1;
            for (int i = 0; i < w.size(); i++) {
                string pred = w.substr(0, i) + w.substr(i + 1);
                if (dp.count(pred)) dp[w] = max(dp[w], dp[pred] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};


2)
class Solution {
public:
    int longestStringChain(vector<string>& words) {
        unordered_map<string, int> dp;
        int res = 1;
        for (auto &w : words) dp[w] = 1;
        sort(words.begin(), words.end(), [](string &a, string &b) { return a.size() < b.size(); });
        for (auto &w : words) 
            for (int i = 0; i < w.size(); i++) 
                res = max(res, dp[w] = max(dp[w], dp[w.substr(0, i) + w.substr(i + 1)] + 1));
        return res;
    }
};


3)
class Solution {
public:
    unordered_map<string, int> dp;
    int dfs(unordered_set<string>& wordSet, string& word) {
        if (dp.count(word)) return dp[word];
        int res = 1;
        for (int i = 0; i < word.size(); i++) {
            string pred = word.substr(0, i) + word.substr(i + 1);
            if (wordSet.count(pred)) res = max(res, 1 + dfs(wordSet, pred));
        }
        return dp[word] = res;
    }

    int longestStringChain(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        int res = 0;
        for (auto &w : words) res = max(res, dfs(wordSet, w));
        return res;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
