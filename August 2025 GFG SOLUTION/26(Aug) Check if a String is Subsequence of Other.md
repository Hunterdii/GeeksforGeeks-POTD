---
title: "🔤 Check if a String is Subsequence of Other | GFG Solution 🔍"
keywords🏷️: ["🔤 string subsequence", "🔍 two pointers", "📈 greedy algorithm", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to check if one string is a subsequence of another using efficient two-pointer technique. Find if s1 is subsequence of s2 optimally. 🚀"
date: 📅 2025-08-26
---

# *26. Check if a String is Subsequence of Other*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1)

## **🧩 Problem Description**

Given two strings `s1` and `s2`, you need to check whether `s1` is a **subsequence** of `s2` or not.

**Note:** A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

## **📘 Examples**

### Example 1

```cpp
Input: s1 = "AXY", s2 = "YADXCP"
Output: false
Explanation: s1 is not a subsequence of s2 as 'Y' appears before 'A' in s2, 
but in s1, 'A' comes before 'Y'.
```

### Example 2

```cpp
Input: s1 = "gksrek", s2 = "geeksforgeeks"
Output: true
Explanation: If we combine the bold characters of "g**e**e**k**sfor**g**ee**k**s", 
it gives us "geksrek". We can derive "gksrek" by removing one 'e', making s1 a subsequence of s2.
```

### Example 3

```cpp
Input: s1 = "abc", s2 = "aec"
Output: false
Explanation: Character 'b' is missing in s2, so s1 cannot be a subsequence of s2.
```

## **🔒 Constraints**

* $1 \le \text{s1.size()}, \text{s2.size()} \le 10^6$

## **✅ My Approach**

The optimal approach uses the **Two Pointer Technique** to efficiently check if one string is a subsequence of another:

### **Two Pointer Greedy Algorithm**

1. **Initialize Pointers:**
   * Use pointer `i` for string `s1` (subsequence to find).
   * Traverse string `s2` using a range-based loop or second pointer.

2. **Character Matching:**
   * For each character in `s2`, check if it matches the current character in `s1` (at position `i`).
   * If characters match, advance pointer `i` to look for the next character in `s1`.

3. **Greedy Strategy:**
   * Always take the first available match in `s2` for each character in `s1`.
   * This greedy approach is optimal because taking later matches cannot give better results.

4. **Final Check:**
   * If we've successfully matched all characters in `s1` (i.e., `i == s1.length()`), then `s1` is a subsequence of `s2`.

5. **Early Termination:**
   * We can stop as soon as we've found all characters of `s1`, even if `s2` has more characters.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(m), where m is the length of string s2. We traverse s2 exactly once, and for each character, we perform constant time operations.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the pointer variable and loop counters.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0;
        for (char c : s2) {
            if (i < s1.size() && s1[i] == c) {
                i++;
            }
        }
        return i == s1.size();
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterator-Based Approach**

### 💡 Algorithm Steps:

1. Use iterators to traverse both strings simultaneously.
2. Advance s1 iterator only when characters match.
3. Always advance s2 iterator to check all characters.
4. Return true if s1 iterator reaches the end.

```cpp
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        auto it1 = s1.begin(), it2 = s2.begin();
        while (it1 != s1.end() && it2 != s2.end()) {
            if (*it1 == *it2) {
                it1++;
            }
            it2++;
        }
        return it1 == s1.end();
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m) - Single pass through s2
* **Auxiliary Space:** 💾 O(1) - Only iterator variables

### ✅ **Why This Approach?**

* Clean iterator-based implementation
* Explicit control over traversal
* Good for understanding pointer mechanics

## 📊 **3️⃣ Traditional Two Pointer Approach**

### 💡 Algorithm Steps:

1. Initialize two pointers: `i` for s1 and `j` for s2.
2. Compare characters at current positions.
3. If characters match, advance both pointers.
4. If they don't match, advance only the s2 pointer.
5. Continue until one string is fully traversed.

```cpp
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        int i = 0, j = 0;
        int n = s1.size(), m = s2.size();
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }
        return i == n;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m) - Linear traversal of s2
