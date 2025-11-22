---
title: "🏥 Minimum Operations to Connect Hospitals | GFG Solution 🔗"
keywords🏷️: ["🏥 hospital network", "🔗 union find", "📊 DSU", "🌐 graph connectivity", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Operations to Connect Hospitals problem: determine minimum reconnections needed to connect all hospitals using Union-Find with path compression. 🚀"
date: 📅 2025-11-22
---

# *22. Minimum Operations to Connect Hospitals*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimize-connections/1)

## **🧩 Problem Description**

You are given an undirected network of V hospitals numbered from 0 to V - 1, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` denotes a direct connection between hospital `u` and hospital `v`.

In one operation, you are allowed to remove any existing link and reconnect it between two hospitals that are currently not directly or indirectly connected.

Your task is to determine the **minimum number of operations** required to make sure that all hospitals become connected, either directly or indirectly, using the given links.

**Note:** If it is impossible to connect all hospitals into a single network, return -1.

## **📘 Examples**

### Example 1

```cpp
Input: V = 4, E = 3, edges[][] = [[0, 1], [0, 2], [1, 2]]
Output: 1
Explanation: Remove the connection between hospitals 1 and 2 and connect hospitals 1 and 3.
The redundant edge [1, 2] can be used to connect the isolated hospital 3.
```

### Example 2

```cpp
Input: V = 5, E = 4, edges[][] = [[0, 1], [0, 2], [2, 3], [3, 4]]
Output: 0
Explanation: All hospitals are already connected directly or indirectly. 
No rearrangement of connections is required.
```

## **🔒 Constraints**

* $1 \le V \le 10^3$
* $0 \le E \le V \times (V-1)/2$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$

## **✅ My Approach**

The optimal approach uses the **Disjoint Set Union (DSU)** data structure with **path compression** to efficiently track connected components:

### **Union-Find with Path Compression**

1. **Initial Check:**
   * If the number of edges is less than `V - 1`, it's impossible to connect all hospitals, return -1.
   * A tree connecting V nodes requires at least V-1 edges.

2. **Initialize DSU:**
   * Create a parent array where each hospital is initially its own parent.
   * Track the number of components, initially equal to V.

3. **Process Edges:**
   * For each edge, find the root representatives of both hospitals using path compression.
   * If they belong to different components, union them by updating parent pointers.
   * Decrement the component count when a successful union occurs.

4. **Calculate Result:**
   * After processing all edges, the number of operations needed equals `components - 1`.
   * This represents the number of edges needed to connect all remaining disconnected components.

5. **Path Compression Optimization:**
   * During the find operation, compress paths by making nodes point directly to the root.
   * This ensures nearly constant-time operations for subsequent queries.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(E × α(V)), where E is the number of edges and α is the inverse Ackermann function. Due to path compression, α(V) is effectively constant (≤ 5) for all practical values, making this approach nearly linear in practice.
* **Expected Auxiliary Space Complexity:** O(V), as we only use a parent array of size V to track the disjoint set structure. No additional data structures like adjacency lists are required.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        int comp = V, e = edges.size();
        if (e < V - 1) return -1;
        vector<int> p(V);
        for (int i = 0; i < V; i++) p[i] = i;
        for (auto &ed : edges) {
            int x = findp(p, ed[0]), y = findp(p, ed[1]);
            if (x != y) { p[x] = y; --comp; }
        }
        return comp - 1;
    }
    int findp(vector<int> &p, int x) {
        return p[x] == x ? x : p[x] = findp(p, p[x]);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS Component Counting**

### 💡 Algorithm Steps:

1. Build adjacency list from edges for graph representation.
2. Use DFS to traverse and mark all nodes in each component.
3. Count total disconnected components in the graph.
4. Calculate if extra edges can connect all components together.

```cpp
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        int comp = 0;
        function<void(int)> dfs = [&](int u) { vis[u] = 1; for (int v : g[u]) if (!vis[v]) dfs(v); };
        for (int i = 0; i < V; i++) if (!vis[i]) ++comp, dfs(i);
        int extra = edges.size() - (V - comp);
        return extra >= comp - 1 ? comp - 1 : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Graph traversal visits all vertices and edges
* **Auxiliary Space:** 💾 O(V + E) - Adjacency list and recursion stack

### ✅ **Why This Approach?**

* Natural graph traversal using DFS pattern
* Clear component identification logic
* Easy visualization of connected regions

## 📊 **3️⃣ BFS Component Detection**

### 💡 Algorithm Steps:

1. Create adjacency list representation of the graph structure.
2. Use BFS with queue to explore each component level by level.
3. Track visited nodes to avoid counting same component multiple times.
4. Verify if redundant edges exist to bridge all components.

```cpp
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        int comp = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ++comp;
                queue<int> q; q.push(i); vis[i] = 1;
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    for (int v : g[u]) if (!vis[v]) vis[v] = 1, q.push(v);
                }
            }
        }
        int extra = edges.size() - (V - comp);
        return extra >= comp - 1 ? comp - 1 : -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Breadth-first traversal of graph
* **Auxiliary Space:** 💾 O(V + E) - Queue and adjacency list storage

### ✅ **Why This Approach?**

* Iterative approach avoids stack overflow risks
* Level-by-level exploration is intuitive
* Good for shortest path related extensions

## 📊 **4️⃣ Quick Union-Find**

### 💡 Algorithm Steps:

1. Initialize parent array where each node is its own parent.
2. For each edge, find roots of both endpoints without path compression.
3. Union components by linking parent pointers directly.
4. Count remaining components and check if connections are possible.

```cpp
class Solution {
public:
    int minConnect(int V, vector<vector<int>>& edges) {
        if (edges.size() < V - 1) return -1;
        vector<int> p(V);
        iota(p.begin(), p.end(), 0);
        int comp = V;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            while (p[x] != x) x = p[x];
            while (p[y] != y) y = p[y];
            if (x != y) p[x] = y, --comp;
        }
        return comp - 1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(E × log V) - Without path compression optimization
* **Auxiliary Space:** 💾 O(V) - Parent array only

### ✅ **Why This Approach?**

* Simple union-find without compression optimization
* Minimal code for union-find implementation
* Good baseline for understanding DSU pattern

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Union-Find (Path Compression)** | 🟢 O(E × α(V))        | 🟢 O(V)                 | 🚀 Near optimal with compression  | 🔧 Requires DSU knowledge            |
| 🔍 **DFS Component Counting**      | 🟢 O(V + E)            | 🟡 O(V + E)             | 📖 Intuitive graph traversal      | 💾 Higher space for adjacency list   |
| 📊 **BFS Component Detection**     | 🟢 O(V + E)            | 🟡 O(V + E)             | 🎯 Iterative, no recursion        | 🐌 Queue overhead                    |
| 🔄 **Quick Union-Find**            | 🟡 O(E × log V)        | 🟢 O(V)                 | ⭐ Minimal space usage            | 🔧 Slower without optimization       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Union-Find Path Compression**   | ★★★★★                     |
| 📖 **Learning graph algorithms**                      | 🥈 **DFS Component Counting**        | ★★★★☆                     |
| 🔧 **Avoiding recursion**                             | 🥉 **BFS Component Detection**       | ★★★★☆                     |
| 🎯 **Minimal space constraint**                       | 🏅 **Quick Union-Find**              | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minConnect(int V, int[][] edges) {
        int comp = V, e = edges.length;
        if (e < V - 1) return -1;
        int[] p = new int[V];
        for (int i = 0; i < V; i++) p[i] = i;
        for (int[] ed : edges) {
            int x = find(p, ed[0]), y = find(p, ed[1]);
            if (x != y) { p[x] = y; --comp; }
        }
        return comp - 1;
    }
    int find(int[] p, int x) { 
       return p[x] == x ? x : (p[x] = find(p, p[x])); 
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minConnect(self, V, edges):
        comp, e = V, len(edges)
        if e < V - 1: return -1
        p = list(range(V))
        def find(x): 
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        for u, v in edges:
            x, y = find(u), find(v)
            if x != y: p[x] = y; comp -= 1
        return comp - 1
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

