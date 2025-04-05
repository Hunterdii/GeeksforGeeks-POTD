## 04. Construct Binary Tree from Inorder and Postorder

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1)

### Problem Description

Given inorder and postorder traversals of a binary tree (having \(n\) nodes) in the arrays `in[]` and `post[]` respectively, the task is to construct a binary tree from these traversals.

The driver code will print the preorder traversal of the constructed tree.

**Examples:**

1.  Input:

    - \(n = 8\)
    - `in[] = {4, 8, 2, 5, 1, 6, 3, 7}`
    - `post[] = {8, 4, 5, 2, 6, 7, 3, 1}`

    Output:

    ```
    1 2 4 8 5 3 6 7
    ```

    Explanation:
    For the given postorder and inorder traversal of the tree, the resultant binary tree will be:

                 1
              /      \
            2        3
          /  \      /  \
         4   5    6   7
          \
           8

### Approach

1. **Building Tree:**

   - We begin by selecting the last element of the postorder traversal array as the root of the binary tree.
   - We find the index of the root in the inorder traversal to determine the left and right subtrees.
   - Recursively, we construct the right subtree first and then the left subtree.

2. **Helper Function:**

   - We use a helper function to build the tree recursively.
   - This function takes parameters such as the inorder and postorder arrays, along with indices indicating the current range of elements.

3. **Time Complexity:**

   - Since for each node, we search for its index in the inorder traversal, the time complexity of constructing the tree is \(O(n^2)\), where \(n\) is the number of nodes in the tree.

4. **Auxiliary Space Complexity:**
   - The space complexity of the algorithm is \(O(n)\), where \(n\) is the number of nodes in the tree. This is due to the recursive stack space used during the construction of the tree.

### Code (C++)

```cpp
class Solution {
public:
    Node* buildTreeHelper(int in[], int post[], int inStart, int inEnd, int& postIndex) {
        if (inStart > inEnd) return NULL;

        Node* root = new Node(post[postIndex--]); // Create root node using the last element of postorder traversal

        int inIndex; // Index of current root in inorder traversal
        for (int i = inStart; i <= inEnd; ++i) {
            if (in[i] == root->data) {
                inIndex = i;
                break;
            }
        }

        // Construct right subtree first
        root->right = buildTreeHelper(in, post, inIndex + 1, inEnd, postIndex);
        // Construct left subtree
        root->left = buildTreeHelper(in, post, inStart, inIndex - 1, postIndex);

        return root;
    }

    Node* buildTree(int in[], int post[], int n) {
        int postIndex = n - 1; // Start from the last index of postorder traversal
        return buildTreeHelper(in, post, 0, n - 1, postIndex);
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
