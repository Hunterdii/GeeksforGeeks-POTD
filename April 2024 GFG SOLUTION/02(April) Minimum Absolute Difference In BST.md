## 02. Minimum Absolute Difference in BST

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1)

### Problem Description

Given a binary search tree having \( n \) (\( n > 1 \)) nodes, the task is to find the minimum absolute difference between any two nodes.

**Example:**

Input Tree:
<br/>

<p align="center">
<img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/67de4a06-fbb5-4513-b49f-6517d94104d2" alt="Image" width="450" />
</p>

Output:

```
10
```

Explanation:
There are no two nodes whose absolute difference is smaller than 10.

### My Approach

1. **Inorder Traversal:**

   - Traverse the BST in inorder traversal, which will give the elements in sorted order.
   - Keep track of the previous visited node's value and compute the absolute difference between the current node's value and the previous node's value.
   - Update the minimum absolute difference encountered so far.

2. **Return:**
   - Return the minimum absolute difference.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse through all the nodes of the BST once during the inorder traversal.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing variables like `prev` and `minDiff`.

### Code (C++)

```cpp
class Solution
{
public:
    void inorder(Node *root, int &prev, int &minDiff) {
        if (!root) return;
        inorder(root->left, prev, minDiff);
        if (prev != INT_MAX) {
            minDiff = min(minDiff, root->data - prev);
        }
        prev = root->data;
        inorder(root->right, prev, minDiff);
    }

    int absolute_diff(Node *root) {
        int minDiff = INT_MAX;
        int prev = INT_MAX;
        inorder(root, prev, minDiff);
        return minDiff;
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
