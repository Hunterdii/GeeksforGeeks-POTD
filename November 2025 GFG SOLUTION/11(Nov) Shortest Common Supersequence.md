---
title: "🔤 Shortest Common Supersequence | GFG Solution 📏"
keywords🏷️: ["🔤 supersequence", "📏 dynamic programming", "🔍 LCS", "📊 string algorithms", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Shortest Common Supersequence problem: find the length of smallest string containing both input strings as subsequences using dynamic programming. 🚀"
date: 📅 2025-11-11
---

# *11. Shortest Common Supersequence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1)

## **🧩 Problem Description**

Given two strings `s1` and `s2`, find the length of the **smallest string** which has both `s1` and `s2` as its subsequences.

A supersequence is a sequence that contains both strings as subsequences. The goal is to find the minimum length of such a supersequence where characters from both strings can be found in order (not necessarily contiguous).

**Note:** `s1` and `s2` can have both uppercase and lowercase English letters.

## **📘 Examples**

### Example 1

```cpp
Input: s1 = "geek", s2 = "eke"
Output: 5
Explanation: String "geeke" has both string "geek" and "eke" as subsequences.
```

### Example 2

```cpp
Input: s1 = "AGGTAB", s2 = "GXTXAYB"
Output: 9
Explanation: String "AGXGTXAYB" has both string "AGGTAB" and "GXTXAYB" as subsequences.
```

### Example 3

```cpp
Input: s1 = "geek", s2 = "ek"
Output: 4
Explanation: String "geek" has both string "geek" and "ek" as subsequences.
```

## **🔒 Constraints**

* $1 \le \text{s1.size(), s2.size()} \le 500$

## **✅ My Approach**

The optimal approach uses **Space-Optimized Dynamic Programming** to build the shortest common supersequence length:

### **Space-Optimized DP**

1. **Define DP State:**
   * `dp[i][j]` represents the length of shortest common supersequence for first `i` characters of `s1` and first `j` characters of `s2`.
   * To optimize space, use only two 1D arrays: `prev` and `curr`.

2. **Base Cases:**
   * If `s1` is empty (`i = 0`), we need all characters from `s2`, so length = `j`.
   * If `s2` is empty (`j = 0`), we need all characters from `s1`, so length = `i`.

3. **State Transitions:**
   * **If characters match** (`s1[i-1] == s2[j-1]`): Include the character once.
     * `curr[j] = 1 + prev[j-1]`
   * **If characters don't match**: Take minimum of two choices and add 1.
     * `curr[j] = 1 + min(prev[j], curr[j-1])`
     * `prev[j]` means skip current character from `s1`
     * `curr[j-1]` means skip current character from `s2`

4. **Iterate Through Strings:**
   * Process each character of both strings using nested loops.
   * Update `curr` array based on `prev` array values.
   * After processing each row, copy `curr` to `prev` for next iteration.

5. **Return Result:**
   * Final answer is stored in `prev[n]` after processing all characters.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(m × n), where m is the length of string s1 and n is the length of string s2. We iterate through all possible combinations of characters from both strings using nested loops, performing constant-time operations for each cell.
* **Expected Auxiliary Space Complexity:** O(n), where n is the length of string s2. We use two 1D arrays of size (n+1) to store previous and current row values, eliminating the need for a full 2D DP table and achieving space optimization.

## **🧑‍💻 Code (C)**

```c
int minSuperSeq(char *s1, char *s2) {
    int m = strlen(s1), n = strlen(s2);
    int prev[n + 1], curr[n + 1];
    for (int j = 0; j <= n; j++) prev[j] = j;
    for (int i = 1; i <= m; i++) {
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            curr[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev[j - 1] : 
                      1 + (prev[j] < curr[j - 1] ? prev[j] : curr[j - 1]);
        }
        for (int j = 0; j <= n; j++) prev[j] = curr[j];
    }
    return prev[n];
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1), curr(n + 1);
        for (int j = 0; j <= n; j++) prev[j] = j;
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                curr[j] = (s1[i - 1] == s2[j - 1]) ? 1 + prev[j - 1] : 
                          1 + min(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ LCS-Based Formula Approach**

### 💡 Algorithm Steps:

1. Calculate the length of Longest Common Subsequence (LCS) between two strings.
2. Use the formula: SCS length = m + n - LCS length.
3. This works because common characters need to be included only once.
4. Build LCS using standard dynamic programming approach.

```cpp
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return m + n - prev[n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Nested iteration through both strings
* **Auxiliary Space:** 💾 O(n) - Two 1D arrays for DP

### ✅ **Why This Approach?**

* Mathematical elegance using LCS formula
* Easy to understand relationship between LCS and SCS
* Reusable LCS logic for similar problems

## 📊 **3️⃣ 2D DP Table Approach**

### 💡 Algorithm Steps:

1. Create a 2D DP table where dp[i][j] represents SCS length for first i characters of s1 and first j characters of s2.
2. Initialize base cases: dp[0][j] = j and dp[i][0] = i.
3. For each cell, if characters match, add 1 to diagonal value.
4. If characters don't match, take minimum of left and top cells and add 1.

```cpp
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Double nested loop
* **Auxiliary Space:** 💾 O(m × n) - 2D DP table

### ✅ **Why This Approach?**

* Clear visualization of state transitions
* Easy to trace back for constructing actual supersequence
* Standard DP pattern for string problems

## 📊 **4️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Define recursive function that explores character matching decisions.
2. Base cases: if either string is empty, return length of other string.
3. If characters match, include once and recurse on remaining strings.
4. If not match, try both options and take minimum plus 1.

```cpp
class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>>& memo) {
        if (i == s1.size()) return s2.size() - j;
        if (j == s2.size()) return s1.size() - i;
        if (memo[i][j] != -1) return memo[i][j];
        if (s1[i] == s2[j])
            return memo[i][j] = 1 + solve(i + 1, j + 1, s1, s2, memo);
        return memo[i][j] = 1 + min(solve(i + 1, j, s1, s2, memo), 
                                     solve(i, j + 1, s1, s2, memo));
    }
    int minSuperSeq(string &s1, string &s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(0, 0, s1, s2, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Each state computed once with memoization
* **Auxiliary Space:** 💾 O(m × n) - Memoization table and recursion stack

### ✅ **Why This Approach?**

* Top-down approach easier to conceptualize
* Natural representation of decision tree
* Good for understanding problem structure

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Space Optimized DP**         | 🟢 O(m × n)            | 🟢 O(n)                 | 🚀 Optimal space usage            | 🔧 Cannot backtrack for actual string |
| 🔍 **LCS-Based Formula**          | 🟢 O(m × n)            | 🟢 O(n)                 | 📖 Mathematical elegance          | 🧮 Two-step computation              |
| 📊 **2D DP Table**                | 🟢 O(m × n)            | 🟡 O(m × n)             | 🎯 Easy to visualize              | 💾 Higher space usage                |
| 🔄 **Recursive Memoization**      | 🟢 O(m × n)            | 🟡 O(m × n)             | ⭐ Intuitive logic                | 🐌 Recursion overhead                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Space Optimized DP**            | ★★★★★                     |
| 📖 **Understanding problem structure**                | 🥈 **LCS-Based Formula**             | ★★★★☆                     |
| 🔧 **Need to construct actual string**                | 🥉 **2D DP Table**                   | ★★★★☆                     |
| 🎯 **Interview/Learning**                             | 🏅 **Recursive Memoization**         | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static int minSuperSeq(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int[] prev = new int[n + 1], curr = new int[n + 1];
        for (int j = 0; j <= n; j++) prev[j] = j;
        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                curr[j] = (s1.charAt(i - 1) == s2.charAt(j - 1)) ? 1 + prev[j - 1] : 
                          1 + Math.min(prev[j], curr[j - 1]);
            }
            prev = curr.clone();
        }
        return prev[n];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minSuperSeq(self, s1, s2):
        m, n = len(s1), len(s2)
        prev, curr = [0] * (n + 1), [0] * (n + 1)
        for j in range(n + 1): prev[j] = j
        for i in range(1, m + 1):
            curr[0] = i
            for j in range(1, n + 1):
                curr[j] = 1 + prev[j - 1] if s1[i - 1] == s2[j - 1] else 1 + min(prev[j], curr[j - 1])
            prev = curr[:]
        return prev[n]
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