* **Auxiliary Space:** 💾 O(1) - Only pointer variables

### ✅ **Why This Approach?**

* Classic two-pointer implementation
* Easy to understand and debug
* Traditional approach taught in algorithms

## 📊 **4️⃣ Recursive Approach**

### 💡 Algorithm Steps:

1. Base case: if s1 is empty, it's always a subsequence.
2. If s2 is empty but s1 isn't, return false.
3. If characters match, advance both strings recursively.
4. If they don't match, advance only s2 recursively.

```cpp
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        return helper(s1, s2, 0, 0);
    }
private:
    bool helper(string& s1, string& s2, int i, int j) {
        if (i == s1.size()) return true;
        if (j == s2.size()) return false;
        if (s1[i] == s2[j]) {
            return helper(s1, s2, i + 1, j + 1);
        }
        return helper(s1, s2, i, j + 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(m) - Each character in s2 is visited once
* **Auxiliary Space:** 💾 O(m) - Recursion stack space

### ✅ **Why This Approach?**

* Elegant recursive solution
* Clear base cases and transitions
* Good for understanding problem structure

## 📊 **5️⃣ STL Algorithm Approach**

### 💡 Algorithm Steps:

1. Use STL's `find` function to locate each character of s1 in s2.
2. Search for each subsequent character starting from the position after the previous match.
3. If any character is not found, return false.
4. If all characters are found in order, return true.

```cpp
class Solution {
public:
    bool isSubSeq(string& s1, string& s2) {
        size_t pos = 0;
        for (char c : s1) {
            pos = s2.find(c, pos);
            if (pos == string::npos) return false;
            pos++; 
        }
        return true;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × m) - In worst case, find() may scan remaining string
* **Auxiliary Space:** 💾 O(1) - Only position variable

### ✅ **Why This Approach?**

* Utilizes STL functionality
* Concise and readable
* Good for rapid prototyping

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔥 **Range-Based Loop**           | 🟢 O(m)                | 🟢 O(1)                 | 🚀 Fastest, most readable         | 📚 Requires C++11                    |
| 🔍 **Iterator-Based**             | 🟢 O(m)                | 🟢 O(1)                 | 📖 Explicit control               | 🔧 More verbose                       |
| 👥 **Traditional Two Pointer**    | 🟢 O(m)                | 🟢 O(1)                 | 🎯 Classic, easy to understand    | 💭 Slightly more code                 |
| 🌀 **Recursive**                  | 🟢 O(m)                | 🟡 O(m)                 | 🎭 Elegant structure               | 💾 Stack space overhead              |
| 🛠️ **STL Algorithm**              | 🟡 O(n × m)            | 🟢 O(1)                 | 📦 Uses STL, concise               | 🐌 Potentially slower                 |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production code, interviews**                | 🥇 **Range-Based Loop**              | ★★★★★                     |
| 📖 **Learning algorithms**                        | 🥈 **Traditional Two Pointer**       | ★★★★☆                     |
| 🔧 **Iterator practice**                          | 🥉 **Iterator-Based**                | ★★★★☆                     |
| 🎓 **Academic understanding**                     | 🏅 **Recursive**                     | ★★★☆☆                     |
| ⚡ **Quick prototyping**                          | 🎖️ **STL Algorithm**                 | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public boolean isSubSeq(String s1, String s2) {
        int i = 0, n = s1.length(), m = s2.length();
        
        for (int j = 0; j < m && i < n; j++) {
            if (s1.charAt(i) == s2.charAt(j)) {
                i++;
            }
        }
        return i == n;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def isSubSeq(self, s1, s2):
        i = 0
        for c in s2:
            if i < len(s1) and s1[i] == c:
                i += 1
        return i == len(s1)
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
