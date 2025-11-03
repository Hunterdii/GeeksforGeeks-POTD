---
title: "🔒 Safe States | GFG Solution 🔍"
keywords🏷️: ["🔒 safe states", "🔍 graph algorithms", "📍 topological sort", "📈 BFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Safe States problem: find all safe nodes in a directed graph where every path leads to a terminal node using reverse topological sort technique. 🚀"
date: 📅 2025-11-03
---

# *03. Safe States*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/eventual-safe-states/1)

## **🧩 Problem Description**

You are given a directed graph with `V` vertices numbered from `0` to `V-1` and `E` directed edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents a directed edge from vertex `u` to vertex `v`. Your task is to return all **Safe Nodes** of the graph.

A vertex with no outgoing edges is called a **terminal node**. A vertex is considered **safe** if every path starting from it eventually reaches a terminal node (i.e., it doesn't lead to a cycle or get stuck in an infinite loop).

## **📘 Examples**

### Example 1

```cpp
Input: V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]
Output: [0, 1, 2, 3, 4]
Explanation: Vertices 4 and 0 are terminal nodes (no outgoing edges). 
All paths from vertices 1, 2, and 3 eventually lead to terminal node 4.
Therefore, all nodes are safe.
```

### Example 2

```cpp
Input: V = 4, E = 3, edges[][] = [[1, 2], [2, 3], [3, 2]]
Output: [0]
Explanation: Vertex 0 is a terminal node with no outgoing edges.
Vertices 2 and 3 form a cycle, making vertex 1 unsafe.
Only vertex 0 is safe.
```

## **🔒 Constraints**

* $1 \le V \le 10^5$
* $0 \le E \le 10^5$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$

## **✅ My Approach**

The optimal approach uses **Reverse Topological Sort** with **BFS (Kahn's Algorithm)** to efficiently identify safe nodes:

### **Reverse Topological Sort + BFS**

1. **Build Reverse Graph:**
   * Create a reversed adjacency list where edges point backward.
   * Calculate outdegree for each node (number of outgoing edges in original graph).

2. **Initialize Queue:**
   * Add all terminal nodes (outdegree = 0) to the queue.
   * Mark these nodes as safe.

3. **Process Nodes:**
   * Dequeue a safe node and process its predecessors in the reverse graph.
   * Decrement the outdegree of each predecessor.
   * If a predecessor's outdegree becomes 0, mark it safe and add to queue.

4. **Collect Results:**
   * After processing, collect all nodes marked as safe.
   * These are nodes from which all paths lead to terminal nodes.

5. **Key Insight:**
   * By reversing the graph and starting from terminal nodes, we propagate safety backward.
   * A node is safe only when all its outgoing paths have been verified as safe.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V + E), as we traverse each vertex and edge exactly once during the BFS process. Building the reverse graph takes O(E) time, and processing all nodes takes O(V) time.
* **Expected Auxiliary Space Complexity:** O(V + E), where O(V) is used for storing outdegree and safe arrays, and O(E) is used for storing the reverse adjacency list. The queue uses at most O(V) space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<int> out(V), safe(V);
        vector<vector<int>> g(V);
        for (auto& e : edges) out[e[0]]++, g[e[1]].push_back(e[0]);
        queue<int> q;
        for (int i = 0; i < V; i++) if (!out[i]) q.push(i), safe[i] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) if (!safe[v] && --out[v] == 0) q.push(v), safe[v] = 1;
        }
        vector<int> res;
        for (int i = 0; i < V; i++) if (safe[i]) res.push_back(i);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS with Color Marking**

### 💡 Algorithm Steps:

1. Use three colors: white (unvisited), gray (visiting), black (safe).
2. Perform DFS from each unvisited node to detect cycles.
3. Mark nodes as gray during traversal and black when safe.
4. A node is safe if all its paths lead to terminal nodes or safe nodes.

