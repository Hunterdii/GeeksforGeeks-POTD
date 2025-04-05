# _5. Mirror Tree_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/mirror-tree/1)

## **Problem Description**

Given a binary tree, convert it into its **Mirror Tree** by swapping the left and right children of all non-leaf nodes.

### **Example 1:**

#### **Input:**

```
        1
       / \
      2   3
         /
        4
```

#### **Output:**

```
        1
       / \
      3   2
       \
        4
```

<img src="https://github.com/user-attachments/assets/16c6b8d7-160f-4260-b6e5-629d51b3d248" width="40%">

#### **Explanation:**

Every non-leaf node has its left and right children interchanged.

### **Example 2:**

#### **Input:**

```
        1
       / \
      2   3
     / \
    4   5
```

#### **Output:**

```
        1
       / \
      3   2
         / \
        5   4
```

<img src="https://github.com/user-attachments/assets/f4d620f5-19e1-4c84-94a5-a543cb89f9d1" width="40%">

#### **Explanation:**

Every non-leaf node has its left and right children interchanged.

### **Constraints:**

- 1 ≤ number of nodes ≤ $10^5$
- 1 ≤ node->data ≤ $10^5$

## **My Approach**

### **Recursive DFS (Top-Down)**

1. **Base Case:** If the node is `NULL`, return.
2. **Recursively traverse** the left and right subtrees.
3. **Swap** the left and right children of the current node.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N)`, since every node is visited once.
- **Expected Auxiliary Space Complexity:** `O(1)` OR `O(H)` for recursive DFS (`H = height of the tree`).

## Code (C)

```c
void mirror(Node *n) {
    if (!n) return;
    mirror(n->left);
    mirror(n->right);
    Node* t = n->left;
    n->left = n->right;
    n->right = t;
}
```

**Note:** The C code may show an error when compiled and run, but if you proceed with submission, it still passes all test cases.

For example, consider the input:

```
1 2 3 N N 4
```

The output after compilation and running:

```
1 3 2
```

Expected output:

```
1 3 2 N 4
```

Although there is a difference in output format during execution, submitting the code results in a **successful pass for all test cases**.

## Code (C++)

```cpp
class Solution {
public:
    void mirror(Node* node) {
        if (!node) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

### **2️⃣ Iterative BFS (Level Order)**

```cpp
class Solution {
public:
    void mirror(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            swap(cur->left, cur->right);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
};
```

### **3️⃣ Iterative DFS (Using Stack)**

```cpp
class Solution {
public:
    void mirror(Node* root) {
        if (!root) return;
        stack<Node*> s;
        s.push(root);
        while (!s.empty()) {
            Node* cur = s.top(); s.pop();
            swap(cur->left, cur->right);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
    }
};
```

## **Comparison of Approaches**

| Approach                        | Time Complexity | Space Complexity | Method      | Pros                                  | Cons                                    |
| ------------------------------- | --------------- | ---------------- | ----------- | ------------------------------------- | --------------------------------------- |
| **Recursive DFS (Top-Down)**    | 🟢 **O(N)**     | 🟡 **O(H)**      | Recursion   | Simple and concise                    | May cause stack overflow for deep trees |
| **Iterative BFS (Level Order)** | 🟢 **O(N)**     | 🔴 **O(W)**      | Queue-based | Avoids recursion depth issues         | Uses more memory for wide trees         |
| **Iterative DFS (Stack)**       | 🟢 **O(N)**     | 🟡 **O(H)**      | Stack-based | Explicit control over traversal order | Still uses extra space for the stack    |

### **Best Choice?**

- **For balanced trees**, the **Recursive DFS** approach is fine.
- **For deep trees**, the **Iterative BFS** approach is preferable to avoid recursion depth issues.
- **For explicit control and iterative processing**, the **Iterative DFS (Stack)** approach is a solid option.

</details>

## Code (Java)

```java
class Solution {
    void mirror(Node node) {
        if (node == null) return;
        mirror(node.left);
        mirror(node.right);
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;
    }
}
```

## Code (Python)

```python
class Solution:
    def mirror(self, root):
        if not root:
            return
        self.mirror(root.left)
        self.mirror(root.right)
        root.left, root.right = root.right, root.left
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
