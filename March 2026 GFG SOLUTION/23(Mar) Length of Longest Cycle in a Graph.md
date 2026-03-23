---
title: "🔁 Length of Longest Cycle in a Graph | GFG Solution 🔍"
keywords🏷️: ["🔁 longest cycle", "🔍 graph traversal", "📍 timestamp marking", "📈 functional graph", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Length of Longest Cycle in a Graph problem: find the longest cycle in a directed functional graph using iterative timestamp traversal. 🚀"
date: 📅 2025-03-23
---

# *23. Length of Longest Cycle in a Graph*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1)

## **🧩 Problem Description**

Given a **directed graph** with `V` vertices numbered from `0` to `V-1` and `E` edges, represented as a 2D array `edges[][]`, where each entry `edges[i] = [u, v]` denotes a directed edge from `u` to `v`. Each node has **at most one outgoing edge** (functional graph).

Your task is to find the **length of the longest cycle** present in the graph. If no cycle exists, return `-1`.

> **Note:** A cycle is a path that starts and ends at the same vertex.

## **📘 Examples**

### Example 1

```
Input: V = 7, edges[][] = [[0,5],[1,0],[2,4],[3,1],[4,6],[5,6],[6,3]]
Output: 5
Explanation: The longest cycle is 0 → 5 → 6 → 3 → 1 → 0, which has length 5.
```

### Example 2

```
Input: V = 8, edges[][] = [[0,1],[1,2],[2,3],[3,0],[4,1],[5,4],[6,2],[7,6]]
Output: 4
Explanation: The longest cycle is 0 → 1 → 2 → 3 → 0, which has length 4.
```

## **🔒 Constraints**

* $1 \le V, E \le 10^4$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$

## **✅ My Approach**

The optimal approach uses **Iterative Timestamp Traversal** — a technique specially suited for functional graphs (at most one outgoing edge per node):

### **Timestamp Traversal (Iterative)**

1. **Build Next Array:**
   * Since every node has at most one outgoing edge, flatten `edges[][]` into a `nxt[]` array where `nxt[u] = v`. Unconnected nodes have `nxt[u] = -1`.

2. **Initialize Visited Array:**
   * Maintain a `vis[]` array of size `V` initialized to `-1`. Instead of a simple boolean, store the **global timestamp** at which each node was first visited. This lets us measure cycle lengths directly by subtraction.

3. **Traverse Each Component:**
   * For every unvisited node `i`, record `start = t` (current global time) and walk the chain: assign `vis[cur] = t++`, then follow `nxt[cur]`.
   * Stop when either:
     * `cur == -1` → reached a dead end, no cycle in this path.
     * `vis[cur] != -1` → revisited a node. Two sub-cases:
       * `vis[cur] >= start` → the revisited node belongs to the **current traversal**, so a cycle exists. Its length is `t - vis[cur]`.
       * `vis[cur] < start` → the revisited node was already settled in a **previous traversal**; no new cycle here.

4. **Update Answer:**
   * Whenever a valid cycle is detected, update `ans = max(ans, t - vis[cur])`.

5. **Return Result:**
   * After all nodes are processed, return `ans`. If no cycle was ever found, `ans` remains `-1`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V), as each node is visited at most once across all traversals — the global timestamp ensures no node is re-processed.
