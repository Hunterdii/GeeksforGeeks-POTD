---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Graph
---

# 🚀 _Day 9. Articulation Point - II_ 🧠


## 💡 **Problem Description:**

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/graph-gfg-160/problem/articulation-point2616)

Given an undirected graph with **V** vertices and **E** edges, the graph is provided as a 2D array `edges[][]` where each element `edges[i] = [u, v]` indicates an undirected edge between vertices **u** and **v**. Your task is to return all the **articulation points** (or **cut vertices**) in the graph.

An articulation point is a vertex whose removal (along with all its connected edges) increases the number of connected components in the graph.

> **Note:** The graph may be disconnected, i.e., it may consist of more than one connected component.  
> If no such point exists, return `{-1}`.

> *Note: Sorry for the delayed upload; my Final Semester exams are underway. Best of luck with your coding journey!*


## 🔍 **Example Walkthrough:**

#### **Input:**  
```
V = 5  
edges = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]
```

<img src="https://github.com/user-attachments/assets/eac31efb-cc2a-4dc0-9589-b15b99856b5b" width="40%">

#### **Output:**  
```
[1, 4]
```

#### **Explanation:**  
Removing vertex **1** or **4** disconnects the graph. For instance, if vertex **1** is removed, the part of the graph connected to **1** becomes isolated from the rest of the components.

<img src="https://github.com/user-attachments/assets/ff5cb0aa-9555-4ba0-87fb-2e67a302e623" width="37%">

<img src="https://github.com/user-attachments/assets/4adc114a-b353-458a-9e41-8558632fe1c7" width="38%">


### **Example 2:**

#### **Input:**  
```
V = 4  
edges = [[0, 1], [0, 2]]
```

#### **Output:**  
```
[0]
```

#### **Explanation:**  
Removing vertex **0** will increase the number of disconnected components from 1 to 3.


## **Constraints**

- **1 ≤ V, E ≤ 10⁴**


## 🎯 **My Approach:**

### **Optimized DFS Using Tarjan’s Algorithm**

### **Algorithm Steps:**

1. **Convert the edge list to an adjacency list:**  
   Build an adjacency list from the given edges to represent the graph.

2. **Use Tarjan’s DFS-based algorithm:**  
   During the DFS traversal, maintain two arrays:  
   - **`disc[u]`:** The discovery time of vertex **u**.  
   - **`low[u]`:** The lowest discovery time reachable from **u** (including back-edges).

3. **Identify Articulation Points:**  
   - For a **non-root vertex** **u**, if there is a child **v** such that `low[v] >= disc[u]`, then **u** is an articulation point.  
   - For the **root vertex** of the DFS, if it has **more than one child**, then it is an articulation point.

4. **Handle Disconnected Graphs:**  
   Since the graph can be disconnected, run the DFS for every unvisited vertex.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(V + E), as every vertex and edge is visited only once in the DFS traversal.
