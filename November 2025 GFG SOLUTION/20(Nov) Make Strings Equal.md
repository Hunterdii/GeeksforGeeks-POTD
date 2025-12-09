---
title: "🔄 Make Strings Equal | GFG Solution 🔍"
keywords🏷️: ["🔄 string transformation", "🔍 shortest path", "📈 Floyd-Warshall", "🎯 graph algorithms", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Make Strings Equal problem: find minimum cost to transform two strings to be identical using Floyd-Warshall algorithm for shortest path computation. 🚀"
date: 📅 2025-11-20
---

# *20. Make Strings Equal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/make-strings-equal--150209/1)

## **🧩 Problem Description**

You are given two strings `s` and `t` consisting of lowercase English letters. You are also given a 2D array `transform[][]` of size `n*2`, where each entry `[x, y]` means you can transform character `x` into character `y`, and an array `cost[]`, where `cost[i]` is the cost of transforming `transform[i][0]` into `transform[i][1]`.

Your task is to find the **minimum total cost** required to make the strings identical by transforming characters. You can apply any transformation any number of times on either string. If it is impossible to make the two strings identical, return `-1`.

## **📘 Examples**

### Example 1

```cpp
Input: s = "abcc", t = "bccc", transform[][] = [['a', 'b'], ['b', 'c'], ['c', 'a']], cost[] = [2, 1, 4]
Output: 3
Explanation: We can convert both strings into "bccc" with a cost of 3:
- Position 0 in s: a -> b (cost 2)
- Position 1 in s: b -> c (cost 1)
Other characters already match.
```

### Example 2

```cpp
Input: s = "az", t = "dc", transform[][] = [['a', 'b'], ['b', 'c'], ['c', 'd'], ['a', 'd'], ['z', 'c']], cost[] = [5, 3, 2, 50, 10]
Output: 20
Explanation: We can convert both strings into "dc" with a cost of 20:
- Position 0 in s: a -> d by path a->b->c->d (cost 5+3+2=10)
- Position 1 in s: z -> c (cost 10)
```

### Example 3

```cpp
Input: s = "xyz", t = "xzy", transform[][] = [['x', 'y'], ['x', 'z']], cost[] = [3, 3]
Output: -1
Explanation: It is not possible to make the two strings equal.
```

## **🔒 Constraints**

* $1 \le s.size() = t.size() \le 10^5$
* $1 \le transform.size() = cost.size() \le 500$
* $'a' \le transform[i][0], transform[i][1] \le 'z'$
* $1 \le cost[i] \le 500$

## **✅ My Approach**

The optimal approach uses **Floyd-Warshall Algorithm** to precompute shortest transformation paths between all pairs of characters:

### **Floyd-Warshall with Graph Transformation**

1. **Build Distance Matrix:**
   * Create a 26x26 matrix representing all lowercase English letters.
   * Initialize diagonal elements to 0 (no cost to transform character to itself).
   * Initialize all other distances to infinity.

2. **Fill Direct Transformation Costs:**
   * For each transformation rule, update the distance matrix with minimum cost.
   * Handle multiple transformations between same character pairs by taking minimum.

3. **Apply Floyd-Warshall:**
   * For each intermediate character k, update all pairs (i, j).
   * If path i->k->j is cheaper than direct i->j, update the distance.
   * This computes shortest transformation paths between all character pairs.

4. **Find Common Target Characters:**
   * For each mismatched position in strings, try all 26 possible common characters.
   * Calculate cost to transform both s[i] and t[i] to each common character.
   * Choose the minimum cost transformation.

5. **Return Result:**
   * Sum all transformation costs for mismatched positions.
   * Return -1 if any position cannot be resolved.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(26³ + n), where 26³ accounts for Floyd-Warshall preprocessing on the fixed 26-character alphabet, and n is the length of strings for comparing and computing transformations at each position. The preprocessing is a constant operation, making the overall complexity effectively O(n) for the string comparison phase.
* **Expected Auxiliary Space Complexity:** O(26²) = O(1), as we use a fixed 26x26 distance matrix regardless of input size. This is constant space since the alphabet size is fixed.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        const int INF = 1e9;
        vector<vector<int>> d(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) d[i][i] = 0;
        for (int i = 0; i < transform.size(); i++) 
            d[transform[i][0] - 'a'][transform[i][1] - 'a'] = min(d[transform[i][0] - 'a'][transform[i][1] - 'a'], cost[i]);
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;
            int mn = INF, a = s[i] - 'a', b = t[i] - 'a';
            for (int c = 0; c < 26; c++)
                if (d[a][c] < INF && d[b][c] < INF)
                    mn = min(mn, d[a][c] + d[b][c]);
            if (mn == INF) return -1;
            res += mn;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dijkstra-Based Approach**

### 💡 Algorithm Steps:

1. Build an adjacency list representation from transformation rules for efficient graph traversal.
2. For each mismatched character position, compute shortest paths using Dijkstra's algorithm.
3. Run Dijkstra from both source characters to find costs to all possible target characters.
4. Select the common character with minimum combined transformation cost.
5. Aggregate costs across all mismatched positions to compute total transformation cost.

```cpp
class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform, vector<int> &cost) {
        vector<vector<pair<int,int>>> g(26);
        for (int i = 0; i < transform.size(); i++)
            g[transform[i][0] - 'a'].push_back({transform[i][1] - 'a', cost[i]});
        auto dijkstra = [&](int src) {
            vector<int> dist(26, 1e9);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
            dist[src] = 0;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[u]) continue;
                for (auto [v, w] : g[u]) {
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
        };
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i]) continue;
            auto d1 = dijkstra(s[i] - 'a'), d2 = dijkstra(t[i] - 'a');
            int mn = 1e9;
            for (int c = 0; c < 26; c++) mn = min(mn, d1[c] + d2[c]);
            if (mn == 1e9) return -1;
            res += mn;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × 26 × E log V), where E is the number of transformation edges and n is string length. Dijkstra runs for each mismatched position with complexity O(E log V) per execution.
* **Auxiliary Space:** 💾 O(E), for storing the adjacency list representation of the transformation graph.

### ✅ **Why This Approach?**

* More efficient when transformation graph is sparse with fewer edges.
* Computes paths on-demand only for characters present in input strings.
* Avoids unnecessary preprocessing when most transformations are unused.

### ⚠️ **Limitations:**

> * Results in Time Limit Exceeded (TLE) for large inputs due to repeated Dijkstra calls.
> * Fails approximately 1010/1120 test cases in competitive environments.
> * Less efficient than Floyd-Warshall for dense transformation graphs.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Floyd-Warshall**             | 🟢 O(26³ + n)          | 🟢 O(1)                 | 🚀 Optimal for dense graphs       | 🔧 Fixed cubic preprocessing overhead |
| 🔍 **Dijkstra**                   | 🔴 O(n × 26 × E log V) | 🟢 O(E)                 | 📖 Good for sparse graphs         | ⏱️ TLE on large inputs               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Dense transformation graph**                     | 🥇 **Floyd-Warshall**                | ★★★★★                     |
| 📖 **Sparse transformations, small inputs**            | 🥈 **Dijkstra**                      | ★★★☆☆                     |
| 🎯 **Competitive programming**                         | 🏅 **Floyd-Warshall**                | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCost(String s, String t, char[][] transform, int[] cost) {
        final int INF = (int)1e9;
        int[][] d = new int[26][26];
        for (int i = 0; i < 26; i++) {
            Arrays.fill(d[i], INF);
            d[i][i] = 0;
        }
        for (int i = 0; i < transform.length; i++)
            d[transform[i][0] - 'a'][transform[i][1] - 'a'] = Math.min(d[transform[i][0] - 'a'][transform[i][1] - 'a'], cost[i]);
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = Math.min(d[i][j], d[i][k] + d[k][j]);
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == t.charAt(i)) continue;
            int mn = INF, a = s.charAt(i) - 'a', b = t.charAt(i) - 'a';
            for (int c = 0; c < 26; c++)
                if (d[a][c] < INF && d[b][c] < INF)
                    mn = Math.min(mn, d[a][c] + d[b][c]);
            if (mn == INF) return -1;
            res += mn;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, s, t, transform, cost):
        INF = int(1e9)
        d = [[INF] * 26 for _ in range(26)]
        for i in range(26): d[i][i] = 0
        for i in range(len(transform)):
            u, v = ord(transform[i][0]) - ord('a'), ord(transform[i][1]) - ord('a')
            d[u][v] = min(d[u][v], cost[i])
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if d[i][k] < INF and d[k][j] < INF:
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j])
        res = 0
        for i in range(len(s)):
            if s[i] == t[i]: continue
            mn, a, b = INF, ord(s[i]) - ord('a'), ord(t[i]) - ord('a')
            for c in range(26):
                if d[a][c] < INF and d[b][c] < INF:
                    mn = min(mn, d[a][c] + d[b][c])
            if mn == INF: return -1
            res += mn
        return res
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
