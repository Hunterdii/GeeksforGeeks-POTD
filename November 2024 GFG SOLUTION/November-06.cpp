//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
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

class Solution {
  public:
    int treePathsSum(Node* root) {
        int sum = 0, currentValue = 0;
        calculateSum(root, currentValue, sum);
        return sum;
    }

  private:
    void calculateSum(Node* node, int currentValue, int& totalSum) {
        if (!node) return;
        currentValue = currentValue * 10 + node->data;
        if (!node->left && !node->right) {
            totalSum += currentValue;
            return;
        }
        calculateSum(node->left, currentValue, totalSum);
        calculateSum(node->right, currentValue, totalSum);
    }
};

1)
class Solution {
    int treePathsSumUtil(Node *root, int val) {
        if (root == NULL)
            return 0;
        val = (val * 10 + root->data);
        if (root->left == NULL && root->right == NULL)
            return val;
        return treePathsSumUtil(root->left, val) + treePathsSumUtil(root->right, val);
    }

  public:
    int treePathsSum(Node *root) {
        return treePathsSumUtil(root, 0);
    }
};

2)
class Solution {
  public:
    int treePathsSum(Node* root) {
        return treePathsSumHelper(root, 0);
    }

  private:
    int treePathsSumHelper(Node* node, int currentSum) {
        if (!node) return 0;

        currentSum = currentSum * 10 + node->data;

        if (!node->left && !node->right) return currentSum;
        return treePathsSumHelper(node->left, currentSum) +
              treePathsSumHelper(node->right, currentSum);
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.treePathsSum(root);
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends
