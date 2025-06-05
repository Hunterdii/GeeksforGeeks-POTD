---
title: "🛤️ Count the paths | GFG Solution 🚦"
keywords🏷️: ["🛤️ count paths", "🌳 DAG", "🔢 topological sort", "🧮 dynamic programming", "📈 graph traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Count Paths in DAG problem: count total distinct paths from source to destination in a directed acyclic graph using topological sorting and DP. 🚀"
date: 📅 2025-06-05
---

# *05. Count the paths*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-the-paths4332/1)

## **🧩 Problem Description**

Given a Directed Acyclic Graph (DAG) with `V` nodes labeled from `0` to `V-1`, and a list of directed edges `edges[i] = [u, v]` representing a directed edge from node `u` to node `v`, find the total number of distinct paths from a given source node `S` to a destination node `D`.


## **📘 Examples**

### Example 1

```
Input: edges = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, S = 2, D = 3
Output: 3
Explanation: There are 3 ways to reach 3 from 2:
2 -> 1 -> 3,
2 -> 0 -> 3,
2 -> 0 -> 1 -> 3.
```

<img src="https://github.com/user-attachments/assets/bd89acc7-c440-44f9-91a5-1f06110c4778" alt="Count the paths" width="30%">


### Example 2

```
Input: edges = [[0,1], [1,2], [1,3], [2,3]], V = 4, S = 0, D = 3
Output: 2
Explanation: There are 2 ways to reach 3 from 0:
0 -> 1 -> 2 -> 3,
0 -> 1 -> 3.
```

<img src="https://github.com/user-attachments/assets/19fd6173-f70b-48c3-b708-3de64de95f67" alt="Count the paths" width="30%">


## **🔒 Constraints**

* \$2 \le V \le 10^3\$
* \$1 \le E = \text{edges.size()} \le \frac{V \times (V - 1)}{2}\$


## **✅ My Approach**

### Topological Sort + Dynamic Programming (DP)

**Idea:**

Since the graph is a DAG (Directed Acyclic Graph), we can perform a **topological sort** to linearize the nodes in an order that respects dependencies (edges).

1. **Build the adjacency list** and an **in-degree array** (counts of incoming edges per node).
2. Use **Kahn’s algorithm** for **topological sorting**:

   * Initialize a queue with all nodes having zero in-degree.
   * Iteratively remove nodes from the queue, adding them to the topological order, and decrease in-degree of their neighbors.
3. Initialize a `dp` array where `dp[i]` = number of ways to reach the destination `D` from node `i`.

   * Set `dp[D] = 1` (base case).
4. Iterate nodes in reverse topological order:

   * For each node `u`, sum the paths of all its neighbors `v`: `dp[u] += dp[v]`.
5. The answer is `dp[S]` — the number of ways from source `S` to destination `D`.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V + E), since each node and edge is processed exactly once during topological sort and DP calculation.
* **Expected Auxiliary Space Complexity:** O(V + E), required for adjacency list, in-degree array, DP array, and queue.


## 🧑‍💻 **Code (C++)**

```cpp
class Solution {
  public:
    int countPaths(vector<vector<int>>& E, int V, int S, int D) {
        vector<vector<int>> G(V); vector<int> I(V);
        for (auto& e : E) G[e[0]].push_back(e[1]), I[e[1]]++;
        queue<int> Q; for (int i = 0; i < V; i++) if (!I[i]) Q.push(i);
        vector<int> T, dp(V); dp[D] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop(); T.push_back(u);
            for (int v : G[u]) if (--I[v] == 0) Q.push(v);
        }
        for (int i = V - 1; i >= 0; i--)
            for (int v : G[T[i]]) dp[T[i]] += dp[v];
        return dp[S];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ DFS + Memoization**

Use a depth‐first search from the source, caching (memoizing) the number of ways from each node to the destination.

### **Algorithm Steps:**

1. Build an adjacency list `graph` of size `V` from `edges`.
2. Maintain a `memo` array of size `V`, initialized to `-1`.
3. Write a recursive function `dfs(u)` that:

   * If `u == dest`, return `1`.
   * If `memo[u] != -1`, return `memo[u]`.
   * Otherwise, iterate over all neighbors `v` of `u`, sum up `dfs(v)`, store in `memo[u]`, and return it.
4. Call `dfs(src)` to get the total number of distinct paths.

```cpp
class Solution {
  public:
    int dfs(int node, int dest, vector<vector<int>>& graph, vector<int>& memo) {
        if (node == dest) return 1;
        if (memo[node] != -1) return memo[node];
        int paths = 0;
        for (int v : graph[node])
            paths += dfs(v, dest, graph, memo);
        return memo[node] = paths;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> graph(V);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);
        vector<int> memo(V, -1);
        return dfs(src, dest, graph, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time: ⏱️** O(V + E) — Each node and edge is processed once thanks to memoization.
* **Auxiliary Space: 💾** O(V + E) — For adjacency list and memo array, plus recursion stack space.


### ✅ **Why This Approach?**
* Avoids building an explicit topological order.
* Caches results of subproblems for efficiency.
  
### ⚠️ Caveat:

* May cause stack overflow on very deep graphs.



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                 | ⏱️ **Time Complexity** | 💾 **Space Complexity**    | ✅ **Pros**                                         | ⚠️ **Cons**                                 |
| -------------------- | ----------- | -------- | ---------------------------- | -------------------------------- |
| 🎯 Topo + DP         | 🟢 O(V + E)    | 🟢 O(V + E) | Fast, optimal, non-recursive | Slightly more setup (Kahn’s alg) |
| 🔄 DFS + Memoization | 🟢 O(V + E)    | 🟢 O(V + E) | Simple recursive logic       | Risk of stack overflow           |


### 🏆 **Best Choice by Scenario**

| 🎯 Scenario                                        | 🥇 Recommended Approach |
| -------------------------------------------------- | ----------------------- |
| 🌐 Moderate/large DAG, need guaranteed O(V+E)      | 🥇 Topo + DP (Kahn’s)   |
| 📚 Simpler code when graph size is small           | 🥈 DFS + Memoization    |


</details>



## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countPaths(int[][] E, int V, int S, int D) {
        List<List<Integer>> G = new ArrayList<>();
        int[] I = new int[V], dp = new int[V];
        for (int i = 0; i < V; i++) G.add(new ArrayList<>());
        for (int[] e : E) {
            G.get(e[0]).add(e[1]);
            I[e[1]]++;
        }
        Queue<Integer> Q = new ArrayDeque<>();
        for (int i = 0; i < V; i++) if (I[i] == 0) Q.add(i);
        List<Integer> T = new ArrayList<>();
        while (!Q.isEmpty()) {
            int u = Q.poll(); T.add(u);
            for (int v : G.get(u)) if (--I[v] == 0) Q.add(v);
        }
        dp[D] = 1;
        for (int i = V - 1; i >= 0; i--)
            for (int v : G.get(T.get(i))) dp[T.get(i)] += dp[v];
        return dp[S];
    }
}
```


## **🐍 Code (Python)**

```python
class Solution:
    def countPaths(self, E, V, S, D):
        from collections import defaultdict, deque
        G = defaultdict(list); I = [0] * V
        for u, v in E: G[u].append(v); I[v] += 1
        Q = deque(i for i in range(V) if I[i] == 0)
        T, dp = [], [0] * V; dp[D] = 1
        while Q:
            u = Q.popleft(); T.append(u)
            for v in G[u]:
                I[v] -= 1
                if I[v] == 0: Q.append(v)
        for u in reversed(T):
            for v in G[u]: dp[u] += dp[v]
        return dp[S]
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
