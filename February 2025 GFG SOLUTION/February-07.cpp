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


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
public:
    vector<int> inOrder(Node* r) {
        vector<int> a;
        while (r) {
            if (!r->left) a.push_back(r->data), r = r->right;
            else {
                Node* p = r->left;
                while (p->right && p->right != r) p = p->right;
                if (!p->right) p->right = r, r = r->left;
                else p->right = nullptr, a.push_back(r->data), r = r->right;
            }
        }
        return a;
    }
};

2)
class Solution{
public:
    void f(Node* r, vector<int>& a){if(!r)return;f(r->left,a);a.push_back(r->data);f(r->right,a);}
    vector<int> inOrder(Node* r){vector<int> a;f(r,a);return a;}
};


3)
class Solution {
public:
    vector<int> inOrder(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* curr = root;
        
        while (curr != nullptr || !st.empty()) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            result.push_back(curr->data);
            curr = curr->right;
        }
        
        return result;
    }
};

4)
class Solution {
public:
    void inorderHelper(Node* root, vector<int>& result) {
        if (!root) return;
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }
    
    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};

5)
class Solution {
public:
    void f(Node* r, vector<int>& a) {
        if (!r)
            return;
        f(r->left, a);
        a.push_back(r->data);
        f(r->right, a);
    }
    
    vector<int> inOrder(Node* r) {
        vector<int> a;
        f(r, a);
        return a;
    }
};


//{ Driver Code Starts.

// Function to Build Tree
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

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        Solution ob;
        vector<int> res = ob.inOrder(root);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
