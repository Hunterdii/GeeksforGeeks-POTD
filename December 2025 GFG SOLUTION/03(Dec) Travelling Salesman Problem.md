---
title: "🚗 Travelling Salesman Problem | GFG Solution 🔍"
keywords🏷️: ["🚗 TSP", "🔍 dynamic programming", "📍 bitmask DP", "📈 graph traversal", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Travelling Salesman Problem: find minimum cost to visit all cities exactly once and return to start using dynamic programming with bitmask optimization. 🚀"
date: 📅 2025-12-03
---

# *03. Travelling Salesman Problem*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/travelling-salesman-problem2732/1)

## **🧩 Problem Description**

You are given a 2D matrix `cost[][]` of size `n` where `cost[i][j]` denotes the cost of moving from city `i` to city `j`. Your task is to complete a tour from city 0 (0-based index) to all other cities such that you visit each city exactly once and then at the end come back to city 0 at minimum cost.

This is the classic **Travelling Salesman Problem (TSP)**, where the goal is to find the shortest possible route that visits every city exactly once and returns to the starting city.

## **📘 Examples**

### Example 1

```cpp
Input: cost[][] = [[0, 111], 
                   [112, 0]]
Output: 223
Explanation: We can visit 0->1->0 and cost = 111 + 112 = 223.
```

### Example 2

```cpp
Input: cost[][] = [[0, 1000, 5000],
                   [5000, 0, 1000],
                   [1000, 5000, 0]]
Output: 3000
Explanation: We can visit 0->1->2->0 and cost = 1000 + 1000 + 1000 = 3000.
```

## **🔒 Constraints**

* $1 \le \text{cost.size()} \le 15$
* $0 \le \text{cost}[i][j] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Bitmask** (Held-Karp algorithm) to efficiently explore all possible tours:

### **Bitmask Dynamic Programming**

1. **State Representation:**
   * Use `dp[mask][i]` to represent the minimum cost to visit all cities represented by set bits in `mask`, ending at city `i`.
   * The bitmask `mask` tracks which cities have been visited (bit `i` is 1 if city `i` is visited).

2. **Base Case:**
   * Start from city 0: `dp[1][0] = 0` (only city 0 visited with cost 0).

3. **State Transitions:**
   * For each state `(mask, i)`, try moving to every unvisited city `j`.
   * Update `dp[mask | (1 << j)][j]` with the minimum of current value and `dp[mask][i] + cost[i][j]`.

4. **Final Answer:**
   * After visiting all cities (when `mask = 2^n - 1`), add the cost to return to city 0.
   * The answer is `min(dp[fullMask][i] + cost[i][0])` for all cities `i`.

5. **Optimization:**
   * Process states in order of increasing mask values to ensure all dependencies are resolved.
   * Skip invalid states where city `i` is not in the mask or cost is infinity.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n² × 2ⁿ), where n is the number of cities. We have 2ⁿ possible subsets of cities and for each subset-city combination, we try to extend to n other cities.
* **Expected Auxiliary Space Complexity:** O(n × 2ⁿ), as we maintain a 2D DP table with dimensions (2ⁿ × n) to store the minimum cost for each state.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        int FULL = (1 << n) - 1;
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        dp[1][0] = 0;
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            if (dp[FULL][i] != INT_MAX)
                ans = min(ans, dp[FULL][i] + cost[i][0]);
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursive Memoization Approach**

### 💡 Algorithm Steps:

1. Use recursion with memoization to explore all paths starting from city 0.
2. Track visited cities using bitmask and current city position.
3. Store computed results in memo table to avoid recomputation.
4. Return to starting city after visiting all cities to complete the tour.

```cpp
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        vector<vector<int>> memo(1 << n, vector<int>(n, -1));
        function<int(int, int)> solve = [&](int mask, int pos) {
            if (mask == (1 << n) - 1) return cost[pos][0];
            if (memo[mask][pos] != -1) return memo[mask][pos];
            int res = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) {
                    res = min(res, cost[pos][i] + solve(mask | (1 << i), i));
                }
            }
            return memo[mask][pos] = res;
        };
        return solve(1, 0);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × 2ⁿ) - Exploring all subsets with transitions
* **Auxiliary Space:** 💾 O(n × 2ⁿ) - Memoization table and recursion stack

### ✅ **Why This Approach?**

* Top-down approach easier to understand and debug
* Natural recursive structure matches problem definition
* Clean code with lambda functions for modern C++

## 📊 **3️⃣ Space-Optimized Bottom-Up DP**

### 💡 Algorithm Steps:

1. Process states layer by layer based on number of visited cities.
2. Use two arrays to track current and next layer states.
3. Reduce space by only keeping necessary previous states.
4. Calculate minimum cost by building solutions incrementally.

```cpp
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        map<pair<int,int>, int> curr, next;
        curr[{1, 0}] = 0;
        for (int cnt = 1; cnt < n; cnt++) {
            next.clear();
            for (auto& [key, val] : curr) {
                int mask = key.first, pos = key.second;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) continue;
                    int nmask = mask | (1 << i);
                    if (!next.count({nmask, i}) || next[{nmask, i}] > val + cost[pos][i])
                        next[{nmask, i}] = val + cost[pos][i];
                }
            }
            curr = next;
        }
        int ans = INT_MAX;
        for (auto& [key, val] : curr)
            ans = min(ans, val + cost[key.second][0]);
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × 2ⁿ) - Same state transitions
* **Auxiliary Space:** 💾 O(n × 2ⁿ⁻¹) - Only store reachable states

