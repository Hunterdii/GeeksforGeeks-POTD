---
title: "🌳 Bottom View of Binary Tree | GFG Solution 🔍"
keywords🏷️: ["🌳 binary tree", "🔍 bottom view", "📍 BFS traversal", "📈 horizontal distance", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Bottom View of Binary Tree problem: find nodes visible from bottom using level order traversal and horizontal distance tracking. 🚀"
date: 📅 2025-10-07
---

# *07. Bottom View of Binary Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)

## **🧩 Problem Description**

You are given the root of a binary tree, and your task is to return its **bottom view**. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

**Note:** If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

## **📘 Examples**

### Example 1

```cpp
Input: root = [1, 2, 3, 4, 5, N, 6]
Output: [4, 2, 5, 3, 6]
Explanation: The nodes visible from the bottom view are 4, 2, 5, 3, and 6 
based on their horizontal distances.
```

### Example 2

```cpp
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
Output: [5, 10, 4, 28, 25]
Explanation: These nodes are visible when viewing the tree from bottom, 
considering horizontal distances and level order priority.
```

## **🔒 Constraints**

* $1 \le \text{number of nodes} \le 10^5$
* $1 \le \text{node->data} \le 10^5$

## **✅ My Approach**

The optimal approach uses **Level Order Traversal (BFS)** with **Horizontal Distance Tracking** using a map to efficiently find bottom view nodes:

### **BFS with Horizontal Distance Mapping**

1. **Initialize Data Structures:**
   * Use a `map<int, int>` to store the mapping from horizontal distance to node value.
   * Use a queue to perform level order traversal, storing pairs of `(Node*, horizontal_distance)`.
   * Start with root at horizontal distance 0.

2. **Perform Level Order Traversal:**
   * Dequeue the front node and its horizontal distance.
   * Update the map with current node's data at its horizontal distance (overwrites previous value).
   * For left child: enqueue with `horizontal_distance - 1`.
   * For right child: enqueue with `horizontal_distance + 1`.

3. **Extract Bottom View:**
   * The map automatically maintains sorted order of horizontal distances.
   * Since we process level by level and update the map, the last node at each horizontal distance represents the bottom view.
   * Extract all values from the map in order.

4. **Return Result:**
   * Convert map values to vector and return as the bottom view.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the number of nodes in the binary tree. We visit each node once during BFS traversal (O(n)), and each map insertion/update operation takes O(log n) time due to the ordered map structure.
* **Expected Auxiliary Space Complexity:** O(w), where w is the maximum width of the tree. The queue can hold at most w nodes at any level, and the map stores at most w entries for different horizontal distances.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            m[hd] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> res;
        for (auto& [k, v] : m) res.push_back(v);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS with Level Tracking**

### 💡 Algorithm Steps:

1. Use DFS traversal while tracking horizontal distance and depth level.
2. Store node data only if it's deeper than previously stored node at same horizontal distance.
3. Update the map with node data when a deeper level is encountered.
4. Extract values from the sorted map for the final result.

```cpp
class Solution {
public:
    vector<int> bottomView(Node* root) {
        map<int, pair<int, int>> m;
        dfs(root, 0, 0, m);
        vector<int> res;
        for (auto& [k, p] : m) res.push_back(p.second);
        return res;
    }
    void dfs(Node* node, int hd, int lvl, map<int, pair<int, int>>& m) {
        if (!node) return;
        if (m.find(hd) == m.end() || m[hd].first <= lvl) 
            m[hd] = {lvl, node->data};
        dfs(node->left, hd - 1, lvl + 1, m);
        dfs(node->right, hd + 1, lvl + 1, m);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - DFS traversal with map operations
* **Auxiliary Space:** 💾 O(h + w) - Recursion stack height and width of tree

### ✅ **Why This Approach?**

* Recursive approach for developers comfortable with DFS
* Natural depth tracking without explicit level order traversal
* Clean separation of concerns with helper function

## 📊 **3️⃣ TreeMap with Custom Comparator**

### 💡 Algorithm Steps:

1. Perform level order traversal using BFS with queue.
2. Store nodes with their horizontal distance and level in a TreeMap.
3. Automatically maintains sorted order of horizontal distances.
4. Extract bottom-most nodes by overwriting with later levels.

```cpp
class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto [curr, dist] = q.front();
                q.pop();
                mp[dist] = curr->data;
                if (curr->left) q.push({curr->left, dist - 1});
                if (curr->right) q.push({curr->right, dist + 1});
            }
        }
        vector<int> ans;
        for (auto& p : mp) ans.push_back(p.second);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n) - BFS with sorted map insertions
* **Auxiliary Space:** 💾 O(w) - Width of tree for queue and map

### ✅ **Why This Approach?**

* Level-wise processing ensures correct bottom view
* Map automatically handles sorting by horizontal distance
* No need for manual min/max tracking

## 📊 **4️⃣ Vector-Based Range Mapping**

### 💡 Algorithm Steps:

1. Find the range of horizontal distances in a preprocessing pass.
2. Use offset-based indexing with vector instead of map.
3. Perform BFS and update vector positions directly.
4. Avoid map overhead with constant-time array access.

```cpp
class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        int mn = 0, mx = 0;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            mn = min(mn, hd);
            mx = max(mx, hd);
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> v(mx - mn + 1);
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            v[hd - mn] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        return v;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Two BFS passes with array operations
* **Auxiliary Space:** 💾 O(w) - Width of tree for vector storage

### ✅ **Why This Approach?**

* Faster constant-time array access vs map operations
* Optimal for wide trees with many horizontal distances
* Eliminates sorting overhead entirely

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **BFS with Map**              | 🟢 O(n log n)          | 🟢 O(w)                 | 🚀 Clean and concise              | 🔧 Map overhead                      |
| 🔍 **DFS with Levels**            | 🟢 O(n log n)          | 🟡 O(h + w)             | 📖 Recursive elegance             | 💾 Stack space required              |
| 📊 **Level-wise BFS**             | 🟢 O(n log n)          | 🟢 O(w)                 | 🎯 Clear level separation         | 🐌 Nested loops complexity           |
| 🔄 **Vector Range Mapping**       | 🟢 O(n)                | 🟢 O(w)                 | ⭐ Fastest with O(1) access       | 🔧 Two-pass traversal needed         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Vector Range Mapping**          | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **BFS with Map**                  | ★★★★★                     |
| 🔧 **Recursive preference**                           | 🥉 **DFS with Levels**               | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **BFS with Map**                  | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> bottomView(Node root) {
        ArrayList<Integer> res = new ArrayList<>();
        if (root == null) return res;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root, 0));
        while (!q.isEmpty()) {
            Pair p = q.poll();
            map.put(p.hd, p.node.data);
            if (p.node.left != null) q.add(new Pair(p.node.left, p.hd - 1));
            if (p.node.right != null) q.add(new Pair(p.node.right, p.hd + 1));
        }
        for (int val : map.values()) res.add(val);
        return res;
    }
    class Pair {
        Node node;
        int hd;
        Pair(Node n, int h) { node = n; hd = h; }
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def bottomView(self, root):
        if not root: return []
        d = {}
        q = deque([(root, 0)])
        while q:
            node, hd = q.popleft()
            d[hd] = node.data
            if node.left: q.append((node.left, hd - 1))
            if node.right: q.append((node.right, hd + 1))
        return [d[k] for k in sorted(d)]
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
