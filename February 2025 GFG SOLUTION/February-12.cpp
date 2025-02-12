//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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


// } Driver Code Ends
/*Complete the function below

struct Node {
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
    void inorder(Node* root, int& k, int& res) {
        if (!root) return;
        inorder(root->left, k, res);
        if (--k == 0) { res = root->data; return; }
        inorder(root->right, k, res);
    }
    int kthSmallest(Node* root, int k) {
        int res = -1;
        inorder(root, k, res);
        return res;
    }
};

2)
class Solution {
public:
    int kthSmallest(Node* root, int k) {
        if (!root) return -1; 
        stack<Node*> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) return -1;
            root = st.top(); st.pop();
            if (--k == 0) return root->data; 
            root = root->right;
        }
    }
};


3)
class Solution {
public:
    int kthSmallest(Node* root, int &k) {
        if (!root) return -1;
        int left = kthSmallest(root->left, k);
        if (k == 0) return left;
        if (--k == 0) return root->data;
        return kthSmallest(root->right, k);
    }
};


4)
class Solution {
  public:
    int kthSmallest(Node* root, int k) {
        while (root) {
            if (!root->left) {
                if (--k == 0) return root->data;
                root = root->right;
            } else {
                Node* pre = root->left;
                while (pre->right && pre->right != root) pre = pre->right;
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = NULL;
                    if (--k == 0) return root->data;
                    root = root->right;
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
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
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.kthSmallest(root, k) << endl;
        // cout<<"~"<<endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
