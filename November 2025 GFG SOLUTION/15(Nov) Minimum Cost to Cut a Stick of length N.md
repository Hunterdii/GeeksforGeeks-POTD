---
title: "✂️ Minimum Cost to Cut a Stick of length N | GFG Solution 🔍"
keywords🏷️: ["✂️ minimum cost", "🔍 dynamic programming", "📍 interval DP", "📈 memoization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Cost to Cut a Stick problem: find minimum total cost to perform all cuts on a wooden stick using interval dynamic programming technique. 🚀"
date: 📅 2025-11-15
---

# *15. Minimum Cost to Cut a Stick of length N*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-stick/1)

## **🧩 Problem Description**

You are given a wooden stick of length `n`, labeled from 0 to n. You are also given an integer array `cuts[]`, where each element `cuts[i]` represents a position along the stick at which you can make a cut.

Each cut costs an amount equal to the length of the stick being cut at that moment. After performing a cut, the stick is divided into two smaller sticks.

You can perform the cuts in any order. Your task is to determine the **minimum total cost** required to perform all the cuts.

## **📘 Examples**

### Example 1

```cpp
Input: n = 10, cuts[] = [2, 4, 7]
Output: 20
Explanation: If we cut the stick in the order [4, 2, 7], the cost will be 10 + 4 + 6 = 20, 
which is the minimum total cost.
```

### Example 2

```cpp
Input: n = 8, cuts[] = [1, 6, 3, 5]
Output: 19
Explanation: If we cut the stick in the order [3, 6, 1, 5], the cost will be 8 + 5 + 3 + 3 = 19, 
which is the minimum total cost.
```

## **🔒 Constraints**

* $2 \le n \le 10^6$
* $1 \le \text{cuts}[i] \le n - 1$
* $1 \le \text{cuts.size()} \le 100$

## **✅ My Approach**

The optimal approach uses **Interval Dynamic Programming** to solve this problem efficiently:

### **Interval DP with Bottom-Up Approach**

1. **Add Boundaries:**
   - Add 0 and n to the cuts array to represent the stick's endpoints.
   - Sort the cuts array to process intervals in order.

2. **Define DP State:**
   - `dp[i][j]` represents the minimum cost to make all cuts between position `cuts[i]` and `cuts[j]`.
   - The cost of cutting between positions `cuts[i]` and `cuts[j]` is `cuts[j] - cuts[i]`.

3. **Build DP Table:**
   - Iterate over all possible gap sizes (length of intervals).
   - For each interval `[i, j]`, try all possible cut positions `k` between them.
   - The cost for cutting at position `k` is: `dp[i][k] + dp[k][j] + cuts[j] - cuts[i]`.
   - Choose the minimum cost among all possible cut positions.

4. **Base Case:**
   - When there are no cuts between two positions (`j - i <= 1`), the cost is 0.

5. **Result:**
   - The answer is stored in `dp[0][sz-1]`, representing the entire stick from 0 to n.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(m³), where m is the total number of cuts including boundaries (m = cuts.size() + 2). We have O(m²) subproblems and each subproblem requires O(m) time to try all possible cut positions.
* **Expected Auxiliary Space Complexity:** O(m²), as we use a 2D DP table to store the minimum cost for all possible intervals between cuts.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int sz = cuts.size();
        vector<vector<int>> dp(sz, vector<int>(sz, 0));
        for (int gap = 2; gap < sz; gap++) {
            for (int i = 0; i + gap < sz; i++) {
                int j = i + gap;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][sz - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Top-Down DP with Memoization**

### 💡 Algorithm Steps:

1. Add boundary points and sort the cuts array.
2. Use recursive function with memoization to compute minimum cost.
3. Try each possible cut position and recursively solve subproblems.
4. Store results in memo table to avoid recomputation.

```cpp
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> memo(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(0, cuts.size() - 1, cuts, memo);
    }
    int solve(int i, int j, vector<int>& c, vector<vector<int>>& m) {
        if (j - i <= 1) return 0;
        if (m[i][j] != -1) return m[i][j];
        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            res = min(res, solve(i, k, c, m) + solve(k, j, c, m) + c[j] - c[i]);
        }
        return m[i][j] = res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m³) - Where m is number of cuts plus boundaries
* **Auxiliary Space:** 💾 O(m²) - Memoization table storage

### ✅ **Why This Approach?**

* Intuitive recursive thinking pattern
* Natural problem decomposition structure
* Easier to understand the subproblem relationships

## 📊 **3️⃣ Map-Based Memoization**

### 💡 Algorithm Steps:

1. Use hash map to store computed subproblem results.
2. Encode state as integer key for memoization.
3. Recursively solve with pruning of already computed states.
4. Return cached result if subproblem already solved.

```cpp
class Solution {
public:
    int minCutCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        unordered_map<int, int> dp;
        return dfs(0, cuts.size() - 1, cuts, dp);
    }
    int dfs(int l, int r, vector<int>& c, unordered_map<int, int>& dp) {
        if (r - l <= 1) return 0;
        int key = l * 1000 + r;
        if (dp.count(key)) return dp[key];
        int ans = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            ans = min(ans, dfs(l, i, c, dp) + dfs(i, r, c, dp) + c[r] - c[l]);
        }
        return dp[key] = ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m³) - Same subproblem count as standard DP
* **Auxiliary Space:** 💾 O(m²) - Hash map storage for states

### ✅ **Why This Approach?**

* Flexible state representation using hash map
* Easy to extend for more complex state spaces
* Good for sparse DP state scenarios

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Bottom-Up DP**              | 🟢 O(m³)                | 🟡 O(m²)                 | 🚀 Fast iterative solution           | 💾 Full 2D table needed              |
| 🔍 **Top-Down Memoization**                  | 🟢 O(m³)                | 🟡 O(m²)                 | 📖 Natural recursive structure             | 🔄 Function call overhead              |
| 🔄 **Map-Based**                | 🟢 O(m³)                | 🟡 O(m²)                 | ⭐ Flexible state encoding               | 🔧 Hash map overhead            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Standard competitive programming**                     | 🥇 **Bottom-Up DP**                 | ★★★★★                     |
| 📖 **Easier to understand**                           | 🥈 **Top-Down Memoization**                     | ★★★★☆                     |
| 🎯 **Complex state encoding**                          | 🥉 **Map-Based**                 | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minCutCost(int n, int[] cuts) {
        int m = cuts.length + 2;
        int[] c = new int[m];
        c[0] = 0;
        c[m - 1] = n;
        System.arraycopy(cuts, 0, c, 1, cuts.length);
        Arrays.sort(c);
        int[][] dp = new int[m][m];
        for (int gap = 2; gap < m; gap++) {
            for (int i = 0; i + gap < m; i++) {
                int j = i + gap;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k][j] + c[j] - c[i]);
                }
            }
        }
        return dp[0][m - 1];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minCutCost(self, n, cuts):
        cuts = [0] + sorted(cuts) + [n]
        m = len(cuts)
        dp = [[0] * m for _ in range(m)]
        for gap in range(2, m):
            for i in range(m - gap):
                j = i + gap
                dp[i][j] = float('inf')
                for k in range(i + 1, j):
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i])
        return dp[0][m - 1]
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
