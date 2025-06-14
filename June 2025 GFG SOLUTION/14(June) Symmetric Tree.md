---
title: "🌳 Symmetric Tree | GFG Solution 🔍"
keywords🏷️: ["🌳 symmetric tree", "🔍 binary tree", "🪞 mirror image", "🌿 tree traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Symmetric Tree problem: check if a binary tree is symmetric using recursive mirror comparison. 🚀"
date: 📅 2025-06-14
---

# *14. Symmetric Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/symmetric-tree/1)

## **🧩 Problem Description**

Given the root of a **binary tree**, check whether it is **symmetric**, i.e., whether the tree is a mirror image of itself.

A binary tree is symmetric if the **left subtree** is a mirror reflection of the **right subtree**.

## **📘 Examples**

### Example 1

```cpp
Input: root[] = [1, 2, 2, 3, 4, 4, 3]
       1
      / \
     2   2
    / \ / \
   3  4 4  3
Output: True
Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
```

### Example 2

```cpp
Input: root[] = [1, 2, 2, N, 3, N, 3]
       1
      / \
     2   2
      \   \
       3   3
Output: False
Explanation: As the left and right half of the above tree is not the mirror image, tree is not symmetric.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 2000$

## **✅ My Approach**

The optimal approach uses **Recursive Mirror Comparison** to check if the left and right subtrees are mirror images of each other:

### **Recursive Mirror Comparison**

1. **Base Cases:**
   * If root is null, the tree is symmetric by definition.
   * If both nodes being compared are null, they are symmetric.
   * If one node is null and the other isn't, they are not symmetric.

2. **Value Comparison:**
   * If the data values of the two nodes don't match, they are not symmetric.

3. **Recursive Mirror Check:**
   * Compare left subtree of first node with right subtree of second node.
   * Compare right subtree of first node with left subtree of second node.
   * Both comparisons must return true for the tree to be symmetric.

4. **Main Function Logic:**
   * Handle the null root case directly.
   * Call the helper function with `root->left` and `root->right`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the tree. We visit each node exactly once during the recursive traversal.
* **Expected Auxiliary Space Complexity:** O(h), where h is the height of the tree. This is due to the recursive call stack, which can go as deep as the height of the tree. In the worst case (skewed tree), h = n, making it O(n).

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  bool isSym(Node* a, Node* b){
    if(!a||!b) return a==b;
    if(a->data!=b->data) return false;
    return isSym(a->left,b->right)&&isSym(a->right,b->left);
  }
 public:
    bool isSymmetric(Node* r){
        return !r||isSym(r->left,r->right);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative with Queue (BFS)**

### 💡 Algorithm Steps:

1. If `root` is null, it's symmetric.
2. Use a queue to store pairs of nodes, starting with `(root->left, root->right)`.
3. While queue is not empty:
   * Dequeue a pair `(u, v)`.
   * If both are null, continue to next pair.
   * If one is null or their data values differ, return false.
   * Enqueue `(u->left, v->right)` and `(u->right, v->left)`.
4. Return true if all pairs are symmetric.

```cpp
class Solution {
  public:
    bool isSymmetric(Node* root) {
        if (!root) return true;
        queue<Node*> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            Node* a = q.front(); q.pop();
            Node* b = q.front(); q.pop();
            if (!a && !b) continue;
            if (!a || !b || a->data != b->data) return false;
            q.push(a->left); q.push(b->right);
            q.push(a->right); q.push(b->left);
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) — each node visited once
* **Auxiliary Space:** 💾 O(n) — queue may hold up to n/2 pairs in the worst case

### ✅ **Why This Approach?**

* Avoids recursion, preventing stack overflow for deep trees.
* Uses breadth-first traversal for level-by-level comparison.

## 📊 **3️⃣ Iterative with Two Stacks (DFS)**

### 💡 Algorithm Steps:

1. If `root` is null, it's symmetric.
2. Use two stacks to simulate the recursive calls.
3. Push `root->left` to first stack and `root->right` to second stack.
4. While stacks are not empty:
   * Pop one node from each stack.
   * If both are null, continue.
   * If one is null or their data values differ, return false.
   * Push nodes in mirror order to respective stacks.
5. Return true if both stacks are empty.

```cpp
class Solution {
 public:
    bool isSymmetric(Node* r){
        if(!r) return true;
        stack<Node*> s1,s2;
        s1.push(r->left);
        s2.push(r->right);
        while(!s1.empty()){
            Node* u=s1.top(); s1.pop();
            Node* v=s2.top(); s2.pop();
            if(!u&&!v) continue;
            if(!u||!v||u->data!=v->data) return false;
            s1.push(u->left);  s2.push(v->right);
            s1.push(u->right); s2.push(v->left);
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Mimics recursion with explicit stacks.
* Good when recursion depth is a concern.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**             | 💡 **Strategy**                       | ⏱️ **Time Complexity**  | 💾 **Space Complexity** | ⚙️ **Type**     | ⚖️ **Pros**                        | ❗ **Cons**                           |
| ---------------------------- | ------------------------------------- | ----------- | ------------ | --------------- | ---------------------------------- | ------------------------------------ |
| ✅ Recursive DFS             | Compare mirrored subtrees recursively | 🟢 O(n)        | 🟢 O(h)         | Recursive       | Elegant, short code                | Stack overflow on deep trees         |
| 🔁 Iterative BFS with Queue  | Compare mirrored pairs via queue      | 🟢 O(n)        | 🟡 O(n)         | Iterative (BFS) | No recursion, handles large trees  | Queue may grow large                 |
| 🔃 Iterative DFS with Stacks | Simulates recursion using two stacks  | 🟢 O(n)        | 🟡 O(n)         | Iterative (DFS) | Explicit control, avoids recursion | Slightly more complex implementation |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                              | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| -------------------------------------------- | ---------------------------- | ------------------------- |
| ⚡ Balanced trees, clean code preferred       | 🥇 Recursive DFS             | ★★★★★                     |
| 🌳 Large/deep trees, avoid stack overflow    | 🥈 Iterative with Queue      | ★★★★☆                     |
| 🧪 Need explicit stack control               | 🥉 Iterative Two Stack DFS   | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    boolean isSym(Node a, Node b){
        if(a==null||b==null) return a==b;
        if(a.data!=b.data) return false;
        return isSym(a.left,b.right)&&isSym(a.right,b.left);
    }
    public boolean isSymmetric(Node r){
        return r==null||isSym(r.left,r.right);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isSym(self,a,b):
        if not a or not b: return a is b
        if a.data!=b.data: return False
        return self.isSym(a.left,b.right) and self.isSym(a.right,b.left)
    def isSymmetric(self, root):
        return root is None or self.isSym(root.left,root.right)
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
