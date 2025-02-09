//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int findMaxUtil(Node* root, int& res) {
        if (!root) return 0;
        int l = max(0, findMaxUtil(root->left, res));
        int r = max(0, findMaxUtil(root->right, res));
        res = max(res, l + r + root->data);
        return max(l, r) + root->data;
    }

    int findMaxSum(Node* root) {
        int res = INT_MIN;
        findMaxUtil(root, res);
        return res;
    }
};

2)
class Solution {
public:
    int findMaxSum(Node* root) {
        if (!root) return 0;
        stack<Node*> s;
        unordered_map<Node*, int> mp;
        Node* last = nullptr;
        int res = INT_MIN;

        while (root || !s.empty()) {
            if (root) s.push(root), root = root->left;
            else {
                Node* node = s.top();
                if (node->right && last != node->right) root = node->right;
                else {
                    s.pop();
                    int l = max(0, mp[node->left]);
                    int r = max(0, mp[node->right]);
                    res = max(res, l + r + node->data);
                    mp[node] = max(l, r) + node->data;
                    last = node;
                }
            }
        }
        return res;
    }
};

3)
class Solution {
    pair<int, int> dfs(Node* r) {
        if (!r) return {0, INT_MIN};
        
        pair<int, int> left = dfs(r->left);
        pair<int, int> right = dfs(r->right);
        
        int maxSingle = max({r->data, r->data + left.first, r->data + right.first});
        int maxTop = max(maxSingle, r->data + left.first + right.first);
        
        return {maxSingle, max({maxTop, left.second, right.second})};
    }
public:
    int findMaxSum(Node* root) {
        return dfs(root).second;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        cout << ob.findMaxSum(root) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
