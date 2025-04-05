# _06. Root to Leaf Paths Sum_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1)

## Problem Description

Given a binary tree where each node value is a number, find the sum of all the numbers formed from root to leaf paths. The formation of these numbers follows the pattern `10 * parent + current`. The aim is to accumulate the values for each leaf path and return the total sum.

#### Examples:

**Input:**  
Tree Structure:

```
       6
      / \
     3   4
    / \
   2   5
      / \
     7   4
```

**Output:**  
13997  
**Explanation:** The numbers formed are 632, 6357, 6354, and 654. Their sum is 13997.

**Input:**  
Tree Structure:

```
    1
   / \
  2   3
 / \
4   5
```

**Output:**  
2630  
**Explanation:** The numbers formed are 1240, 1260, and 130. Their sum is 2630.

**Input:**  
Tree Structure:

```
   1
  /
 2
```

**Output:**  
12  
**Explanation:** The number formed is 12.

## My Approach

1. **Recursive Calculation:**

   - Use a helper function to perform a depth-first traversal of the binary tree.
   - For each node, maintain a running value that represents the number formed so far. Update this value using the formula `currentValue = currentValue * 10 + node->data`.
   - When a leaf node is reached, add the current value to the total sum.
   - Recursively traverse the left and right children, accumulating the total sum for all paths.

2. **Edge Cases:**
   - If the root is `null`, the output should be 0.
   - If the tree only has one node, the output should be the value of that node.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the number of nodes in the binary tree, as we visit each node exactly once.
- **Expected Auxiliary Space Complexity:** O(h), where `h` is the height of the binary tree. This space is used for the recursion call stack.

## Code (C++)

```cpp
class Solution {
public:
    int treePathsSum(Node* root) {
        int sum = 0;
        calculateSum(root, 0, sum);
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
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

1. **Using a Recursive Helper Function:**

```cpp
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
        return treePathsSumHelper(node->left, currentSum) + treePathsSumHelper(node->right, currentSum);
    }
};
```

2. **Using a Simplified Utility Function:**

```cpp
class Solution {
    int treePathsSumUtil(Node *root, int val) {
        if (!root) return 0;
        val = val * 10 + root->data;
        if (!root->left && !root->right) return val;
        return treePathsSumUtil(root->left, val) + treePathsSumUtil(root->right, val);
    }

public:
    int treePathsSum(Node *root) {
        return treePathsSumUtil(root, 0);
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public int treePathsSum(Node root) {
        return calculateSum(root, 0);
    }

    private int calculateSum(Node node, int currentValue) {
        if (node == null) return 0;
        currentValue = currentValue * 10 + node.data;
        if (node.left == null && node.right == null) {
            return currentValue;
        }
        return calculateSum(node.left, currentValue) + calculateSum(node.right, currentValue);
    }
}
```

## Code (Python)

```python
class Solution:
    def treePathSum(self, root):
        return self.calculateSum(root, 0)

    def calculateSum(self, node, currentValue):
        if not node:
            return 0
        currentValue = currentValue * 10 + node.data
        if not node.left and not node.right:
            return currentValue
        return (self.calculateSum(node.left, currentValue) +
                self.calculateSum(node.right, currentValue))
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
