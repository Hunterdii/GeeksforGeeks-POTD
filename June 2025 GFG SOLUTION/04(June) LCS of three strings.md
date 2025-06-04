---
title: "📚 LCS of three Strings | GFG Solution 🧬"
keywords🏷️: ["🧬 LCS", "📘 dynamic programming", "📚 3D DP", "🧠 string problems", "📈 optimization", "📘 GFG", "🏁 competitive programming", "🔁 memoization"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for LCS of 3 strings: dynamic programming with full 3D table, space optimized 2D, and recursion with memoization. 💡"
date: 📅 2025-06-04
---

# *04. LCS of three Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/lcs-of-three-strings0028/1)


## **🧩 Problem Description**

Given three strings `A`, `B`, and `C`, the task is to find the **length of the Longest Common Subsequence (LCS)** present in all three strings.

A **subsequence** is a sequence that appears in the same relative order, but not necessarily contiguous.


## **📘 Examples**

### Example 1

```cpp
Input:
s1 = "geeks"
s2 = "geeksfor"
s3 = "geeksforgeeks"

Output: 5

Explanation:
The longest common subsequence is "geeks" (length = 5).
```

### Example 2

```cpp
Input:
s1 = "abcd1e2"
s2 = "bc12ea"
s3 = "bd1ea"

Output: 3

Explanation:
The longest common subsequence is "b1e" (length = 3).
```


## **🔒 Constraints**

* $1 \leq |s1|,|s2|,|s3| \leq 100$
* Strings contain only lowercase English letters.

## **✅ My Approach**

### **Optimized 2D DP (Rolling Arrays)**

1. **Idea:**

   * A naive 3D DP table $dp[i][j][k]$ (size $(n1+1) \times (n2+1) \times (n3+1)$) takes $O(n1 \times n2 \times n3)$ time and space.
   * We can reduce space by noticing that at layer `i`, we only need layer `i-1` to compute the current values.
   * Maintain two 2D arrays `prev[j][k]` and `curr[j][k]` of size $(n2+1) \times (n3+1)$.

2. **DP Relation:**

   * Let `n1 = |s1|`, `n2 = |s2|`, `n3 = |s3|`.
   * For each `i` from `1` to `n1`, and for each `j` from `1` to `n2`, and each `k` from `1` to `n3`:

     * If `s1[i-1] == s2[j-1] == s3[k-1]`, then

       $$
         \text{curr}[j][k] = 1 + \text{prev}[\,j-1\,][\,k-1\,];
       $$
     * Otherwise,

       $$
         \text{curr}[j][k] = \max\bigl(\text{prev}[j][k],\,\text{curr}[\,j-1\,][k],\,\text{curr}[j][\,k-1\,]\bigr).
       $$
   * After filling `curr` for a fixed `i`, swap `prev` and `curr`, and zero out `curr` for the next iteration.

3. **Answer:**

   * The value `prev[n2][n3]` at the end of the loops is the length of the LCS among all three strings.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:**
  $\displaystyle O(n1 \times n2 \times n3)$, since we iterate over all `i ∈ [1..n1]`, `j ∈ [1..n2]`, `k ∈ [1..n3]`.

* **Expected Auxiliary Space Complexity:**
  $\displaystyle O(n2 \times n3)$, because we only store two 2D arrays of size $(n2+1)\times(n3+1)$ instead of a full 3D table.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        vector<vector<int>> prev(n2 + 1, vector<int>(n3 + 1, 0));
        vector<vector<int>> curr(n2 + 1, vector<int>(n3 + 1, 0));
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    else
                        curr[j][k] = max({prev[j][k], curr[j - 1][k], curr[j][k - 1]});
                }
            }
            prev.swap(curr);
        }
        return prev[n2][n3];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Full 3D DP Table**

### **Algorithm Steps:**

1. Define a 3D DP array:

   $$
     dp[i][j][k] = \text{length of LCS for } s1[0..i-1],\,s2[0..j-1],\,s3[0..k-1].
   $$
2. Initialize a `(n1+1) × (n2+1) × (n3+1)` table with zeros.
3. For each `i` in `[1..n1]`, `j` in `[1..n2]`, `k` in `[1..n3]`:

   * If `s1[i-1] == s2[j-1] == s3[k-1]`, then

     $$
       dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
     $$
   * Otherwise,

     $$
       dp[i][j][k] = \max\bigl(dp[i-1][j][k],\,dp[i][j-1][k],\,dp[i][j][k-1]\bigr).
     $$
4. Return `dp[n1][n2][n3]`.

