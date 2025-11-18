---
title: "🛣️ Number of Ways to Arrive at Destination | GFG Solution 🚀"
keywords🏷️: ["🛣️ shortest path", "🔍 Dijkstra", "📍 graph algorithms", "📈 path counting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Number of Ways to Arrive at Destination: count all shortest paths from source to destination using Dijkstra's algorithm with path counting. 🚀"
date: 📅 2025-11-18
---

# *18. Number of Ways to Arrive at Destination*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1)

## **🧩 Problem Description**

You are given an undirected weighted graph with **V vertices** numbered from **0 to V-1** and **E edges**, represented as a 2D array `edges[][]`, where `edges[i] = [ui, vi, timei]` means that there is an undirected edge between nodes `ui` and `vi` that takes `timei` minutes to reach.

Your task is to return **in how many ways** you can travel from node **0** to node **V - 1** in the **shortest amount of time**.

## **📘 Examples**

### Example 1

```cpp
Input: V = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [0, 3, 5], [1, 3, 3], [2, 3, 4]]
Output: 2
Explanation: The shortest path from 0 to 3 is 5.
Two ways to reach 3 in 5 minutes are:
0 -> 3
0 -> 1 -> 3
```

### Example 2

```cpp
Input: V = 6, edges[][] = [[0, 2, 3], [0, 4, 2], [0, 5, 7], [2, 3, 1], [2, 5, 5], [5, 3, 3], [5, 1, 4], [1, 4, 1], [4, 5, 5]]
Output: 4
Explanation: The shortest path from 0 to 5 is 7.
Four ways to reach 5 in 7 minutes are:
0 -> 5
0 -> 4 -> 5
0 -> 4 -> 1 -> 5
0 -> 2 -> 3 -> 5
```

## **🔒 Constraints**

* $1 \le V \le 200$
* $V - 1 \le \text{edges.size()} \le V \times (V - 1) / 2$
* $0 \le u_i, v_i \le V - 1$
* $1 \le \text{time}_i \le 10^5$
* $u_i \ne v_i$

## **✅ My Approach**

The optimal solution uses **Dijkstra's Algorithm** combined with **path counting** to efficiently compute both shortest distances and the number of ways to reach each node:

### **Dijkstra's Algorithm with Path Counting**

1. **Initialize Data Structures:**
   * Create adjacency list to represent the graph with edge weights.
   * Maintain `dist[]` array initialized to infinity (except source = 0).
   * Maintain `ways[]` array to count paths (source has 1 way).
   * Use min-heap priority queue sorted by distance.

2. **Process Nodes in Distance Order:**
   * Extract node with minimum distance from priority queue.
   * Skip if current distance is outdated (already processed with shorter path).

3. **Relax Adjacent Edges:**
   * For each neighbor, calculate new distance through current node.
   * If new distance is shorter: update distance, copy path count, add to queue.
   * If new distance equals current shortest: add current node's paths to neighbor's count.

4. **Apply Modulo:**
   * Since path counts can be large, apply modulo $10^9 + 7$ to prevent overflow.

5. **Return Result:**
   * Return the count of shortest paths to destination node (V-1).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O((V + E) log V), as we process each vertex once and each edge may be relaxed multiple times. The priority queue operations (insertion and extraction) take O(log V) time, and we perform these operations for all edges in the worst case.
* **Expected Auxiliary Space Complexity:** O(V + E), where O(V) is used for the distance and ways arrays, and O(E) is used for storing the adjacency list representation of the graph. The priority queue also uses O(V) space in the worst case.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(V, LLONG_MAX), ways(V, 0);
        dist[0] = 0;
        ways[0] = 1;
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;
        pq.push({0, 0});
        const int MOD = 1e9 + 7;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if (d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[V - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BFS-Based Level Processing**

### 💡 Algorithm Steps:

1. Use BFS to process nodes level by level based on distance.
2. Maintain a queue sorted by distance using map structure.
3. Update paths when finding equal or shorter distances.
4. Process all nodes at same distance level together.

```cpp
class Solution {
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        vector<long long> dist(V, LLONG_MAX);
        vector<long long> paths(V, 0);
        map<long long, vector<int>> levels;
        dist[0] = 0;
        paths[0] = 1;
        levels[0].push_back(0);
        const int MOD = 1e9 + 7;
        while (!levels.empty()) {
            auto it = levels.begin();
            long long d = it->first;
            vector<int> nodes = it->second;
            levels.erase(it);
            for (int u : nodes) {
                if (d > dist[u]) continue;
                for (auto [v, w] : adj[u]) {
                    long long nd = d + w;
                    if (nd < dist[v]) {
                        dist[v] = nd;
                        paths[v] = paths[u];
                        levels[nd].push_back(v);
                    }
                    else if (nd == dist[v]) {
                        paths[v] = (paths[v] + paths[u]) % MOD;
                    }
                }
            }
        }
        return paths[V - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(E log V) - Map operations for level processing
* **Auxiliary Space:** 💾 O(V + E) - Level map and adjacency list

### ✅ **Why This Approach?**

* Level-by-level distance processing
* Natural BFS structure for path problems
* Useful when distance-based grouping is needed

## 📊 **3️⃣ DFS with Memoization**

### 💡 Algorithm Steps:

1. Recursively explore all paths from source to destination.
2. Memoize computed distances and path counts for each node.
3. Combine results from all valid paths with minimum distance.
4. Return accumulated count for destination with shortest distance.

```cpp
class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<long long> dist, ways;
    const int MOD = 1e9+7;
    void dfs(int u, long long d) {
        if (d > dist[u]) return;
        if (d < dist[u]) {
            dist[u] = d;
            ways[u] = 1;
        } else {
            ways[u]++;
        }
        for (auto [v, w] : adj[u]) {
            dfs(v, d + w);
        }
    }
public:
    int countPaths(int V, vector<vector<int>>& edges) {
        adj.assign(V, {});
        dist.assign(V, LLONG_MAX);
        ways.assign(V, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        dfs(0, 0);
        return ways[V - 1] % MOD;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V + E) - Visit each node and edge once with memoization
* **Auxiliary Space:** 💾 O(V) - Recursion stack and memoization arrays

### ✅ **Why This Approach?**

* Recursive solution pattern
* Natural for tree-like structures
* Intuitive path exploration logic

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1120 test cases due to time constraints).



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach** | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros** | ⚠️ **Cons** |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Dijkstra Priority Queue** | 🟢 O((V+E) log V) | 🟢 O(V+E) | 🚀 Optimal for sparse graphs | 🔧 Requires priority queue |
| 📊 **BFS Levels** | 🟡 O(E log V) | 🟡 O(V + E) | 🎯 Natural level processing | 💾 Map overhead |
| 🔄 **DFS Memoization** | 🟢 O(V+E) | 🟡 O(V) | ⭐ Recursive pattern | 🔧 Stack overflow risk |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario** | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Sparse graphs optimal** | 🥇 **Dijkstra Priority Queue** | ★★★★★ |
| 🔧 **Distance grouping needed** | 🥈 **BFS Levels** | ★★★★☆ |
| 🎯 **Recursive preference** | 🏅 **DFS Memoization** | ★★★★☆ |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countPaths(int V, int[][] edges) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(new int[]{e[1], e[2]});
            adj.get(e[1]).add(new int[]{e[0], e[2]});
        }
        long[] dist = new long[V], ways = new long[V];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;
        PriorityQueue<long[]> pq =
            new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));
        pq.offer(new long[]{0, 0});
        int MOD = 1_000_000_007;
        while (!pq.isEmpty()) {
            long[] top = pq.poll();
            long d = top[0];
            int u = (int) top[1];
            if (d > dist[u]) continue;
            for (int[] nxt : adj.get(u)) {
                int v = nxt[0], w = nxt[1];
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.offer(new long[]{dist[v], v});
                }
                else if (d + w == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return (int) ways[V - 1];
    }
}
```

## **🐍 Code (Python)**

```python
from heapq import heappush, heappop
class Solution:
    def countPaths(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        dist = [float('inf')] * V
        ways = [0] * V
        dist[0] = 0
        ways[0] = 1
        pq = [(0, 0)]
        MOD = 10**9 + 7
        while pq:
            d, u = heappop(pq)
            if d > dist[u]:
                continue
            for v, w in adj[u]:
                if d + w < dist[v]:
                    dist[v] = d + w
                    ways[v] = ways[u]
                    heappush(pq, (dist[v], v))
                elif d + w == dist[v]:
                    ways[v] = (ways[v] + ways[u]) % MOD
                    
        return ways[V - 1]
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




































