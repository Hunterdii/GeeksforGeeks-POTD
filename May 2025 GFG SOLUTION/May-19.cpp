//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


// } Driver Code Ends

/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr;
        Node* curr = root;
        while (curr) {
            if (curr->data < key) {
                pre = curr;
                curr = curr->right;
            } else curr = curr->left;
        }
        curr = root;
        while (curr) {
            if (curr->data > key) {
                suc = curr;
                curr = curr->left;
            } else curr = curr->right;
        }
        return {pre, suc};
    }
};


2)
class Solution {
  void find(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;
    if (root->data == key) {
        Node* l = root->left;
        while (l) pre = l, l = l->right;
        Node* r = root->right;
        while (r) suc = r, r = r->left;
    } else if (root->data > key) {
        suc = root;
        find(root->left, pre, suc, key);
    } else {
        pre = root;
        find(root->right, pre, suc, key);
    }
  }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr;
        find(root, pre, suc, key);
        return {pre, suc};
    }
};

3)
class Solution {
  void inorder(Node* root, vector<Node*>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
  }

  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> nodes;
        inorder(root, nodes);
        Node *pre = nullptr, *suc = nullptr;
        for (Node* node : nodes) {
            if (node->data < key) pre = node;
            else if (node->data > key) {
                suc = node;
                break;
            }
        }
        return {pre, suc};
    }
};

4)
class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node *pre = nullptr, *suc = nullptr, *curr = root;

        while (curr) {
            if (!curr->left) {
                if (curr->data < key) pre = curr;
                else if (curr->data > key && !suc) suc = curr;
                curr = curr->right;
            } else {
                Node* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    if (curr->data < key) pre = curr;
                    else if (curr->data > key && !suc) suc = curr;
                    curr = curr->right;
                }
            }
        }

        return {pre, suc};
    }
};


//{ Driver Code Starts.

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
    Node* root = new Node(stoi(ip[0]));

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Driver program to test above functions
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int key = stoi(s);

        Solution ob;
        vector<Node*> result = ob.findPreSuc(root, key);
        Node* pre = result[0];
        Node* suc = result[1];

        if (pre != nullptr)
            cout << pre->data << " ";
        else
            cout << -1 << " ";

        if (suc != nullptr)
            cout << suc->data << endl;
        else
            cout << -1 << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
