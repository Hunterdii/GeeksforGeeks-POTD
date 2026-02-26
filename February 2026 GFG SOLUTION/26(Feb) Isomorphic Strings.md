---
title: "🔤 Isomorphic Strings | GFG Solution 🎯"
keywords🏷️: ["🔤 isomorphic strings", "🔍 character mapping", "📊 hash map", "📈 string transformation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Isomorphic Strings: check if two strings have one-to-one character mapping using efficient array-based or hash map techniques. 🚀"
date: 📅 2025-02-26
---

# *26. Isomorphic Strings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1)

## **🧩 Problem Description**

Given two strings `s1` and `s2` consisting of only lowercase English letters and of equal length, check if these two strings are **isomorphic** to each other.

If the characters in `s1` can be changed to get `s2`, then two strings are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but **no two characters may map to the same character**.

## **📘 Examples**

### Example 1

```cpp
Input: s1 = "aab", s2 = "xxy"
Output: true
Explanation: Each character in s1 can be consistently mapped to a unique character in s2 
(a → x, b → y).
```

### Example 2

```cpp
Input: s1 = "aab", s2 = "xyz"
Output: false
Explanation: Same character 'a' in s1 maps to two different characters 'x' and 'y' in s2.
```

### Example 3

```cpp
Input: s1 = "abc", s2 = "xxz"
Output: false
Explanation: Two different characters 'a' and 'b' in s1 map to the same character 'x' in s2.
```

## **🔒 Constraints**

* $1 \le \text{s1.size()} = \text{s2.size()} \le 10^5$

## **✅ My Approach**

The optimal solution uses **Two-Way Character Mapping with Arrays**:

### **Bidirectional Mapping Validation**

1. **Key Insight:**
   * We need to ensure **one-to-one mapping** between characters.
   * This requires checking both directions: s1→s2 and s2→s1.
   * Use two arrays to track mappings in both directions.

2. **Two-Array Strategy:**
   * `map1[c]`: stores which character in s2 that character c in s1 maps to.
   * `map2[c]`: stores which character in s1 that character c in s2 maps to.
   * Initialize both arrays with a sentinel value (e.g., 0 or -1).

3. **Validation Logic:**
   * For each position i, check both directions:
     - If s1[i] already mapped but to different character → return false
     - If s2[i] already mapped but from different character → return false
     - Otherwise, establish bidirectional mapping

4. **Algorithm Steps:**
   * Iterate through both strings simultaneously.
   * Check if current mapping is consistent in both directions.
   * If inconsistency found, return false immediately.
   * If loop completes without issues, return true.

**Why This Works:** Bidirectional checking ensures no two characters map to the same character and each character has at most one mapping.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the strings. We make a single pass through both strings with constant time operations for each character.
* **Expected Auxiliary Space Complexity:** O(1), as we use fixed-size arrays of 256 or 26 elements for character mappings, which is constant space regardless of input size.

## **🧑‍💻 Code (C)**

```c
#include <stdbool.h>
#include <string.h>

bool areIsomorphic(char* s1, char* s2) {
    int m1[256] = {0}, m2[256] = {0};
    for (int i = 0; s1[i]; i++) {
        if (m1[(int)s1[i]] != m2[(int)s2[i]]) return false;
        m1[(int)s1[i]] = m2[(int)s2[i]] = i + 1;
    }
    return true;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        int m1[256] = {0}, m2[256] = {0};
        for (int i = 0; i < s1.size(); i++) {
            if (m1[s1[i]] != m2[s2[i]]) return false;
            m1[s1[i]] = m2[s2[i]] = i + 1;
        }
        return true;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Two Hash Maps Approach**

### 💡 Algorithm Steps:

1. Use two unordered maps for bidirectional character mapping.
2. For each character pair, check if mapping exists and is consistent.
3. If s1[i] already maps to different character, return false.
4. If s2[i] already mapped from different character, return false.

```cpp
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        unordered_map<char, char> m1, m2;
        for (int i = 0; i < s1.size(); i++) {
            if (m1.count(s1[i]) && m1[s1[i]] != s2[i]) return false;
            if (m2.count(s2[i]) && m2[s2[i]] != s1[i]) return false;
            m1[s1[i]] = s2[i];
            m2[s2[i]] = s1[i];
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with hash operations
* **Auxiliary Space:** 💾 O(k) - Where k is number of unique characters (max 26)

### ✅ **Why This Approach?**

* Clean and intuitive with hash maps
* Easy to understand bidirectional mapping
* Good for dynamic character sets

## 📊 **3️⃣ Vector-Based Mapping**

### 💡 Algorithm Steps:

1. Use two vectors of size 26 for lowercase letters only.
2. Initialize with -1 to indicate no mapping exists.
3. Track which characters in s2 are already used.
4. Validate consistency during single pass.

```cpp
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        vector<int> map(26, -1);
        vector<bool> used(26, false);
        for (int i = 0; i < s1.size(); i++) {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            if (map[a] == -1) {
                if (used[b]) return false;
                map[a] = b;
                used[b] = true;
            } else if (map[a] != b) return false;
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single traversal
* **Auxiliary Space:** 💾 O(1) - Fixed size vectors (26 elements)

### ✅ **Why This Approach?**

* Optimized for lowercase letters only
* Clear separation of mapping and usage tracking
* Similar to given reference solution

## 📊 **4️⃣ String as Mapping Storage**

### 💡 Algorithm Steps:

1. Use two strings of size 256 initialized with 0.
2. Store character mappings directly in string indices.
3. Compare mappings for consistency.
4. Update both mappings simultaneously.

```cpp
class Solution {
public:
    bool areIsomorphic(string &s1, string &s2) {
        string m1(256, 0), m2(256, 0);
        for (int i = 0; i < s1.size(); i++) {
            if (m1[s1[i]] != m2[s2[i]]) return false;
            m1[s1[i]] = m2[s2[i]] = s2[i];
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time traversal
* **Auxiliary Space:** 💾 O(1) - Fixed size strings

### ✅ **Why This Approach?**

* Compact representation using strings
* Direct character storage in mapping
* Efficient for all ASCII characters

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Two-Array Bidirectional**    | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Most efficient, cache-friendly | 🔧 Fixed size for all ASCII          |
| 🔍 **Two Hash Maps**              | 🟢 O(n)                | 🟡 O(k)                 | 📖 Clean and intuitive            | 🔧 Hash map overhead                 |
| 📊 **Vector-Based**               | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Optimized for lowercase        | 🔧 Limited to 26 characters          |
| 🔤 **String Mapping**             | 🟢 O(n)                | 🟢 O(1)                 | 💾 Compact representation         | 🔧 Less readable                     |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Two-Array Bidirectional**       | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **Two Hash Maps**                 | ★★★★★                     |
| 🔧 **Lowercase only**                                 | 🥉 **Vector-Based**                  | ★★★★☆                     |
| 🎯 **Competitive programming**                        | 🏅 **Two-Array Bidirectional**       | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean areIsomorphic(String s1, String s2) {
        int[] m1 = new int[256], m2 = new int[256];
        for (int i = 0; i < s1.length(); i++) {
            if (m1[s1.charAt(i)] != m2[s2.charAt(i)]) return false;
            m1[s1.charAt(i)] = m2[s2.charAt(i)] = i + 1;
        }
        return true;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def areIsomorphic(self, s1, s2):
        m1, m2 = {}, {}
        for c1, c2 in zip(s1, s2):
            if (c1 in m1 and m1[c1] != c2) or (c2 in m2 and m2[c2] != c1):
                return False
            m1[c1] = c2
            m2[c2] = c1
        return True
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
