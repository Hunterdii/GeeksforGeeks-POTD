---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Graph
---

# 🚀 _Day 8. Bridge edge in a graph_ 🧠


The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/bridge-edge-in-graph)

## 💡 **Problem Description:**

Given an **undirected graph** with **V** vertices and **E** edges, along with a specific edge connecting vertices **c** and **d**, the task is to determine whether this edge is a **bridge**. An edge (c–d) is considered a bridge if removing it increases the number of connected components in the graph, meaning that vertices c and d were part of the same connected component before, but become disconnected after its removal.

> Note: Sorry for uploading late, my Final Sem exam is going on.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

<img src="https://github.com/user-attachments/assets/1630b101-9fdd-4c26-958e-986c0b274e33" width="40%">


- V = 5, E = 5
- Edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {2, 4}}
- c = 1, d = 2

#### **Output:**
- True

#### **Explanation:**
Removing the edge between nodes 1 and 2 disconnects the graph, indicating that it is a bridge.

### **Example 2:**

#### **Input:**

<img src="https://github.com/user-attachments/assets/09149db6-b08f-4974-9996-b4d0c6115979" width="40%">


- V = 5, E = 5
- Edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {2, 4}}
- c = 2, d = 4

#### **Output:**
- False

#### **Explanation:**
Removing the edge between nodes 2 and 4 does not affect the connectivity of the graph, indicating that it is not a bridge.

<img src="https://github.com/user-attachments/assets/c88756b4-e3ce-4fc1-b9c1-df4c8677abab" width="40%">


## **Constraints:**
- $1 \leq V, E \leq 10^5$
- $0 \leq c, d \leq V-1$

## 🎯 **My Approach:**

To determine if the edge (c, d) is a bridge, we can use the following approach:

1. **Graph Representation:** Represent the graph using an adjacency list for efficient traversal.

2. **Depth First Search (DFS):** Perform a DFS traversal to check the connectivity between nodes c and d after temporarily removing the edge (c, d).

3. **Connectivity Check:**
   - Temporarily remove the edge (c, d) from the graph.
   - Use DFS starting from node c to see if node d is still reachable.
   - If node d is not reachable from node c after removing the edge, then the edge (c, d) is a bridge.

### **Algorithm Steps:**

1. **Build the Adjacency List:** Construct the adjacency list from the given list of edges.

2. **Remove the Edge (c, d):** Temporarily remove the edge by not including it in the adjacency list.

3. **DFS Traversal:**
   - Initialize a visited array to keep track of visited nodes.
   - Start DFS traversal from node c.
   - Mark all reachable nodes from c as visited.

4. **Check Reachability of d:**
   - After the DFS traversal, check if node d has been visited.
   - If node d is not visited, it means removing the edge (c, d) disconnects node d from node c, indicating that the edge is a bridge.

5. **Restore the Edge (c, d):** After the check, restore the edge to its original state in the adjacency list.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(V + E), as we perform a DFS traversal which visits each vertex and edge once.
- **Expected Auxiliary Space Complexity:** O(V), due to the space required for the visited array and the recursion stack during DFS.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    void dfs(vector<vector<int>> &adj, int u, vector<bool> &vis) {
        vis[u] = true;
        for (int v : adj[u])
            if (!vis[v]) dfs(adj, v, vis);
    }

    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c))
                adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<bool> vis(V);
        dfs(adj, c, vis);
        return !vis[d];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **2️⃣ Tarjan’s Algorithm for Bridge Detection**

#### **Algorithm Steps:**

1. Convert edge list to adjacency list.
2. Perform DFS traversal and track discovery time `tin[u]` and lowest reachable time `low[u]`.
3. For every node, update the `low` value based on its descendants.
4. An edge `(u, v)` is a **bridge** if `low[v] > tin[u]`.

```cpp
class Solution {
    int timer;
    bool dfs(int u, int p, vector<int> adj[], vector<int> &tin, vector<int> &low, int c, int d) {
        tin[u] = low[u] = ++timer;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (!tin[v]) {
                if (dfs(v, u, adj, tin, low, c, d)) return true;
                low[u] = min(low[u], low[v]);
                if ((u == c && v == d || u == d && v == c) && low[v] > tin[u]) return true;
            } else low[u] = min(low[u], tin[v]);
        }
        return false;
    }
public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> adj[V], tin(V), low(V);
        for (auto &e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        timer = 0;
        for (int i = 0; i < V; i++)
            if (!tin[i] && dfs(i, -1, adj, tin, low, c, d))
                return true;
        return false;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)` (Adjacency list + recursion stack)

#### ✅ **Why This Approach?**

Efficient for detecting **all** bridges in a graph in one pass. The fastest method if this is done repeatedly or on large graphs.


## 📊 **3️⃣ Remove Edge + DFS Reachability Check (Iterative)**

#### **Algorithm Steps:**

1. Build an adjacency list excluding the edge `(c, d)`.
2. Perform an **iterative DFS** using a stack starting from node `c`.
3. If `d` is not reachable from `c`, then `(c, d)` is a bridge.

```cpp
class Solution {
public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c))
                adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<bool> vis(V, false);
        stack<int> st;
        st.push(c);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (int v : adj[u]) if (!vis[v]) st.push(v);
        }
        return !vis[d];
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)` (Adjacency list + visited + stack)

#### ✅ **Why This Approach?**

Simple to implement and avoids recursion limits; best when only one edge needs checking, not all bridges.


### 🆚 **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                      | ⚠️ **Cons**                           |
|-------------------------------------|-------------------------|--------------------------|--------------------------------------------------|----------------------------------------|
| **Tarjan’s Algorithm**              | 🟢 O(V + E)              | 🟡 O(V + E)               | Fastest for multiple bridge queries              | More complex; recursive                |
| **Remove Edge + DFS (Recursive)**   | 🟢 O(V + E)              | 🟢 O(V + E)               | Intuitive; easier to write                       | Recursion depth limits                 |
| **Remove Edge + DFS (Iterative)**   | 🟢 O(V + E)              | 🟡 O(V + E)               | Stack-based; avoids recursion                    | Slightly more verbose                  |

✅ **Best Choice?**

- **Use Tarjan’s** when multiple bridge checks or global bridge detection is needed.
- **Use DFS-based** methods for one-time or simpler cases.

</details>


## **Code (Java)**

```java
class Solution {
    void dfs(List<List<Integer>> g, boolean[] vis, int u) {
        vis[u] = true;
        for (int v : g.get(u)) if (!vis[v]) dfs(g, vis, v);
    }

    public boolean isBridge(int V, int[][] edges, int c, int d) {
        List<List<Integer>> g = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges)
            if (!(e[0] == c && e[1] == d || e[0] == d && e[1] == c)) {
                g.get(e[0]).add(e[1]);
                g.get(e[1]).add(e[0]);
            }
        boolean[] vis = new boolean[V];
        dfs(g, vis, c);
        return !vis[d];
    }
}
```


## **Code (Python)**

```python
class Solution:
    def dfs(self, g, vis, u):
        vis[u] = 1
        for v in g[u]:
            if not vis[v]: self.dfs(g, vis, v)

    def isBridge(self, V, edges, c, d):
        g = [[] for _ in range(V)]
        for u, v in edges:
            if (u, v) != (c, d) and (v, u) != (c, d):
                g[u].append(v)
                g[v].append(u)
        vis = [0] * V
        self.dfs(g, vis, c)
        return not vis[d]
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