```cpp
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]);
        vector<int> col(V), res;
        for (int i = 0; i < V; i++) if (!col[i]) dfs(i, adj, col);
        for (int i = 0; i < V; i++) if (col[i] == 2) res.push_back(i);
        return res;
    }
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& col) {
        if (col[u]) return col[u] == 2;
        col[u] = 1;
        for (int v : adj[u]) if (!dfs(v, adj, col)) return false;
        col[u] = 2;
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Visit each vertex and edge once
* **Auxiliary Space:** 💾 O(V) - Recursion stack and color array

### ✅ **Why This Approach?**

* Natural recursive solution pattern
* Efficient cycle detection mechanism
* Clear state tracking with three colors

## 📊 **3️⃣ Topological Sort with Adjacency List**

### 💡 Algorithm Steps:

1. Build adjacency list and calculate outdegree for each node.
2. Use queue-based topological sort starting from terminal nodes.
3. Process nodes with zero outdegree and reduce outdegree of predecessors.
4. Collect all processed nodes as safe nodes.

```cpp
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> rev(V);
        vector<int> deg(V);
        for (auto& e : edges) rev[e[1]].push_back(e[0]), deg[e[0]]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (!deg[i]) q.push(i);
        vector<int> ans;
        while (q.size()) {
            int node = q.front(); q.pop();
            ans.push_back(node);
            for (int prev : rev[node]) if (--deg[prev] == 0) q.push(prev);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E + V log V) - Graph processing plus sorting
* **Auxiliary Space:** 💾 O(V + E) - Reversed graph storage

### ✅ **Why This Approach?**

* Based on standard topological sort algorithm
* Intuitive reverse graph processing
* Works well with directed acyclic components

## 📊 **4️⃣ BFS from Safe Nodes**

### 💡 Algorithm Steps:

1. Create reverse adjacency list mapping nodes to their predecessors.
2. Initialize BFS queue with all terminal nodes (outdegree zero).
3. Propagate safety backward through the graph using BFS.
4. Mark and collect all nodes that can reach terminal nodes safely.

```cpp
class Solution {
public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        vector<vector<int>> back(V);
        vector<int> cnt(V);
        for (auto& e : edges) back[e[1]].push_back(e[0]), cnt[e[0]]++;
        vector<bool> vis(V);
        queue<int> q;
        for (int i = 0; i < V; i++) if (cnt[i] == 0) q.push(i), vis[i] = 1;
        while (q.size()) {
            int cur = q.front(); q.pop();
            for (int pre : back[cur]) if (!vis[pre] && --cnt[pre] == 0) q.push(pre), vis[pre] = 1;
        }
        vector<int> ans;
        for (int i = 0; i < V; i++) if (vis[i]) ans.push_back(i);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Single pass through vertices and edges
* **Auxiliary Space:** 💾 O(V + E) - Reverse graph and auxiliary arrays

### ✅ **Why This Approach?**

* Clean BFS implementation pattern
* Efficient level-by-level processing
* Natural fit for graph reachability problems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Reverse Topological**       | 🟢 O(V + E)            | 🟢 O(V)                 | 🚀 Most space efficient           | 🔧 Requires understanding reverse graph |
| 🔍 **DFS Color Marking**          | 🟢 O(V + E)            | 🟡 O(V)                 | 📖 Intuitive recursion            | ⚠️ Stack overflow risk for deep graphs |
| 📊 **Topological Sort**           | 🟡 O(V + E + V log V)  | 🟡 O(V + E)             | 🎯 Standard algorithm pattern     | 🐌 Extra sorting overhead             |
| 🔄 **BFS Propagation**            | 🟢 O(V + E)            | 🟡 O(V + E)             | ⭐ Iterative and safe             | 💾 More space for reverse graph       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Reverse Topological**           | ★★★★★                     |
| 📖 **Recursive solution preference**                  | 🥈 **DFS Color Marking**             | ★★★★☆                     |
| 🔧 **Standard pattern familiarity**                   | 🥉 **Topological Sort**              | ★★★★☆                     |
| 🎯 **Interview/Iterative preference**                 | 🏅 **BFS Propagation**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        int[] out = new int[V];
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges) { out[e[0]]++; g.get(e[1]).add(e[0]); }
        Queue<Integer> q = new LinkedList<>();
        boolean[] safe = new boolean[V];
        for (int i = 0; i < V; i++) if (out[i] == 0) { q.add(i); safe[i] = true; }
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g.get(u)) if (!safe[v] && --out[v] == 0) { q.add(v); safe[v] = true; }
        }
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) if (safe[i]) res.add(i);
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def safeNodes(self, V, edges):
        out, g = [0] * V, [[] for _ in range(V)]
        for u, v in edges: out[u] += 1; g[v].append(u)
        q, safe = [], [0] * V
        for i in range(V):
            if not out[i]: q.append(i); safe[i] = 1
        for u in q:
            for v in g[u]:
                if not safe[v]:
                    out[v] -= 1
                    if not out[v]: q.append(v); safe[v] = 1
        return [i for i in range(V) if safe[i]]
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
