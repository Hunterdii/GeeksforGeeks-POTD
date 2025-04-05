## 20. Sum of the Longest Root to Leaf Path

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1)

### Problem Description

Given a binary tree having n nodes. Find the sum of all nodes on the longest path from root to any leaf node. If two or more paths compete for the longest path, then the path having the maximum sum of nodes will be considered.

**Example:**

Input:

```
        4
       /  \
      2   5
     / \   /  \
    7  1 2  3
      /
     6
```

Output:

```
13
```

Explanation:

```
        4
       /  \
      2   5
     / \   /  \
    7  1 2  3
      /
     6
```

The highlighted nodes (4, 2, 1, 6) above are part of the longest root to leaf path having the sum = (4 + 2 + 1 + 6) = 13

### My Approach

1. We will perform a depth-first search (DFS) traversal of the binary tree.
2. During traversal, we will keep track of the length and sum of the current path.
3. We will update the maximum length and maximum sum whenever we encounter a leaf node or reach the end of a path.
4. Finally, we return the maximum sum obtained during the traversal.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we visit each node of the binary tree exactly once.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
    void dfs(Node *root, int len, int& maxLen, int sum, int &maxSum) {
        if (root == nullptr) {
            if (len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if (len == maxLen) {
                maxSum = std::max(sum, maxSum);
            }
            return;
        }

        sum += root->data;
        dfs(root->left, len + 1, maxLen, sum, maxSum);
        dfs(root->right, len + 1, maxLen, sum, maxSum);
    }

public:
    int sumOfLongRootToLeafPath(Node *root) {
        if (root == nullptr) {
            return 0;
        }

        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = 0;

        dfs(root, len, maxLen, sum, maxSum);

        return maxSum;
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
