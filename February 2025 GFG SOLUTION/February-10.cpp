//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
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
    // string after spliting by space
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
/*
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
    unordered_map<int,int> m;
    int cnt = 0;
    void dfs(Node* r, int k, int s) {
        if(!r)return;
        s += r->data;
        if(m.count(s - k)) cnt += m[s - k];
        m[s]++;
        dfs(r->left, k, s);
        dfs(r->right, k, s);
        if(--m[s] == 0) m.erase(s);
    }
    int sumK(Node* r, int k) {
        m[0] = 1;
        dfs(r, k, 0);
        return cnt;
    }
};


2)
class Solution {
public:
    unordered_map<int, int> prefixSumCount;
    int result = 0;

    void dfs(Node* node, int currSum, int k) {
        if (!node) return;

        currSum += node->data;

        if (prefixSumCount.count(currSum - k))
            result += prefixSumCount[currSum - k];

        prefixSumCount[currSum]++;

        dfs(node->left, currSum, k);
        dfs(node->right, currSum, k);

        prefixSumCount[currSum]--; // Backtrack
    }

    int sumK(Node* root, int k) {
        prefixSumCount[0] = 1; // Base case: empty path sums to 0
        dfs(root, 0, k);
        return result;
    }
};

3)
class Solution {
public:
    int sumK(Node* root, int k) {
        if(!root)return 0;
        int cnt = 0;
        stack<pair<Node*, vector<int>>> st;
        st.push(make_pair(root, vector<int>()));
        while(!st.empty()){
            auto cur = st.top(); st.pop();
            Node* node = cur.first;
            vector<int> path = cur.second;
            path.push_back(node->data);
            int s = 0;
            for(int i = path.size()-1; i >= 0; i--){
                s += path[i];
                if(s == k) cnt++;
            }
            if(node->right) st.push(make_pair(node->right, path));
            if(node->left) st.push(make_pair(node->left, path));
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int countFrom(Node* node, int k) {
//         if (!node) return 0;
//         return (node->data == k) +
//               countFrom(node->left, k - node->data) +
//               countFrom(node->right, k - node->data);
//     }

//     int sumK(Node* root, int k) {
//         if (!root) return 0;
//         return countFrom(root, k) + sumK(root->left, k) + sumK(root->right, k);
//     }
// };

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);

    while (t--) {
        string s, ch;
        getline(cin, s);
        Node *root = buildTree(s);

        string key;
        getline(cin, key);
        int k = stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
