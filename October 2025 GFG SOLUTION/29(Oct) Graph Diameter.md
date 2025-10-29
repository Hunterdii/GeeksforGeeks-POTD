---
title: "🌳 Graph Diameter | GFG Solution 🔍"
keywords🏷️: ["🌳 graph diameter", "🔍 BFS", "📍 tree diameter", "📈 two BFS", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Graph Diameter problem: find the longest path in an undirected tree using two BFS traversals. 🚀"
date: 📅 2025-10-29
---

# *29. Graph Diameter*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/diameter-of-a-graph/1)

## **🧩 Problem Description**

You are given an undirected connected graph with `V` vertices numbered from `0` to `V-1` and `E` edges, represented as a 2D array `edges[][]`, where each element `edges[i] = [u, v]` represents an undirected edge between vertex `u` and vertex `v`.

Find the **diameter** of the graph. The diameter of a graph (sometimes called the width) is the **number of edges** on the longest path between two vertices in the graph.

**Note:** Graph does not contain any cycle (it's a tree).

## **📘 Examples**

### Example 1

```cpp
Input: V = 6, E = 5, edges[][] = [[0, 1], [0, 4], [1, 3], [1, 2], [2, 5]]
Output: 4
Explanation: The longest path in the graph is from vertices 4 to vertices 5 (4 -> 0 -> 1 -> 2 -> 5).
```

### Example 2

```cpp
Input: V = 7, E = 6, edges[][] = [[0, 2], [0, 4], [0, 3], [3, 1], [3, 5], [1, 6]]
Output: 4
Explanation: The longest path in the graph is from vertices 2 to vertices 6 (2 -> 0 -> 3 -> 1 -> 6).
```

## **🔒 Constraints**

* $2 \le V \le 10^5$
* $1 \le E \le V - 1$
* $0 \le \text{edges}[i][0], \text{edges}[i][1] < V$

## **✅ My Approach**

The optimal approach uses the **Two BFS Technique** to find the diameter of a tree:

### **Two BFS Traversal**

1. **Build Adjacency List:**
   * Convert the edge list into an adjacency list representation for efficient traversal.
   * Since the graph is undirected, add edges in both directions.

2. **First BFS - Find One End of Diameter:**
   * Start BFS from any arbitrary node (e.g., node 0).
   * Track distances from the starting node to all other nodes.
   * The farthest node from the starting point will be one end of the diameter.

3. **Second BFS - Find Diameter:**
   * Start another BFS from the farthest node found in step 2.
   * Track distances again and find the maximum distance reached.
   * This maximum distance is the diameter of the tree.

4. **Why This Works:**
   * In a tree, the farthest node from any starting point must be one endpoint of the longest path.
   * A second BFS from this endpoint will traverse the entire longest path.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V + E), as we perform two BFS traversals where each BFS visits every vertex and edge once. Since E = V - 1 for a tree, this simplifies to O(V).
* **Expected Auxiliary Space Complexity:** O(V), for storing the adjacency list, distance array, and BFS queue. Each data structure requires space proportional to the number of vertices.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto bfs = [&](int src) {
            vector<int> d(V, -1);
            queue<int> q;
            q.push(src);
            d[src] = 0;
            int far = src, maxD = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                        if (d[v] > maxD) {
                            maxD = d[v];
                            far = v;
                        }
                    }
                }
            }
            return make_pair(far, maxD);
        };
        auto [end1, _] = bfs(0);
        auto [end2, diam] = bfs(end1);
        return diam;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Single DFS with Global Maximum**

### 💡 Algorithm Steps:

1. Perform DFS from any arbitrary node to compute depths.
2. Track maximum diameter while exploring using postorder traversal.
3. For each node calculate max two depths from children.
4. Update global maximum with sum of top two depths.