```cpp
class Solution {
  public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        vector<vector<vector<int>>> dp(
            n1 + 1,
            vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0))
        );
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                        dp[i][j][k] = 1 + dp[i - 1][j - 1][k - 1];
                    else
                        dp[i][j][k] = max({
                            dp[i - 1][j][k],
                            dp[i][j - 1][k],
                            dp[i][j][k - 1]
                        });
                }
            }
        }
        return dp[n1][n2][n3];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n1 × n2 × n3) — three nested loops.
* **Auxiliary Space:** 💾 O(n1 × n2 × n3) — full 3D DP table.

### ✅ **Why This Approach?**

* Directly generalizes 2-string LCS to three dimensions.
* Conceptually straightforward—each state references the previous layer for matching or skipping.


## 📊 **3️⃣ Recursive + Memoization**

### **Algorithm Steps:**

1. Define a recursive function `solve(i, j, k)` that returns LCS length up to indices `i`, `j`, `k` (0-based).
2. Base case: if any of `i`, `j`, or `k` is `< 0`, return 0.
3. Use a 3D memo table `memo[i][j][k]`, initialized to `-1`.
4. If `s1[i] == s2[j] == s3[k]`, then

   $$
     \text{memo}[i][j][k] = 1 + \text{solve}(i-1, j-1, k-1);
   $$

   Otherwise,

   $$
     \text{memo}[i][j][k] = \max\bigl(
       \text{solve}(i-1, j, k),\,
       \text{solve}(i, j-1, k),\,
       \text{solve}(i, j, k-1)
     \bigr).
   $$
5. Return `memo[n1-1][n2-1][n3-1]`.

```cpp
class Solution {
  public:
    int dp[101][101][101]; 

    int solve(int i, int j, int k, const string& s1, const string& s2, const string& s3) {
        if (i < 0 || j < 0 || k < 0) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (s1[i] == s2[j] && s2[j] == s3[k])
            return dp[i][j][k] = 1 + solve(i - 1, j - 1, k - 1, s1, s2, s3);
        return dp[i][j][k] = max({
            solve(i - 1, j, k, s1, s2, s3),
            solve(i, j - 1, k, s1, s2, s3),
            solve(i, j, k - 1, s1, s2, s3)
        });
    }

    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        memset(dp, -1, sizeof(dp));
        return solve(n1 - 1, n2 - 1, n3 - 1, s1, s2, s3);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n1 × n2 × n3) — each `(i,j,k)` computed once via memo.
* **Auxiliary Space:** 💾 O(n1 × n2 × n3) — memo table plus recursion stack.

### ✅ **Why This Approach?**

* Expresses the problem in a recursive decision-tree style.
* Memoization avoids redundant computations of overlapping subproblems.



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                 | ⏱️ **Time Complexity** | 💾 **Space Complexity**    | ✅ **Pros**                                         | ⚠️ **Cons**                                 |
| ------------------------------- | ---------------------- | -------------------------- | -------------------------------------------------- | ------------------------------------------- |
| 🎯 **2D DP + Swap (Optimized)** | 🟢 O(n1 × n2 × n3)     | 🟢 O(n2 × n3)              | Low memory (only two 2D layers), easy to implement | Still O(n1·n2·n3) runtime                   |
| 🧮 **Full 3D DP Table**         | 🟢 O(n1 × n2 × n3)     | 🔴 O(n1 × n2 × n3)         | Conceptually simple 3D extension                   | Very high memory usage for large inputs     |
| 🔁 **Recursive + Memoization**  | 🟢 O(n1 × n2 × n3)     | 🔴 O(n1 × n2 × n3) (stack) | Clear recursion logic, easy to reason              | Large recursion depth; high memory overhead |

### 🏆 **Best Choice by Scenario**

| 🎯 **Scenario**                                                | 🥇 **Recommended Approach** |
| -------------------------------------------------------------- | --------------------------- |
| 🌐 Moderate lengths where memory matters (n1·n2·n3 large)      | 🥇 Optimized 2D DP + Swap   |
| 📚 Educational or small inputs, prioritize clarity             | 🥈 Full 3D DP Table         |
| 💡 Recursive style or quick prototyping, small to medium sizes | 🥉 Recursive + Memoization  |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int lcsOf3(String s1, String s2, String s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        int[][] prev = new int[n2 + 1][n3 + 1];
        int[][] curr = new int[n2 + 1][n3 + 1];
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                for (int k = 1; k <= n3; ++k) {
                    if (s1.charAt(i - 1) == s2.charAt(j - 1) && 
                        s2.charAt(j - 1) == s3.charAt(k - 1))
                        curr[j][k] = 1 + prev[j - 1][k - 1];
                    else
                        curr[j][k] = Math.max(
                            Math.max(prev[j][k], curr[j - 1][k]),
                            curr[j][k - 1]
                        );
                }
            }
            int[][] temp = prev;
            prev = curr;
            curr = temp;
        }
        return prev[n2][n3];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def lcsOf3(self, s1, s2, s3):
        n1, n2, n3 = len(s1), len(s2), len(s3)
        prev = [[0] * (n3 + 1) for _ in range(n2 + 1)]
        curr = [[0] * (n3 + 1) for _ in range(n2 + 1)]
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                for k in range(1, n3 + 1):
                    if s1[i - 1] == s2[j - 1] == s3[k - 1]:
                        curr[j][k] = 1 + prev[j - 1][k - 1]
                    else:
                        curr[j][k] = max(
                            prev[j][k],
                            curr[j - 1][k],
                            curr[j][k - 1]
                        )
            prev, curr = curr, prev
        return prev[n2][n3]
```


## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
