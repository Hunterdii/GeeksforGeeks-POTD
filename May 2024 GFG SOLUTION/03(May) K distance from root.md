## 03. K Distance from Root

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/k-distance-from-root/1)

### Problem Description

Given a binary tree with \(n\) nodes and an integer \(k\), print all nodes that are at a distance \(k\) from the root. Here, the root is considered at distance 0 from itself, and nodes should be printed from left to right.

**Example 1:**

Input:

```
k = 0
      1
    /   \
   3     2
```

Output:

```
1
```

Explanation:
1 is the only node which is 0 distance from the root 1.

### Approach

1. **Depth-First Search (DFS):**

- Start DFS traversal from the root node.
- Maintain a variable `distance` to keep track of the distance of each node from the root.
- If the `distance` becomes equal to `k`, add the node's value to the result vector.
- Recursively traverse the left and right subtrees while incrementing the `distance` by 1.

2. **Return:**

- Return the vector containing nodes at distance \(k\) from the root.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n)\), as we traverse the entire tree once.
- **Expected Auxiliary Space Complexity:** \(O(h)\), where \(h\) is the height of the tree, as the recursive function call stack will go as deep as the height of the tree.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> Kdistance(Node *root, int k) {
        vector<int> result;
        dfs(root, k, result);
        return result;
    }

    void dfs(Node *node, int k, vector<int> &result, int distance = 0) {
        if (!node)
            return;
        if (distance == k) {
            result.push_back(node->data);
            return; // Early termination if distance reaches k
        }
        dfs(node->left, k, result, distance + 1);
        dfs(node->right, k, result, distance + 1);
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
