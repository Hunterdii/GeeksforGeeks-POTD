---
title: "🔍 Minimum Window Subsequence | GFG Solution 🎯"
keywords🏷️: ["🔍 minimum window", "📍 two pointers", "🔄 sliding window", "📘 GFG", "🏁 competitive programming", "📚 DSA", "subsequence"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Minimum Window Subsequence problem: find the smallest substring in s1 that contains s2 as a subsequence using greedy backtracking and two-pointer techniques. 🚀"
date: 📅 2025-01-11
---

# *11. Minimum Window Subsequence*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1)

## **🧩 Problem Description**

You are given two strings, `s1` and `s2`. Your task is to find the **smallest substring** in `s1` such that `s2` appears as a **subsequence** within that substring.

- The characters of `s2` must appear in the same sequence within the substring of `s1`.
- If there are multiple valid substrings of the same minimum length, return the one that appears first in `s1`.
- If no such substring exists, return an empty string.

**Note:** Both the strings contain only lowercase English letters.

## **📘 Examples**

### Example 1

```cpp
Input: s1 = "geeksforgeeks", s2 = "eksrg"
Output: "eksforg"
Explanation: "eksforg" satisfies all required conditions. s2 is its subsequence and it is 
smallest and leftmost among all possible valid substrings of s1.
```

### Example 2

```cpp
Input: s1 = "abcdebdde", s2 = "bde" 
Output: "bcde"
Explanation: "bcde" and "bdde" are two substrings of s1 where s2 occurs as subsequence 
but "bcde" occurs first so we return that.
```

### Example 3

```cpp
Input: s1 = "ad", s2 = "b" 
Output: ""
Explanation: There is no substring that exists.
```

## **🔒 Constraints**

* $1 \le \text{s1.length} \le 10^4$
* $1 \le \text{s2.length} \le 50$

## **✅ My Approach**

The optimal approach uses a **Greedy Backtracking with Two-Pointer** technique to efficiently find the minimum window subsequence:

### **Greedy Backtracking Strategy**

1. **Forward Pass - Find Complete Subsequence:**
   * Use two pointers: `i` for `s1` and `j` for `s2`.
   * Move `i` forward through `s1`, incrementing `j` whenever characters match.
   * When `j` reaches the end of `s2`, we've found a valid window endpoint.

2. **Backward Pass - Minimize Window:**
   * Once a complete subsequence is found, backtrack from the current position.
   * Move `i` backward while decrementing `j` to find the leftmost starting position.
   * This gives us the minimum window for this particular endpoint.

3. **Track Minimum Window:**
   * Compare the current window length with the global minimum.
   * Update the result if a smaller window is found.
   * Continue the forward pass to explore other potential windows.

4. **Optimization:**
   * After each backtrack, resume the forward search from the optimized starting position.
   * This ensures we don't miss any potentially smaller windows.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(m × n), where m is the length of `s1` and n is the length of `s2`. In the worst case, for each character in `s1`, we might backtrack through the entire subsequence `s2`.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for pointers and variables, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        int start = -1, minLen = INT_MAX;
        for (int i = 0, j = 0; i < m; i++) {
            if (s1[i] == s2[j]) j++;
            if (j == n) {
                int end = i;
                j--;
                while (j >= 0) {
                    if (s1[i] == s2[j]) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Build a DP table storing the starting index of each character match.
2. For each position, track where the subsequence starting point is.
3. Iterate through all valid endpoints to find minimum window.
4. Return the smallest substring containing the subsequence.

```cpp
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            if (s1[i] == s2[0]) dp[i][0] = i;
            else if (i > 0) dp[i][0] = dp[i-1][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j];
            }
        }
        int start = -1, minLen = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[i][n-1] != -1) {
                int len = i - dp[i][n-1] + 1;
                if (len < minLen) {
                    minLen = len;
                    start = dp[i][n-1];
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Fill entire DP table
* **Auxiliary Space:** 💾 O(m × n) - 2D DP array storage

### ✅ **Why This Approach?**

* Systematic tabulation of all possibilities
* Clear state transitions and relationships
* Works well for understanding the problem structure

## 📊 **3️⃣ Next Index Tracking**

### 💡 Algorithm Steps:

1. Precompute next occurrence of each character from every position.
2. For each starting position, greedily find the closest match.
3. Track the minimum window length during traversal.
4. Use next index array for O(1) character lookups.

```cpp
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> next(m+1, vector<int>(26, -1));
        for (int i = m-1; i >= 0; i--) {
            next[i] = next[i+1];
            next[i][s1[i]-'a'] = i;
        }
        int start = -1, minLen = INT_MAX;
        for (int i = 0; i < m; i++) {
            int pos = i, j = 0;
            while (j < n && pos < m) {
                pos = next[pos][s2[j]-'a'];
                if (pos == -1) break;
                j++;
                if (j < n) pos++;
            }
            if (j == n) {
                int len = pos - i + 1;
                if (len < minLen) {
                    minLen = len;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Preprocess and search
* **Auxiliary Space:** 💾 O(26m) - Next index arrays

### ✅ **Why This Approach?**

* Efficient character lookup with preprocessing
* Good for multiple queries on same string
* Optimized for alphabet size consideration

## 📊 **4️⃣ Two-Pointer Sliding Window**

### 💡 Algorithm Steps:

1. Use two pointers to expand and contract the window.
2. Expand right pointer to include all characters of s2.
3. Contract left pointer to minimize window size.
4. Track minimum valid window throughout the process.

```cpp
class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int m = s1.size(), n = s2.size();
        int start = -1, minLen = INT_MAX;
        int i = 0, j = 0;
        while (i < m) {
            if (s1[i] == s2[j]) {
                j++;
                if (j == n) {
                    int end = i;
                    j--;
                    while (j >= 0) {
                        if (s1[i] == s2[j]) j--;
                        i--;
                    }
                    i++;
                    if (end - i + 1 < minLen) {
                        minLen = end - i + 1;
                        start = i;
                    }
                    j = 0;
                }
            }
            i++;
        }
        return start == -1 ? "" : s1.substr(start, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m × n) - Worst case backtracking
* **Auxiliary Space:** 💾 O(1) - Constant extra space

### ✅ **Why This Approach?**

* Space efficient with minimal memory usage
* Natural sliding window pattern application
* Intuitive expand and contract logic

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Greedy Backtrack**           | 🟢 O(m × n)            | 🟢 O(1)                 | 🚀 Optimal space usage            | 🔧 Complex backtracking logic        |
| 🔍 **Dynamic Programming**         | 🟡 O(m × n)            | 🟡 O(m × n)             | 📖 Clear state transitions        | 💾 High memory usage                 |
| 📊 **Next Index Tracking**         | 🟡 O(m × n)            | 🟡 O(26m)               | 🎯 Fast character lookup          | 💾 Extra preprocessing needed        |
| 🔄 **Two-Pointer Sliding**         | 🟡 O(m × n)            | 🟢 O(1)                 | ⭐ Intuitive window logic         | 🐌 May revisit positions             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Memory-constrained systems**                    | 🥇 **Greedy Backtrack**              | ★★★★★                     |
| 📖 **Learning DP patterns**                          | 🥈 **Dynamic Programming**           | ★★★★☆                     |
| 🔧 **Multiple queries on same text**                 | 🥉 **Next Index Tracking**           | ★★★★☆                     |
| 🎯 **Interview scenarios**                           | 🏅 **Two-Pointer Sliding**           | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String minWindow(String s1, String s2) {
        int m = s1.length(), n = s2.length();
        int start = -1, minLen = Integer.MAX_VALUE;
        for (int i = 0, j = 0; i < m; i++) {
            if (s1.charAt(i) == s2.charAt(j)) j++;
            if (j == n) {
                int end = i;
                j--;
                while (j >= 0) {
                    if (s1.charAt(i) == s2.charAt(j)) j--;
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }
        return start == -1 ? "" : s1.substring(start, start + minLen);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minWindow(self, s1, s2):
        m, n = len(s1), len(s2)
        start, minLen = -1, float('inf')
        i = j = 0
        while i < m:
            if s1[i] == s2[j]:
                j += 1
            if j == n:
                end = i
                j -= 1
                while j >= 0:
                    if s1[i] == s2[j]:
                        j -= 1
                    i -= 1
                i += 1
                j += 1
                if end - i + 1 < minLen:
                    minLen = end - i + 1
                    start = i
            i += 1
        return "" if start == -1 else s1[start:start + minLen]
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
