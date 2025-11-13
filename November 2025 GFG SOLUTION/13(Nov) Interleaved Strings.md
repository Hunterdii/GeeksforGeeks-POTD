---
title: "🔀 Interleaved Strings | GFG Solution 🔍"
keywords🏷️: ["🔀 interleaved strings", "🔍 dynamic programming", "📍 string matching", "📈 memoization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Interleaved Strings problem: determine if string s3 is formed by interleaving s1 and s2 while maintaining character order using dynamic programming. 🚀"
date: 📅 2025-11-13
---

# *13. Interleaved Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/interleaved-strings/1)

## **🧩 Problem Description**

Given strings `s1`, `s2`, and `s3`, find whether `s3` is formed by an **interleaving** of `s1` and `s2`.

Interleaving of two strings `s1` and `s2` is a way to mix their characters to form a new string `s3`, while maintaining the relative order of characters from `s1` and `s2`.

**Conditions for interleaving:**
- Characters from `s1` must appear in the same order in `s3` as they are in `s1`.
- Characters from `s2` must appear in the same order in `s3` as they are in `s2`.
- The length of `s3` must be equal to the combined length of `s1` and `s2`.

## **📘 Examples**

### Example 1

```cpp
Input: s1 = "AAB", s2 = "AAC", s3 = "AAAABC"
Output: true
Explanation: The string "AAAABC" has all characters of the other two strings and in the same order.
```

### Example 2

```cpp
Input: s1 = "AB", s2 = "C", s3 = "ACB"
Output: true
Explanation: s3 has all characters of s1 and s2 and retains order of characters of s1.
```

### Example 3

```cpp
Input: s1 = "YX", s2 = "X", s3 = "XXY"
Output: false
Explanation: "XXY" is not interleaved of "YX" and "X". The strings that can be formed are YXX and XYX.
```

## **🔒 Constraints**

* $1 \le \text{s1.length, s2.length} \le 300$
* $1 \le \text{s3.length} \le 600$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with Space Optimization** to efficiently determine if `s3` can be formed by interleaving `s1` and `s2`:

### **1D Dynamic Programming (Space Optimized)**

1. **Initial Check:**
   * Verify if the total length of `s1` and `s2` equals the length of `s3`. If not, return false immediately.

2. **DP Array Setup:**
   * Use a 1D boolean array `dp` of size `m+1` (where `m` is the length of `s2`).
   * `dp[j]` represents whether the first `i` characters of `s1` and first `j` characters of `s2` can interleave to form the first `i+j` characters of `s3`.

3. **Base Case:**
   * `dp[0] = true` (empty strings can interleave to form empty string).
   * Initialize first row: Check if `s2` alone can form the beginning of `s3`.

4. **DP Transition:**
   * For each position `(i, j)`, check two possibilities:
     - Take character from `s1`: `dp[j]` remains true if previous state was true AND current `s1` character matches `s3`.
     - Take character from `s2`: `dp[j-1]` was true AND current `s2` character matches `s3`.
   * Update `dp[j]` using OR logic of both possibilities.

5. **Result:**
   * Return `dp[m]` which indicates if entire `s1` and `s2` can interleave to form `s3`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × m), where n is the length of `s1` and m is the length of `s2`. We fill a DP table of size n × m, processing each cell once.
* **Expected Auxiliary Space Complexity:** O(m), as we use a 1D array of size m+1 for space-optimized dynamic programming, avoiding the O(n × m) space of a full 2D DP table.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<bool> dp(m + 1);
        dp[0] = true;
        for (int j = 1; j <= m; j++) dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
            for (int j = 1; j <= m; j++)
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
        return dp[m];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ BFS Queue-Based Approach**

### 💡 Algorithm Steps:

1. Use breadth-first search to explore all possible interleaving paths.
2. Track visited states using a set to avoid redundant computation.
3. Each state represents current positions in both strings.
4. Return true if we successfully reach the end of all strings.

