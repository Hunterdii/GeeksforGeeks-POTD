# **15. Binary Tree to DLL**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1)

**Note:** Sorry for uploading late, my exam is going on.

### Problem Description

Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in the converted DLL. The order of nodes in the DLL must be the same as the order of the given Binary Tree. The first node of the Inorder traversal (leftmost node in BT) must be the head node of the DLL.

**Example 1:**

Input:

```
      1
    /  \
   3    2
```

Output:

```
3 1 2
2 1 3
```

Explanation: DLL would be 3 <=> 1 <=> 2.

**Example 2:**

Input:

```
       10
      /   \
     20   30
   /   \
  40   60
```

Output:

```
40 20 60 10 30
30 10 60 20 40
```

Explanation: DLL would be 40 <=> 20 <=> 60 <=> 10 <=> 30.

### My Approach

1. **Recursive Inorder Traversal:**

   - Perform an inorder traversal of the binary tree while adjusting the left and right pointers to convert it into a doubly linked list.

2. **Tracking Previous Node:**

   - Maintain a `prev` pointer to link each node with its predecessor during traversal.

3. **Head of DLL:**

   - Set the head of the DLL as the first node encountered during the inorder traversal (i.e., the leftmost node of the tree).

4. **Step-by-Step Conversion:**
   - Traverse the left subtree, connect the current node with the previous node, then traverse the right subtree, ensuring that both the left and right pointers are appropriately assigned.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(no. of nodes), as we are performing a full traversal of the tree, visiting each node once.
- **Expected Auxiliary Space Complexity:** O(height of the tree), as the recursion stack space depends on the height of the binary tree.

### Code (C++)

```cpp
class Solution {
  public:
    Node* prev = NULL;
    Node* bToDLLUtil(Node* root) {
        if (root == NULL) return NULL;
        Node* head = bToDLLUtil(root->left);
        if (prev == NULL)
            head = root;
        else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bToDLLUtil(root->right);

        return head;
    }

    Node* bToDLL(Node* root) {
        prev = NULL;
        return bToDLLUtil(root);
    }
};
```

### Code (Java)

```java
class Solution
{
    Node prev = null;
    Node bToDLL(Node root)
    {
        if (root == null) return null;
        Node head = bToDLL(root.left);
        if (prev == null)
            head = root;
        else {
            root.left = prev;
            prev.right = root;
        }

        prev = root;
        bToDLL(root.right);

        return head;
    }
}
```

### Code (Python)

```python
class Solution:
    def __init__(self):
        self.prev = None
    def bToDLL(self, root):
        if root is None:
            return None
        head = self.bToDLL(root.left)
        if self.prev is None:
            head = root
        else:
            root.left = self.prev
            self.prev.right = root

        self.prev = root
        self.bToDLL(root.right)

        return head
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align=center>
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center" >   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
