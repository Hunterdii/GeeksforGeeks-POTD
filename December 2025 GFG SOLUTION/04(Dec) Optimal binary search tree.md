---
title: "🌳 Optimal binary search tree | GFG Solution 🎯"
keywords🏷️: ["Optimal BST", "Dynamic Programming", "BST construction", "GFG", "search cost", "frequency optimization", "Knuth Optimization"]
author: "Het Patel (Hunterdii)"
description: "Efficient solutions to compute minimum cost of Optimal Binary Search Tree using DP, including optimized variants."
date: 📅 2025-12-04
---


# *04. Optimal Binary Search Tree*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/optimal-binary-search-tree2214/1)

## **🧩 Problem Description**

You are given a set of distinct keys in sorted order, represented by `keys[]`. Each key `ki` represents a data record accessed during a search operation. For all keys, you are also given a frequency array `freq[]`, which denotes how many times key `ki` is searched for.

The cost of accessing a key in a binary search tree is calculated by multiplying its access frequency by the level at which it appears in the tree. Therefore, different arrangements of keys in the BST result in different total search costs.

Your task is to calculate the **minimum total search cost** required to construct a binary search tree containing all the keys.

**Note:** Consider the root of the BST is at level 1.

## **📘 Examples**

### Example 1

```cpp
Input: keys[] = [10, 12], freq[] = [34, 50]
Output: 118
Explanation: There can be two possible BSTs:
Tree I: 10 as root, 12 as right child → Cost = 34*1 + 50*2 = 134
Tree II: 12 as root, 10 as left child → Cost = 50*1 + 34*2 = 118
The minimum cost is 118.
```

### Example 2

```cpp
Input: keys[] = [10, 12, 20], freq[] = [34, 8, 50]
Output: 142
Explanation: Among all possible BSTs, the optimal configuration has:
20 as root (level 1), 10 as left child (level 2), 12 as right child of 10 (level 3)
Cost = 1*50 + 2*34 + 3*8 = 142
```

## **🔒 Constraints**

* $1 \le \text{keys.size()} = \text{freq.size()} \le 100$
* $1 \le \text{keys}[i], \text{freq}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Prefix Sum Optimization** to efficiently compute the minimum cost BST:

### **Dynamic Programming with Prefix Sum**

1. **Initialize DP Table:**
   * Create a 2D DP table `dp[i][j]` representing the minimum cost to construct a BST with keys from index `i` to `j`.
   * Base case: `dp[i][i] = freq[i]` (single key costs its frequency at level 1).

2. **Precompute Prefix Sums:**
   * Build prefix sum array `ps[]` where `ps[i]` stores the cumulative sum of frequencies up to index `i-1`.
   * This allows O(1) range sum queries: `sum(i, j) = ps[j+1] - ps[i]`.

3. **Fill DP Table:**
   * Iterate over all possible subarray lengths `l` from 2 to n.
   * For each subarray `[i, j]`, try every key `r` in the range as the root.
   * Calculate cost when key `r` is root: `cost = dp[i][r-1] + dp[r+1][j] + frequencySum(i, j)`.
   * The frequency sum represents the cost increment as all keys in the range go one level deeper.

4. **Recurrence Relation:**
   * `dp[i][j] = min(dp[i][r-1] + dp[r+1][j]) + sum(freq[i..j])` for all r in [i, j].
   * Left subtree cost + Right subtree cost + Total frequency sum of current range.

5. **Return Result:**
   * `dp[0][n-1]` contains the minimum cost for constructing BST with all keys.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n³), as we have three nested loops: one for subarray length (O(n)), one for starting position (O(n)), and one for choosing the root within the range (O(n)).
