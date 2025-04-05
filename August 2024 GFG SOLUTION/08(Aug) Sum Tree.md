## 08. Sum Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sum-tree/1)

### Problem Description

Given a Binary Tree, check whether it is a Sum Tree or not. A Sum Tree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree. An empty tree is also considered a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.

**Example:**

Input:

```
    3
  /   \
 1     2
```

Output:

```
true
```

Explanation:
The sum of the left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore, the given binary tree is a Sum Tree.

Input:

```
          10
        /    \
      20      30
    /   \
   10    10
```

Output:

```
false
```

Explanation:
The given tree is not a Sum Tree. For the root node, the sum of elements in the left subtree is 40 and the sum of elements in the right subtree is 30. The root element is 10, which is not equal to 30 + 40.

### My Approach

1. **Leaf Node Check:**

   - Define a helper function `isLeaf` to check if a node is a leaf node (i.e., it has no children).

2. **Sum Tree Check:**

   - Define a recursive helper function `checkSumTree` that checks whether a given tree is a Sum Tree. This function calculates the sum of the nodes in the left and right subtrees and verifies if the current node's value equals this sum.

3. **Main Function:**
   - The main function `isSumTree` uses the `checkSumTree` helper to determine if the entire tree is a Sum Tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. Each node is visited once in a post-order traversal.
- **Expected Auxiliary Space Complexity:** O(h), where h is the height of the binary tree. This space is used by the call stack during recursion.

### Code (C++)

```cpp
class Solution {
public:
    bool isLeaf(Node* node) {
        return (node != nullptr && node->left == nullptr && node->right == nullptr);
    }

    bool checkSumTree(Node* node, int &sum) {
        if (node == nullptr) {
            sum = 0;
            return true;
        }
        if (isLeaf(node)) {
            sum = node->data;
            return true;
        }

        int leftSum = 0, rightSum = 0;

        if (checkSumTree(node->left, leftSum) && checkSumTree(node->right, rightSum)) {
            sum = node->data + leftSum + rightSum;
            return node->data == leftSum + rightSum;
        }

        return false;
    }

    bool isSumTree(Node* root) {
        int sum = 0;
        return checkSumTree(root, sum);
    }
};
```

### Code (Java)

```java
class Solution {
    boolean isLeaf(Node node) {
        return (node != null && node.left == null && node.right == null);
    }

    boolean checkSumTree(Node node, int[] sum) {
        if (node == null) {
            sum[0] = 0;
            return true;
        }
        if (isLeaf(node)) {
            sum[0] = node.data;
            return true;
        }

        int[] leftSum = {0}, rightSum = {0};

        if (checkSumTree(node.left, leftSum) && checkSumTree(node.right, rightSum)) {
            sum[0] = node.data + leftSum[0] + rightSum[0];
            return node.data == leftSum[0] + rightSum[0];
        }

        return false;
    }

    boolean isSumTree(Node root) {
        int[] sum = {0};
        return checkSumTree(root, sum);
    }
}
```

### Code (Python)

```python
class Solution:

    def is_leaf(self, node):
        if node is None:
            return True
        if node.left is None and node.right is None:
            return True
        return False

    def is_sum_tree(self, node):
        if node is None or self.is_leaf(node):
            return True

        if self.is_sum_tree(node.left) and self.is_sum_tree(node.right):
            ls = 0
            rs = 0

            if node.left is None:
                ls = 0
            elif self.is_leaf(node.left):
                ls = node.left.data
            else:
                ls = 2 * node.left.data

            if node.right is None:
                rs = 0
            elif self.is_leaf(node.right):
                rs = node.right.data
            else:
                rs = 2 * node.right.data

            return node.data == ls + rs

        return False
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
