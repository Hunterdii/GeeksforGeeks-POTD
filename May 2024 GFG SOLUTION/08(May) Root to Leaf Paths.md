## 08. Root to Leaf Paths

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1)

### Problem Description

Given a Binary Tree of nodes, find all possible paths from the root node to all the leaf nodes of the binary tree.

**Example 1:**

Input:

```
       1
    /     \
   2       3
```

Output:

```
1 2
1 3
```

Explanation:
All possible paths:
1->2
1->3

**Example 2:**

Input:

```
         10
       /    \
      20    30
     /  \
    40   60
```

Output:

```
10 20 40
10 20 60
10 30
```

### My Approach

1. **Depth-First Search (DFS):**

- Implement a recursive DFS function to traverse the binary tree.
- At each node, append the node's value to the current path.
- When reaching a leaf node, add the current path to the list of paths.

2. **Path Collection:**

- Use a vector of vectors to store all the paths found during the DFS traversal.

3. **Return:**

- Return the vector containing all the root to leaf paths.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where \(n\) is the number of nodes in the binary tree. We traverse each node exactly once.
- **Expected Auxiliary Space Complexity:** O(h), where \(h\) is the height of the binary tree. In the worst case, the recursion stack can go as deep as the height of the tree.

### Code (C++)

```cpp
class Solution {
public:
    void solve(Node* root, vector<vector<int>>& ans, vector<int>& ds) {
        if(root == NULL) return;

        ds.push_back(root->data);

        if(root->left == NULL && root->right == NULL) {
            ans.push_back(ds);
            return;
        }

        if(root->left) {
            solve(root->left, ans, ds);
            ds.pop_back(); // Backtrack after exploring left subtree
        }

        if(root->right) {
            solve(root->right, ans, ds);
            ds.pop_back(); // Backtrack after exploring right subtree
        }
    }

    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root, ans, ds);
        return ans;
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
