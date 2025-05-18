//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    return new Node(val);
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
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

/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    vector<int> findSpiral(Node* r) {
        if (!r) return {};
        vector<int> a;
        deque<Node*> q{r};
        bool f = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                Node* x = f ? q.back() : q.front();
                f ? q.pop_back() : q.pop_front();
                a.push_back(x->data);
                if (f) {
                    if (x->right) q.push_front(x->right);
                    if (x->left) q.push_front(x->left);
                } else {
                    if (x->left) q.push_back(x->left);
                    if (x->right) q.push_back(x->right);
                }
            }
            f = !f;
        }
        return a;
    }
};

2)
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        vector<int> ans;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* u = s1.top(); s1.pop();
                ans.push_back(u->data);
                if (u->right) s2.push(u->right);
                if (u->left)  s2.push(u->left);
            }
            while (!s2.empty()) {
                Node* u = s2.top(); s2.pop();
                ans.push_back(u->data);
                if (u->left)  s1.push(u->left);
                if (u->right) s1.push(u->right);
            }
        }
        return ans;
    }
};

3)
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if (!root) return {};
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl;
            for (int i = 0; i < sz; ++i) {
                Node* u = q.front(); q.pop();
                lvl.push_back(u->data);
                if (u->left)  q.push(u->left);
                if (u->right) q.push(u->right);
            }
            levels.push_back(lvl);
        }
        vector<int> ans;
        for (int i = 0; i < levels.size(); ++i) {
            if (i % 2 == 0)
                reverse(levels[i].begin(), levels[i].end());
            ans.insert(ans.end(), levels[i].begin(), levels[i].end());
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    Solution sol; // Create Solution object
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        // Call the findSpiral function from Solution class
        vector<int> vec = sol.findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
