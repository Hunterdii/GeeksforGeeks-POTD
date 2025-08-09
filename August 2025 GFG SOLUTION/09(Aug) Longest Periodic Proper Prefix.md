---
title: "🔤 Longest Periodic Proper Prefix | GFG Solution 🔍"
keywords🏷️: ["🔤 longest prefix", "🔍 Z-algorithm", "📍 string matching", "📈 prefix function", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Periodic Proper Prefix problem: find the length of longest periodic proper prefix using Z-algorithm technique. 🚀"
date: 📅 2025-08-09
---

# *09. Longest Periodic Proper Prefix*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1)

## **🧩 Problem Description**

Given a string `s`, find the length of the **longest periodic proper prefix** of `s`. If no such prefix exists, return `-1`.

A **periodic proper prefix** is a non-empty prefix of `s` (but not the whole string), such that repeating this prefix enough times produces a string that starts with `s`.

## **📘 Examples**

### Example 1

```cpp
Input: s = "aaaaaa"
Output: 5
Explanation: Repeating the proper prefix "aaaaa" forms "aaaaaaaaaa...", which contains "aaaaaa" as a prefix. No longer proper prefix satisfies this.
```

### Example 2

```cpp
Input: s = "abcab"
Output: 3
Explanation: Repeating the proper prefix "abc" forms "abcabc...", which contains "abcab" as a prefix. No longer proper prefix satisfies this.
```

### Example 3

```cpp
Input: s = "ababd"
Output: -1
Explanation: No proper prefix satisfying the given condition.
```

## **🔒 Constraints**

* $1 \le s.size() \le 10^5$
* `s` consists of lowercase English alphabets

## **✅ My Approach**

The optimal approach uses the **Z-algorithm** to efficiently find all positions where a prefix of the string matches a suffix starting at that position:

### **Z-Algorithm Based Solution**

1. **Z-Array Construction:**
   * Build a Z-array where `z[i]` represents the length of the longest substring starting from `s[i]` which is also a prefix of `s`.
   * Use the efficient Z-algorithm with left (`l`) and right (`r`) pointers to maintain the rightmost Z-box.

2. **Key Insight:**
   * For a periodic proper prefix, we need to find the largest index `i` such that:
     - `z[i] == n - i` (the suffix starting at position `i` matches the prefix)
     - `i < n` (ensuring it's a proper prefix, not the entire string)

3. **Algorithm Steps:**
   * Initialize `z[0] = 0` (by convention, as we start from index 1).
   * For each position `i` from 1 to n-1:
     - If `i` is within the current Z-box (`i <= r`), use previously computed values.
     - Extend the match as far as possible using character comparisons.
     - Update the Z-box boundaries if necessary.
     - Check if `z[i] == n - i` and update the answer.

4. **Finding the Answer:**
   * Iterate through all positions and find the largest `i` where `z[i] == n - i`.
   * This indicates that the prefix of length `i` is periodic.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. The Z-algorithm processes each character at most twice due to the sliding window approach with left and right pointers.
* **Expected Auxiliary Space Complexity:** O(n), as we maintain a Z-array of size n to store the Z-values for each position.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getLongestPrefix(string s) {
        int n = s.size(), l = 0, r = 0, ans = -1;
        vector<int> z(n);
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
            if (z[i] == n - i) ans = i;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Brute Force with Period Checking(TLE)**

### 💡 Algorithm Steps:

1. For each possible prefix length from n-1 down to 1.
2. Extract the prefix and check if repeating it generates a string that starts with the original string.
3. Return the first (longest) valid prefix found.

```cpp
class Solution {
public:
    int getLongestPrefix(string s) {
        int n = s.length();
        for (int len = n - 1; len >= 1; len--) {
            string prefix = s.substr(0, len);
            string repeated = "";
            while (repeated.length() < n) {
                repeated += prefix;
            }
            if (repeated.substr(0, n) == s) {
                return len;
            }
        }
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - worst case
* **Auxiliary Space:** 💾 O(n)

### ⚠️ **Why Not This Approach?**

* Too slow for large inputs.
* Multiple string operations make it inefficient.
* Not suitable for competitive programming.

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1120 test cases due to time constraints).



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Z-Algorithm**                | 🟢 O(n)                | 🟡 O(n)                 | ⚡ Optimal, direct pattern matching | 🧮 Requires Z-algorithm knowledge    |
| 🔺 **Brute Force**                | 🔴 O(n³)               | 🟡 O(n)                 | 🎯 Easy to understand             | ⏰ Too slow for large inputs         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ **Competitive programming, optimal solution**   | 🥇 **Z-Algorithm**             | ★★★★★                     |
| 📚 **Learning purposes only**                     | 🥈 **Brute Force**             | ★☆☆☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int getLongestPrefix(String s) {
        int n = s.length(), l = 0, r = 0, ans = -1;
        int[] z = new int[n];
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = Math.min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s.charAt(z[i]) == s.charAt(i + z[i])) z[i]++;
            if (i + z[i] - 1 > r) { l = i; r = i + z[i] - 1; }
            if (z[i] == n - i) ans = i;
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getLongestPrefix(self, s):
        n, l, r, ans = len(s), 0, 0, -1
        z = [0] * n
        for i in range(1, n):
            if i <= r:
                z[i] = min(r - i + 1, z[i - l])
            while i + z[i] < n and s[z[i]] == s[i + z[i]]:
                z[i] += 1
            if i + z[i] - 1 > r:
                l, r = i, i + z[i] - 1
            if z[i] == n - i:
                ans = i
        return ans
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
