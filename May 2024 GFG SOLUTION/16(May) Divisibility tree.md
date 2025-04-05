## 16. Divisibility Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/divisibility-tree1902/1)

### Problem Description

Given a tree with \(n\) nodes and edge connections between them, where the tree is rooted at node 1, the task is to remove the minimum number of edges from the given tree such that the tree converts into a disjoint union tree, with the nodes of each connected component left divisible by 2.

**Example 1:**

Input:

```
n = 10
edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
```

Output:

```
2
```

Explanation:
Take two integers at a time i.e. 2 is connected with 1, 3 is connected with 1,4 is
connected with 3, 5 is connected with 2 and so on. Fig will understand you better.
Original tree:

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/b89f771f-8932-4ae7-8d22-8037e1648fe5" alt="Image" width="270" />
</p>

After removing edge 1-3 and 1-6. So ans is 2 because all nodes are even.

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/5ddab435-7a79-4414-9e2c-381e682abc49" alt="Image" width="270" />
</p>

Explanation:
Removing the edge 2-1 converts the tree into a disjoint union tree, with the nodes of each connected component left divisible by 2.

### My Approach

1. **Depth-First Search (DFS):**

- Construct an adjacency list representation of the tree from the given edges.
- Implement a DFS traversal starting from node 1 to explore the tree.
- During DFS, count the number of nodes in each connected component.
- If the count of nodes in a connected component is odd, it means removing an edge from that component will make all nodes in that component divisible by 2.

2. **Edge Removal:**

- During DFS, whenever an odd count of nodes in a connected component is encountered, increment a counter for edge removal.
- Finally, return the count of edges to be removed.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we traverse through all the nodes of the tree once using DFS.
- **Expected Auxiliary Space Complexity:** O(n), as we use an adjacency list to represent the tree and maintain a boolean array to track visited nodes during DFS.

### Code (C++)

```cpp
class Solution {
public:
    int ans = 0;

    int dfs(int v, vector<bool>& vis, vector<vector<int>>& adj) {
        int cnt = 0;
        vis[v] = true;
        for (auto u : adj[v]) {
            if (!vis[u]) {
                int res = dfs(u, vis, adj);
                if (res % 2 == 0)
                    ans++;
                else
                    cnt += res;
            }
        }
        return cnt + 1;
    }

    int minimumEdgeRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for (auto i : edges) {
            adj[i[0] - 1].push_back(i[1] - 1);
            adj[i[1] - 1].push_back(i[0] - 1);
        }
        dfs(0, vis, adj);
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
