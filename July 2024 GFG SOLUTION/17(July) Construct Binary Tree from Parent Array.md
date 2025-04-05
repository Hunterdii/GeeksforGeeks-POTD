## 17. Construct Binary Tree from Parent Array

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1)

### Problem Description

Given an array `parent` that is used to represent a tree, construct the standard linked representation of the binary tree from this array representation and return the root node of the constructed tree. The array indices (0-based indexing) are the values of the tree nodes, and `parent[i]` denotes the parent node of a particular node. The parent of the root node is always `-1`, as there is no parent for the root.

Note: If two elements have the same parent, the one that appears first in the array will be the left child, and the other is the right child.

**Example:**

Input:

```
parent = [-1, 0, 0, 1, 1, 3, 5]
```

Output:

```
0 1 2 3 4 5 6
```

Explanation:
The tree generated will have a structure like:

```
        0
      /   \
     1     2
    / \
   3   4
  /
 5
/
6
```

### My Approach

1. **Initialization:**

- Create an array `created` of size `n` to store the created nodes.
- Initialize the `root` node as `NULL`.

2. **Node Creation:**

- Iterate through the `parent` array.
- For each index `i`, create a node if it has not been created.
- If the `parent[i]` is `-1`, set the `root` as the created node.
- Otherwise, recursively ensure the parent node is created, then attach the current node as the left or right child of the parent node.

3. **Return:**

- Return the `root` node of the constructed tree.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the `parent` array and create nodes.
- **Expected Auxiliary Space Complexity:** O(n), as we use an array of size `n` to store the created nodes.

### Code (C++)

```cpp
class Solution {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(NULL), right(NULL) {}
    };

    void createNode(vector<int> parent, int i, Node* created[], Node** root) {
        if (created[i] != NULL)
            return;

        created[i] = new Node(i);

        if (parent[i] == -1) {
            *root = created[i];
            return;
        }

        if (created[parent[i]] == NULL)
            createNode(parent, parent[i], created, root);

        Node* p = created[parent[i]];
        if (p->left == NULL)
            p->left = created[i];
        else
            p->right = created[i];
    }

    Node* createTree(vector<int> parent) {
        int n = parent.size();
        Node* created[n];
        for (int i = 0; i < n; i++)
            created[i] = NULL;

        Node* root = NULL;
        for (int i = 0; i < n; i++)
            createNode(parent, i, created, &root);
        return root;
    }
};
```

### Code (Java)

```java
class Solution {
    class Node {
        int data;
        Node left, right;
        Node(int val) { data = val; left = right = null; }
    }

    public Node createTree(int[] parent) {
        int n = parent.length;
        Node[] created = new Node[n];
        Node root = null;

        for (int i = 0; i < n; i++) {
            if (created[i] == null) {
                createNode(parent, i, created);
            }
        }

        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root = created[i];
                break;
            }
        }

        return root;
    }

    private void createNode(int[] parent, int i, Node[] created) {
        if (created[i] != null) return;

        created[i] = new Node(i);

        if (parent[i] == -1) return;

        if (created[parent[i]] == null) {
            createNode(parent, parent[i], created);
        }

        Node p = created[parent[i]];
        if (p.left == null) {
            p.left = created[i];
        } else {
            p.right = created[i];
        }
    }
}
```

### Code (Python)

```python
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Solution:
    def createTree(self, parent):
        n = len(parent)
        created = [None] * n
        root = None

        for i in range(n):
            if created[i] is None:
                self.createNode(parent, i, created)

        for i in range(n):
            if parent[i] == -1:
                root = created[i]
                break

        return root

    def createNode(self, parent, i, created):
        if created[i] is not None:
            return

        created[i] = Node(i)

        if parent[i] == -1:
            return

        if created[parent[i]] is None:
            self.createNode(parent, parent[i], created)

        p = created[parent[i]]
        if p.left is None:
            p.left = created[i]
        else:
            p.right = created[i]
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
