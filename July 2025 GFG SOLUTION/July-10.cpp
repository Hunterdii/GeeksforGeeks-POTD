class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_map<string, vector<string>> adj;
        unordered_set<string> wordSet(words.begin(), words.end());
        
        for (string& w : words) {
            if (w.length() > 1) {
                string prefix = w.substr(0, w.length() - 1);
                if (wordSet.count(prefix)) adj[prefix].push_back(w);
            }
        }
        
        string result = "";
        for (string& w : words) {
            if (w.length() == 1) {
                string temp = dfs(w, adj);
                if (temp.length() > result.length()) result = temp;
            }
        }
        return result;
    }
    
private:
    string dfs(string word, unordered_map<string, vector<string>>& adj) {
        string longest = word;
        for (string& next : adj[word]) {
            string candidate = dfs(next, adj);
            if (candidate.length() > longest.length()) longest = candidate;
        }
        return longest;
    }
}; 


2)
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        TrieNode* root = new TrieNode();
        
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children[c - 'a']) 
                    node->children[c - 'a'] = new TrieNode();
                node = node->children[c - 'a'];
            }
            node->isEnd = true;
        }
        
        return dfs(root, "");
    }
    
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            fill(children, children + 26, nullptr);
        }
    };
    
    string dfs(TrieNode* node, string path) {
        string result = path;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] && node->children[i]->isEnd) {
                string candidate = dfs(node->children[i], path + char('a' + i));
                if (candidate.length() > result.length()) result = candidate;
            }
        }
        return result;
    }
};


3)
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;
        string res = "";
        for (string& w : words) {
            if (w.length() == 1 || st.count(w.substr(0, w.length() - 1))) {
                st.insert(w);
                if (w.length() > res.length()) res = w;
            }
        }
        return res;
    }
};


4)
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> valid;
        string ans = "";
        for (auto& word : words) {
            if (word.size() == 1 || valid.find(word.substr(0, word.size() - 1)) != valid.end()) {
                valid.insert(word);
                if (word.size() > ans.size()) ans = word;
            }
        }
        return ans;
    }
};


5)
class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.length() != b.length()) return a.length() < b.length();
            return a < b;
        });
        
        unordered_set<string> valid;
        string result = "";
        
        for (string& w : words) {
            if (w.length() == 1 || valid.count(w.substr(0, w.length() - 1))) {
                valid.insert(w);
                if (w.length() > result.length()) result = w;
            }
        }
        return result;
    }
};

