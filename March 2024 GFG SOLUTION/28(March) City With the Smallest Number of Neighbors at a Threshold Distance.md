## 28. City with the Smallest Number of Neighbors at a Threshold Distance

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1)

### Problem Description

Given an integer `n`, return the Fibonacci series up to the `n`th term. Since the terms can become very large, return the terms modulo \(10^9 + 7\).

**Example:**

Input:
```
n = 5
```
Output:
```
0 1 1 2 3 5
```
Explanation:
0 1 1 2 3 5 is the Fibonacci series up to the 5th term.

### My Approach 

1. **Initialization:**
   - Create a vector `ans` to store the Fibonacci series up to the \(n\)th term.
   - Initialize the first two terms of the series, `ans[0]` and `ans[1]`, as 0 and 1 respectively.
   
2. **Fibonacci Calculation:**
   - Iterate from `i = 2` to \(n\).
   - Calculate the \(i\)th term of the Fibonacci series as the sum of the previous two terms: \(ans[i] = (ans[i - 1] + ans[i - 2]) \% MOD\), where `MOD` is \(10^9 + 7\).
   
3. **Return:**
   - Return the vector `ans` containing the Fibonacci series up to the \(n\)th term.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** \(O(n^3)\), as we perform a nested loop for constructing the distance matrix, and the Floyd Warshall algorithm itself has a time complexity of \(O(n^3)\).
- **Expected Auxiliary Space Complexity:** \(O(n^2)\), as we store the distance matrix, which has dimensions \(n \times n\).

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

For discussions, questions, or doubts related to this solution, please visit my LinkedIn:- [Any Questions](https://www.linkedin.com/in/het-patel-8b110525a/). 
Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐
