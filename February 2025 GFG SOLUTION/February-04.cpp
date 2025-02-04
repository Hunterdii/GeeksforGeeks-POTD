//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
class Node {class Solution {
public:
    int dfs(Node* n, int &ans) {
        return n ? max(dfs(n->left,ans), dfs(n->right,ans), ans=max(ans,dfs(n->left, ans)+dfs(n->right, ans))) + 1 : 0;
    }
    int diameter(Node* root) { return dfs(root, 0); }
};

public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int dfs(Node* n, int &d) {
        if (!n) return 0;
        int l = dfs(n->left, d), r = dfs(n->right, d);
        return d = max(d, l + r), 1 + max(l, r);
    }

    int diameter(Node* root) {
        int d = 0;
        return dfs(root, d), d;
    }
};

2)
class Solution {
public:
    pair<int,int> f(Node* r){
        if(!r) return {0,0};
        auto l = f(r->left), rt = f(r->right);
        int h = 1 + max(l.first, rt.first);
        int d = max({l.second, rt.second, l.first + rt.first});
        return {h, d};
    }
    int diameter(Node* root){
        return f(root).second;
    }
};

3)
class Solution {
public:
    int diameter(Node* root) {
        if (!root) return 0;
        unordered_map<Node*, int> h;
        vector<Node*> nodes;
        queue<Node*> q; 
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            nodes.push_back(cur);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        int d = 0;
        for (int i = nodes.size()-1; i >= 0; i--) {
            Node* cur = nodes[i];
            int l = cur->left ? h[cur->left] : 0;
            int r = cur->right ? h[cur->right] : 0;
            h[cur] = 1 + max(l, r);
            d = max(d, l + r);
        }
        return d;
    }
};

4)
class Solution {
public:
    void build(Node* r, unordered_map<Node*, vector<Node*>>& g) {
        if (!r) return;
        if (r->left) {
            g[r].push_back(r->left);
            g[r->left].push_back(r);
            build(r->left, g);
        }
        if (r->right) {
            g[r].push_back(r->right);
            g[r->right].push_back(r);
            build(r->right, g);
        }
    }
    
    pair<Node*, int> dfs(Node* r, Node* p, unordered_map<Node*, vector<Node*>>& g) {
        pair<Node*, int> res = {r, 0};
        for (auto nb : g[r]) {
            if (nb == p) continue;
            auto t = dfs(nb, r, g);
            t.second++;
            if (t.second > res.second) res = t;
        }
        return res;
    }
    
    int diameter(Node* root) {
        if (!root) return 0;
        unordered_map<Node*, vector<Node*>> g;
        build(root, g);
        auto f = dfs(root, nullptr, g);
        auto s = dfs(f.first, nullptr, g);
        return s.second;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function */
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