```cpp
class Solution {
public:
    int res = 0;
    int dfs(int u, int p, vector<vector<int>>& adj) {
        int m1 = 0, m2 = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int d = dfs(v, u, adj) + 1;
                if (d > m1) m2 = m1, m1 = d;
                else if (d > m2) m2 = d;
            }
        }
        res = max(res, m1 + m2);
        return m1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V) - Single DFS traversal
* **Auxiliary Space:** 💾 O(V) - Recursion stack space

### ✅ **Why This Approach?**

* Single pass solution instead of two BFS/DFS
* More efficient for dense graphs
* Natural recursive structure

## 📊 **3️⃣ Level Order BFS Approach**

### 💡 Algorithm Steps:

1. Build adjacency list from edges.
2. Use BFS from node 0 to find farthest node.
3. Use BFS again from farthest node to find diameter.
4. Return maximum distance in second BFS.

```cpp
class Solution {
public:
    pair<int, int> bfs(int s, vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> d(n, -1);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        int node = s, dist = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (d[v] < 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                    if (d[v] > dist) dist = d[v], node = v;
                }
            }
        }
        return {node, dist};
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return bfs(bfs(0, adj).first, adj).second;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V) - Two BFS traversals
* **Auxiliary Space:** 💾 O(V) - Queue and distance array

### ✅ **Why This Approach?**

* Clear two-phase algorithm
* Iterative solution avoids stack overflow
* Standard BFS pattern for tree diameter

## 📊 **4️⃣ DFS with Height Tracking**

### 💡 Algorithm Steps:

1. Recursively compute height of each subtree.
2. At each node track two maximum heights from children.
3. Diameter through current node is sum of two max heights.
4. Update global diameter and return max height to parent.

```cpp
class Solution {
public:
    int maxDiam = 0;
    int height(int u, int p, vector<vector<int>>& adj) {
        int h1 = 0, h2 = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int h = height(v, u, adj);
                if (h > h1) h2 = h1, h1 = h;
                else if (h > h2) h2 = h;
            }
        }
        maxDiam = max(maxDiam, h1 + h2);
        return h1 + 1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        height(0, -1, adj);
        return maxDiam;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(V) - Single DFS pass
* **Auxiliary Space:** 💾 O(V) - Call stack depth

### ✅ **Why This Approach?**

* Elegant single-pass solution
* Natural tree recursion pattern
* Optimal time and space

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔄 **Two BFS**                    | 🟢 O(V)                | 🟢 O(V)                 | 🎯 Easy to understand             | 🔄 Two passes required               |
| 🌳 **Single DFS Global**          | 🟢 O(V)                | 🟢 O(V)                 | 🚀 Single pass                    | 🧠 Slightly complex logic            |
| 📊 **Level Order BFS**            | 🟢 O(V)                | 🟢 O(V)                 | 📖 Iterative approach             | 🔄 Two BFS calls                     |
| 🎯 **DFS Height**                 | 🟢 O(V)                | 🟢 O(V)                 | ⭐ Elegant recursion              | 🔧 Needs global variable             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Single DFS Global**             | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Two BFS**                       | ★★★★☆                     |
| 🔧 **Avoid recursion**                                | 🥉 **Level Order BFS**               | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **DFS Height**                    | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int diameter(int V, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }
        int[] first = bfs(0, adj);
        int[] second = bfs(first[0], adj);
        return second[1];
    }
    private int[] bfs(int src, List<List<Integer>> adj) {
        int n = adj.size();
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        dist[src] = 0;
        int far = src, maxD = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj.get(u)) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.add(v);
                    if (dist[v] > maxD) {
                        maxD = dist[v];
                        far = v;
                    }
                }
            }
        }
        return new int[]{far, maxD};
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def diameter(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        def bfs(src):
            dist = [-1] * V
            q = deque([src])
            dist[src] = 0
            far, maxD = src, 0
            while q:
                u = q.popleft()
                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
                        if dist[v] > maxD:
                            maxD = dist[v]
                            far = v
            return far, maxD
        end1, _ = bfs(0)
        _, diam = bfs(end1)
        return diam
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