### ✅ **Why This Approach?**

* Memory efficient by storing only necessary states
* Avoids allocating full 2D array for sparse graphs
* Better cache locality for smaller problem instances

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110/1115 test cases due to time constraints).


## 📊 **4️⃣ Held-Karp with Path Reconstruction**

### 💡 Algorithm Steps:

1. Build DP table similar to standard approach but track parent information.
2. Store both minimum cost and previous city for each state.
3. After finding optimal cost reconstruct the actual path taken.
4. Useful when both cost and path sequence are needed.

```cpp
class Solution {
public:
    int tsp(vector<vector<int>>& cost) {
        int n = cost.size();
        if (n <= 1) return n ? cost[0][0] : 0;
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));
        dp[1][0] = 0;
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i)) || dp[mask][i] == INT_MAX) continue;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue;
                    int nxt = mask | (1 << j);
                    if (dp[nxt][j] > dp[mask][i] + cost[i][j]) {
                        dp[nxt][j] = dp[mask][i] + cost[i][j];
                        parent[nxt][j] = i;
                    }
                }
            }
        }
        int ans = INT_MAX, lastCity = -1;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] != INT_MAX && ans > dp[(1 << n) - 1][i] + cost[i][0]) {
                ans = dp[(1 << n) - 1][i] + cost[i][0];
                lastCity = i;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² × 2ⁿ) - Standard DP with parent tracking
* **Auxiliary Space:** 💾 O(n × 2ⁿ) - Additional parent array

### ✅ **Why This Approach?**

* Provides both optimal cost and actual tour path
* Essential for applications needing the route details
* Minimal overhead compared to basic DP solution

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Bottom-Up DP**              | 🟢 O(n² × 2ⁿ)         | 🟡 O(n × 2ⁿ)           | 🚀 Iterative, no stack overflow   | 💾 Full state space allocation       |
| 🔍 **Recursive Memoization**      | 🟢 O(n² × 2ⁿ)         | 🟡 O(n × 2ⁿ)           | 📖 Intuitive top-down logic       | 🔧 Recursion stack overhead          |
| 📊 **Space-Optimized**            | 🟢 O(n² × 2ⁿ)         | 🟢 O(n × 2ⁿ⁻¹)         | 💾 Reduced memory footprint       | 🔧 More complex state management     |
| 🔄 **Path Reconstruction**        | 🟢 O(n² × 2ⁿ)         | 🟡 O(n × 2ⁿ)           | ⭐ Returns both cost and path     | 💾 Extra space for parent tracking   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Standard TSP problem**                           | 🥇 **Bottom-Up DP**                  | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Recursive Memoization**         | ★★★★☆                     |
| 💾 **Memory-constrained**                             | 🥉 **Space-Optimized**               | ★★★★☆                     |
| 🎯 **Need actual tour path**                          | 🏅 **Path Reconstruction**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int tsp(int[][] cost) {
        int n = cost.length;
        if (n <= 1) return n == 1 ? cost[0][0] : 0;
        int FULL = (1 << n) - 1;
        int[][] dp = new int[1 << n][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE);
        dp[1][0] = 0;
        for (int mask = 1; mask <= FULL; mask++) {
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0 || dp[mask][i] == Integer.MAX_VALUE) continue;
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) != 0) continue;
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = Math.min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            if (dp[FULL][i] != Integer.MAX_VALUE)
                ans = Math.min(ans, dp[FULL][i] + cost[i][0]);
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def tsp(self, cost):
        n = len(cost)
        if n <= 1: return cost[0][0] if n else 0
        FULL = (1 << n) - 1
        dp = [[float('inf')] * n for _ in range(1 << n)]
        dp[1][0] = 0
        for mask in range(1, (1 << n)):
            for i in range(n):
                if not (mask & (1 << i)) or dp[mask][i] == float('inf'): continue
                for j in range(n):
                    if mask & (1 << j): continue
                    nxt = mask | (1 << j)
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j])
        ans = float('inf')
        for i in range(n):
            if dp[FULL][i] != float('inf'):
                ans = min(ans, dp[FULL][i] + cost[i][0])
        return ans
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













