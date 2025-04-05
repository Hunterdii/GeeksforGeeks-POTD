## 06. Print All Nodes That Don't Have Sibling

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1)

### Problem Description

Given a Binary Tree of \(n\) nodes, find all the nodes that don't have any siblings. You need to return a list of integers containing all the nodes that don't have a sibling in sorted order (increasing).

Two nodes are said to be siblings if they are present at the same level, and their parents are the same.

**Example 1:**

Input:

```
       37
      /
    20
    /
  113
```

Output:

```
20 113
```

Explanation:
Nodes 20 and 113 don't have any siblings.

**Example 2:**

Input:

```
       1
      / \
     2   3
```

Output:

```
-1
```

Explanation:
Every node has a sibling.

### Approach

1. **Traversal:**

   - Implement a depth-first traversal of the binary tree.
   - During the traversal, keep track of nodes that don't have siblings.

2. **Sorting and Return:**
   - Sort the list of nodes that don't have siblings in increasing order.
   - If all nodes have siblings, return a list containing only -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(nlogn), where \(n\) is the number of nodes in the binary tree. We traverse the entire tree once, and sorting the result takes \(O(nlogn)\) time.
- **Expected Auxiliary Space Complexity:** O(height of the tree), as the space required is proportional to the height of the tree due to recursive function calls.

### Code (C++)

```cpp
void findNoSibling(Node* node, vector<int> &ans) {
    if (node == NULL)
        return;

    findNoSibling(node->left, ans);

    if ((node->left && !node->right) || (!node->left && node->right))
        ans.push_back(node->left ? node->left->data : node->right->data);

    findNoSibling(node->right, ans);
}

vector<int> noSibling(Node* node) {
    vector<int> ans;
    findNoSibling(node, ans);

    if (ans.empty())
        ans.push_back(-1);

    sort(ans.begin(), ans.end());

    return ans;
}
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
