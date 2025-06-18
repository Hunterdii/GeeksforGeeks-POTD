---
title: "🎯 All Palindromic Partitions | GFG Solution 🔍"
keywords🏷️: ["🎯 palindrome partitions", "🔍 dynamic programming", "📍 backtracking", "📈 string processing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to All Palindromic Partitions problem: find all ways to partition string into palindromic substrings using DP preprocessing and backtracking. 🚀"
date: 📅 2025-06-18
---

# *18. All Palindromic Partitions*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1)

## **🧩 Problem Description**

Given a string `s`, find all possible ways to partition it such that **every substring** in the partition is a **palindrome**.

A palindrome is a string that reads the same forward and backward.

## **📘 Examples**

### Example 1

```cpp
Input: s = "geeks"
Output: [[g, e, e, k, s], [g, ee, k, s]]
Explanation: [g, e, e, k, s] and [g, ee, k, s] are the only partitions of "geeks" where each substring is a palindrome.
```

### Example 2

```cpp
Input: s = "abcba"
Output: [[a, b, c, b, a], [a, bcb, a], [abcba]]
Explanation: [a, b, c, b, a], [a, bcb, a] and [abcba] are the only partitions of "abcba" where each substring is a palindrome.
```

## **🔒 Constraints**

* $1 \le s.size() \le 20$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming Preprocessing** combined with **Backtracking** to efficiently find all palindromic partitions:

### **DP Preprocessing + Backtracking**

1. **Preprocessing Phase:**
   * Build a 2D DP table `d[i][j]` to precompute whether substring `s[i...j]` is a palindrome.
   * Fill single characters (always palindromes).
   * Fill pairs of characters.
   * Fill longer substrings using the recurrence: `d[i][j] = (s[i] == s[j]) && d[i+1][j-1]`.

2. **Backtracking Phase:**
   * Start from index 0 and try all possible partitions.
   * For each position, check all substrings starting from that position.
   * If a substring is palindromic (using precomputed table), add it to current partition and recurse.
   * When we reach the end of string, add the current partition to results.
   * Backtrack by removing the last added substring.

3. **Optimization Benefits:**
   * O(1) palindrome checks during backtracking.
   * Avoids redundant palindrome computations.
   * Clean separation of concerns between preprocessing and partition generation.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n² + 2ⁿ), where n is the string length. The DP preprocessing takes O(n²) to fill the palindrome table, and the backtracking generates at most 2ⁿ partitions (each character can either start a new partition or continue the current one).
* **Expected Auxiliary Space Complexity:** O(n²), as we use a 2D DP table of size n×n to store palindrome information. The recursion depth is O(n) and the space for storing results is not counted in auxiliary space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        vector<vector<bool>> d(n, vector<bool>(n));
        for (int i = 0; i < n; i++) d[i][i] = true;
        for (int i = 0; i < n - 1; i++) d[i][i + 1] = s[i] == s[i + 1];
        for (int l = 3; l <= n; l++)
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = s[i] == s[j] && d[i + 1][j - 1];
            }
        vector<vector<string>> r;
        vector<string> c;
        function<void(int)> b = [&](int i) {
            if (i == n) { r.push_back(c); return; }
            for (int j = i; j < n; j++)
                if (d[i][j]) {
                    c.push_back(s.substr(i, j - i + 1));
                    b(j + 1);
                    c.pop_back();
                }
        };
        b(0);
        return r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Expand Around Centers**

### 💡 Algorithm Steps:

1. For each position, expand around center to find palindromes.
2. Build palindrome table using center expansion.
3. Use backtracking to generate all partitions.

