## 18. Level Order Traversal

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/level-order-traversal/1)

### Problem Description

Given a root of a binary tree with \( n \) nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

**Example 1:**

Input:

```
        10
     /      \
    20       30
  /   \
 40   60
```

Output:

```
10 20 30 40 60
```

### My Approach

1. **Initialization:**

   - Start by checking if the tree is empty. If it is, return an empty result vector.

2. **Level Order Traversal:**

   - Use a queue to perform a level-order traversal.
   - Push the root node into the queue.
   - While the queue is not empty, do the following:
     - Get the number of nodes at the current level.
     - Iterate through each node at the current level:
       - Pop the front node from the queue.
       - Push its data into the result vector.
       - Enqueue its child nodes if they exist.
   - Continue until the queue is empty.

3. **Return Result:**
   - Return the result vector containing the level order traversal of the binary tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \( O(n) \), where \( n \) is the number of nodes in the binary tree. We visit each node once.
- **Expected Auxiliary Space Complexity:** \( O(n) \), as we use a queue to perform the level order traversal, which can contain up to \( n \) nodes at its maximum size.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> levelOrder(Node* root) {
        vector<int> result;
        if (!root) return result; // Check if the tree is empty

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Get the number of nodes at the current level

            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                result.push_back(node->data);

                // Enqueue child nodes if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return result;
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
