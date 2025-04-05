# **23. Left View of Binary Tree**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)

### **Problem Description**

## **Note:** Sorry for uploading late; my exam is going on.

Given a Binary Tree, return the Left view of it. The Left view of a Binary Tree is the set of nodes visible when the tree is visited from the Left side. The task is to complete the function `leftView()`, which accepts the root of the tree as an argument. If no left view is possible, return an empty list.

**Example:**

Input:

```
   1
 /  \
3    2
```

Output:

```
1 3
```

Input:

```
        10
       /  \
     20   30
    /  \
   40  60
```

Output:

```
10 20 40
```

### **My Approach**

1. **Recursive Traversal:**

   - Use a recursive function to traverse the tree and keep track of the maximum level visited so far.
   - If the current level is greater than the maximum level seen so far, add the current node’s value to the result.
   - Traverse the left subtree before the right subtree to ensure the leftmost node at each level is considered first.

2. **Utility Function:**
   - The utility function `leftViewUtil` is used to perform the actual traversal, updating the result list when a node at a new level is encountered.

### **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as each node is visited exactly once.
- **Expected Auxiliary Space Complexity:** O(N), considering the recursive stack space used during the traversal.

### **Code (C++)**

```cpp
void leftViewUtil(vector<int>& vec, struct Node *root, int level, int& max_level) {
    if (root == NULL) return;

    if (max_level < level) {
        vec.push_back(root->data);
        max_level = level;
    }

    leftViewUtil(vec, root->left, level + 1, max_level);
    leftViewUtil(vec, root->right, level + 1, max_level);
}

vector<int> leftView(struct Node *root) {
    int max_level = 0;
    vector<int> vec;
    leftViewUtil(vec, root, 1, max_level);
    return vec;
}
```

### **Code (Java)**

```java
class Tree {
    void leftViewUtil(Node root, int level, int[] maxLevel, ArrayList<Integer> result) {
        if (root == null) return;

        if (maxLevel[0] < level) {
            result.add(root.data);
            maxLevel[0] = level;
        }

        leftViewUtil(root.left, level + 1, maxLevel, result);
        leftViewUtil(root.right, level + 1, maxLevel, result);
    }

    ArrayList<Integer> leftView(Node root) {
        ArrayList<Integer> result = new ArrayList<>();
        int[] maxLevel = new int[1]; // using array to mimic pass by reference
        leftViewUtil(root, 1, maxLevel, result);
        return result;
    }
}
```

### **Code (Python)**

```python
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

def leftViewUtil(root, level, max_level, result):
    if root is None:
        return

    if max_level[0] < level:
        result.append(root.data)
        max_level[0] = level

    leftViewUtil(root.left, level + 1, max_level, result)
    leftViewUtil(root.right, level + 1, max_level, result)

def LeftView(root):
    result = []
    max_level = [0]
    leftViewUtil(root, 1, max_level, result)
    return result
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