```cpp
class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        vector<vector<bool>> p(n, vector<bool>(n, false));
        for (int c = 0; c < n; c++) {
            for (int l = c, r = c; l >= 0 && r < n && s[l] == s[r]; l--, r++) p[l][r] = true;
            for (int l = c, r = c + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) p[l][r] = true;
        }
        vector<vector<string>> res;
        vector<string> cur;
        function<void(int)> dfs = [&](int i) {
            if (i >= n) { res.push_back(cur); return; }
            for (int j = i; j < n; j++) {
                if (p[i][j]) {
                    cur.push_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    cur.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² + 2^n)
* **Auxiliary Space:** 💾 O(n²)

### ✅ **Why This Approach?**

* Natural palindrome detection pattern.
* Better cache locality during expansion.


## 🔄 **3️⃣ Recursive Backtracking Without Preprocessing**

### 💡 Algorithm Steps:

1. **No DP table.** Instead, use a helper `isPalindrome()` function.
2. During recursion, for every prefix of the string, check if it's a palindrome.
3. If it is, add to current path and recurse for remaining string.

```cpp
class Solution {
public:
    bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    vector<vector<string>> palinParts(string& s) {
        vector<vector<string>> res;
        vector<string> cur;

        function<void(int)> dfs = [&](int start) {
            if (start == s.size()) {
                res.push_back(cur);
                return;
            }
            for (int end = start; end < s.size(); end++) {
                if (isPalin(s, start, end)) {
                    cur.push_back(s.substr(start, end - start + 1));
                    dfs(end + 1);
                    cur.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × 2ⁿ) — palindrome check inside recursion
* **Space:** 💾 O(n) recursion depth

### ✅ **Why This Approach?**

* Very easy to write and understand.
* Best for small inputs or conceptual learning.



## 🚀 **4️⃣ Memoized DFS (Top-Down with Palindrome Cache)**

### 💡 Algorithm Steps:

1. Use a **memoization table** `dp[i][j]` to store palindromic results.
2. Use DFS with memoization to build partitions recursively.
3. Lazily compute palindromic checks only when needed.

```cpp
class Solution {
public:
    vector<vector<string>> palinParts(string& s) {
        int n = s.size();
        unordered_map<string, bool> palMemo;
        vector<vector<string>> res;
        vector<string> cur;

        auto isPal = [&](const string& sub) {
            if (palMemo.count(sub)) return palMemo[sub];
            int l = 0, r = sub.size() - 1;
            while (l < r) {
                if (sub[l++] != sub[r--]) return palMemo[sub] = false;
            }
            return palMemo[sub] = true;
        };

        function<void(int)> dfs = [&](int idx) {
            if (idx == s.size()) {
                res.push_back(cur);
                return;
            }
            for (int j = idx; j < s.size(); j++) {
                string part = s.substr(idx, j - idx + 1);
                if (isPal(part)) {
                    cur.push_back(part);
                    dfs(j + 1);
                    cur.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(2ⁿ × n)
* **Space:** 💾 O(n²) for cache

### ✅ **Why This Approach?**

* Trades space for speed using lazy palindrome checks.
* Useful when `s.length()` is moderate and substring reuse is frequent.


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**               | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**               | ⚠️ **Cons**                     |
| ----------------------------- | ---------------------- | ----------------------- | ------------------------ | ------------------------------- |
| 🔍 **Backtracking DP (Main)** | 🟢 O(n² + 2ⁿ)          | 🟢 O(n²)                | ⚡ Fast palindrome lookup | Uses extra space for DP table   |
| 🔄 **Expand Centers**         | 🟢 O(n² + 2ⁿ)          | 🟢 O(n²)                | 🔧 Natural detection     | Center expansion less intuitive |
| 🧩 **Plain Backtracking**     | 🟠 O(n × 2ⁿ)           | 🟢 O(n)                 | ✨ Simple, clean          | Slower due to repeated checks   |
| 🧠 **Memoized DFS**           | 🟢 O(2ⁿ × n)           | 🟠 O(n²)                | 💾 Avoids repeated work  | Slightly more complex           |



### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                          | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| ---------------------------------------- | ---------------------------- | ------------------------- |
| ⚡ High performance and speed             | 🥇 **Backtracking DP**       | ★★★★★                     |
| 🔧 Easy to implement                     | 🥈 **Plain Backtracking**    | ★★★★☆                     |
| 🧠 Efficient for overlapping palindromes | 🥉 **Memoized DFS**          | ★★★★☆                     |
| 🧪 Educational, visually intuitive       | 🏅 **Expand Centers**        | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public ArrayList<ArrayList<String>> palinParts(String s) {
        int n = s.length();
        boolean[][] d = new boolean[n][n];
        for (int i = 0; i < n; i++) d[i][i] = true;
        for (int i = 0; i < n - 1; i++) d[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
        for (int l = 3; l <= n; l++)
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = s.charAt(i) == s.charAt(j) && d[i + 1][j - 1];
            }
        ArrayList<ArrayList<String>> r = new ArrayList<>();
        ArrayList<String> c = new ArrayList<>();
        dfs(0, s, d, c, r);
        return r;
    }

    void dfs(int i, String s, boolean[][] d, ArrayList<String> c, ArrayList<ArrayList<String>> r) {
        if (i == s.length()) { r.add(new ArrayList<>(c)); return; }
        for (int j = i; j < s.length(); j++)
            if (d[i][j]) {
                c.add(s.substring(i, j + 1));
                dfs(j + 1, s, d, c, r);
                c.remove(c.size() - 1);
            }
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def palinParts(self, s):
        n = len(s)
        d = [[False]*n for _ in range(n)]
        for i in range(n): d[i][i] = True
        for i in range(n-1): d[i][i+1] = s[i] == s[i+1]
        for l in range(3, n+1):
            for i in range(n-l+1):
                j = i + l - 1
                d[i][j] = s[i] == s[j] and d[i+1][j-1]
        r = []
        def b(i, c):
            if i == n: r.append(c[:]); return
            for j in range(i, n):
                if d[i][j]:
                    c.append(s[i:j+1])
                    b(j+1, c)
                    c.pop()
        b(0, [])
        return r
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
