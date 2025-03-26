//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> u(d.begin(), d.end());
        int n = s.size(), m = 0;
        for(auto &w : d) m = max(m, (int)w.size());
        vector<bool> dp(n + 1);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            if(!dp[i]) continue;
            for(int j = 1; j <= m && i + j <= n; j++)
                if(u.count(s.substr(i, j))) dp[i + j] = 1;
        }
        return dp[n];
    }
};


2)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size(), maxLen = 0;
        for (auto &w : wordDict) maxLen = max(maxLen, (int)w.size());
        
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;
            for (int j = 1; j <= maxLen && i + j <= n; j++) {
                if (dict.count(s.substr(i, j))) dp[i + j] = true;
            }
        }
        return dp[n];
    }
};

3)
struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isEnd(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(const string &word) {
        TrieNode* node = root;
        for(char c : word) {
            if(!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isEnd = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        Trie trie;
        for(auto &w: d) trie.insert(w);
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            TrieNode* node = trie.root;
            for(int j = i; j < n; j++){
                char c = s[j];
                if(!node->children.count(c)) break;
                node = node->children[c];
                if(node->isEnd && dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
//{ Driver Code Starts.

vector<string> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<string> res;
    while (ss >> str) {
        res.push_back(str);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        cin >> s;
        cin.ignore();
        vector<string> dictionary = inputLine();

        Solution ob;
        if (ob.wordBreak(s, dictionary)) {
            cout << "true\n";
        } else
            cout << "false\n";
        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
