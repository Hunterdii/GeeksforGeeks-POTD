---
title: "🪨 Minimum Cost to Merge Stones | GFG Solution 🔍"
keywords🏷️: ["🪨 merge stones", "🔍 dynamic programming", "📍 interval dp", "📈 prefix sum", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Cost to Merge Stones problem: find minimum cost to merge all stone piles into one using dynamic programming with interval DP technique. 🚀"
date: 📅 2025-11-14
---

# *14. Minimum Cost to Merge Stones*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-cost-to-merge-stones/1)

## **🧩 Problem Description**

You are given an array `stones[]`, where the ith element represents the number of stones in the ith pile. In one move, you can merge exactly **k consecutive piles** into a single pile, and the cost of this move is equal to the total number of stones in these k piles.

Determine the **minimum total cost** required to merge all the piles into one single pile. If it is not possible to merge all piles into one according to the given rules, return **-1**.

## **📘 Examples**

### Example 1

```cpp
Input: stones[] = [1, 2, 3], k = 2
Output: 9
Explanation: Initially the array looks like [1, 2, 3].
First, we merge first 2 stones, i.e., 1 and 2, array becomes [3, 3] and cost is 1 + 2 = 3.
Then, we merge remaining stones, i.e., 3 and 3, array becomes [6] and the cost = 3 + 3 = 6.
Total cost = 3 + 6 = 9.
```

### Example 2

```cpp
Input: stones[] = [1, 5, 3, 2, 4], k = 2
Output: 35
Explanation: Initially the array looks like [1, 5, 3, 2, 4].
First, we merge 1 and 5, array becomes [6, 3, 2, 4] and cost is 1 + 5 = 6.
Then, we merge 3 and 2, array becomes [6, 5, 4] and the cost = 3 + 2 = 5.
Then, we merge 5 and 4, array becomes [6, 9] and the cost = 5 + 4 = 9.
Finally, we merge 6 and 9, array becomes [15] and the cost = 6 + 9 = 15.
Total cost = 6 + 5 + 9 + 15 = 35.
```

### Example 3

```cpp
Input: stones[] = [1, 5, 3, 2, 4], k = 4
Output: -1
Explanation: There is no possible way to combine the stones in piles of 4 to get 1 stone in the end.
```

## **🔒 Constraints**

* $1 \le \text{stones.size()} \le 30$
* $2 \le k \le 30$
* $1 \le \text{stones}[i] \le 100$

## **✅ My Approach**

The optimal approach uses **Interval Dynamic Programming** with **Prefix Sum** optimization to efficiently compute the minimum cost:

### **Interval DP + Prefix Sum**

1. **Feasibility Check:**
   * For n piles to be merged into 1 pile, we need `(n - 1) % (k - 1) == 0`.
   * This is because each merge reduces pile count by `k - 1`.
   * If condition fails, return -1 immediately.

2. **Prefix Sum Computation:**
   * Build prefix sum array to calculate range sum in O(1) time.
   * `sum[i]` stores total stones from index 0 to i-1.

3. **DP State Definition:**
   * `dp[i][j]` represents minimum cost to optimally partition range [i, j].
   * Base case: `dp[i][i] = 0` (single pile needs no merging).

4. **DP Transition:**
   * For each subrange [i, j], try all valid split points at intervals of `k - 1`.
   * Split range into two parts and combine their minimum costs.
   * If range can be merged into single pile `((j - i) % (k - 1) == 0)`, add merge cost.

5. **Bottom-Up Computation:**
   * Process subarrays in increasing order of length from k to n.
   * For each length, iterate through all valid starting positions.
   * Final answer is stored in `dp[0][n-1]`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n³), as we iterate over all possible subranges [i, j] and for each range, we try multiple split points. The outer loop runs O(n) times for different lengths, the middle loop runs O(n) times for starting positions, and the inner loop runs O(n/k-1) times for split points, resulting in overall O(n³) complexity.