* **Expected Auxiliary Space Complexity:** O(n²), as we use a 2D DP table of size n×n and a prefix sum array of size n+1.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + freq[i];
        for (int i = 0; i < n; i++) dp[i][i] = freq[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                int fsum = ps[j + 1] - ps[i];
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + fsum;
                    dp[i][j] = min(dp[i][j], c);
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Memoization Approach**

### 💡 Algorithm Steps:

1. Use recursive top-down approach with memoization for subproblem results.
2. For each range calculate cost by trying each node as root.
3. Store computed results in memo table to avoid recomputation.
4. Return the minimum cost among all possible root choices.

```cpp
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(0, n - 1, freq, memo);
    }
    int solve(int i, int j, vector<int>& f, vector<vector<int>>& m) {
        if (i > j) return 0;
        if (m[i][j] != -1) return m[i][j];
        int fs = 0;
        for (int k = i; k <= j; k++) fs += f[k];
        int res = INT_MAX;
        for (int r = i; r <= j; r++) {
            int c = solve(i, r - 1, f, m) + solve(r + 1, j, f, m) + fs;
            res = min(res, c);
        }
        return m[i][j] = res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Three nested loops for all subproblems
* **Auxiliary Space:** 💾 O(n²) - Memoization table and recursion stack

### ✅ **Why This Approach?**

* Natural recursive structure matches problem definition
* Easy to understand and debug recursively
* Avoids redundant calculations through memoization

## 📊 **3️⃣ Space-Optimized DP**

### 💡 Algorithm Steps:

1. Use bottom-up DP with optimized space for frequency sum calculation.
2. Precompute prefix sums to get range sum in O(1) time.
3. Build DP table for increasing subproblem sizes.
4. Optimize by reusing computed subproblem results efficiently.

```cpp
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int g = 0; g < n; g++) {
            for (int i = 0, j = g; j < n; i++, j++) {
                if (g == 0) dp[i][j] = freq[i];
                else {
                    int mn = INT_MAX, sm = 0;
                    for (int k = i; k <= j; k++) sm += freq[k];
                    for (int r = i; r <= j; r++) {
                        int lt = r > i ? dp[i][r - 1] : 0;
                        int rt = r < j ? dp[r + 1][j] : 0;
                        mn = min(mn, lt + rt);
                    }
                    dp[i][j] = mn + sm;
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Three loops for DP table construction
* **Auxiliary Space:** 💾 O(n²) - Only DP table storage needed

### ✅ **Why This Approach?**

* Iterative approach avoids recursion overhead
* Gap-based iteration provides clear subproblem ordering
* Compact code structure with inline sum calculation

## 📊 **4️⃣ Knuth Optimization**

### 💡 Algorithm Steps:

1. Apply Knuth's optimization to reduce search space for optimal root.
2. For each subproblem maintain the root index that gives minimum cost.
3. Use property that optimal root lies between roots of adjacent subproblems.
4. Reduce the range of root candidates from O(n) to O(n) amortized.

```cpp
class Solution {
public:
    int minCost(vector<int> &keys, vector<int> &freq) {
        int n = keys.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> rt(n + 1, vector<int>(n + 1, 0));
        vector<int> ps(n + 1, 0);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + freq[i];
            dp[i][i] = freq[i];
            rt[i][i] = i;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int r = rt[i][j - 1]; r <= rt[i + 1][j]; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + ps[j + 1] - ps[i];
                    if (c < dp[i][j]) {
                        dp[i][j] = c;
                        rt[i][j] = r;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Optimized root search reduces complexity
* **Auxiliary Space:** 💾 O(n²) - DP and root tracking tables

### ✅ **Why This Approach?**

* Best asymptotic time complexity for this problem
* Leverages optimal substructure property efficiently
* Significant speedup for large input sizes

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Prefix Sum DP**              | 🟡 O(n³)               | 🟢 O(n²)                | 🚀 Fast range sum queries         | 🐌 Cubic time complexity             |
| 🔍 **Memoization**                 | 🟡 O(n³)               | 🟡 O(n²)                | 📖 Intuitive recursive logic      | 📚 Recursion stack overhead          |
| 📊 **Space-Optimized DP**          | 🟡 O(n³)               | 🟢 O(n²)                | 🎯 Clean iterative structure      | 🐌 Same time as basic DP             |
| 🔄 **Knuth Optimization**          | 🟢 O(n²)               | 🟢 O(n²)                | ⭐ Best time complexity           | 🔧 More complex implementation       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Large input sizes**                              | 🥇 **Knuth Optimization**            | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **Memoization**                   | ★★★★☆                     |
| 🔧 **Interview setting**                              | 🥉 **Prefix Sum DP**                 | ★★★★☆                     |
| 🎯 **Balance simplicity/speed**                       | 🏅 **Space-Optimized DP**            | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCost(int keys[], int freq[]) {
        int n = keys.length;
        int[][] dp = new int[n][n];
        int[] ps = new int[n + 1];
        for (int i = 0; i < n; i++) ps[i + 1] = ps[i] + freq[i];
        for (int i = 0; i < n; i++) dp[i][i] = freq[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = Integer.MAX_VALUE;
                int fsum = ps[j + 1] - ps[i];
                for (int r = i; r <= j; r++) {
                    int c = (r > i ? dp[i][r - 1] : 0) + (r < j ? dp[r + 1][j] : 0) + fsum;
                    dp[i][j] = Math.min(dp[i][j], c);
                }
            }
        }
        return dp[0][n - 1];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCost(self, keys, freq):
        n = len(keys)
        dp = [[0] * n for _ in range(n)]
        ps = [0] * (n + 1)
        for i in range(n):
            ps[i + 1] = ps[i] + freq[i]
            dp[i][i] = freq[i]
        for l in range(2, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                fsum = ps[j + 1] - ps[i]
                for r in range(i, j + 1):
                    c = (dp[i][r - 1] if r > i else 0) + (dp[r + 1][j] if r < j else 0) + fsum
                    dp[i][j] = min(dp[i][j], c)
        return dp[0][n - 1]
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



