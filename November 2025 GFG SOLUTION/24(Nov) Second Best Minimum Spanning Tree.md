---
title: "🔢 Second Best Minimum Spanning Tree | GFG Solution 🔍"
keywords🏷️: ["🔢 second MST", "🌲 spanning tree", "🔍 Kruskal's algorithm", "📊 union-find", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Second Best Minimum Spanning Tree problem: find the second minimum weight spanning tree using MST edge removal technique with Kruskal's algorithm and union-find. 🚀"
date: 📅 2025-11-24
---

# *24. Second Best Minimum Spanning Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/second-best-minimum-spanning-tree/1)

## **🧩 Problem Description**

You are given an undirected graph with `V` vertices numbered from `0` to `V-1` and `E` edges. Each edge is represented as `[u, v, w]`, where `u` and `v` are connected vertices with weight `w`. Your task is to find the weight of the **second best minimum spanning tree** of the given graph.

A second best MST is defined as a minimum-weight spanning tree whose total weight is **strictly greater** than the weight of the minimum spanning tree (MST). If no such second best MST exists, return `-1`.

## **📘 Examples**

### Example 1

```cpp
Input: V = 5, E = 7, edges[][] = [[0, 1, 4], [0, 2, 3], [1, 2, 1], [1, 3, 5], [2, 4, 10], [2, 3, 7], [3, 4, 2]]
Output: 12
Explanation: The MST has weight 11 (edges with weights 1, 3, 2, 5). By removing one MST edge and 
adding another, we can form a spanning tree with weight 12, which is the second best MST.
```

### Example 2

```cpp
Input: V = 5, E = 4, edges[][] = [[0, 1, 2], [1, 2, 3], [2, 3, 4], [3, 4, 5]]
Output: -1
Explanation: This graph forms a linear tree structure. There's only one unique spanning tree 
possible, so no second best MST exists.
```

## **🔒 Constraints**

* $1 \le V \le 100$
* $V-1 \le E \le V \times (V-1)/2$
* $0 \le \text{edges}[i][2] \le 10^3$

## **✅ My Approach**

The optimal solution uses **Kruskal's Algorithm** with **Union-Find (Disjoint Set Union)** to systematically find the second best MST:

### **MST Edge Removal with Kruskal's Algorithm**

1. **Sort Edges by Weight:**
   * Sort all edges in ascending order of their weights for greedy MST construction.

2. **Build the First MST:**
   * Use Union-Find with path compression and union by rank.
   * Apply Kruskal's algorithm to construct the MST.
   * Store all edges that form the MST and calculate its total weight.

3. **Find Second Best MST:**
   * For each edge in the original MST:
     * Temporarily exclude that edge from consideration.
     * Rebuild a spanning tree using remaining edges with Kruskal's algorithm.
     * Check if the new tree is valid (has exactly V-1 edges).
     * If valid and weight is strictly greater than original MST, update the minimum among these candidates.

4. **Union-Find Operations:**
   * **Find with Path Compression:** Recursively finds the root and compresses the path.
   * **Union by Rank:** Merges two sets by attaching the smaller rank tree under the larger rank tree.

5. **Return Result:**
   * Return the minimum weight found that is greater than the original MST.
   * If no such tree exists, return -1.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(V × E log E), where we sort edges once in O(E log E), build the initial MST in O(E log V), and then for each of the V-1 MST edges, we rebuild the spanning tree in O(E log V). Since V-1 < E in most cases, the dominant term is O(V × E log E).
* **Expected Auxiliary Space Complexity:** O(V + E), where O(V) is used for the Union-Find data structure (parent and rank arrays) and O(E) for storing the MST edges. The space for sorting is typically O(log E) for the recursion stack.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int secondMST(int V, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
        vector<int> p(V), r(V);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) { return p[x] == x ? x : p[x] = find(p[x]); };
        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return false;
            if (r[a] < r[b]) swap(a, b);
            p[b] = a;
            if (r[a] == r[b]) r[a]++;
            return true;
        };
        int mst = 0, ans = INT_MAX;
        vector<array<int, 3>> tree;
        for (auto& e : edges) {
            if (unite(e[0], e[1])) {
                mst += e[2];
                tree.push_back({e[0], e[1], e[2]});
            }
        }
        for (auto& [u, v, w] : tree) {
            fill(p.begin(), p.end(), 0);
            iota(p.begin(), p.end(), 0);
            fill(r.begin(), r.end(), 0);
            int cost = 0, cnt = 0;
            for (auto& e : edges) {
                if ((e[0] == u && e[1] == v) || (e[0] == v && e[1] == u)) continue;
                if (unite(e[0], e[1])) {
                    cost += e[2];
                    if (++cnt == V - 1) break;
                }
            }
            if (cnt == V - 1 && cost > mst) ans = min(ans, cost);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```


## **☕ Code (Java)**

```java
class Solution {
    public int secondMST(int V, int[][] edges) {
        Arrays.sort(edges, (a, b) -> a[2] - b[2]);
        int[] p = new int[V], r = new int[V];
        for (int i = 0; i < V; i++) p[i] = i;
        int mst = 0, ans = Integer.MAX_VALUE;
        List<int[]> tree = new ArrayList<>();
        for (int[] e : edges) {
            int a = find(p, e[0]), b = find(p, e[1]);
            if (a != b) {
                if (r[a] < r[b]) { int t = a; a = b; b = t; }
                p[b] = a;
                if (r[a] == r[b]) r[a]++;
                mst += e[2];
                tree.add(e);
            }
        }
        for (int[] skip : tree) {
            for (int i = 0; i < V; i++) { p[i] = i; r[i] = 0; }
            int cost = 0, cnt = 0;
            for (int[] e : edges) {
                if ((e[0] == skip[0] && e[1] == skip[1]) || (e[0] == skip[1] && e[1] == skip[0])) continue;
                int a = find(p, e[0]), b = find(p, e[1]);
                if (a != b) {
                    if (r[a] < r[b]) { int t = a; a = b; b = t; }
                    p[b] = a;
                    if (r[a] == r[b]) r[a]++;
                    cost += e[2];
                    if (++cnt == V - 1) break;
                }
            }
            if (cnt == V - 1 && cost > mst) ans = Math.min(ans, cost);
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
    int find(int[] p, int x) { return p[x] == x ? x : (p[x] = find(p, p[x])); }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def secondMST(self, V, edges):
        edges.sort(key=lambda x: x[2])
        p = list(range(V))
        r = [0] * V
        def find(x):
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        def unite(a, b):
            a, b = find(a), find(b)
            if a == b: return False
            if r[a] < r[b]: a, b = b, a
            p[b] = a
            if r[a] == r[b]: r[a] += 1
            return True
        mst, tree = 0, []
        for u, v, w in edges:
            if unite(u, v):
                mst += w
                tree.append((u, v, w))
        ans = float('inf')
        for su, sv, sw in tree:
            p = list(range(V))
            r = [0] * V
            cost = cnt = 0
            for u, v, w in edges:
                if (u == su and v == sv) or (u == sv and v == su): continue
                if unite(u, v):
                    cost += w
                    cnt += 1
                    if cnt == V - 1: break
            if cnt == V - 1 and cost > mst: ans = min(ans, cost)
        return -1 if ans == float('inf') else ans
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>

