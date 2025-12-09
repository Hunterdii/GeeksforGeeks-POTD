---
title: "🎭 Wildcard Pattern Matching | GFG Solution 🎯"
keywords🏷️: ["🎭 pattern matching", "🔍 dynamic programming", "📍 wildcard", "📈 string matching", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Wildcard Pattern Matching problem: determine if a pattern with wildcards ('?' and '*') matches a given text using dynamic programming. 🚀"
date: 📅 2025-11-12
---

# *12. Wildcard Pattern Matching*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1)

## **🧩 Problem Description**

Given two strings `txt` and `pat` which may be of different sizes, you have to return `true` if the wildcard pattern `pat` matches with `txt`, else return `false`.

The wildcard pattern `pat` can include the characters `'?'` and `'*'`:
- `'?'` – matches any single character.
- `'*'` – matches any sequence of characters (including the empty sequence).

**Note:** The matching should cover the entire `txt` (not partial `txt`).

## **📘 Examples**

### Example 1

```cpp
Input: txt = "abcde", pat = "a?c*"
Output: true
Explanation: '?' matches with 'b' and '*' matches with "de".
```

### Example 2

```cpp
Input: txt = "baaabab", pat = "a*ab"
Output: false
Explanation: The pattern starts with 'a', but the text starts with 'b', 
so the pattern does not match the text.
```

### Example 3

```cpp
Input: txt = "abc", pat = "*"
Output: true
Explanation: '*' matches with whole text "abc".
```

## **🔒 Constraints**

* $1 \le \text{txt.size()}, \text{pat.size()} \le 100$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with a 2D table to efficiently determine if the pattern matches the text:

### **Bottom-Up Dynamic Programming**

1. **Initialize DP Table:**
   * Create a 2D boolean array `dp[n+1][m+1]` where `n` is the length of text and `m` is the length of pattern.
   * `dp[i][j]` represents whether first `i` characters of text match first `j` characters of pattern.
   * Set `dp[0][0] = true` (empty pattern matches empty text).

2. **Handle Leading Stars:**
   * For pattern positions with `'*'`, if previous position matched empty text, current position also matches.
   * Fill first row: `dp[0][j] = dp[0][j-1]` if `pat[j-1] == '*'`.

3. **Fill DP Table:**
   * For each position `(i, j)`:
     - If `pat[j-1] == '*'`: Can match empty sequence `dp[i][j-1]` or match one/more characters `dp[i-1][j]`.
     - If `pat[j-1] == '?'` or characters match: Take diagonal value `dp[i-1][j-1]`.
     - Otherwise: No match, `dp[i][j] = false`.

4. **Return Result:**
   * Final answer is `dp[n][m]` indicating if entire text matches entire pattern.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n*m), where n is the length of the text and m is the length of the pattern. We fill each cell of the DP table exactly once.
