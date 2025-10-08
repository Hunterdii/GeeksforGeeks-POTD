---
title: "🌲 Construct Tree from Preorder & Postorder | GFG Solution 🔍"
keywords🏷️: ["🌲 binary tree construction", "🔍 tree traversal", "📍 preorder postorder", "📈 recursion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Construct Tree from Preorder & Postorder problem: build a full binary tree from preorder and postorder traversals using recursive approach with optimized lookups. 🚀"
date: 📅 2025-10-08
---

# *08. Construct Tree from Preorder & Postorder*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/construct-tree-from-preorder-postorder/1)

## **🧩 Problem Description**

Given two arrays `pre[]` and `post[]` that represent the preorder and postorder traversals of a full binary tree, your task is to construct the binary tree and return its root.

A **full binary tree** is a binary tree where every node has either 0 or 2 children. The preorder and postorder traversals contain unique values, and every value present in the preorder traversal is also found in the postorder traversal.

## **📘 Examples**

### Example 1

```cpp
Input: pre[] = [1, 2, 4, 8, 9, 5, 3, 6, 7], post[] = [8, 9, 4, 5, 2, 6, 7, 3, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
Explanation: The tree structure is:
        1
       / \
      2   3
     / \ / \
    4  5 6  7
   / \
  8   9
```

### Example 2

```cpp
Input: pre[] = [1, 2, 4, 5, 3, 6, 7], post[] = [4, 5, 2, 6, 7, 3, 1]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: The tree structure is:
      1
     / \
    2   3
   / \ / \
  4  5 6  7
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^3$
* $1 \le \text{pre}[i], \text{post}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **recursive tree construction** with **postorder boundary tracking**:

### **Recursive Construction with Postorder Search**

1. **Understanding Traversal Properties:**
   * In preorder: Root → Left Subtree → Right Subtree
   * In postorder: Left Subtree → Right Subtree → Root
   * The first element in preorder is always the root
   * The last element in postorder is always the root

2. **Key Insight:**
   * After identifying the root from preorder, the next element is the root of the left subtree
   * Find this left subtree root in postorder to determine the boundary between left and right subtrees

3. **Algorithm Steps:**
   * Use a global index pointer to track current position in preorder array
   * Create root node with current preorder element and increment index
   * If subtree is not a leaf (l ≠ r) and more nodes exist:
     * Find the position of next preorder element (left child) in postorder within current range
     * Recursively build left subtree from l to pos
     * Recursively build right subtree from pos+1 to r-1
   * Return the constructed root

4. **Base Case:**
   * When left boundary equals right boundary (l == r), we have a leaf node
   * When index reaches end of preorder array, no more nodes to process

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the number of nodes in the tree. In the worst case, for each node we perform a linear search in the postorder array to find the left child position, resulting in O(n) operations per node.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the tree. This space is used by the recursion call stack. In the worst case of a skewed tree, h can be O(n), but for a balanced full binary tree, h = O(log n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int idx = 0;
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        return build(pre, post, 0, post.size() - 1);
    }
    Node* build(vector<int>& pre, vector<int>& post, int l, int r) {
        Node* root = new Node(pre[idx++]);
        
        if (l != r && idx < pre.size()) {
            int pos = l;
            while (post[pos] != pre[idx]) pos++;
            
            root->left  = build(pre, post, l, pos);
            root->right = build(pre, post, pos + 1, r - 1);
        }
        return root;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap with Index Mapping**

### 💡 Algorithm Steps:

1. Create a HashMap to store postorder element indices for O(1) lookup.
2. Use recursive function with preorder index pointer and postorder boundaries.
3. Root is always the current preorder element, increment pointer after creating node.
4. Left child root is next preorder element, find its position in postorder to determine subtree size.

```cpp
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        unordered_map<int, int> m;
        for (int i = 0; i < post.size(); i++) m[post[i]] = i;
        int idx = 0;
        return build(pre, post, m, idx, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, unordered_map<int,int>& m, int& idx, int l, int r) {
        Node* root = new Node(pre[idx++]);
        if (l == r || idx >= pre.size()) return root;
        int pos = m[pre[idx]];
        if (pos <= r) {
            root->left = build(pre, post, m, idx, l, pos);
            root->right = build(pre, post, m, idx, pos + 1, r - 1);
        }
        return root;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with O(1) lookups
* **Auxiliary Space:** 💾 O(n) - HashMap storage for postorder indices

### ✅ **Why This Approach?**

* Fast constant time lookups eliminate repeated searches
* Cleaner code with preprocessing step
* Standard approach for tree construction problems

## 📊 **3️⃣ Stack-Based Iterative**

### 💡 Algorithm Steps:

1. Use stack to track current path from root to current node being processed.
2. Iterate through preorder array and create nodes sequentially.
3. Match postorder elements with stack top to determine when subtrees complete.
4. Pop from stack when current node matches postorder element indicating subtree completion.

```cpp
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        stack<Node*> s;
        Node* root = new Node(pre[0]);
        s.push(root);
        for (int i = 1, j = 0; i < pre.size(); i++) {
            Node* node = new Node(pre[i]);
            while (s.top()->data == post[j]) {
                s.pop();
                j++;
            }
            if (!s.top()->left) s.top()->left = node;
            else s.top()->right = node;
            s.push(node);
        }
        return root;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through arrays
* **Auxiliary Space:** 💾 O(h) - Stack space for tree height

### ✅ **Why This Approach?**

* Avoids recursion overhead with iterative solution
* Space efficient using only stack for current path
* Single forward pass through both arrays

## 📊 **4️⃣ Range-Based Recursive**

### 💡 Algorithm Steps:

1. Track current range in both preorder and postorder arrays simultaneously.
2. Root is first element in current preorder range.
3. Find root's left child (next preorder element) in postorder to split ranges.
4. Recursively build left subtree then right subtree with updated ranges.

```cpp
class Solution {
public:
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        return build(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
    }
    
    Node* build(vector<int>& pre, vector<int>& post, int preL, int preR, int postL, int postR) {
        if (preL > preR) return nullptr;
        Node* root = new Node(pre[preL]);
        if (preL == preR) return root;
        int idx = postL;
        while (post[idx] != pre[preL + 1]) idx++;
        int leftSize = idx - postL + 1;
        root->left = build(pre, post, preL + 1, preL + leftSize, postL, idx);
        root->right = build(pre, post, preL + leftSize + 1, preR, idx + 1, postR - 1);
        return root;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Linear search in each recursive call
* **Auxiliary Space:** 💾 O(h) - Recursion stack depth

### ✅ **Why This Approach?**

* Explicit range tracking for clear boundary management
* No preprocessing required
* Intuitive divide and conquer approach

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Direct Search**              | 🟡 O(n²)               | 🟢 O(h)                 | 🎯 No preprocessing needed        | 🐌 Repeated linear searches          |
| 🗺️ **HashMap Mapping**           | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Fast O(1) lookups              | 💾 Extra space for HashMap           |
| 📚 **Stack Iterative**            | 🟢 O(n)                | 🟢 O(h)                 | ⭐ No recursion overhead          | 🔧 Complex pointer manipulation      |
| 📏 **Range Recursive**            | 🟡 O(n²)               | 🟢 O(h)                 | 📖 Clear boundary tracking        | 🐌 Slower without optimization       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time complexity**                    | 🥇 **HashMap Mapping**                | ★★★★★                     |
| 💾 **Space optimization priority**                | 🥈 **Stack Iterative**                | ★★★★☆                     |
| 📖 **Code simplicity**                            | 🥉 **Direct Search**                  | ★★★☆☆                     |
| 🎯 **Interview/Competitive**                      | 🏅 **HashMap Mapping**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int idx = 0;
    public Node constructTree(int[] pre, int[] post) {
        return build(pre, post, 0, post.length - 1);
    }
    
    Node build(int[] pre, int[] post, int l, int r) {
        Node root = new Node(pre[idx++]);
        if (l != r && idx < pre.length) {
            int pos = l;
            while (post[pos] != pre[idx]) pos++;
            root.left = build(pre, post, l, pos);
            root.right = build(pre, post, pos + 1, r - 1);
        }
        return root;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def constructTree(self, pre, post):
        self.idx = 0
        return self.build(pre, post, 0, len(post) - 1)
    
    def build(self, pre, post, l, r):
        root = Node(pre[self.idx])
        self.idx += 1
        if l != r and self.idx < len(pre):
            pos = post.index(pre[self.idx], l, r + 1)
            root.left = self.build(pre, post, l, pos)
            root.right = self.build(pre, post, pos + 1, r - 1)
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
