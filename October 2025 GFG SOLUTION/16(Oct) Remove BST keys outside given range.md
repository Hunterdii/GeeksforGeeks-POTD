---
title: "🌳 Remove BST Keys Outside Given Range | GFG Solution 🔍"
keywords🏷️: ["🌳 binary search tree", "🔍 BST trimming", "📍 recursion", "🔄 tree traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Remove BST Keys Outside Given Range: efficiently trim a BST to keep only nodes within a specified range using recursive DFS. 🚀"
date: 📅 2025-10-16
---

# *16. Remove BST Keys Outside Given Range*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/remove-bst-keys-outside-given-range/1)

## **🧩 Problem Description**

Given the root of a **Binary Search Tree (BST)** and two integers `l` and `r`, remove all the nodes whose values lie outside the range `[l, r]`.

**Note:** The modified tree should also be a BST and the sequence of the remaining nodes should not be changed.

## **📘 Examples**

### Example 1
```cpp
Input: root = [6, -13, 14, N, -8, 13, 15, N, N, 7], l = -10, r = 13
Output: [6, -8, 13, N, N, 7]
Explanation: All the nodes outside the range [-10, 13] are removed and the modified tree is a valid BST.
```

### Example 2
```cpp
Input: root = [14, 4, 16, 2, 8, 15, N, -8, 3, 7, 10], l = 2, r = 6
Output: [4, 2, N, N, 3]
Explanation: All the nodes outside the range [2, 6] are removed and the modified tree is a valid BST.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^4$
* $1 \le \text{node->data} \le 10^4$
* $1 \le l \le r \le 10^4$

## **✅ My Approach**

The optimal approach uses **Post-Order Recursive Traversal** with **BST Property Optimization**:

### **Recursive DFS with BST Pruning**

1. **Base Case:**
   * If the current node is `NULL`, return `NULL` immediately.

2. **Post-Order Recursion:**
   * Recursively process the left subtree first: `root->left = removekeys(root->left, l, r)`.
   * Then recursively process the right subtree: `root->right = removekeys(root->right, l, r)`.

3. **Node Validation:**
   * If `root->data < l`: The current node is below the valid range. Since it's a BST, all nodes in the left subtree are also below `l`. Return the right subtree.
   * If `root->data > r`: The current node is above the valid range. Since it's a BST, all nodes in the right subtree are also above `r`. Return the left subtree.
   * If `root->data` is within `[l, r]`: Keep the current node and return it with updated children.

4. **BST Property Utilization:**
   * Leverage the BST property where left children are smaller and right children are larger.
   * This allows early pruning of entire subtrees without visiting every node.

5. **Return Modified Root:**
   * The function returns the new root of the modified subtree at each level.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the BST. In the worst case, we visit each node once to determine if it should be kept or removed.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the BST. This space is used by the recursion call stack. In the worst case of a skewed tree, h = n, but for a balanced BST, h = log(n).

## **🧑‍💻 Code (C++)**
```cpp
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l) return root->right;
        if (root->data > r) return root->left;
        return root;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative with Stack Approach**

### 💡 Algorithm Steps:

1. Use a stack to simulate recursive calls iteratively.
2. Process nodes in post-order traversal to handle children first.
3. Replace parent references based on range conditions.
4. Build the filtered tree bottom-up without recursion overhead.
```cpp
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return NULL;
        stack<Node*> st;
        st.push(root);
        unordered_map<Node*, Node*> processed;
        while (!st.empty()) {
            Node* curr = st.top();
            if ((curr->left && !processed.count(curr->left)) || 
                (curr->right && !processed.count(curr->right))) {
                if (curr->right) st.push(curr->right);
                if (curr->left) st.push(curr->left);
            } else {
                st.pop();
                Node* left = curr->left ? processed[curr->left] : NULL;
                Node* right = curr->right ? processed[curr->right] : NULL;
                if (curr->data >= l && curr->data <= r) {
                    curr->left = left;
                    curr->right = right;
                    processed[curr] = curr;
                } else if (curr->data < l) {
                    processed[curr] = right;
                } else {
                    processed[curr] = left;
                }
            }
        }
        return processed[root];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node once
* **Auxiliary Space:** 💾 O(n) - Stack and map storage

### ✅ **Why This Approach?**

* Avoids recursion stack overflow for deep trees
* Explicit control over traversal order
* Good for environments with limited stack space

## 📊 **3️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. First pass: Remove all nodes less than left boundary.
2. Second pass: Remove all nodes greater than right boundary.
3. Process each boundary separately for clearer logic.
4. Combine results to get final trimmed tree.
```cpp
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        root = trimLeft(root, l);
        root = trimRight(root, r);
        return root;
    }
    Node* trimLeft(Node* n, int l) {
        if (!n) return NULL;
        if (n->data < l) return trimLeft(n->right, l);
        n->left = trimLeft(n->left, l);
        return n;
    }
    Node* trimRight(Node* n, int r) {
        if (!n) return NULL;
        if (n->data > r) return trimRight(n->left, r);
        n->right = trimRight(n->right, r);
        return n;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two passes through tree
* **Auxiliary Space:** 💾 O(h) - Recursion depth

### ✅ **Why This Approach?**

* Separates concerns for easier debugging
* More modular and testable code structure
* Clear boundary handling logic

## 📊 **4️⃣ Early Termination Optimization**

### 💡 Algorithm Steps:

1. Check current node's validity before processing children.
2. If node is outside range, skip to appropriate subtree immediately.
3. Only recurse on both children if current node is valid.
4. Reduces unnecessary recursive calls for invalid subtrees.
```cpp
class Solution {
public:
    Node* removekeys(Node* root, int l, int r) {
        return filter(root, l, r);
    }
    
    Node* filter(Node* node, int l, int r) {
        if (!node) return NULL;
        if (node->data < l) return filter(node->right, l, r);
        if (node->data > r) return filter(node->left, l, r);
        node->left = filter(node->left, l, r);
        node->right = filter(node->right, l, r);
        return node;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through tree
* **Auxiliary Space:** 💾 O(h) - Recursion stack height

### ✅ **Why This Approach?**

* Cleaner early termination logic
* Reduces unnecessary subtree traversals
* More efficient for sparse valid ranges

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🌲 **Recursive DFS**              | 🟢 O(n)                | 🟢 O(h)                 | 🚀 Clean and concise              | 🔄 Recursion overhead                |
| 🔍 **Iterative Stack**            | 🟢 O(n)                | 🟡 O(n)                 | 📖 No recursion limit             | 💾 More space overhead               |
| ✂️ **Two-Pass**                   | 🟢 O(n)                | 🟢 O(h)                 | 📖 Modular structure              | 🔄 Multiple traversals               |
| 🔄 **Early Termination**          | 🟢 O(n)                | 🟢 O(h)                 | ⭐ Optimal pruning                | 🔧 Similar to main approach          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Recursive DFS**                 | ★★★★★                     |
| 📖 **Deep tree handling**                             | 🥈 **Iterative Stack**               | ★★★★☆                     |
| 🔧 **Modularity priority**                            | 🥉 **Two-Pass**                      | ★★★★☆                     |
| 🎯 **Sparse ranges**                                  | 🏅 **Early Termination**             | ★★★★★                     |

</details>

## **☕ Code (Java)**
```java
class Solution {
    Node removekeys(Node root, int l, int r) {
        if (root == null) return null;
        root.left = removekeys(root.left, l, r);
        root.right = removekeys(root.right, l, r);
        if (root.data < l) return root.right;
        if (root.data > r) return root.left;
        return root;
    }
}
```

## **🐍 Code (Python)**
```python
class Solution:
    def removekeys(self, root, l, r):
        if not root: return None
        root.left = self.removekeys(root.left, l, r)
        root.right = self.removekeys(root.right, l, r)
        if root.data < l: return root.right
        if root.data > r: return root.left
        return root
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
