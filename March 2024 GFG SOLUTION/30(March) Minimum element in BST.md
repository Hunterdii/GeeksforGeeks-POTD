## 30. Minimum Element in Binary Search Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1)

### Problem Description

Given the root of a Binary Search Tree, the task is to find the minimum valued element in this given BST.

**Example:**

Example 1:

Input:

```
           5
         /    \
        4      6
       /        \
      3          7
     /
    1
```

Output:

```
1
```

Explanation:
The minimum value in the given BST is 1.

**Expected Time Complexity:** O(Height of the BST)
**Expected Auxiliary Space:** O(1)

### Approach 1: Recursive Approach

1. **Recursive Traversal:**
   - Start from the root node and traverse the BST recursively.
   - At each node, compare its value with the minimum value found so far.
   - Recur for the left subtree if it exists.
2. **Base Case:**
   - If the current node is `null`, return `INT_MAX` to indicate no minimum value found.
3. **Return Minimum:**
   - After traversing all nodes, return the minimum value found.

### Code (C++)

```cpp
class Solution {
public:
    int minValue(Node* root) {
        if (root == nullptr)
            return INT_MAX;

        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);

        return std::min(root->data, std::min(leftMin, rightMin));
    }
};
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(Height of the BST), as we traverse the tree until we reach the leftmost node.
- **Expected Auxiliary Space Complexity:** O(1), as we perform recursive calls that occupy stack space proportional to the height of the tree.

### Approach 2: Recursive Approach with Global Variable

1. **Recursive Traversal:**

   - Similar to the first approach, but instead of returning the minimum value found so far from each recursion, we update a global variable `min` to store the minimum value.

2. **Base Case:**
   - If the current node is `null`, return `INT_MAX` to indicate no minimum value found.
3. **Update Minimum:**
   - At each node, update the `min` variable with the minimum of its value and the value stored in `min`.
4. **Return Minimum:**
   - After traversing all nodes, return the value stored in `min`.

### Code (C++)

```cpp
class Solution {
public:
    int min = INT_MAX;

    int minValue(Node* root) {
        if (root == nullptr)
            return INT_MAX;

        if (root->data < min) {
            min = root->data;
        }

        minValue(root->left);
        minValue(root->right);

        return min;
    }
};
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(Height of the BST), as we traverse the tree until we reach the leftmost node.
- **Expected Auxiliary Space Complexity:** O(1), as we perform recursive calls that occupy stack space proportional to the height of the tree.

### Approach 3: Iterative Approach with Improved Space Complexity

1. **Iterative Traversal:**

   - Start from the root node and traverse the left subtree iteratively until we reach the leftmost node.

2. **Update Minimum:**

   - At each node, update the minimum value found so far.

3. **Return Minimum:**
   - After traversing all nodes, return the minimum value found.

### Code (C++)

```cpp
class Solution {
public:
    int minValue(Node* root) {
        if (root == nullptr)
            return INT_MAX;

        int leftMin = minValue(root->left);
        int rightMin = minValue(root->right);

        int minVal = std::min(root->data, std::min(leftMin, rightMin));

        // Only traverse the subtree with the smaller minimum value.
        if (leftMin < minVal)
            return leftMin;
        else if (rightMin < minVal)
            return rightMin;
        else
            return minVal;
    }
};
```

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(Height of the BST), as we traverse the tree until we reach the leftmost node.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

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
