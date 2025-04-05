---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Tree
---

# 🚀 _Day 7. Tree Boundary Traversal_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/boundary-traversal-of-binary-tree)

## 💡 **Problem Description:**

Given a binary tree, the task is to return a list of nodes representing its boundary traversal in an **anticlockwise direction**, starting from the **root**. The boundary includes:

1. The **left boundary** (excluding the leaf nodes).
2. All the **leaf nodes** (both from left and right subtrees).
3. The **right boundary** (excluding the leaf nodes), added in **reverse order**.

## 🔍 **Example Walkthrough:**

### **Example 1**

**Input:**  
 `root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N] `

**Output:**  
`[1, 2, 4, 8, 9, 6, 7, 3]`

#### **Explanation:**

<img src="https://github.com/user-attachments/assets/e18cfc62-05ae-4b66-82da-1602ab7cf9af" width="40%">

### **Example 2**

**Input:**  
`root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]`

**Output:**  
`[1, 2, 4, 6, 5, 7, 8]`

#### **Explanation:**

<img src="https://github.com/user-attachments/assets/4318b5b8-868d-4a62-9cdc-92e85e3e4326" width="40%">

### **Example 3**

**Input:**  
`root[] = [1, N, 2, N, 3, N, 4, N, N]`

```
    1
     \
      2
       \
        3
         \
          4
```

**Output:**  
 `[1, 4, 3, 2]`

#### **Explanation:**

- `Left boundary: [1] (as there is no left subtree)`
- `Leaf nodes: [4]`
- `Right boundary: [3, 2] (in reverse order)`
- `Final traversal: [1, 4, 3, 2]`

## **Constraints**

- 1 <= Number of Nodes <= $10^4$
- 1 <= Node Value <= $10^5$

## 🎯 **My Approach:**

The boundary traversal of a binary tree consists of three parts:

1. **Left Boundary:**

   - Traverse the leftmost nodes, **excluding** the leaf nodes.
   - Move **left whenever possible**; otherwise, move **right**.

2. **Leaf Nodes:**

   - Perform **inorder traversal** to collect leaf nodes.

3. **Right Boundary:**
   - Traverse the rightmost nodes, **excluding** the leaf nodes.
   - Move **right whenever possible**; otherwise, move **left**.
   - Store nodes in a stack to reverse them before adding to the final result.

## 🕒 **Time and Auxiliary Space Complexity**

- **Time Complexity:** `O(N)` Each node is visited **at most once**, so the time complexity is **O(N)**.
- **Auxiliary Space Complexity:** `O(H)` (Height of the tree) The recursion stack space in a **skewed tree** can be **O(N)**. In a **balanced tree**, it will be **O(log N)**.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
    void lb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        v.push_back(r->data);
        lb(r->left ? r->left : r->right, v);
    }
    void rb(Node* r, vector<int>& v) {
        if (!r || (!r->left && !r->right)) return;
        rb(r->right ? r->right : r->left, v);
        v.push_back(r->data);
    }
    void leaf(Node* r, vector<int>& v) {
        if (!r) return;
        leaf(r->left, v);
        if (!r->left && !r->right) v.push_back(r->data);
        leaf(r->right, v);
    }
