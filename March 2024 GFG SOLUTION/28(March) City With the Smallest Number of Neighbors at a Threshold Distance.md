## 28. City with the Smallest Number of Neighbors at a Threshold Distance

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1)

### Problem Description

Given a number of cities labeled from 0 to \(n-1\) with \(m\) edges connecting them, represented by the array `edges` where `edges[i] = [fromi, toi, weighti]`, indicating a bidirectional edge with weight \(weighti\) between cities \(fromi\) and \(toi\). Additionally, given an integer `distanceThreshold`, find a city with the smallest number of cities that are reachable through some path and whose distance is at most `distanceThreshold`. If there are multiple such cities, return the city with the greatest label.

**Example:**

Input:

```
n = 4, m = 4
edges = [[0, 1, 3],
         [1, 2, 1],
         [1, 3, 4],
         [2, 3, 1]]
distanceThreshold = 4
```

Output:

```
3
```

<p align="center">
  <img src="https://github.com/Hunterdii/GeeksforGeeks-POTD/assets/124852522/bc928ea9-6440-4069-bd74-ff36dc17ad61" alt="Image" width="300" />
</p>

Explanation:
The neighboring cities at a `distanceThreshold` of 4 for each city are:

- City 0 -> [City 1, City 2]
- City 1 -> [City 0, City 2, City 3]
- City 2 -> [City 0, City 1, City 3]
- City 3 -> [City 1, City 2]

Cities 0 and 3 have 2 neighboring cities at a `distanceThreshold` of 4, but we have to return city 3 since it has the greatest number.

**Your Task:**

You don't need to read input or print anything. Your task is to complete the function `findCity()` which takes the number of nodes `n`, the total number of edges `m`, a vector of edges `edges`, and `distanceThreshold` as input, and returns the city with the smallest number of cities that are reachable through some path and whose distance is at most `distanceThreshold`. If there are multiple such cities, return the city with the greatest label.

### My Approach

1. **Data Preparation:**

   - Construct the adjacency list representation of the graph using the given `edges`.

2. **Shortest Path Calculation:**

   - Use Floyd Warshall algorithm to find the shortest distances between all pairs of cities.

3. **City Selection:**
   - For each city, count the number of neighboring cities within the `distanceThreshold`.
   - Return the city with the smallest number of such neighboring cities. If there are multiple such cities, return the city with the greatest label.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n^3 + \text{length(edges)} \times n \log n)\), considering the time complexity of Floyd Warshall algorithm and the construction of the graph.
- **Expected Auxiliary Space Complexity:** \(O(n^2)\), for storing the distance matrix in Floyd Warshall algorithm.

### Code (C++)

```cpp
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        vector<vector<int>> dist(n, vector<int>(n, numeric_limits<int>::max()));

        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
            for (auto& p : adj[i]) {
                int v = p.first, w = p.second;
                dist[i][v] = w;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != numeric_limits<int>::max() &&
                        dist[k][j] != numeric_limits<int>::max()) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minCity = n, ans = -1;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= minCity) {
                minCity = count;
                ans = i;
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
