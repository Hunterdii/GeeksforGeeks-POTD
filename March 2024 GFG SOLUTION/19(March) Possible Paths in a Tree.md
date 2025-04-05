## 19. Possible Paths in a Tree

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/possible-paths--141628/1)

### Problem Description

Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

**Note:** Path from A to B and B to A are considered to be the same.

**Example 1:**

Input:

```
n = 7
edges {start, end, weight} = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
q = 3
queries[] = {1, 3, 5}
```

Output:

```
1 3 4
```

Explanation:

- Query 1: Path from 2 to 3
- Query 2: Path from 1 to 2, 1 to 3, and 2 to 3
- Query 3: Path from 1 to 2, 1 to 3, 2 to 3, and 5 to 7

### My Approach

1. We'll initialize a `parent` array, a `sz` array, and a `res` vector to store the results.
2. Initialize `ans` to 0.
3. Populate `parent` and `sz` arrays.
4. Sort the edges based on weight.
5. Iterate over each edge and perform Union-Find operations, updating `ans` accordingly.
6. Store the results of queries based on the maximum weight found in paths.
7. Return the result vector.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(nlogn + qlogn), where n is the number of nodes and q is the number of queries. Sorting the edges and performing Union-Find operations both contribute to this complexity.
- **Expected Auxiliary Space Complexity:** O(n), for storing the `parent` and `sz` arrays.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> maximumWeight(int n, vector<vector<int>>& edges, int q, vector<int>& queries) {
        vector<int> parent(n + 1), sz(n + 1), res;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        vector<pair<int, pair<int, int>>> wt;
        for (auto& edge : edges)
            wt.push_back({edge[2], {edge[0], edge[1]}});

        sort(wt.begin(), wt.end());

        map<int, int> mp;
        for (auto& edge : wt) {
            int a = edge.first;
            int b = edge.second.first;
            int c = edge.second.second;
            mp[a] = Union(b, c, parent, sz, ans);
        }

        for (int i = 0; i < q; i++) {
            auto val = mp.upper_bound(queries[i]);
            if (val == mp.begin())
                res.push_back(0);
            else {
                val--;
                res.push_back(val->second);
            }
        }
        return res;
    }

private:
    int root(int i, vector<int>& parent) {
        while (parent[i] != i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }

    int Union(int a, int b, vector<int>& parent, vector<int>& sz, int& ans) {
        int ra = root(a, parent);
        int rb = root(b, parent);
        if (ra == rb)
            return sz[ra] * sz[ra];
        if (sz[ra] < sz[rb]) {
            swap(ra, rb);
            swap(a, b);
        }
        ans += sz[ra] * sz[rb];
        parent[rb] = ra;
        sz[ra] += sz[rb];
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