```cpp
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;
        q.push({0, 0});
        vis.insert({0, 0});
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if (i == n && j == m) return true;
            if (i < n && s1[i] == s3[i + j] && !vis.count({i + 1, j})) {
                q.push({i + 1, j});
                vis.insert({i + 1, j});
            }
            if (j < m && s2[j] == s3[i + j] && !vis.count({i, j + 1})) {
                q.push({i, j + 1});
                vis.insert({i, j + 1});
            }
        }
        return false;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m) - Visit each state at most once
* **Auxiliary Space:** 💾 O(n×m) - Queue and visited set storage

### ✅ **Why This Approach?**

* Intuitive path exploration visualization
* Natural state transition tracking
* Easy to debug and trace execution flow

> **Note:** This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1111 test cases due to time constraints).

## 📊 **3️⃣ Recursive Memoization (Top-Down DP)**

### 💡 Algorithm Steps:

1. Use recursion to try both choices at each position.
2. Cache results in a memoization map to avoid recomputation.
3. Base cases handle when either string is exhausted.
4. Combine results from taking character from either string.

```cpp
class Solution {
    unordered_map<string, bool> memo;
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return solve(s1, s2, s3, 0, 0, 0);
    }
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k) {
        if (k == s3.size()) return i == s1.size() && j == s2.size();
        string key = to_string(i) + "," + to_string(j);
        if (memo.count(key)) return memo[key];
        bool res = false;
        if (i < s1.size() && s1[i] == s3[k]) res = solve(s1, s2, s3, i + 1, j, k + 1);
        if (!res && j < s2.size() && s2[j] == s3[k]) res = solve(s1, s2, s3, i, j + 1, k + 1);
        return memo[key] = res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m) - Each subproblem computed once
* **Auxiliary Space:** 💾 O(n×m) - Recursion stack and memoization map

### ✅ **Why This Approach?**

* Top-down thinking matches problem intuition
* Easy to convert from naive recursion
* Good for explaining DP concept in interviews

## 📊 **4️⃣ 2D Bottom-Up DP**

### 💡 Algorithm Steps:

1. Create a 2D DP table where dp[i][j] represents if first i chars of s1 and j chars of s2 interleave to form first i+j chars of s3.
2. Initialize base case for empty strings.
3. Fill first row and column for single string matches.
4. Fill remaining cells using transition from previous states.

```cpp
class Solution {
public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        int n = s1.size(), m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        for (int j = 1; j <= m; j++) dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        return dp[n][m];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n×m) - Fill entire DP table once
* **Auxiliary Space:** 💾 O(n×m) - 2D DP table storage

### ✅ **Why This Approach?**

* Complete state visibility for debugging
* Classic DP pattern implementation
* Foundation for space-optimized version

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **1D DP (Space Optimized)**   | 🟢 O(n×m)              | 🟢 O(m)                 | 🚀 Optimal space usage            | 🔧 Less intuitive state tracking     |
| 🔍 **BFS Queue-Based**            | 🟢 O(n×m)              | 🟡 O(n×m)               | 📖 Clear path visualization       | ⚠️ TLE on large inputs               |
| 📊 **Recursive Memoization**      | 🟢 O(n×m)              | 🟡 O(n×m)               | 🎯 Natural problem decomposition  | 🐌 Stack overflow risk for large inputs |
| 🔄 **2D Bottom-Up DP**            | 🟢 O(n×m)              | 🟡 O(n×m)               | ⭐ Easy to understand and verify  | 💾 Uses more space than needed       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production/Optimal performance**                 | 🥇 **1D DP Space Optimized**         | ★★★★★                     |
| 📖 **Learning/Interview explanation**                 | 🥈 **2D Bottom-Up DP**               | ★★★★☆                     |
| 🔧 **Debugging complex cases**                        | 🥉 **Recursive Memoization**         | ★★★★☆                     |
| 🎯 **Understanding state transitions**                | 🏅 **BFS Queue-Based**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        int n = s1.length(), m = s2.length();
        boolean[] dp = new boolean[m + 1];
        dp[0] = true;
        for (int j = 1; j <= m; j++) dp[j] = dp[j - 1] && s2.charAt(j - 1) == s3.charAt(j - 1);
        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && s1.charAt(i - 1) == s3.charAt(i - 1);
            for (int j = 1; j <= m; j++)
                dp[j] = (dp[j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
        }
        return dp[m];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isInterleave(self, s1, s2, s3):
        if len(s1) + len(s2) != len(s3): return False
        n, m = len(s1), len(s2)
        dp = [False] * (m + 1)
        dp[0] = True
        for j in range(1, m + 1): dp[j] = dp[j - 1] and s2[j - 1] == s3[j - 1]
        for i in range(1, n + 1):
            dp[0] = dp[0] and s1[i - 1] == s3[i - 1]
            for j in range(1, m + 1):
                dp[j] = (dp[j] and s1[i - 1] == s3[i + j - 1]) or (dp[j - 1] and s2[j - 1] == s3[i + j - 1])
        return dp[m]
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
