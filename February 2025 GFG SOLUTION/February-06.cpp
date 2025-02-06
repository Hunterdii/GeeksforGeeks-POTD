//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<int, int> idxMap;
    int preIndex = 0;

    Node* build(vector<int>& inorder, vector<int>& preorder, int inStart, int inEnd) {
        if (inStart > inEnd) return NULL;
        Node* root = new Node(preorder[preIndex++]);
        int mid = idxMap[root->data];
        root->left = build(inorder, preorder, inStart, mid - 1);
        root->right = build(inorder, preorder, mid + 1, inEnd);
        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        for (int i = 0; i < inorder.size(); i++) idxMap[inorder[i]] = i;
        return build(inorder, preorder, 0, inorder.size() - 1);
    }
};


class Solution {
public:
    unordered_map<int, int> m;
    int i = 0;
    Node* f(vector<int>& in, vector<int>& pre, int l, int r) {
        if(l > r) return nullptr;
        Node* root = new Node(pre[i++]);
        int pos = m[root->data];
        root->left = f(in, pre, l, pos - 1);
        root->right = f(in, pre, pos + 1, r);
        return root;
    }
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        for (int j = 0; j < inorder.size(); j++) m[inorder[j]] = j;
        return f(inorder, preorder, 0, inorder.size() - 1);
    }
};


class Solution {
public:
    int i = 0;
    unordered_map<int, int> m;
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        for (int j = 0; j < inorder.size(); j++) m[inorder[j]] = j;
        function<Node*(int, int)> f = [&](int l, int r) -> Node* {
            if (l > r) return nullptr;
            Node* root = new Node(preorder[i++]);
            root->left = f(l, m[root->data] - 1);
            root->right = f(m[root->data] + 1, r);
            return root;
        };
        return f(0, inorder.size() - 1);
    }
};

2)
class Solution {
public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        Node* root = new Node(preorder[0]);
        stack<Node*> s;
        s.push(root);
        int inIndex = 0;
        for (int i = 1; i < preorder.size(); i++) {
            Node* node = s.top();
            if (node->data != inorder[inIndex]) {
                node->left = new Node(preorder[i]);
                s.push(node->left);
            } else {
                while(!s.empty() && s.top()->data == inorder[inIndex]) {
                    node = s.top();
                    s.pop();
                    inIndex++;
                }
                node->right = new Node(preorder[i]);
                s.push(node->right);
            }
        }
        return root;
    }
};

3)
class Solution {
    unordered_map<int, int> m;
    int i;
    Node* f(vector<int>& pre, vector<int>& in, int l, int r) {
        if (l > r) return nullptr;
        Node* root = new Node(pre[i++]);
        int idx = m[root->data];
        root->left = f(pre, in, l, idx - 1);
        root->right = f(pre, in, idx + 1, r);
        return root;
    }
public:
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        i = 0;
        for (int j = 0; j < inorder.size(); j++) m[inorder[j]] = j;
        return f(preorder, inorder, 0, inorder.size() - 1);
    }
};


//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
