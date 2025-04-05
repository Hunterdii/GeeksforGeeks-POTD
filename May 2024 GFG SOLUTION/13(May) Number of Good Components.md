## 13. Number of Good Components

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1)

### Problem Description

Given an undirected graph with \(v\) vertices (numbered from 1 to \(v\)) and \(e\) edges, find the number of good components in the graph. A component of the graph is good if and only if the component is fully connected.

**Example:**

Input:

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/7b9e1b90-3a0b-4dbf-a343-54dbdf59bdd3" alt="Image" width="350" />
</p>

```
e = 3
v = 3
edges = {{1, 2}, {1, 3}, {3, 2}}
```

Output:

```
1
```

Explanation:
There is only one component in the graph, and in this component, there is an edge between any two vertices.

### My Approach

1. **Initialization:**

   - Initialize a variable `ans` to store the number of good components, initially set to 0.
   - Create a vector `visited` to mark visited vertices, initialized with 0.
   - Create an adjacency list `adj` to represent the graph.

2. **Building Graph:**

   - Populate the adjacency list `adj` using the provided edges.

3. **DFS Traversal:**

   - Perform Depth-First Search (DFS) traversal starting from each unvisited vertex.
   - While traversing, count the number of vertices and edges in the connected component.
   - Check if the number of edges in the component is equal to \(\frac{{\text{vertices} \times (\text{vertices} - 1)}}{2}\), indicating a fully connected component.
   - If yes, increment `ans` by 1.

4. **Return:**
   - Return `ans`, the total number of good components.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(v + e), as we visit each vertex and edge once during DFS traversal.
- **Expected Auxiliary Space Complexity:** O(depth of the graph), as we use a stack for DFS traversal and additional space proportional to the depth of the graph.

### Code (C++)

```cpp
class Solution {
public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        int ans = 0;
        vector<int> visited(v + 1, 0);

        vector<vector<int>> adj(v + 1);
        for (int i = 0; i < e; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 1; i <= v; i++) {
            if (visited[i] == 0) {
                int vertices = 0;
                int edgesCount = 0;

                stack<int> stk;
                stk.push(i);
                visited[i] = 1;

                while (!stk.empty()) {
                    int node = stk.top();
                    stk.pop();
                    vertices++;
                    edgesCount += adj[node].size();

                    for (int neighbor : adj[node]) {
                        if (visited[neighbor] == 0) {
                            stk.push(neighbor);
                            visited[neighbor] = 1;
                        }
                    }
                }

                edgesCount /= 2;
                if (edgesCount == (vertices * (vertices - 1)) / 2) {
                    ans++;
                }
            }
        }
        return ans;
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