public:
    vector<int> boundaryTraversal(Node* r) {
        if (!r) return {};
        vector<int> v = {r->data};
        lb(r->left, v);
        leaf(r->left, v);
        leaf(r->right, v);
        rb(r->right, v);
        return v;
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

## **2️⃣ Iterative Approach Using Queue (BFS)**

#### **Algorithm**

- Traverse the left boundary iteratively.
- Collect leaf nodes via BFS.
- Traverse the right boundary iteratively in **reverse order**.

```cpp
class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->data);

        Node* cur = root->left;
        while (cur) {
            if (cur->left || cur->right) res.push_back(cur->data);
            cur = cur->left ? cur->left : cur->right;
        }

        function<void(Node*)> leafNodes = [&](Node* node) {
            if (!node) return;
            leafNodes(node->left);
            if (!node->left && !node->right) res.push_back(node->data);
            leafNodes(node->right);
        };
        leafNodes(root);

        stack<int> rightBoundary;
        cur = root->right;
        while (cur) {
            if (cur->left || cur->right) rightBoundary.push(cur->data);
            cur = cur->right ? cur->right : cur->left;
        }

        while (!rightBoundary.empty()) {
            res.push_back(rightBoundary.top());
            rightBoundary.pop();
        }

        return res;
    }
};
```

## **3️⃣ Iterative DFS (Using Stack)**

#### **Algorithm**

- Use **DFS traversal** to visit nodes iteratively.
- Push the **left boundary**.
- Collect **leaf nodes**.
- Push the **right boundary** in reverse.

```cpp
class Solution {
public:
    vector<int> boundaryTraversal(Node* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->data);

        stack<Node*> s;
        Node* cur = root->left;
        while (cur) {
            if (cur->left || cur->right) res.push_back(cur->data);
            s.push(cur);
            cur = cur->left ? cur->left : cur->right;
        }

        function<void(Node*)> leafNodes = [&](Node* node) {
            if (!node) return;
            leafNodes(node->left);
            if (!node->left && !node->right) res.push_back(node->data);
            leafNodes(node->right);
        };
        leafNodes(root);

        stack<int> rightBoundary;
        cur = root->right;
        while (cur) {
            if (cur->left || cur->right) rightBoundary.push(cur->data);
            cur = cur->right ? cur->right : cur->left;
        }

        while (!rightBoundary.empty()) {
            res.push_back(rightBoundary.top());
            rightBoundary.pop();
        }

        return res;
    }
};
```

## **🔍 Comparison of Approaches**

| Approach                  | Time Complexity | Space Complexity | Method      | Pros                          | Cons                          |
| ------------------------- | --------------- | ---------------- | ----------- | ----------------------------- | ----------------------------- |
| **Recursive DFS**         | 🟢 O(N)         | 🟡 O(H)          | Recursion   | Simple & structured           | Stack overflow for deep trees |
| **Iterative BFS**         | 🟢 O(N)         | 🔴 O(W)          | Queue-based | Avoids recursion depth issues | More memory for wide trees    |
| **Iterative DFS (Stack)** | 🟢 O(N)         | 🟡 O(H)          | Stack-based | Explicit traversal order      | Extra space for stack         |

### **🚀 Best Choice?**

- **For balanced trees**, the **Recursive DFS** method is best.
- **For deep trees**, the **Iterative BFS** is preferable.
- **For explicit iterative control**, the **DFS with Stack** is an option.

</details>

## Code (Java)

```java
class Solution {
    void lb(Node r, ArrayList<Integer> v) {
        if(r==null || (r.left==null && r.right==null)) return;
        v.add(r.data);
        lb(r.left!=null ? r.left : r.right, v);
    }
    void rb(Node r, ArrayList<Integer> v) {
        if(r==null || (r.left==null && r.right==null)) return;
        rb(r.right!=null ? r.right : r.left, v);
        v.add(r.data);
    }
    void leaf(Node r, ArrayList<Integer> v) {
        if(r==null)return;
        leaf(r.left,v);
        if(r.left==null && r.right==null) v.add(r.data);
        leaf(r.right,v);
    }
    public ArrayList<Integer> boundaryTraversal(Node r) {
        ArrayList<Integer> v = new ArrayList<>();
        if(r==null)return v;
        v.add(r.data);
        lb(r.left, v);
        leaf(r.left, v);
        leaf(r.right, v);
        rb(r.right, v);
        return v;
    }
}
```

## Code (Python)

```python
class Solution:
    def boundaryTraversal(self, root):
        if not root:
            return []
        res = [root.data] if root.left or root.right else []

        cur = root.left
        while cur:
            if cur.left or cur.right:
                res.append(cur.data)
            cur = cur.left if cur.left else cur.right

        def leaf_nodes(node):
            if not node:
                return
            leaf_nodes(node.left)
            if not node.left and not node.right:
                res.append(node.data)
            leaf_nodes(node.right)

        leaf_nodes(root)

        right_boundary = []
        cur = root.right
        while cur:
            if cur.left or cur.right:
                right_boundary.append(cur.data)
            cur = cur.right if cur.right else cur.left

        res += reversed(right_boundary)
        return res
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
