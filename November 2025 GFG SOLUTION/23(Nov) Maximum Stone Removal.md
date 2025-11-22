---
title: "🪨 Maximum Stone Removal | GFG Solution 🔍"
keywords🏷️: ["🪨 stone removal", "🔗 union find", "🌳 graph connectivity", "📊 DSU", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Maximum Stone Removal problem: find maximum number of removable stones sharing rows or columns using Union-Find and graph connectivity techniques. 🚀"
date: 📅 2025-11-23
---

# *23. Maximum Stone Removal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1)

## **🧩 Problem Description**

You are given a 2D array `stones[][]` of non-negative integers where `stones[i] = [xi, yi]` represents the location of the ith stone on a 2D plane. Your task is to return the **maximum possible number of stones** that you can remove.

A stone can be removed if it shares either the **same row** or the **same column** as another stone that has not been removed. The goal is to maximize the number of stones removed while following this constraint.

**Note:** Each coordinate point may have at most one stone.

## **📘 Examples**

### Example 1

```cpp
Input: stones[][] = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
Output: 5
Explanation: One way to remove 5 stones:
1. Remove [2, 2] (shares row with [2, 1])
2. Remove [2, 1] (shares column with [0, 1])
3. Remove [1, 2] (shares row with [1, 0])
4. Remove [1, 0] (shares column with [0, 0])
5. Remove [0, 1] (shares row with [0, 0])
Stone [0, 0] remains as it cannot be removed.
```

### Example 2

```cpp
Input: stones[][] = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
Output: 3
Explanation: One way to remove 3 stones:
1. Remove [2, 2] (shares row with [2, 0])
2. Remove [2, 0] (shares column with [0, 0])
3. Remove [0, 2] (shares row with [0, 0])
Stones [0, 0] and [1, 1] remain.
```

## **🔒 Constraints**

* $1 \le \text{stones.size()} \le 1000$
* $0 \le x_i, y_i \le 10^4$
* No two stones are at the same position

## **✅ My Approach**

The optimal approach uses **Union-Find (Disjoint Set Union)** to group stones into connected components based on shared rows or columns:

### **Union-Find (DSU) Strategy**

1. **Component Identification:**
   * Stones sharing the same row or column belong to the same connected component.
   * Within each component, all stones except one can be removed.

2. **Coordinate Mapping:**
   * Map each row index to a unique identifier.
   * Map each column index to a different unique identifier (offset by 10001 to avoid collision).
   * Union row and column identifiers for each stone.

3. **Path Compression:**
   * Implement find operation with path compression for O(α(n)) amortized time.
   * Union operation merges components by connecting their root parents.

4. **Count Components:**
   * After processing all stones, count distinct connected components.
   * Maximum removable stones = Total stones - Number of components.

5. **Key Insight:**
   * Each connected component must keep at least one stone.
   * All other stones in that component can be removed.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × α(n)), where n is the number of stones and α(n) is the inverse Ackermann function, which is nearly constant for all practical values. Each union and find operation takes O(α(n)) time with path compression.
* **Expected Auxiliary Space Complexity:** O(n), as we use a parent array of size 20002 to handle coordinate mapping and a hash set to store unique component roots.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
    int find(int x, vector<int>& p) {
        return p[x] < 0 ? x : p[x] = find(p[x], p);
    }
    void unite(int x, int y, vector<int>& p) {
        x = find(x, p); y = find(y, p);
        if (x != y) p[x] = y;
    }
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> p(20002, -1);
        for (auto& s : stones) unite(s[0], s[1] + 10001, p);
        unordered_set<int> roots;
        for (auto& s : stones) roots.insert(find(s[0], p));
        return n - roots.size();
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ DFS with Direct Stone Comparison**

### 💡 Algorithm Steps:

1. For each unvisited stone, initiate a depth-first search traversal.
2. Mark current stone as visited and explore all other stones.
3. If another stone shares the same row or column, recursively visit it.
4. Count the number of connected components formed by DFS traversals.
5. Return total stones minus the number of components found.

