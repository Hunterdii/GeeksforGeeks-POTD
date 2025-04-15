# *15. Bellman-Ford*

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1)

## **Problem Description**

Given a **weighted graph** with `V` vertices (numbered from `0` to `V-1`) and a list of `E` edges, where each edge is represented as a triplet `[u, v, w]` denoting a **directed edge from `u` to `v`** with weight `w`.

Also given a source vertex `src`.  
Your task is to compute the **shortest distance from the source to all other vertices** using the **Bellman-Ford algorithm**.

- If a vertex is unreachable from the source, mark its distance as **1e8**.
- If the graph contains a **negative weight cycle**, return `[-1]`.

> 📝 **Note:** Sorry for uploading late, my Final Sem exam is going on.

## **Examples**

### **Example 1:**

#### **Input:**

```text
V = 5
edges = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]]
src = 0
```

<img src="https://github.com/user-attachments/assets/459e6b36-f56c-4168-a4de-d57077575fbf" width="30%">


#### **Output:**

```text
[0, 5, 6, 6, 7]
```

#### **Explanation:**

- 0 → 1: 5  
- 0 → 1 → 2: 6  
- 0 → 1 → 2 → 4 → 3: 6  
- 0 → 1 → 2 → 4: 7



### **Example 2:**

#### **Input:**

```text
V = 4
edges = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]]
src = 0
```

<img src="https://github.com/user-attachments/assets/b0b07197-440a-4611-b5ab-3160dc791247" width="30%">

#### **Output:**

```text
[-1]
```

#### **Explanation:**

- The cycle: 1 → 2 → 3 → 1 has a negative weight → **Negative Cycle Detected**


## **Constraints**

- $\( 1 \leq V \leq 100 \)$
- $\( 1 \leq E = \text{edges.size()} \leq V \times (V-1) \)$
- $\( -1000 \leq w \leq 1000 \)$
- $\( 0 \leq \text{src} < V \)$



## **My Approach**

### Standard Bellman-Ford Algorithm

The Bellman-Ford algorithm is designed to find the shortest paths from a **single source** node to all other nodes, even when **negative edge weights** exist.

### **Algorithm Steps:**

1. Initialize a distance array `dist[]` of size `V` with all elements as `1e8`, and set `dist[src] = 0`.
2. Relax all edges `V - 1` times.
3. Check for negative weight cycles by attempting one more relaxation:
   - If any edge still updates, it means a negative cycle exists → return `[-1]`.



## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** $\( O(V \times E) \)$, as we perform edge relaxation `V-1` times over all `E` edges.

- **Expected Auxiliary Space Complexity:** $\( O(V) \)$, to store the distance array of size `V`.


## Code (C++)

```cpp
// ✅ Standard Bellman-Ford Algorithm
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; ++i)
            for (auto& e : edges)
                if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        for (auto& e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return {-1};
        return dist;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>


## 📊 **2️⃣ Bellman-Ford with Early Termination Optimization**

#### **Algorithm Steps:**

1. Initialize a distance array with a large value (here, `1e8`) and set the source distance to 0.
2. For each of the `V - 1` iterations, update the distances of the vertices.  
   - If no update is made in an iteration, break out early to optimize runtime.
3. Check once more for any possible relaxation to detect negative cycles.
4. Return `{-1}` if a negative cycle is detected, else return the distance array.

```cpp
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V - 1; ++i) {
            bool updated = false;
            for (auto& e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    updated = true;
                }
            }
            if (!updated) break;  // Optimization
        }

        for (auto& e : edges)
            if (dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return {-1};

        return dist;
    }
};
```

### 📝 **Complexity Analysis**

- **Time Complexity:** `O(V * E)` in worst-case, better with early break.
- **Space Complexity:** `O(V)`

### ✅ **Why This?**

This can significantly reduce computation when the graph stabilizes early. A practical tweak that saves time in sparse or nearly optimal graphs.


### 🆚 Comparison of Approaches

| **Approach**                                 | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                                  | ⚠️ **Cons**                            |
|---------------------------------------------|-------------------------|--------------------------|----------------------------------------------|-----------------------------------------|
| **Standard Bellman-Ford**                   | 🟢 O(V × E)                | 🟢 O(V)                     | Simple, classic, handles all cases            | May do redundant passes                 |
| **Optimized with Early Termination**        | 🟡 Best: O(E), Worst: O(V × E) | 🟢 O(V)              | Faster on converging graphs, fewer passes    | Still worst-case `O(V × E)`             |

- Use **Bellman-Ford** when negative weights or cycles are possible.

- Use **Early Termination** for performance optimization.


</details>


## Code (Java)

```java
class Solution {
    public int[] bellmanFord(int V, int[][] edges, int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, (int)1e8);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++)
            for (int[] e : edges)
                if (dist[e[0]] < 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        for (int[] e : edges)
            if (dist[e[0]] < 1e8 && dist[e[0]] + e[2] < dist[e[1]])
                return new int[]{-1};
        return dist;
    }
}
```


## Code (Python)

```python
class Solution:
    def bellmanFord(self, V, edges, src):
        dist = [int(1e8)] * V
        dist[src] = 0
        for _ in range(V - 1):
            for u, v, w in edges:
                if dist[u] < 1e8 and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
        for u, v, w in edges:
            if dist[u] < 1e8 and dist[u] + w < dist[v]:
                return [-1]
        return dist
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
