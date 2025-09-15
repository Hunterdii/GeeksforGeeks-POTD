---
title: "🔤 String Stack | GFG Solution 🔍"
keywords🏷️: ["🔤 string stack", "🔍 two pointers", "📍 greedy", "📈 string matching", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the String Stack problem: determine if target string can be constructed from pattern using append/delete operations with optimal two-pointer approach. 🚀"
date: 📅 2025-09-15
---

# *15. String Stack*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/string-stack--165812/1)

## **🧩 Problem Description**

You are given two strings `pat` and `tar` consisting of lowercase English characters. You can construct a new string `s` by performing any one of the following operations for each character in `pat`:

1. **Append** the character `pat[i]` to the string `s`.
2. **Delete** the last character of `s` (if `s` is empty do nothing).

After performing operations on every character of `pat` exactly once, your goal is to determine if it is possible to make the string `s` equal to string `tar`.

## **📘 Examples**

### Example 1

```cpp
Input: pat = "geuaek", tar = "geek"
Output: true
Explanation: Append the first three characters of pat to s, resulting in s = "geu". 
Delete the last character for 'a', leaving s = "ge". Then, append the last two 
characters 'e' and 'k' from pat to s, resulting in s = "geek", which matches tar.
```

### Example 2

```cpp
Input: pat = "agiffghd", tar = "gfg"
Output: true
Explanation: Skip the first character 'a' in pat. Append 'g' and 'i' to s, 
resulting in s = "gi". Delete the last character for 'f', leaving s = "g". 
Append 'f', 'g', and 'h' to s, resulting in s = "gfgh". Finally, delete the 
last character for 'd', leaving s = "gfg", which matches tar.
```

### Example 3

```cpp
Input: pat = "ufahs", tar = "aus"
Output: false
Explanation: It is impossible to construct the string tar from pat with the given operations.
```

## **🔒 Constraints**

* $1 \le \text{pat.size()}, \text{tar.size()} \le 10^5$

## **✅ My Approach**

The optimal approach uses a **Reverse Two-Pointer** technique with **Greedy Strategy**:

### **Reverse Two-Pointer + Greedy**

1. **Initialize Pointers:**
   * Start from the end of both strings: `i = pat.length() - 1` and `j = tar.length() - 1`.
   * Process characters from right to left (reverse order).

2. **Key Insight:**
   * When we process `pat` from left to right, we either append or delete.
   * Processing from right to left simulates the final state of our constructed string.
   * If `pat[i] == tar[j]`, this character was appended to match the target.
   * If `pat[i] != tar[j]`, this character was used for deletion (removing previous character).

3. **Algorithm Logic:**
   * **Match Found (`pat[i] == tar[j]`):** 
     * This character contributes to the target string.
     * Move both pointers backward: `i--`, `j--`.
   * **No Match (`pat[i] != tar[j]`):**
     * This character was used for deletion operation.
     * It deleted the previous character, so skip 2 positions: `i -= 2`.
     * Keep `j` unchanged as no progress made toward target.

4. **Termination:**
   * Continue until either pointer goes out of bounds.
   * Return `true` if all target characters are matched (`j < 0`).

5. **Why This Works:**
   * Greedy approach: prioritize matching characters when possible.
   * Reverse processing naturally handles the stack-like append/delete operations.
   * Each character in `pat` is used exactly once (either for append or delete).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m), where n is the length of `pat` and m is the length of `tar`. In the worst case, we traverse both strings once.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for the two pointers and no extra data structures.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool stringStack(string &pat, string &tar) {
        int i = pat.length() - 1, j = tar.length() - 1;
        while (i >= 0 && j >= 0) {
            if (pat[i] == tar[j]) {
                i--; j--;
            } else {
                i -= 2;
            }
        }
        return j < 0;
    }
};
```

## **☕ Code (Java)**

```java
class Solution {
    public boolean stringStack(String pat, String tar) {
        int i = pat.length() - 1, j = tar.length() - 1;
        while (i >= 0 && j >= 0) {
            if (pat.charAt(i) == tar.charAt(j)) {
                i--; j--;
            } else {
                i -= 2;
            }
        }
        return j < 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def stringStack(self, pat, tar):
        i, j = len(pat) - 1, len(tar) - 1
        while i >= 0 and j >= 0:
            if pat[i] == tar[j]:
                i -= 1
                j -= 1
            else:
                i -= 2
        return j < 0
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
