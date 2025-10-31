---
title: "🔄 Shortest Cycle | GFG Solution 🔍"
keywords🏷️: ["🔄 shortest cycle", "🔍 BFS", "📍 graph traversal", "📈 cycle detection", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Shortest Cycle in Undirected Graph problem: find minimum length cycle in an undirected graph using multi-source BFS technique. 🚀"
date: 📅 2025-10-31
---

# *31. Shortest Cycle*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/shortest-cycle/1)

## **🧩 Problem Description**

You are given an undirected graph with `V` vertices numbered from 0 to V-1 and `E` edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents an undirected edge between vertex `u` and `v`.

Find the length of the **shortest cycle** in the graph. If the graph does not contain any cycle, return `-1`.

A cycle is a path that starts and ends at the same vertex without repeating any edge or vertex (except the start/end vertex). The shortest cycle is the one with the minimum number of edges.

## **📘 Examples**

### Example 1

```cpp
Input: V = 7, E = 8, edges[][] = [[0, 5], [0, 6], [5, 1], [6, 1], [6, 2], [2, 3], [3, 4], [1, 4]]
Output: 4
Explanation: Possible cycles are: 
0 → 5 → 1 → 6 → 0 (length = 4)
1 → 4 → 3 → 2 → 6 → 1 (length = 5)
The smallest one is 0 → 5 → 1 → 6 → 0, with length 4.
```

### Example 2

```cpp
Input: V = 7, E = 9, edges[][] = [[0, 5], [0, 6], [1, 2], [1, 4], [1, 5], [1, 6], [2, 6], [2, 3], [3, 4]]
Output: 3
Explanation: Possible cycles include:
1 → 2 → 6 → 1 (length = 3)
1 → 2 → 3 → 4 → 1 (length = 4)
0 → 5 → 1 → 6 → 0 (length = 4)
The smallest one is 1 → 2 → 6 → 1, with length 3.
```

## **🔒 Constraints**

* $1 \le V \le 10^3$
* $0 \le E \le 10^3$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$

## **✅ My Approach**

The optimal approach uses **Multi-Source BFS** to detect the shortest cycle by running BFS from every vertex:

### **Multi-Source BFS Approach**

1. **Build Adjacency List:**
   * Convert the edge list to an adjacency list representation for efficient neighbor access.
   * For each edge `[u, v]`, add `v` to `adj[u]` and `u` to `adj[v]`.

2. **Run BFS from Each Vertex:**
   * For each vertex `i` from 0 to V-1, run a BFS to detect cycles.
   * Maintain two arrays: `d[]` for distance from source and `p[]` for parent tracking.

3. **Detect Cycle During BFS:**
   * When visiting a neighbor `v` from current node `u`:
     * If `v` is unvisited (`d[v] == -1`), mark distance and parent, then enqueue.
     * If `v` is visited and not the parent of `u` (`p[u] != v`), a cycle is found.
     * Calculate cycle length as `d[u] + d[v] + 1` (distance from source to both endpoints plus the edge connecting them).

4. **Track Minimum Cycle:**
   * Update result with the minimum cycle length found across all BFS runs.

5. **Return Result:**
   * If no cycle is detected, return -1; otherwise, return the minimum cycle length.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V × (V + E)), as we run BFS from each of the V vertices, and each BFS traversal visits all vertices and edges in the worst case. For each vertex, BFS takes O(V + E) time.
* **Expected Auxiliary Space Complexity:** O(V + E), where O(E) is used for storing the adjacency list representation of the graph, and O(V) is used for the distance and parent arrays during each BFS traversal.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (int i = 0; i < V; i++) {
            vector<int> d(V, -1), p(V, -1);
            queue<int> q;
            d[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        p[v] = u;
                        q.push(v);
                    } else if (p[u] != v) res = min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Modified BFS with Simplified Parent Check**

### 💡 Algorithm Steps:

1. Build adjacency list representation of the graph.
2. Run BFS from each vertex as a potential cycle starting point.
3. Instead of strict parent checking, use bidirectional distance comparison.
4. When encountering a visited node, check if `d[v] >= d[u]` to detect back edges forming cycles.
5. Calculate cycle length and track the minimum across all starting vertices.

```cpp
class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (int i = 0; i < V; i++) {
            vector<int> d(V, -1);
            queue<int> q;
            d[i] = 0;
            q.push(i);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    } else if (d[v] >= d[u]) res = min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V × (V + E))
* **Auxiliary Space:** 💾 O(V + E)

### ✅ **Why This Approach?**

* Simplified logic without explicit parent tracking
* Reduces memory by one array per BFS
* Effective for dense graphs with many cycles

## 📊 **3️⃣ Edge-Centric BFS**

### 💡 Algorithm Steps:

1. For each edge in the graph, temporarily remove it.
2. Run BFS from one endpoint to find shortest path to the other endpoint.
3. If a path exists after edge removal, the original edge completes a cycle.
4. Cycle length equals the shortest path distance plus 1 (for the removed edge).
5. Track minimum cycle length across all edge removal attempts.

```cpp
class Solution {
public:
    int shortCycle(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = INT_MAX;
        for (auto &e : edges) {
            vector<int> d(V, -1);
            queue<int> q;
            d[e[0]] = 0;
            q.push(e[0]);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if ((u == e[0] && v == e[1]) || (u == e[1] && v == e[0])) continue;
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
                }
            }
            if (d[e[1]] != -1) res = min(res, d[e[1]] + 1);
        }
        return res == INT_MAX ? -1 : res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(E × (V + E))
* **Auxiliary Space:** 💾 O(V + E)

### ✅ **Why This Approach?**

* Intuitive edge-based perspective on cycles
* Useful for understanding cycle structure
* Can identify which specific edges participate in shortest cycle

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Multi-source BFS**           | 🟡 O(V × (V + E))      | 🟡 O(V + E)             | 🎯 Guarantees shortest cycle      | 🐌 Slower for very dense graphs      |
| 📊 **Modified BFS**                | 🟡 O(V × (V + E))      | 🟢 O(V)                 | 💾 Less memory per iteration      | 🔧 May need careful handling         |
| 🔄 **Edge-Centric BFS**            | 🔴 O(E × (V + E))      | 🟡 O(V + E)             | 💡 Clear edge perspective         | 🐌 Slowest for large graphs          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Interview / Competitive Programming**         | 🥇 **Multi-source BFS**              | ★★★★★                     |
| 📖 **Memory-constrained environments**             | 🥈 **Modified BFS**                  | ★★★★☆                     |
| 🔧 **Understanding cycle composition**             | 🥉 **Edge-Centric BFS**              | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int shortCycle(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < V; i++) {
            int[] d = new int[V];
            int[] p = new int[V];
            Arrays.fill(d, -1);
            Arrays.fill(p, -1);
            Queue<Integer> q = new LinkedList<>();
            d[i] = 0;
            q.offer(i);
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj.get(u)) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        p[v] = u;
                        q.offer(v);
                    } else if (p[u] != v) res = Math.min(res, d[u] + d[v] + 1);
                }
            }
        }
        return res == Integer.MAX_VALUE ? -1 : res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def shortCycle(self, V, edges):
        from collections import deque
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        res = float('inf')
        for i in range(V):
            d = [-1] * V
            p = [-1] * V
            q = deque([i])
            d[i] = 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if d[v] == -1:
                        d[v] = d[u] + 1
                        p[v] = u
                        q.append(v)
                    elif p[u] != v:
                        res = min(res, d[u] + d[v] + 1)
        return -1 if res == float('inf') else res
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

