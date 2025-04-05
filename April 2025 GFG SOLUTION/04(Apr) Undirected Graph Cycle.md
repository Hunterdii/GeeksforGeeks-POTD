# _4. Undirected Graph Cycle_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

## **Problem Description**

Given an **undirected graph** with `V` vertices and `E` edges, represented as a 2D vector `edges[][]`, where each entry `edges[i] = [u, v]` denotes an edge between vertices `u` and `v`, determine whether the graph contains a **cycle** or not.

> Note: Sorry for uploading late, my exam is going on.

## **Examples**

### **Example 1:**

#### **Input:**

```
V = 4, E = 4
edges = [[0, 1], [0, 2], [1, 2], [2, 3]]
```

<img src="https://github.com/user-attachments/assets/53d6a47c-3dc5-4e1a-9488-c074cdce0199" width="20%">

#### **Output:**

```
True
```

#### **Explanation:**

There exists a cycle: **1 → 2 → 0 → 1**

### **Example 2:**

#### **Input:**

```
V = 4, E = 3
edges = [[0, 1], [1, 2], [2, 3]]
```

<img src="https://github.com/user-attachments/assets/d2fb5707-47cb-45e2-b9fe-06f0ff5602de" width="20%">

#### **Output:**

```
False
```

#### **Explanation:**

No cycle exists in the given graph.

### **Constraints:**

- $1 \leq V \leq 10^5$
- $1 \leq E = \text{edges.size()} \leq 10^5$

## **My Approach:**

## **Optimized Approach: Union-Find with Path Compression**

### **Algorithm Steps:**

1. **Initialize a parent array** where each node is its own parent (`-1`).
2. **Find function with path compression** to efficiently determine the representative parent of each node.
3. **Union function with union by size** to merge sets efficiently.
4. **Iterate over all edges** and apply union-find:
   - If both nodes of an edge belong to the same set, a **cycle is detected**.
   - Otherwise, perform a **union operation** to merge them.
5. **Return true if a cycle is found, otherwise return false**.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(E * α(V))`, where `α(V)` is the inverse Ackermann function, which grows extremely slowly and is nearly constant.
- **Expected Auxiliary Space Complexity:** `O(V)`, as we store only the parent array.

## **Code (C++)**

```cpp
class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> p(V, -1);
        function<int(int)> f = [&](int x){ return p[x] < 0 ? x : p[x] = f(p[x]); };
        for(auto &e : edges){
            int a = f(e[0]), b = f(e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## 📊 **1️⃣ DFS Based Cycle Detection Approach**

#### **Algorithm Steps:**

1. Build an adjacency list from the edge list.
2. Use a DFS traversal to detect a cycle by marking visited nodes and ensuring that a visited neighbor (other than the parent) is detected.

```cpp
class Solution {
public:
    bool dfs(int u, int parent, vector<vector<int>>& g, vector<bool>& vis) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v] ? dfs(v, u, g, vis) : v != parent)
                return true;
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i] && dfs(i, -1, g, vis))
                return true;
        return false;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)`

#### ✅ **Why This Approach?**

This DFS approach is intuitive for many graph problems. It clearly separates the concept of a visited node and its parent, making it straightforward to detect back edges that indicate cycles.

## 📊 **2️⃣ Union-Find (Iterative Path Compression) Approach**

#### **Algorithm Steps:**

1. Initialize a parent array with `-1` for all vertices.
2. For each edge, find the roots iteratively.
3. Merge the sets if roots are different; if not, a cycle exists.

```cpp
class Solution {
public:
    int find(vector<int>& p, int x) {
        while(p[x] >= 0)
            x = p[x];
        return x;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> p(V, -1);
        for(auto &e : edges){
            int a = find(p, e[0]), b = find(p, e[1]);
            if(a == b) return true;
            if(p[a] > p[b]) swap(a, b);
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(E * α(V))` (α is the inverse Ackermann function)
- **Space Complexity:** `O(V)`

#### ✅ **Why This Approach?**

The Union-Find structure with iterative path compression is highly efficient for cycle detection when the graph is provided as an edge list.

### 🆚 **Comparison of Approaches**

| **Approach**                                   | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                  | ⚠️ **Cons**                                       |
| ---------------------------------------------- | ---------------------- | ----------------------- | -------------------------------------------- | ------------------------------------------------- |
| **Union-Find (Recursive Path Compression)**    | 🟢 O(E \* α(V))        | 🟡 O(V)                 | Efficient for edge-list input, compact code. | Recursion depth may be an issue for large graphs. |
| **DFS-Based Cycle Detection (Adjacency List)** | 🟢 O(V + E)            | 🟡 O(V)                 | Simple, intuitive cycle detection method.    | Requires adjacency list construction.             |
| **Union-Find (Iterative Path Compression)**    | 🟢 O(E \* α(V))        | 🟡 O(V)                 | Avoids recursion, better readability.        | Slightly more verbose than recursive version.     |

✅ **Best Choice?**

- **Union-Find (Recursive Path Compression)** is the most efficient when edges are given as an edge list.
- **Union-Find (Iterative Path Compression)** is preferred when recursion is not suitable.
- **DFS-Based Cycle Detection** is best when the graph is naturally stored as an adjacency list.

</details>

## **Code (Java)**

```java
class Solution {
    public boolean isCycle(int V, int[][] edges) {
        int[] p = new int[V];
        Arrays.fill(p, -1);
        for (int[] e : edges) {
            int a = f(p, e[0]), b = f(p, e[1]);
            if (a == b) return true;
            if (p[a] > p[b]) { int t = a; a = b; b = t; }
            p[a] += p[b]; p[b] = a;
        }
        return false;
    }
    int f(int[] p, int x) {
        return p[x] < 0 ? x : (p[x] = f(p, p[x]));
    }
}
```

## **Code (Python)**

```python
class Solution:
    def isCycle(self, V, edges):
        p = [-1]*V
        def f(x): return x if p[x]<0 else f(p[x])
        for u,v in edges:
            a, b = f(u), f(v)
            if a == b: return True
            if p[a] > p[b]: a,b = b,a
            p[a] += p[b]; p[b] = a
        return False
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
