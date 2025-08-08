---
title: "🔢 Longest Prefix Suffix | GFG Solution 🔍"
keywords🏷️: ["🔢 longest prefix suffix", "🔍 KMP algorithm", "📍 pattern matching", "📈 LPS array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Prefix Suffix problem: find the length of longest proper prefix which is also a suffix using KMP's LPS array construction technique. 🚀"
date: 📅 2025-08-08
---

# *08. Longest Prefix Suffix*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-prefix-suffix2527/1)

## **🧩 Problem Description**

Given a string `s` of lowercase English alphabets, find the length of the **longest proper prefix** which is also a **suffix**.

**Note:** Prefix and suffix can be overlapping but they should not be equal to the entire string.

A proper prefix is a prefix that is not equal to the string itself. Similarly, a proper suffix is a suffix that is not equal to the string itself.

## **📘 Examples**

### Example 1

```cpp
Input: s = "abab"
Output: 2
Explanation: The string "ab" is the longest prefix and suffix.
```

### Example 2

```cpp
Input: s = "aabcdaabc"
Output: 4
Explanation: The string "aabc" is the longest prefix and suffix.
```

### Example 3

```cpp
Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest prefix and suffix.
```

## **🔒 Constraints**

* $1 \le s.size() \le 10^6$
* s contains only lowercase English alphabets.

## **✅ My Approach**

The optimal approach uses the **KMP (Knuth-Morris-Pratt) Algorithm's LPS Array Construction** technique:

### **KMP LPS Array Construction**

1. **Initialize Variables:**
   * Create an LPS array of size `n` where `lps[i]` stores the length of longest proper prefix which is also suffix for substring `s[0...i]`.
   * Use two pointers: `i` (current position) and `j` (length of current matching prefix).

2. **Build LPS Array:**
   * Start with `i = 1` and `j = 0` (since `lps[0]` is always 0).
   * If characters match (`s[i] == s[j]`), increment both pointers and set `lps[i] = j`.
   * If characters don't match and `j > 0`, move `j` to `lps[j-1]` (fallback position).
   * If characters don't match and `j == 0`, set `lps[i] = 0` and increment `i`.

3. **Extract Result:**
   * The answer is `lps[n-1]` which gives the length of longest proper prefix-suffix for the entire string.

4. **Key Insight:**
   * The LPS array construction efficiently handles all overlapping cases by using previously computed values.
   * Time complexity remains linear due to the amortized analysis of pointer movements.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Although there are nested loops, the inner while loop's total iterations across all outer loop iterations is bounded by n, making it linear overall.
* **Expected Auxiliary Space Complexity:** O(n), as we use an additional LPS array of size n to store the longest proper prefix-suffix lengths.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length(), j = 0;
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ) {
            if (s[i] == s[j]) lps[i++] = ++j;
            else if (j) j = lps[j - 1];
            else i++;
        }
        return lps[n - 1];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Rolling Hash Approach**

### 💡 Algorithm Steps:

1. Use double hashing with two different bases to avoid collisions.
2. Build prefix hash from left and suffix hash from right simultaneously.
3. Compare hash values at each position to find matching prefix-suffix pairs.
4. Track the maximum length where prefix hash equals suffix hash.

```cpp
class Solution {
public:
    int getLPSLength(string &s) {
        int b1 = 31, b2 = 37, m1 = 1e9+7, m2 = 1e9+9, n = s.size();
        long long p1 = 1, p2 = 1, h1 = 0, h2 = 0, r1 = 0, r2 = 0;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            h1 = (h1 + (s[i] - 'a' + 1) * p1) % m1;
            h2 = (h2 + (s[i] - 'a' + 1) * p2) % m2;
            r1 = (r1 * b1 + s[n - i - 1] - 'a' + 1) % m1;
            r2 = (r2 * b2 + s[n - i - 1] - 'a' + 1) % m2;
            if (h1 == r1 && h2 == r2) res = i + 1;
            p1 = p1 * b1 % m1;
            p2 = p2 * b2 % m2;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash computations
* **Auxiliary Space:** 💾 O(1) - Only constant variables used

### ✅ **Why This Approach?**

* Constant space complexity
* Good for very long strings
* Hash-based pattern matching technique

## 📊 **3️⃣ Brute Force with Optimization**

### 💡 Algorithm Steps:

1. Check each possible prefix-suffix pair starting from the longest.
2. Use early termination when mismatch is found.
3. Compare characters from both ends moving inward.
4. Return the first (longest) matching prefix-suffix length.

```cpp
class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length();
        for (int len = n - 1; len > 0; len--) {
            bool match = true;
            for (int i = 0; i < len; i++) {
                if (s[i] != s[n - len + i]) {
                    match = false;
                    break;
                }
            }
            if (match) return len;
        }
        return 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops for checking all possibilities
* **Auxiliary Space:** 💾 O(1) - No additional data structures

### ✅ **Why This Approach?**

* Simple and intuitive logic
* Space efficient implementation
* Good for small strings or educational purposes

## 📊 **4️⃣ Z-Algorithm Based Approach**

### 💡 Algorithm Steps:

1. Apply Z-algorithm to find all prefix matches throughout the string.
2. Check positions where Z[i] + i equals string length (suffix matches prefix).
3. Among all such positions, find the maximum Z[i] value.
4. This represents the longest proper prefix that is also a suffix.

```cpp
class Solution {
public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
        }
        int maxLPS = 0;
        for (int i = 1; i < n; i++) {
            if (i + z[i] == n) maxLPS = max(maxLPS, z[i]);
        }
        return maxLPS;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time Z-algorithm computation
* **Auxiliary Space:** 💾 O(n) - Z-array storage

### ✅ **Why This Approach?**

* Alternative linear time solution
* Useful for multiple string pattern problems
* Educational value for understanding Z-algorithm

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **KMP LPS Array**              | 🟢 O(n)                | 🟡 O(n)                 | 🚀 Standard optimal solution      | 💾 Extra array space                 |
| 🔍 **Rolling Hash**                | 🟢 O(n)                | 🟢 O(1)                 | 💾 Constant space usage           | 🎲 Hash collision possibility         |
| 📊 **Brute Force**                | 🟡 O(n²)               | 🟢 O(1)                 | 📖 Simple to understand           | 🐌 Quadratic time complexity         |
| 🔄 **Z-Algorithm**                | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Alternative linear approach    | 🧠 More complex to understand        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Standard Implementation**                        | 🥇 **KMP LPS Array**                 | ★★★★★                     |
| 💾 **Memory Constraints**                            | 🥈 **Rolling Hash**                  | ★★★★☆                     |
| 📖 **Learning/Teaching**                             | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Advanced Algorithms**                           | 🏅 **Z-Algorithm**                   | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int getLPSLength(String s) {
        int n = s.length(), j = 0;
        int[] lps = new int[n];
        for (int i = 1; i < n; ) {
            if (s.charAt(i) == s.charAt(j)) lps[i++] = ++j;
            else if (j > 0) j = lps[j - 1];
            else i++;
        }
        return lps[n - 1];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def getLPSLength(self, s):
        n, j, lps = len(s), 0, [0] * len(s)
        i = 1
        while i < n:
            if s[i] == s[j]:
                j += 1
                lps[i] = j
                i += 1
            elif j:
                j = lps[j - 1]
            else:
                i += 1
        return lps[-1]
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


