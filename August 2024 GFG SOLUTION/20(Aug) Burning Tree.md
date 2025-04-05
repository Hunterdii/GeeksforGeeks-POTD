# <b>20. Burning Tree</b>

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/burning-tree/1)

### Problem Description

Given a binary tree and a node data called `target`, find the minimum time required to burn the complete binary tree if the target node is set on fire. It is known that in 1 second, all nodes connected to a given node get burned. This includes its left child, right child, and parent. The tree contains unique values.

**Example:**

Input:

```
        1
      /   \
    2      3
  /  \      \
 4    5      6
     / \      \
    7   8      9
                 \
                 10
```

Target Node = 8

Output:

```
7
```

Explanation: If leaf with the value 8 is set on fire:

- After 1 sec: 5 is set on fire.
- After 2 sec: 2, 7 are set on fire.
- After 3 sec: 4, 1 are set on fire.
- After 4 sec: 3 is set on fire.
- After 5 sec: 6 is set on fire.
- After 6 sec: 9 is set on fire.
- After 7 sec: 10 is set on fire.

It takes 7 seconds to burn the complete tree.

### My Approach

1. **Depth Calculation:**

   - Implement a helper function `maxDepth` to calculate the maximum depth of a node. This function will be used to determine the maximum distance from a given node to its furthest leaf.

2. **Tree Traversal:**

   - Implement a helper function `traverse` to recursively search for the target node. This function updates the maximum time required to burn the tree based on the depth of the left and right subtrees.

3. **Calculate Minimum Time:**
   - The function `minTime` initializes the traversal and returns the result, which is the maximum time required to burn the entire tree starting from the target node.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(number of nodes), as we need to visit each node to determine its depth and check connections.
- **Expected Auxiliary Space Complexity:** O(height of the tree), due to the recursive stack space used during traversal.

### Code (C++)

```cpp
class Solution {
public:
    int maxDepth(Node* n) {
        if (!n) return 0;
        return 1 + std::max(maxDepth(n->left), maxDepth(n->right));
    }

    int traverse(Node* n, int target, int& ret) {
        if (!n) return 0;
        if (n->data == target) {
            ret = std::max(ret, maxDepth(n->left));
            ret = std::max(ret, maxDepth(n->right));
            return 1;
        }

        int left = traverse(n->left, target, ret);
        int right = traverse(n->right, target, ret);

        if (left > 0) {
            ret = std::max(ret, left + maxDepth(n->right));
            return left + 1;
        }

        if (right > 0) {
            ret = std::max(ret, right + maxDepth(n->left));
            return right + 1;
        }

        return 0;
    }

    int minTime(Node* root, int target) {
        int ret = 0;
        traverse(root, target, ret);
        return ret;
    }
};
```

### Code (Java)

```java
class Solution {
    private int maxDepth(Node node) {
        if (node == null) return 0;
        return 1 + Math.max(maxDepth(node.left), maxDepth(node.right));
    }

    private int traverse(Node node, int target, int[] ret) {
        if (node == null) return 0;
        if (node.data == target) {
            ret[0] = Math.max(ret[0], maxDepth(node.left));
            ret[0] = Math.max(ret[0], maxDepth(node.right));
            return 1;
        }

        int left = traverse(node.left, target, ret);
        int right = traverse(node.right, target, ret);

        if (left > 0) {
            ret[0] = Math.max(ret[0], left + maxDepth(node.right));
            return left + 1;
        }

        if (right > 0) {
            ret[0] = Math.max(ret[0], right + maxDepth(node.left));
            return right + 1;
        }

        return 0;
    }

    public int minTime(Node root, int target) {
        int[] ret = new int[1];
        traverse(root, target, ret);
        return ret[0];
    }
}
```

### Code (Python)

```python
class Solution:
    def minTime(self, root, target):
        def maxDepth(node):
            if not node:
                return 0
            return 1 + max(maxDepth(node.left), maxDepth(node.right))

        def traverse(node, target):
            if not node:
                return 0
            if node.data == target:
                ret[0] = max(ret[0], maxDepth(node.left))
                ret[0] = max(ret[0], maxDepth(node.right))
                return 1

            left = traverse(node.left, target)
            right = traverse(node.right, target)

            if left > 0:
                ret[0] = max(ret[0], left + maxDepth(node.right))
                return left + 1

            if right > 0:
                ret[0] = max(ret[0], right + maxDepth(node.left))
                return right + 1

            return 0

        ret = [0]
        traverse(root, target)
        return ret[0]
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
