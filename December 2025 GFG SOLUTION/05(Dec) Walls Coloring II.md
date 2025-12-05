---
title: "🎨 Walls Coloring II | GFG Solution 🏗️"
keywords: ["🎨 paint house", "🏗️ dynamic programming", "🔄 two pointers", "📊 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Walls Coloring II problem: find minimum cost to paint walls with different colors for adjacent walls using optimized DP with two minimum tracking. 🚀"
date: 📅 2025-12-05
---

# *05. Walls Coloring II*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/walls-coloring-ii--170647/1)

## **🧩 Problem Description**

You are given **n walls** arranged in a row, and each wall must be painted using one of the **k available colors**. The cost of painting the **i-th wall** with the **j-th color** is given by `costs[i][j]`.

Your task is to determine the **minimum total cost** required to paint all the walls such that **no two adjacent walls share the same color**. If it is impossible to paint the walls under this condition, return **-1**.

## **📘 Examples**

### Example 1

```cpp
Input: n = 4, k = 3,
costs[][] = [[1, 5, 7],
             [5, 8, 4],
             [3, 2, 9],
             [1, 2, 4]]

Output: 8
Explanation:
Paint wall 0 with color 0. Cost = 1
Paint wall 1 with color 2. Cost = 4
Paint wall 2 with color 1. Cost = 2
Paint wall 3 with color 0. Cost = 1
Total Cost = 1 + 4 + 2 + 1 = 8
```

### Example 2

```cpp
Input: n = 5, k = 1,
costs[][] = [[5],
             [4],
             [9],
             [2],
             [1]]
Output: -1
Explanation: It is not possible to color all the walls under the given conditions 
(only 1 color available but need different colors for adjacent walls).
```

## **🔒 Constraints**

* $0 \le n \le 10^3$
* $0 \le k \le 10^3$
* $1 \le \text{costs}[i][j] \le 10^5$

## **✅ My Approach**

The optimal solution uses **Dynamic Programming with Two Minimum Tracking** to efficiently find the minimum cost while ensuring adjacent walls have different colors:

### **Two Minimum Tracking DP**

1. **Edge Case Handling:**
   * If there's only 1 color available (`k = 1`) and more than 1 wall (`n > 1`), it's impossible to paint adjacent walls with different colors. Return -1.

2. **Initialize Tracking Variables:**
   * `m1` (minimum cost from previous wall)
   * `m2` (second minimum cost from previous wall)
   * `idx` (color index that gave minimum cost)
   * Initially, set `m1 = 0, m2 = 0, idx = -1` (no previous wall)

3. **Process Each Wall:**
   * For each wall `i` from 0 to n-1:
     * Initialize `nm1 = INT_MAX` (new minimum), `nm2 = INT_MAX` (new second minimum), `nidx = -1` (new minimum index)
     * For each color `j` from 0 to k-1:
       * Calculate cost: `c = costs[i][j] + (if same color as previous minimum, use m2, else use m1)`
       * Update `nm1`, `nm2`, and `nidx` based on calculated cost
     * Update tracking variables: `m1 = nm1, m2 = nm2, idx = nidx`

4. **Return Result:**
   * After processing all walls, `m1` contains the minimum cost to paint all walls

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n×k), as we iterate through all n walls and for each wall, we check all k colors. Each element is processed once with constant time operations.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store tracking variables (m1, m2, idx, nm1, nm2, nidx) regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        int m1 = 0, m2 = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            int nm1 = INT_MAX, nm2 = INT_MAX, nidx = -1;
            for (int j = 0; j < m; j++) {
                int c = costs[i][j] + (j == idx ? m2 : m1);
                if (c < nm1) { nm2 = nm1; nm1 = c; nidx = j; }
                else if (c < nm2) nm2 = c;
            }
            m1 = nm1; m2 = nm2; idx = nidx;
        }
        return m1;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming with Space Optimization**

### 💡 Algorithm Steps:

1. Create a DP array to store minimum costs for current row.
2. For each house, calculate cost using minimum from previous row excluding same color.
3. Track two minimum values and their indices for optimization.
4. Update DP array row by row until last house is painted.

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<int> dp = costs[0];
        for (int i = 1; i < n; i++) {
            int min1 = *min_element(dp.begin(), dp.end());
            int minIdx = min_element(dp.begin(), dp.end()) - dp.begin();
            int min2 = INT_MAX;
            for (int j = 0; j < m; j++) if (j != minIdx) min2 = min(min2, dp[j]);
            vector<int> ndp(m);
            for (int j = 0; j < m; j++) ndp[j] = costs[i][j] + (j == minIdx ? min2 : min1);
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×k) - Process each house with k colors
* **Auxiliary Space:** 💾 O(k) - Store costs for k colors

