//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Trie {
    struct Node {
        Node* c[26] = {};
        bool end = 0;
    }*r;
public:
    Trie() { r = new Node(); }

    void insert(string &w) {
        auto *n = r;
        for (char ch : w) {
            if (!n->c[ch - 'a']) n->c[ch - 'a'] = new Node();
            n = n->c[ch - 'a'];
        }
        n->end = 1;
    }

    bool search(string &w) {
        auto *n = r;
        for (char ch : w) {
            if (!n->c[ch - 'a']) return 0;
            n = n->c[ch - 'a'];
        }
        return n->end;
    }

    bool isPrefix(string &w) {
        auto *n = r;
        for (char ch : w) {
            if (!n->c[ch - 'a']) return 0;
            n = n->c[ch - 'a'];
        }
        return 1;
    }
};


2)
class Trie {
    struct N { N* c[26] = {}; bool e = 0; }*r = new N;
public:
    void insert(string &w) {
        auto n = r;
        for (char ch : w) n = n->c[ch - 'a'] ?: (n->c[ch - 'a'] = new N);
        n->e = 1;
    }
    bool search(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return n->e;
    }
    bool isPrefix(string &w) {
        auto n = r;
        for (char ch : w) if (!(n = n->c[ch - 'a'])) return 0;
        return 1;
    }
};


3)
struct Node {
    std::unordered_map<char, Node*> m;
    bool e = false;
};

class Trie {
    Node* root = new Node;
public:
    void insert(const string &w) {
        Node* p = root;
        for (char c : w)
            p = p->m.count(c) ? p->m[c] : (p->m[c] = new Node);
        p->e = true;
    }
    bool search(const string &w) {
        Node* p = root;
        for (char c : w)
            if (!p->m.count(c)) return false;
            else p = p->m[c];
        return p->e;
    }
    bool isPrefix(const string &w) {
        Node* p = root;
        for (char c : w)
            if (!p->m.count(c)) return false;
            else p = p->m[c];
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
