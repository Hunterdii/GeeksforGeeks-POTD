---
title: "🌲 ZigZag Tree Traversal | GFG Solution 🔍"
keywords🏷️: ["🌲 binary tree", "🔍 level order", "📍 zigzag traversal", "📈 BFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the ZigZag Tree Traversal problem: perform level order traversal in alternating left-to-right and right-to-left directions using efficient queue-based techniques. 🚀"
date: 📅 2025-10-10
---

# *10. ZigZag Tree Traversal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1)

## **🧩 Problem Description**

Given the root of a binary tree, you need to perform a **zigzag level order traversal**. In this traversal:
- **Odd-numbered levels** (1st, 3rd, 5th, etc.) are traversed from **left to right**.
- **Even-numbered levels** (2nd, 4th, 6th, etc.) are traversed from **right to left**.

Return the nodes in the order they appear during this zigzag traversal.

## **📘 Examples**

### Example 1

```cpp
Input: root = [1, 2, 3, 4, 5, 6, 7]
          
Output: [1, 3, 2, 4, 5, 6, 7]
Explanation:
Level 1 (left to right): [1]
Level 2 (right to left): [3, 2]
Level 3 (left to right): [4, 5, 6, 7]
Final result: [1, 3, 2, 4, 5, 6, 7]
```

### Example 2

```cpp
Input: root = [7, 9, 7, 8, 8, 6, N, 10, 9]
 
Output: [7, 7, 9, 8, 8, 6, 9, 10] 
Explanation:
Level 1 (left to right): [7]
Level 2 (right to left): [7, 9]
Level 3 (left to right): [8, 8, 6]
Level 4 (right to left): [9, 10]
Final result: [7, 7, 9, 8, 8, 6, 9, 10]
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^5$
* $1 \le \text{node->data} \le 10^5$

## **✅ My Approach**

The optimal approach uses **Queue-Based Level Order Traversal** with **Index Manipulation** to achieve zigzag ordering efficiently:

### **Queue with Index Positioning**

1. **Initialize Data Structures:**
   * Use a queue for standard level-order traversal (BFS).
   * Maintain a boolean flag `ltr` (left-to-right) to track current direction.
   * Create result vector to store final traversal order.

2. **Process Each Level:**
   * For each level, determine its size to process all nodes at current depth.
   * Create a temporary level vector of the exact size needed.

3. **Smart Index Placement:**
   * For left-to-right levels: place nodes at their natural index position (0, 1, 2, ...).
   * For right-to-left levels: place nodes at reversed index positions (size-1, size-2, ...).
   * This eliminates the need for explicit reversal operations.

4. **Add Children to Queue:**
   * Always add left child first, then right child (standard BFS order).
   * The queue maintains proper level-by-level traversal regardless of zigzag pattern.

5. **Toggle Direction:**
   * After processing each level, flip the `ltr` flag.
   * Append the level vector to result and continue to next level.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once during the level order traversal, and inserting nodes at calculated indices takes constant time.
* **Expected Auxiliary Space Complexity:** O(w), where w is the maximum width of the tree. The queue stores at most one complete level of nodes at any given time, which in the worst case (complete binary tree) is approximately n/2 nodes at the last level.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        bool ltr = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl(sz);
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                int idx = ltr ? i : sz - 1 - i;
                lvl[idx] = node->data;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ltr = !ltr;
            res.insert(res.end(), lvl.begin(), lvl.end());
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Deque-Based Approach**

### 💡 Algorithm Steps:

1. Use a deque to enable bidirectional insertion and removal.
2. Track direction flag to determine front or back processing.
3. For left-to-right levels, process from front and add children normally.
4. For right-to-left levels, process from back and reverse child insertion order.

```cpp
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        deque<Node*> dq;
        dq.push_back(root);
        bool ltr = true;
        while (!dq.empty()) {
            int sz = dq.size();
            for (int i = 0; i < sz; i++) {
                if (ltr) {
                    Node* node = dq.front();
                    dq.pop_front();
                    res.push_back(node->data);
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    Node* node = dq.back();
                    dq.pop_back();
                    res.push_back(node->data);
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
            }
            ltr = !ltr;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Visit each node exactly once
* **Auxiliary Space:** 💾 O(w) - Width of tree for deque storage

### ✅ **Why This Approach?**

* Natural bidirectional processing with deque
* Direct zigzag traversal without reversing
* Efficient for wide trees with controlled memory

## 📊 **3️⃣ Two-Stack Approach**

### 💡 Algorithm Steps:

1. Maintain two stacks for alternating level processing.
2. Stack s1 processes left-to-right by pushing left child first.
3. Stack s2 processes right-to-left by pushing right child first.
4. Alternate between stacks for automatic zigzag pattern.

```cpp
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node* node = s1.top();
                s1.pop();
                res.push_back(node->data);
                if (node->left) s2.push(node->left);
                if (node->right) s2.push(node->right);
            }
            while (!s2.empty()) {
                Node* node = s2.top();
                s2.pop();
                res.push_back(node->data);
                if (node->right) s1.push(node->right);
                if (node->left) s1.push(node->left);
            }
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal of all nodes
* **Auxiliary Space:** 💾 O(w) - Maximum width of tree across both stacks

### ✅ **Why This Approach?**

* Classic stack-based zigzag implementation
* Natural LIFO ordering produces zigzag automatically
* Minimal overhead with simple push-pop operations

## 📊 **4️⃣ Recursive Level Order with Reversal**

### 💡 Algorithm Steps:

1. Use level-order traversal with level tracking.
2. Store nodes at each level in separate vectors.
3. Reverse alternate level vectors based on level number.
4. Concatenate all levels to produce final zigzag order.

```cpp
class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        int lvl = 0;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> temp;
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                temp.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (lvl % 2) reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            lvl++;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each node visited once plus reversals
* **Auxiliary Space:** 💾 O(w) - Level storage and queue combined

### ✅ **Why This Approach?**

* Straightforward standard BFS with modification
* Easy to understand and debug
* Flexible for adding additional level processing

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔢 **Queue with Index**           | 🟢 O(n)                | 🟢 O(w)                 | 🚀 Clean and efficient            | 💾 Extra vector per level            |
| 🔄 **Deque-Based**                | 🟢 O(n)                | 🟢 O(w)                 | ⚡ True bidirectional access      | 🔧 Slightly complex logic            |
| 📚 **Two-Stack**                  | 🟢 O(n)                | 🟢 O(w)                 | 🎯 Classic pattern                | 🐌 Two data structures needed        |
| 🔁 **BFS with Reversal**          | 🟢 O(n)                | 🟢 O(w)                 | 📖 Simple BFS modification        | 🔄 Extra reversal operations         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Clean readable code**                            | 🥇 **Queue with Index**              | ★★★★★                     |
| 📖 **Memory optimization**                            | 🥈 **Deque-Based**                   | ★★★★★                     |
| 🔧 **Classic pattern learning**                       | 🥉 **Two-Stack**                     | ★★★★☆                     |
| 🎯 **Simplicity priority**                            | 🏅 **BFS with Reversal**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    ArrayList<Integer> zigZagTraversal(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        boolean ltr = true;
        while (!q.isEmpty()) {
            int sz = q.size();
            Integer[] lvl = new Integer[sz];
            for (int i = 0; i < sz; i++) {
                Node node = q.poll();
                int idx = ltr ? i : sz - 1 - i;
                lvl[idx] = node.data;
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            ltr = !ltr;
            Collections.addAll(res, lvl);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def zigZagTraversal(self, root):
        res = []
        if not root: return res
        q = deque([root])
        ltr = True
        while q:
            sz = len(q)
            lvl = [0] * sz
            for i in range(sz):
                node = q.popleft()
                idx = i if ltr else sz - 1 - i
                lvl[idx] = node.data
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            ltr = not ltr
            res.extend(lvl)
        return res
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