* **Expected Auxiliary Space Complexity:** O(V), as we use a `nxt[]` array of size V to store the functional graph and a `vis[]` array of size V to record visit timestamps.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> nxt(V, -1);
        for (auto& e : edges) nxt[e[0]] = e[1];
        vector<int> vis(V, -1);
        int ans = -1, t = 0;
        for (int i = 0; i < V; i++) {
            if (vis[i] != -1) continue;
            int start = t, cur = i;
            while (cur != -1 && vis[cur] == -1) { vis[cur] = t++; cur = nxt[cur]; }
            if (cur != -1 && vis[cur] >= start) ans = max(ans, t - vis[cur]);
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS with 3-Color Marking**

### 💡 Algorithm Steps:

1. Build a `nxt[]` array from edges (functional graph).
2. Color each node: `0` = unvisited, `1` = currently in DFS stack, `2` = fully processed.
3. Track entry time (`tin[]`) for each node when it enters the stack.
4. During DFS, if the next node is already colored `1` (back-edge to active stack), compute cycle length as `t - tin[v]`.

```cpp
class Solution {
public:
    int ans = -1;
    void dfs(int u, vector<int>& nxt, vector<int>& color, vector<int>& tin, int& t) {
        color[u] = 1; tin[u] = t++;
        int v = nxt[u];
        if (v != -1) {
            if (color[v] == 0) dfs(v, nxt, color, tin, t);
            else if (color[v] == 1) ans = max(ans, t - tin[v]);
        }
        color[u] = 2;
    }
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> nxt(V, -1), color(V, 0), tin(V, -1);
        for (auto& e : edges) nxt[e[0]] = e[1];
        int t = 0;
        for (int i = 0; i < V; i++) if (!color[i]) dfs(i, nxt, color, tin, t);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V) — Each node is visited exactly once during DFS.
* **Auxiliary Space:** 💾 O(V) — Color array, `tin` array, and implicit recursion stack.

### ✅ **Why This Approach?**

* Classic back-edge detection maps naturally to cycle identification.
* 3-color scheme clearly distinguishes unvisited, active, and done states.
* Easy to reason about and extend for general directed graphs.

---

## 📊 **3️⃣ Topological Sort (Kahn's BFS)**

### 💡 Algorithm Steps:

1. Build `nxt[]` and compute in-degrees for all nodes.
2. BFS-remove all nodes with in-degree `0` iteratively — these nodes can never be part of a cycle.
3. Mark them as `removed`. After BFS, only cycle-participating nodes remain.
4. For each unremoved, unseen node, walk the chain counting nodes until a seen node is hit — that count is the cycle length.

```cpp
class Solution {
public:
    int longestCycle(int V, vector<vector<int>>& edges) {
        vector<int> nxt(V, -1), indeg(V, 0);
        for (auto& e : edges) { nxt[e[0]] = e[1]; indeg[e[1]]++; }
        queue<int> q;
        for (int i = 0; i < V; i++) if (!indeg[i]) q.push(i);
        vector<bool> removed(V, false);
        while (!q.empty()) {
            int u = q.front(); q.pop(); removed[u] = true;
            if (nxt[u] != -1 && --indeg[nxt[u]] == 0) q.push(nxt[u]);
        }
        int ans = -1;
        vector<bool> seen(V, false);
        for (int i = 0; i < V; i++) {
            if (removed[i] || seen[i]) continue;
            int len = 0, cur = i;
            while (!seen[cur]) { seen[cur] = true; len++; cur = nxt[cur]; }
            ans = max(ans, len);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V) — BFS over all nodes + single linear pass over cycle nodes.
* **Auxiliary Space:** 💾 O(V) — In-degree array, removed flags, and BFS queue.

### ✅ **Why This Approach?**

* Completely eliminates recursion — safe for very large inputs.
* Clean two-phase logic: prune non-cycle nodes first, then measure remaining cycles.
* Ideal when the graph has a large number of tree/chain nodes leading into cycles.

---

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros** | ⚠️ **Cons** |
|---|---|---|---|---|
| 🏷️ **Timestamp Traversal** | 🟢 O(V) | 🟢 O(V) | 🚀 Iterative, minimal code, fastest | 🔧 Works only on functional graphs |
| 🎨 **3-Color DFS** | 🟢 O(V) | 🟡 O(V) + stack | 📖 Intuitive, classic approach | 💾 Recursion stack risk on large input |
| 🔄 **Topological BFS** | 🟢 O(V) | 🟡 O(V) | ⭐ No recursion, clean two-phase logic | 🐌 Two-pass overhead |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
|---|---|---|
| ⚡ **Maximum performance, competitive programming** | 🥇 **Timestamp Traversal** | ★★★★★ |
| 📖 **Readability / learning** | 🥈 **3-Color DFS** | ★★★★☆ |
| 🔧 **Large input / recursion-safe** | 🥉 **Topological BFS** | ★★★★☆ |
| 🎯 **Interview setting** | 🏅 **Timestamp Traversal** | ★★★★★ |

</details>


## **☕ Code (Java)**

```java
class Solution {
    public int longestCycle(int V, int[][] edges) {
        int[] nxt = new int[V];
        Arrays.fill(nxt, -1);
        for (int[] e : edges) nxt[e[0]] = e[1];
        int[] vis = new int[V];
        Arrays.fill(vis, -1);
        int ans = -1, t = 1;
        for (int i = 0; i < V; i++) {
            if (vis[i] != -1) continue;
            int start = t, cur = i;
            while (cur != -1 && vis[cur] == -1) { vis[cur] = t++; cur = nxt[cur]; }
            if (cur != -1 && vis[cur] >= start) ans = Math.max(ans, t - vis[cur]);
        }
        return ans;
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def longestCycle(self, V, edges):
        nxt = [-1] * V
        for u, v in edges: nxt[u] = v
        vis = [-1] * V
        ans, t = -1, 0
        for i in range(V):
            if vis[i] != -1: continue
            start, cur = t, i
            while cur != -1 and vis[cur] == -1: vis[cur] = t; t += 1; cur = nxt[cur]
            if cur != -1 and vis[cur] >= start: ans = max(ans, t - vis[cur])
        return ans
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
