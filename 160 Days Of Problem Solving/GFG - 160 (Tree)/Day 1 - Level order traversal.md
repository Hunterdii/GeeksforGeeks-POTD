---
Difficulty: Easy
Source: 160 Days of Problem Solving
Tags:
  - Tree
---

# 🚀 _Day 1. Level order traversal_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/level-order-traversal)

## 💡 **Problem Description:**

Given the root of a binary tree with `n` nodes, the task is to find its **level order traversal**.  
Level order traversal of a tree is **breadth-first traversal** for the tree, where we visit nodes level by level.

## 🔍 **Example Walkthrough:**

### **Example 1**

**Input:**

```
root[] = [1, 2, 3]
```

<img src="https://github.com/user-attachments/assets/148468bb-8f80-42c1-817d-d4d62af9a8e9" width="30%">

**Output:**

```
[[1], [2, 3]]
```

### **Example 2**

**Input:**

```
root[] = [10, 20, 30, 40, 50]
```

<img src="https://github.com/user-attachments/assets/7d845e3a-0803-42d0-a175-e8ceb1925850" width="30%">

**Output:**

```
[[10], [20, 30], [40, 50]]
```

### **Example 3**

**Input:**

```
root[] = [1, 3, 2, N, N, N, 4, 6, 5]
```

<img src="https://github.com/user-attachments/assets/e0cceec8-7faf-45ba-bdef-d064f8953c96" width="30%">

**Output:**

```
[[1], [3, 2], [4], [6, 5]]
```

### **Constraints**

- 1 ≤ number of nodes ≤ $10^5$
- 0 ≤ node->data ≤ $10^9$

## 🎯 **My Approach:**

1. **Use a queue** to traverse the tree level by level.
2. Start by pushing the root node into the queue.
3. Process each level:
   - Store the number of nodes in the current level.
   - Traverse all nodes of the level, adding them to the result.
   - Push their left and right children (if they exist) into the queue.
4. Continue the process until all nodes are visited.

This approach ensures that each node is visited **exactly once**, making it **efficient and optimal** for level-order traversal.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n)`, where `n` is the number of nodes in the tree. Each node is visited exactly once.
- **Expected Auxiliary Space Complexity:** `O(n)`, since, in the worst case, we store all nodes in the queue.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};
        queue<Node *> q({root});
        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back({});
            for (int i = q.size(); i > 0; i--) {
                Node *n = q.front(); q.pop();
                res.back().push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
        }
        return res;
    }
};
```

<details>
  <summary><h2 align='center'>🌲 Alternative Approaches</h2></summary>

### **1️⃣ Iterative BFS (Optimized) – Using Queue**

This is the most commonly used approach, leveraging **BFS (Breadth-First Search)** using a queue.

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q({root});
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i > 0; i--) {
                auto n = q.front(); q.pop();
                level.push_back(n->data);
                if (n->left) q.push(n->left);
                if (n->right) q.push(n->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};
```

### **2️⃣ Recursive DFS (Depth First Search)**

This approach utilizes **DFS recursion** to store nodes level-wise.

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(Node* root, int lvl, vector<vector<int>>& res) {
        if (!root) return;
        if (lvl == res.size()) res.push_back({});
        res[lvl].push_back(root->data);
        dfs(root->left, lvl + 1, res);
        dfs(root->right, lvl + 1, res);
    }
};
```

### **3️⃣ BFS Using Single Loop (Memory Efficient)**

This is a **slightly more optimized** BFS version that avoids extra memory operations.

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            while (n--) {
                auto node = q.front(); q.pop();
                level.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};
```

### **Comparison of Approaches**

| **Approach**                   | **Time Complexity** | **Space Complexity**       | **Best For**              |
| ------------------------------ | ------------------- | -------------------------- | ------------------------- |
| **Iterative BFS (Queue) (1️⃣)** | **O(n)**            | **O(n)** (queue storage)   | General case (most used)  |
| **Recursive DFS (2️⃣)**         | **O(n)**            | **O(n)** (recursion stack) | Balanced trees (elegant)  |
| **Memory Efficient BFS (3️⃣)**  | **O(n)**            | **O(n)** (optimized queue) | Space-efficient traversal |

### **Final Recommendation**

- **For General Use (Fast & Simple)** → Use **Iterative BFS (1️⃣)**
- **For Elegant Recursive Solutions** → Use **DFS Recursion (2️⃣)**
- **For Space Efficiency** → Use **Memory-Efficient BFS (3️⃣)**

🚀 **The most optimized and commonly used approach is 1️⃣ (Iterative BFS with Queue).**

</details>

## Code (Java)

```java
class Solution {
    public ArrayList<ArrayList<Integer>> levelOrder(Node root) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        if (root == null) return res;
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty()) {
            ArrayList<Integer> level = new ArrayList<>();
            for (int i = q.size(); i > 0; i--) {
                Node n = q.poll();
                level.add(n.data);
                if (n.left != null) q.add(n.left);
                if (n.right != null) q.add(n.right);
            }
            res.add(level);
        }
        return res;
    }
}
```

## Code (Python)

```python
class Solution:
    def levelOrder(self, root):
        if not root: return []
        res, q = [], [root]
        while q:
            res.append([n.data for n in q])
            q = [c for n in q for c in (n.left, n.right) if c]
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
