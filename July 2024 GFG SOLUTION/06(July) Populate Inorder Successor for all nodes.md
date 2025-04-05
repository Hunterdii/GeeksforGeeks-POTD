## 06. Populate Inorder Successor for All Nodes

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1)

### Problem Description

Given a Binary Tree, complete the function to populate the next pointer for all nodes. The next pointer for every node should point to the Inorder successor of the node. You do not have to return or print anything. Just make changes in the root node given to you.

**Note:** The node having no in-order successor will be pointed to -1. You don't have to add -1 explicitly, the driver code will take care of this.

**Examples:**

Input:

```
       10
       /  \
      8   12
     /
    3
```

Output:

```
3->8 8->10 10->12 12->-1
```

Explanation: The inorder of the above tree is: 3 8 10 12. So the next pointer of node 3 is pointing to 8, next pointer of 8 is pointing to 10, and so on. And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.

### My Approach

1. **Initialization:**

   - Initialize a pointer `prev` as `None`. This pointer will keep track of the previous node visited during the in-order traversal.

2. **Inorder Traversal:**

   - Perform an in-order traversal of the tree.
   - During the traversal, update the `next` pointer of the `prev` node to point to the current node.
   - Update `prev` to the current node.

3. **Completion:**
   - Continue the in-order traversal until all nodes have been visited.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we visit each node exactly once during the in-order traversal.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the `prev` pointer.

### Code (C++)

```cpp
class Solution {
public:
    Node* prev = nullptr;

    void populateNext(Node* root) {
        if (root == NULL) return;

        populateNext(root->left);

        if (prev != NULL) {
            prev->next = root;
        }

        prev = root;

        populateNext(root->right);
    }
};
```

### Code (Java)

```java
class Solution {
    Node prev = null;

    public void populateNext(Node root) {
        if (root == null) return;

        populateNext(root.left);

        if (prev != null) {
            prev.next = root;
        }

        prev = root;

        populateNext(root.right);
    }
}
```

### Code (Python)

```python
class Solution:
    def __init__(self):
        self.prev = None

    def populateNext(self, root):
        if not root:
            return

        self.populateNext(root.left)

        if self.prev:
            self.prev.next = root

        self.prev = root

        self.populateNext(root.right)
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