- **Expected Auxiliary Space Complexity:** O(V + E), primarily for the recursion stack, the adjacency list, and the additional arrays used for tracking discovery times and low values.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<int> disc(V, -1), low(V), res;
        vector<bool> ap(V), vis(V);
        int time = 0;

        function<void(int, int)> dfs = [&](int u, int p) {
            vis[u] = true;
            disc[u] = low[u] = time++;
            int children = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                if (!vis[v]) {
                    dfs(v, u);
                    low[u] = min(low[u], low[v]);
                    if (p != -1 && low[v] >= disc[u]) ap[u] = true;
                    ++children;
                } else {
                    low[u] = min(low[u], disc[v]);
                }
            }
            if (p == -1 && children > 1) ap[u] = true;
        };

        for (int i = 0; i < V; ++i)
            if (!vis[i]) dfs(i, -1);
        for (int i = 0; i < V; ++i)
            if (ap[i]) res.push_back(i);
        return res.empty() ? vector<int>{-1} : res;
    }
};
```


<details>
  <summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Biconnected Components (Using Modified Tarjan’s Algorithm)**

This approach builds upon Tarjan’s algorithm by identifying biconnected components. The vertices that appear in more than one biconnected component are articulation points.

#### **Algorithm Steps:**

1. **Perform DFS** to compute discovery times (`disc[u]`) and low values (`low[u]`).
2. **Maintain a stack** of edges as part of the DFS to capture biconnected components.
3. For each vertex *u*, if a child *v* satisfies `low[v] >= disc[u]`, then *u* is an articulation point.
4. Optionally, you can **pop edges** from the stack to report each biconnected component.

## **C++ Code:**

```cpp
class Solution {
public:
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low,
             vector<bool>& visited, stack<int>& st, vector<bool>& ap, int& time) {
        visited[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                st.push(u); // Optionally use the stack to collect edges (for biconnected components)
                dfs(v, u, adj, disc, low, visited, st, ap, time);
                low[u] = min(low[u], low[v]);
                // Check articulation condition
                if ((parent != -1 && low[v] >= disc[u]) || (parent == -1 && children > 1))
                    ap[u] = true;
            } else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> visited(V, false), ap(V, false);
        stack<int> st; // optional: stores edges (u, v) for biconnected component analysis
        int time = 0;
        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfs(i, -1, adj, disc, low, visited, st, ap, time);
        
        vector<int> res;
        for (int i = 0; i < V; i++)
            if (ap[i])
                res.push_back(i);
        return res.empty() ? vector<int>{-1} : res;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** O(V + E)  
- **Space Complexity:** O(V + E) (includes the recursion stack and the edge stack)

#### ✅ **Why Use This Approach?**

- **Comprehensive Analysis:** It not only finds articulation points but also helps in identifying biconnected components.
- **Applications:** Particularly useful when the structure of biconnected components is needed, as in network reliability studies.


### 🆚 **Comparison of Approaches**

| **Approach**                                    | ⏱️ **Time Complexity**    | 🗂️ **Space Complexity**       | ✅ **Pros**                                                      | ⚠️ **Cons**                                 |
|-------------------------------------------------|---------------------------|-------------------------------|------------------------------------------------------------------|----------------------------------------------|
| **Tarjan’s Algorithm**          | 🟢 O(V + E)                  | 🟢 O(V + E)                      | Optimal, widely used, and efficient                              | Recursive (may hit limits for very deep graphs) |
| **Biconnected Components (Modified Tarjan’s)**  | 🟢 O(V + E)                  | 🟡 O(V + E)                      | Provides extra insight into the structure of the graph           | Slightly more complex to implement          |

✅ **Best Choice?**  
- For efficient and optimal detection of articulation points, **Tarjan’s algorithm** is the best choice.  
- The **biconnected components approach** is useful when additional component structure is required.

</details>



## **Code (Java)**
```java
class Solution {
    static ArrayList<Integer> articulationPoints(int V, int[][] edges) {
        ArrayList<Integer>[] adj = new ArrayList[V];
        for (int i = 0; i < V; i++) adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        int[] disc = new int[V], low = new int[V];
        boolean[] vis = new boolean[V], ap = new boolean[V];
        int[] time = {0};
        for (int i = 0; i < V; i++)
            if (!vis[i]) dfs(i, -1, adj, disc, low, vis, ap, time);
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++)
            if (ap[i]) res.add(i);
        if (res.isEmpty()) res.add(-1);
        return res;
    }

    static void dfs(int u, int p, ArrayList<Integer>[] adj, int[] disc, int[] low, boolean[] vis, boolean[] ap, int[] time) {
        vis[u] = true;
        disc[u] = low[u] = ++time[0];
        int children = 0;
        for (int v : adj[u]) {
            if (!vis[v]) {
                children++;
                dfs(v, u, adj, disc, low, vis, ap, time);
                low[u] = Math.min(low[u], low[v]);
                if (p != -1 && low[v] >= disc[u]) ap[u] = true;
            } else if (v != p)
                low[u] = Math.min(low[u], disc[v]);
        }
        if (p == -1 && children > 1) ap[u] = true;
    }
}
```

## **Code (Python)**
```python
class Solution:
    def articulationPoints(self, V, edges):
        adj = [[] for _ in range(V)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        disc = [-1] * V
        low = [-1] * V
        vis = [False] * V
        ap = [False] * V
        time = [0]

        def dfs(u, p):
            vis[u] = True
            disc[u] = low[u] = time[0] = time[0] + 1
            children = 0
            for v in adj[u]:
                if not vis[v]:
                    children += 1
                    dfs(v, u)
                    low[u] = min(low[u], low[v])
                    if p != -1 and low[v] >= disc[u]:
                        ap[u] = True
                elif v != p:
                    low[u] = min(low[u], disc[v])
            if p == -1 and children > 1:
                ap[u] = True

        for i in range(V):
            if not vis[i]:
                dfs(i, -1)
        res = [i for i, val in enumerate(ap) if val]
        return res if res else [-1]
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



