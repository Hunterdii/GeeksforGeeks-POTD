# *6. Topological Sort*  

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/topological-sort/1)  

## **Problem Description**  

Given a **Directed Acyclic Graph (DAG)** with V vertices (numbered from 0 to V-1) and E directed edges (represented as a 2D list where each edge is given as `[u, v]` indicating an edge from u to v), return a topological ordering of the vertices.  

A **topological sort** of a DAG is a linear ordering of vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.  
Note: Since there can be multiple valid topological orders, you may return any one of them. The returned ordering is considered correct if for every directed edge u -> v, u comes before v.

## **Examples**

### **Example 1:**  

#### **Input:**  
```
V = 4, E = 3  
edges = [[3, 0], [1, 0], [2, 0]]
```

<img src="https://github.com/user-attachments/assets/2a57649a-027b-4ce4-8d29-f5f16724ba29" width="40%">


#### **Output:**  
```
true
```

#### **Explanation:**  
The output `true` denotes that the ordering is valid.  
Few valid topological orders are:  
- [3, 2, 1, 0]  
- [1, 2, 3, 0]  
- [2, 3, 1, 0]  



### **Example 2:**  

#### **Input:**  
```
V = 6, E = 6  
edges = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
```

<img src="https://github.com/user-attachments/assets/d6e5ea9c-4ffb-4ec5-8ce1-9cdd5b0d6efc" width="40%">


#### **Output:**  
```
true
```

#### **Explanation:**  
The output `true` denotes that the returned ordering is valid.  
Few valid topological orders for this graph are:  
- [4, 5, 0, 1, 2, 3]  
- [5, 2, 4, 0, 1, 3]  



### **Constraints:**  
- 2 ≤ V ≤ 10³  
- 1 ≤ E (edges.size()) ≤ (V * (V - 1)) / 2  



## **My Approach**  

### **Kahn’s Algorithm (BFS-based Topological Sort)**

### **Algorithm Steps:**

1. **Construct the Graph:**  
   - Build an **adjacency list** from the edge list.
   - Create an **in-degree array** to store the number of incoming edges for each vertex.

2. **Initialize the Queue:**  
   - Push all vertices with in-degree 0 into a queue.

3. **Process the Queue:**  
   - While the queue is not empty, pop a vertex and add it to the result list.
   - For each neighbor of the popped vertex, reduce its in-degree by 1.
   - If any neighbor's in-degree becomes 0, add it to the queue.

4. **Final Check:**  
   - If the result list contains all vertices, the ordering is valid.

## **Time and Auxiliary Space Complexity**  

- **Expected Time Complexity:** `O(V + E)`, as every vertex and edge is processed exactly once.
- **Expected Auxiliary Space Complexity:** `O(V + E)`, due to the storage required for the adjacency list, in-degree array, and queue.

## **Code (C++)**

```cpp
// ✅ Kahn’s Algorithm (BFS-based Topological Sort)
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> in(V, 0), res;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            in[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
            if (!in[i])
                q.push(i);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v : adj[u])
                if (--in[v] == 0)
                    q.push(v);
        }
        return res;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ DFS-Based Topological Sort (Recursive)**

#### **Algorithm Steps:**

1. Convert the list of edges into an adjacency list.
2. Use a `visited` array to avoid re-visiting nodes.
3. For each unvisited node, run a DFS traversal.
4. Once all neighbors are processed, add the node to the result stack.
5. Reverse the result for topological order.

```cpp
class Solution {
    void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
        vis[u] = true;
        for (int v : g[u])
            if (!vis[v]) dfs(v, g, vis, st);
        st.push(u);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) g[e[0]].push_back(e[1]);
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++)
            if (!vis[i]) dfs(i, g, vis, st);
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)` (Adjacency list + recursion stack)

#### ✅ **Why This Approach?**

It’s the classic and intuitive way to compute topological sort using depth-first traversal. Very concise and clean for problems without large recursion depth.

## 📊 **3️⃣ DFS (Iterative using Stack)**

#### **Algorithm Steps:**

1. Convert the edge list to an adjacency list.
2. Instead of recursion, use an explicit stack to perform DFS.
3. Keep track of the index of each node’s current child to process.
4. Add nodes to the result only when all their children are done.
5. Reverse the result stack for final order.

```cpp
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> g(V);
        for (auto &e : edges) g[e[0]].push_back(e[1]);

        vector<bool> vis(V, false), inStack(V, false);
        vector<int> res;
        stack<pair<int, int>> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                st.push({i, 0});
                while (!st.empty()) {
                    int u = st.top().first;
                    int &idx = st.top().second;
                    if (!vis[u]) {
                        vis[u] = true;
                        inStack[u] = true;
                    }
                    bool done = true;
                    while (idx < g[u].size()) {
                        int v = g[u][idx++];
                        if (!vis[v]) {
                            st.push({v, 0});
                            done = false;
                            break;
                        }
                    }
                    if (done) {
                        res.push_back(u);
                        inStack[u] = false;
                        st.pop();
                    }
                }
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

#### 📝 **Complexity Analysis:**

- **Time Complexity:** `O(V + E)`
- **Space Complexity:** `O(V + E)`

#### ✅ **Why This Approach?**

It simulates recursion using an explicit stack, which helps avoid recursion limits in large graphs and makes it suitable for iterative-only environments.

### 🆚 **Comparison of Approaches**

| **Approach**                     | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                              | ⚠️ **Cons**                              |
|------------------------------------|-------------------------|--------------------------|----------------------------------------------|-----------------------------------------------|
| **Kahn’s Algorithm (BFS)**         | 🟢 O(V + E)                | 🟡 O(V + E)                 | Iterative, detects cycles, queue-based       | Less intuitive for some, more verbose         |
| **DFS (Recursive)**                | 🟢 O(V + E)                | 🟡 O(V + E)                 | Simple and elegant, classic topological sort | Stack overflow risk on large/deep graphs      |
| **DFS (Iterative using Stack)**    | 🟢 O(V + E)                | 🟡 O(V + E)                 | Avoids recursion limit                       | Slightly complex and harder to follow         |


✅ **Best Choice?**

- Use **DFS (Recursive)** for simpler problems and shorter DAGs.
- Use **Kahn’s Algorithm** when cycle detection or iterative logic is required.
- Use **Iterative DFS** to avoid stack overflow in recursion-heavy cases.

</details>


## **Code (Java)**

```java
class Solution {
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> g = new ArrayList<>();
        int[] in = new int[V];
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) g.add(new ArrayList<>());
        for (int[] e : edges) {
            g.get(e[0]).add(e[1]);
            in[e[1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) if (in[i] == 0) q.add(i);
        while (!q.isEmpty()) {
            int u = q.poll();
            res.add(u);
            for (int v : g.get(u)) if (--in[v] == 0) q.add(v);
        }
        return res;
    }
}
```

## **Code (Python)**

```python
from collections import deque

class Solution:
    def topoSort(self, V, edges):
        g = [[] for _ in range(V)]
        in_deg = [0] * V
        res = []
        for u, v in edges:
            g[u].append(v)
            in_deg[v] += 1
        q = deque(i for i in range(V) if in_deg[i] == 0)
        while q:
            u = q.popleft()
            res.append(u)
            for v in g[u]:
                in_deg[v] -= 1
                if in_deg[v] == 0:
                    q.append(v)
        return res
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