* **Expected Auxiliary Space Complexity:** O(n*m), as we use a 2D DP table to store intermediate matching results for all subproblems.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') 
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (pat[j - 1] == '?' || txt[i - 1] == pat[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Space-Optimized DP Approach**

### 💡 Algorithm Steps:

1. Use two 1D arrays instead of 2D matrix to optimize space.
2. Current row depends only on previous row in DP table.
3. Swap between two arrays to track current and previous states.
4. Reduce space complexity from O(n*m) to O(m).

```cpp
class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat[j - 1] == '*') prev[j] = prev[j - 1];
        for (int i = 1; i <= n; i++) {
            curr[0] = false;
            for (int j = 1; j <= m; j++) {
                if (pat[j - 1] == '*') 
                    curr[j] = curr[j - 1] || prev[j];
                else if (pat[j - 1] == '?' || txt[i - 1] == pat[j - 1]) 
                    curr[j] = prev[j - 1];
                else curr[j] = false;
            }
            swap(prev, curr);
        }
        return prev[m];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Linear scan through both strings
* **Auxiliary Space:** 💾 O(m) - Only two 1D arrays needed

### ✅ **Why This Approach?**

* Significant space optimization for large inputs
* Maintains same time complexity as 2D approach
* Better cache locality with 1D arrays

## 📊 **3️⃣ Greedy Two-Pointer Approach**

### 💡 Algorithm Steps:

1. Use two pointers to traverse text and pattern simultaneously.
2. Track last star position for backtracking when mismatch occurs.
3. When star is found, remember positions for potential backtracking.
4. If mismatch and no star available, return false immediately.

```cpp
class Solution {
public:
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        int i = 0, j = 0, star = -1, match = 0;
        while (i < n) {
            if (j < m && (pat[j] == '?' || txt[i] == pat[j])) {
                i++; j++;
            } else if (j < m && pat[j] == '*') {
                star = j++; match = i;
            } else if (star != -1) {
                j = star + 1; i = ++match;
            } else return false;
        }
        while (j < m && pat[j] == '*') j++;
        return j == m;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Worst case with backtracking
* **Auxiliary Space:** 💾 O(1) - Only few pointer variables

### ✅ **Why This Approach?**

* Optimal space complexity with constant space
* Fast for most practical cases with few stars
* No recursion or DP table overhead

## 📊 **4️⃣ Memoized Recursion Approach**

### 💡 Algorithm Steps:

1. Use top-down recursion with memoization for clarity.
2. Store computed subproblems in DP table to avoid recomputation.
3. Handle base cases for empty text and pattern explicitly.
4. Recursively match characters or handle wildcards with memoization.

```cpp
class Solution {
public:
    bool solve(string &txt, string &pat, int i, int j, vector<vector<int>> &dp) {
        if (j == 0) return i == 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == 0) {
            for (int k = 0; k < j; k++) 
                if (pat[k] != '*') return dp[i][j] = 0;
            return dp[i][j] = 1;
        }
        if (txt[i - 1] == pat[j - 1] || pat[j - 1] == '?')
            return dp[i][j] = solve(txt, pat, i - 1, j - 1, dp);
        if (pat[j - 1] == '*')
            return dp[i][j] = solve(txt, pat, i, j - 1, dp) || solve(txt, pat, i - 1, j, dp);
        return dp[i][j] = 0;
    }
    bool wildCard(string &txt, string &pat) {
        int n = txt.size(), m = pat.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(txt, pat, n, m, dp);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n*m) - Each state computed once
* **Auxiliary Space:** 💾 O(n*m) - DP table plus recursion stack

### ✅ **Why This Approach?**

* Natural recursive thinking pattern
* Easy to understand problem breakdown
* Direct translation from problem statement

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Bottom-Up DP**              | 🟢 O(n*m)              | 🟡 O(n*m)               | 🚀 Clear iterative logic          | 💾 Higher space usage                |
| 🔍 **Space-Optimized DP**         | 🟢 O(n*m)              | 🟢 O(m)                 | 💾 Reduced space                  | 🔧 Slightly complex state management |
| 📊 **Greedy Two-Pointer**         | 🟡 O(n*m)              | 🟢 O(1)                 | ⭐ Constant space                 | 🐌 Backtracking overhead             |
| 🔄 **Memoized Recursion**         | 🟢 O(n*m)              | 🟡 O(n*m)               | 📖 Intuitive recursive logic      | 🔧 Recursion stack overhead          |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Balanced performance**                           | 🥇 **Bottom-Up DP**                  | ★★★★★                     |
| 📖 **Memory-constrained systems**                    | 🥈 **Greedy Two-Pointer**            | ★★★★★                     |
| 🔧 **Large inputs with space limits**                | 🥉 **Space-Optimized DP**            | ★★★★☆                     |
| 🎯 **Interview/Learning**                            | 🏅 **Memoized Recursion**            | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean wildCard(String txt, String pat) {
        int n = txt.length(), m = pat.length();
        boolean[][] dp = new boolean[n + 1][m + 1];
        dp[0][0] = true;
        for (int j = 1; j <= m; j++) 
            if (pat.charAt(j - 1) == '*') dp[0][j] = dp[0][j - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (pat.charAt(j - 1) == '*') 
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (pat.charAt(j - 1) == '?' || txt.charAt(i - 1) == pat.charAt(j - 1)) 
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def wildCard(self, txt, pat):
        n, m = len(txt), len(pat)
        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[0][0] = True
        for j in range(1, m + 1):
            if pat[j - 1] == '*': dp[0][j] = dp[0][j - 1]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if pat[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                elif pat[j - 1] == '?' or txt[i - 1] == pat[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
        return dp[n][m]
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