* **Expected Auxiliary Space Complexity:** O(n²), as we use a 2D DP table of size n×n to store the minimum cost for all possible subranges, and an additional O(n) space for the prefix sum array, resulting in O(n²) auxiliary space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += k - 1)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (k - 1) == 0)
                    dp[i][j] += sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ 3D DP Approach**

### 💡 Algorithm Steps:

1. Use three-dimensional DP where `dp[i][j][p]` represents minimum cost to merge stones[i...j] into p piles.
2. Base case: merging range into same number of piles as elements costs 0.
3. Transition: try all split points to divide range and merge subproblems.
4. Final answer is cost to merge entire array into 1 pile.

```cpp
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) return -1;
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 1e9)));
        for (int i = 0; i < n; i++) dp[i][i][1] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                for (int p = 2; p <= k; p++)
                    for (int mid = i; mid < j; mid += k - 1)
                        dp[i][j][p] = min(dp[i][j][p], dp[i][mid][1] + dp[mid + 1][j][p - 1]);
                dp[i][j][1] = dp[i][j][k] + sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1][1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³ × k) - Three nested loops with k iterations
* **Auxiliary Space:** 💾 O(n² × k) - 3D DP table

### ✅ **Why This Approach?**

* More intuitive state representation
* Explicit tracking of pile count
* Easier to understand merge operations

## 📊 **3️⃣ Memoization with Recursion**

### 💡 Algorithm Steps:

1. Use recursive function with memoization to compute minimum merge cost.
2. For each range, try all possible split points at intervals of k-1.
3. Cache results to avoid recomputation of subproblems.
4. Add merge cost when range can be reduced to single pile.

```cpp
class Solution {
    int memo[31][31];
    vector<int> sum;
    int k;
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        k = K;
        if ((n - 1) % (k - 1)) return -1;
        sum.resize(n + 1);
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        memset(memo, -1, sizeof(memo));
        return solve(0, n - 1);
    }
    int solve(int i, int j) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];
        int res = INT_MAX;
        for (int mid = i; mid < j; mid += k - 1)
            res = min(res, solve(i, mid) + solve(mid + 1, j));
        if ((j - i) % (k - 1) == 0) res += sum[j + 1] - sum[i];
        return memo[i][j] = res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Each subproblem computed once with n² states
* **Auxiliary Space:** 💾 O(n²) - Memoization table plus recursion stack

### ✅ **Why This Approach?**

* Top-down approach more natural for some problems
* Easier to implement and debug
* Only computes needed subproblems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **2D Bottom-Up DP**           | 🟢 O(n³)               | 🟢 O(n²)                | 🚀 Optimal space usage            | 🔧 Less intuitive state              |
| 🔍 **3D DP**                      | 🟡 O(n³ × k)           | 🟡 O(n² × k)            | 📖 Clear pile tracking            | 💾 Extra dimension overhead          |
| 📊 **Memoization**                | 🟢 O(n³)               | 🟢 O(n²)                | 🎯 Natural recursion              | 🐌 Recursion overhead                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **2D Bottom-Up DP**               | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **3D DP**                         | ★★★★☆                     |
| 🔧 **Easy implementation**                            | 🥉 **Memoization**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) return -1;
        int[] sum = new int[n + 1];
        for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + stones[i];
        int[][] dp = new int[n][n];
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int mid = i; mid < j; mid += k - 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (k - 1) == 0)
                    dp[i][j] += sum[j + 1] - sum[i];
            }
        }
        return dp[0][n - 1];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def mergeStones(self, stones, k):
        n = len(stones)
        if (n - 1) % (k - 1): return -1
        s = [0] * (n + 1)
        for i in range(n): s[i + 1] = s[i] + stones[i]
        dp = [[0] * n for _ in range(n)]
        for l in range(k, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                for m in range(i, j, k - 1):
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j])
                if (j - i) % (k - 1) == 0:
                    dp[i][j] += s[j + 1] - s[i]
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
