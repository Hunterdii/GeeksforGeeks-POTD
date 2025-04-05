## 29. Euler Circuit in an Undirected Graph

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1)

### Problem Description

Given the number of vertices `v` and an adjacency list `adj` denoting a directed graph, determine whether there exists an Eulerian circuit in the graph. An Eulerian circuit is a path in a graph that visits every edge exactly once and starts and ends at the same vertex.

**Example:**

Input:

```
v = 4
edges[] = {{0, 1},
           {0, 2},
           {1, 3},
           {2, 3}}
```

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/2028909c-f65e-4c45-92a8-13a2fdcb7a22" alt="Image" />
</p>

Output:

```
1
```

Explanation:
One of the Eulerian circuits starting from vertex 0 is as follows:
0 -> 1 -> 3 -> 2 -> 0

### My Approach

1. **Checking for Eulerian Circuit Existence:**

   - Iterate through each vertex in the graph.
   - Check if the degree of each vertex is even. If any vertex has an odd degree, return false indicating that there is no Eulerian circuit.

2. **Return Result:**
   - If all vertices have even degrees, return true indicating the existence of an Eulerian circuit.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(v + e), where `v` is the number of vertices and `e` is the number of edges in the graph.
- **Expected Auxiliary Space Complexity:** O(v), where `v` is the number of vertices, for storing the degree of each vertex.

### Code (C++)

```cpp
class Solution {
public:
    bool isEularCircuitExist(int v, vector<int> adj[]) {
        for (int i = 0; i < v; i++) {
            if (adj[i].size() % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