```cpp
class Solution {
    void dfs(int i, vector<bool>& vis, vector<vector<int>>& stones) {
        vis[i] = true;
        for (int j = 0; j < stones.size(); j++) {
            if (!vis[j] && (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])) {
                dfs(j, vis, stones);
            }
        }
    }
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, stones);
                comp++;
            }
        }
        return n - comp;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Each stone compared with every other stone
* **Auxiliary Space:** 💾 O(n) - Visited array and recursion stack

### ✅ **Why This Approach?**

* Simple and intuitive graph traversal logic
* No additional data structure overhead beyond visited array
* Easy to understand connectivity concept

## 📊 **3️⃣ BFS with Coordinate Indexing**

### 💡 Algorithm Steps:

1. Create hash maps to store stone indices for each row and column.
2. For each unvisited stone, perform breadth-first search using a queue.
3. Explore all stones sharing the current stone's row or column coordinates.
4. Mark visited stones and add newly discovered stones to the queue.
5. Count components and calculate maximum removable stones.

```cpp
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> rows, cols;
        for (int i = 0; i < n; i++) {
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        vector<bool> vis(n);
        int comp = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int j : rows[stones[curr][0]])
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                for (int j : cols[stones[curr][1]])
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
            }
            comp++;
        }
        return n - comp;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × k) - k is average stones per coordinate
* **Auxiliary Space:** 💾 O(n) - Maps, queue, and visited array

### ✅ **Why This Approach?**

* Level-order traversal of connected components
* Efficient coordinate-based stone lookup
* Avoids redundant pairwise comparisons

## 📊 **4️⃣ Union-Find with Map-Based Components**

### 💡 Algorithm Steps:

1. Use hash maps to track component IDs for each row and column.
2. Assign incremental component IDs as new coordinates are encountered.
3. When a stone's row and column belong to different components, merge them.
4. Iterate through all map entries to update merged component IDs.
5. Count unique final component IDs and return removable stone count.

```cpp
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, int> row, col;
        int comp = 0;
        for (auto& s : stones) {
            if (!row.count(s[0])) row[s[0]] = comp++;
            if (!col.count(~s[1])) col[~s[1]] = comp++;
            int r = row[s[0]], c = col[~s[1]];
            if (r != c) {
                for (auto& p : row) if (p.second == c) p.second = r;
                for (auto& p : col) if (p.second == c) p.second = r;
            }
        }
        unordered_set<int> unique;
        for (auto& p : row) unique.insert(p.second);
        for (auto& p : col) unique.insert(p.second);
        return n - unique.size();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - m is number of unique coordinates
* **Auxiliary Space:** 💾 O(m) - Maps for coordinate tracking

### ✅ **Why This Approach?**

* Hash map flexibility for sparse coordinates
* Direct component ID manipulation
* No auxiliary parent array needed

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔗 **Union-Find DSU**             | 🟢 O(n × α(n))         | 🟢 O(n)                 | ⭐ Optimal with path compression  | 🎯 Requires DSU understanding        |
| 🌳 **DFS Direct**                 | 🟡 O(n²)               | 🟢 O(n)                 | 📖 Simple, intuitive logic        | 🐌 Quadratic time for large inputs   |
| 🔄 **BFS Indexing**               | 🟢 O(n × k)            | 🟢 O(n)                 | 🎯 Efficient coordinate lookup    | 💾 Multiple data structures          |
| 🗺️ **Map-Based Union**           | 🟡 O(n × m)            | 🟢 O(m)                 | 🚀 Flexible for sparse data       | 🔧 Complex merging logic             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Union-Find DSU**                | ★★★★★                     |
| 📖 **Learning graph concepts**                        | 🥈 **DFS Direct**                    | ★★★★☆                     |
| 🔧 **Large coordinate ranges**                        | 🥉 **BFS Indexing**                  | ★★★★☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Union-Find DSU**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int maxRemove(int[][] stones) {
        int n = stones.length;
        int[] p = new int[20002];
        Arrays.fill(p, -1);
        for (int[] s : stones) union(s[0], s[1] + 10001, p);
        Set<Integer> roots = new HashSet<>();
        for (int[] s : stones) roots.add(find(s[0], p));
        return n - roots.size();
    }
    int find(int x, int[] p) {
        return p[x] < 0 ? x : (p[x] = find(p[x], p));
    }
    void union(int x, int y, int[] p) {
        x = find(x, p); y = find(y, p);
        if (x != y) p[x] = y;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxRemove(self, stones):
        p = {}
        def find(x):
            if x not in p: p[x] = x
            if p[x] != x: p[x] = find(p[x])
            return p[x]
        def union(x, y):
            p[find(x)] = find(y)
        for r, c in stones:
            union(r, ~c)
        return len(stones) - len({find(r) for r, c in stones})
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