### ✅ **Why This Approach?**

* Clear DP pattern with space optimization
* Easy to debug with explicit state tracking
* Handles edge cases naturally

## 📊 **3️⃣ Full DP Matrix Approach**

### 💡 Algorithm Steps:

1. Create 2D DP table where dp[i][j] represents minimum cost to paint house i with color j.
2. Initialize first row with costs from first house.
3. For each subsequent house, calculate minimum cost by excluding same color from previous row.
4. Return minimum value from last row of DP table.

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) dp[0][j] = costs[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (k != j) dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
                }
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×k²) - Nested loops for color comparison
* **Auxiliary Space:** 💾 O(n×k) - Full DP matrix storage

### ✅ **Why This Approach?**

* Standard DP approach for beginners
* Clear state transitions and dependencies
* Good for understanding problem structure

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1008/1119 test cases due to time constraints).


## 📊 **4️⃣ Prefix Minimum Optimization**

### 💡 Algorithm Steps:

1. Maintain prefix and suffix minimum arrays for each row.
2. For each position, quickly find minimum excluding current color.
3. Use precomputed minimums to avoid repeated calculations.
4. Process row by row with optimized lookups using prefix/suffix arrays.

```cpp
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        if (m == 1 && n > 1) return -1;
        vector<int> prev = costs[0];
        for (int i = 1; i < n; i++) {
            vector<int> left(m), right(m), curr(m);
            left[0] = prev[0];
            for (int j = 1; j < m; j++) left[j] = min(left[j-1], prev[j]);
            right[m-1] = prev[m-1];
            for (int j = m-2; j >= 0; j--) right[j] = min(right[j+1], prev[j]);
            for (int j = 0; j < m; j++) {
                int minVal = INT_MAX;
                if (j > 0) minVal = min(minVal, left[j-1]);
                if (j < m-1) minVal = min(minVal, right[j+1]);
                curr[j] = costs[i][j] + minVal;
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×k) - Linear scan with prefix/suffix arrays
* **Auxiliary Space:** 💾 O(k) - Arrays for prefix, suffix, and current row

### ✅ **Why This Approach?**

* Advanced optimization technique
* Reduces time complexity effectively
* Good for large number of colors

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Two Min Tracking**          | 🟢 O(n×k)              | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Complex index tracking            |
| 🔍 **Space Optimized DP**         | 🟢 O(n×k)              | 🟡 O(k)                 | 📖 Clear DP pattern               | 💾 Extra array needed                |
| 📊 **Full DP Matrix**             | 🟡 O(n×k²)             | 🟡 O(n×k)               | 🎯 Easy to understand             | 🐌 Higher time complexity            |
| 🔄 **Prefix Minimum**             | 🟢 O(n×k)              | 🟡 O(k)                 | ⭐ Optimized lookups              | 🔧 Complex implementation            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two Min Tracking**              | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Space Optimized DP**            | ★★★★☆                     |
| 🔧 **Learning DP patterns**                           | 🥉 **Full DP Matrix**                | ★★★☆☆                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Two Min Tracking**              | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int minCost(int[][] costs) {
        int n = costs.length, m = costs[0].length;
        if (m == 1 && n > 1) return -1;
        int m1 = 0, m2 = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            int nm1 = Integer.MAX_VALUE, nm2 = Integer.MAX_VALUE, nidx = -1;
            for (int j = 0; j < m; j++) {
                int c = costs[i][j] + (j == idx ? m2 : m1);
                if (c < nm1) { nm2 = nm1; nm1 = c; nidx = j; }
                else if (c < nm2) nm2 = c;
            }
            m1 = nm1; m2 = nm2; idx = nidx;
        }
        return m1;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, costs):
        n, m = len(costs), len(costs[0])
        if m == 1 and n > 1: return -1
        m1, m2, idx = 0, 0, -1
        for i in range(n):
            nm1, nm2, nidx = float('inf'), float('inf'), -1
            for j in range(m):
                c = costs[i][j] + (m2 if j == idx else m1)
                if c < nm1: nm2, nm1, nidx = nm1, c, j
                elif c < nm2: nm2 = c
            m1, m2, idx = nm1, nm2, nidx
        return m1
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


















