---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Tree
---

# 🚀 _Day 3. Diameter of a Binary Tree_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/tree-gfg-160/problem/diameter-of-binary-tree)

## 💡 **Problem Description:**

Given a binary tree, the diameter (or width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to determine the diameter of the tree.

## 🔍 **Example Walkthrough:**

**Input:**  
`root[] = [1, 2, 3]`

<img src="https://github.com/user-attachments/assets/59d0050e-2436-4134-a460-3ab897ac178e" width="30%">

**Output:**  
`2`  
**Explanation:**  
The longest path has 2 edges: (node 2 -> node 1 -> node 3).

**Input:**  
`root[] = [5, 8, 6, 3, 7, 9]`

<img src="https://github.com/user-attachments/assets/2d8bdef5-2cdb-4c5c-9f84-083f96d60d1e" width="30%">

**Output:**  
`4`  
**Explanation:**  
The longest path has 4 edges: (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

### Constraints

- 1 ≤ number of nodes ≤ $10^5$
- 0 ≤ node->data ≤ $10^5$

## 🎯 **My Approach:**

1. **Single DFS Traversal (Pair Method):**  
   Use a recursive function that returns a pair: the height of the current subtree and the diameter computed so far. For each node, compute:
   - The height as `1 + max(height(left), height(right))`.
   - The diameter as the maximum of:
     - The diameter in the left subtree.
     - The diameter in the right subtree.
     - The sum of the heights of the left and right subtrees (which represents the path passing through the current node).

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as each node is visited exactly once.
- **Expected Auxiliary Space Complexity:** O(H), where H is the height of the tree (due to recursion stack).

## 📝 **Solution Code**

## Code (C)

```c
struct Pair {
    int h, d; // h: height, d: diameter
};

struct Pair f(struct Node* r) {
    struct Pair p = {0, 0};         // Base case: empty node returns {0,0}
    if (!r) return p;
    // Recursively compute left and right subtree results
    struct Pair a = f(r->left), b = f(r->right);
    p.h = 1 + (a.h > b.h ? a.h : b.h);  // Height is max of left/right + 1
    int m = a.d > b.d ? a.d : b.d;        // m: max diameter from children
    int s = a.h + b.h;                    // s: diameter passing through current node
    p.d = m > s ? m : s;                  // Maximum diameter so far
    return p;
}

int diameter(struct Node* root) {
    return f(root).d;                   // Return computed diameter
}
```

## Code (C++)

```cpp
class Solution {
  public:
    int dfs(Node* n, int &d) {
        if (!n) return 0;                      // Base case: empty node has height 0
        int l = dfs(n->left, d), r = dfs(n->right, d);
        d = max(d, l + r);                       // Update diameter if path through n is larger
        return 1 + max(l, r);                    // Return height of current node
    }

    int diameter(Node* root) {
        int d = 0;
        dfs(root, d);
        return d;                              // Final diameter
    }
};
```

<details>
  <summary><h2 align="center">🌲 Alternative Approaches</h2></summary>

### **1️⃣ Using a Pair (Single DFS Traversal)**

```cpp
class Solution {
public:
    pair<int,int> f(Node* r){
        if(!r) return {0,0};
        auto l = f(r->left), rt = f(r->right);
        int h = 1 + max(l.first, rt.first);
        int d = max({l.second, rt.second, l.first + rt.first});
        return {h, d};
    }
    int diameter(Node* root){
        return f(root).second;
    }
};
```

### **2️⃣ Iterative Approach (BFS + Map for Height)**

```cpp
class Solution {
public:
    int diameter(Node* root) {
        if (!root) return 0;
        unordered_map<Node*, int> h;
        vector<Node*> nodes;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* cur = q.front(); q.pop();
            nodes.push_back(cur);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        int d = 0;
        for (int i = nodes.size()-1; i >= 0; i--) {
            Node* cur = nodes[i];
            int l = cur->left ? h[cur->left] : 0;
            int r = cur->right ? h[cur->right] : 0;
            h[cur] = 1 + max(l, r);
            d = max(d, l + r);
        }
        return d;
    }
};
```

### **3️⃣ Two-Pass DFS (Undirected Graph Approach)**

```cpp
class Solution {
public:
    void build(Node* r, unordered_map<Node*, vector<Node*>>& g) {
        if (!r) return;
        if (r->left) {
            g[r].push_back(r->left);
            g[r->left].push_back(r);
            build(r->left, g);
        }
        if (r->right) {
            g[r].push_back(r->right);
            g[r->right].push_back(r);
            build(r->right, g);
        }
    }

    pair<Node*, int> dfs(Node* r, Node* p, unordered_map<Node*, vector<Node*>>& g) {
        pair<Node*, int> res = {r, 0};
        for (auto nb : g[r]) {
            if (nb == p) continue;
            auto t = dfs(nb, r, g);
            t.second++;
            if (t.second > res.second) res = t;
        }
        return res;
    }

    int diameter(Node* root) {
        if (!root) return 0;
        unordered_map<Node*, vector<Node*>> g;
        build(root, g);
        auto f = dfs(root, nullptr, g);
        auto s = dfs(f.first, nullptr, g);
        return s.second;
    }
};
```

## **Comparison of Approaches**

| Approach                      | Time Complexity | Space Complexity | Method    | Pros                          | Cons                                |
| ----------------------------- | --------------- | ---------------- | --------- | ----------------------------- | ----------------------------------- |
| **Pair (Single DFS)**         | 🟢 **O(N)**     | 🟡 **O(H)**      | DFS       | Concise, single-pass          | Recursion may be deep               |
| **Iterative BFS + Map**       | 🟢 **O(N)**     | 🔴 **O(N)**      | Iterative | Avoids recursion depth issues | Extra space for map/vector          |
| **Two-Pass DFS (Undirected)** | 🟢 **O(N)**     | 🔴 **O(N)**      | DFS       | Finds true farthest nodes     | Requires building an adjacency list |

**Best Choice?**

- Use the **Pair (Single DFS)** for clarity if recursion depth is acceptable.
- The **Iterative BFS** is preferable when avoiding recursion is important.
- The **Two-Pass DFS** method is ideal when you need the undirected perspective to correctly capture all paths.

</details>

## Code (Java)

```java
class Solution {
    int[] f(Node r) {
        if (r == null) return new int[]{0, 0};
        int[] a = f(r.left), b = f(r.right);
        int h = 1 + Math.max(a[0], b[0]);
        int d = Math.max(Math.max(a[1], b[1]), a[0] + b[0]);
        return new int[]{h, d};
    }

    int diameter(Node root) {
        return f(root)[1];
    }
}
```

## Code (Python)

```python
class Solution:
    def f(self, r):
        if not r:
            return (0, 0)
        a, b = self.f(r.left), self.f(r.right)
        h = 1 + max(a[0], b[0])
        d = max(a[1], b[1], a[0] + b[0])
        return (h, d)

    def diameter(self, root):
        return self.f(root)[1]
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
