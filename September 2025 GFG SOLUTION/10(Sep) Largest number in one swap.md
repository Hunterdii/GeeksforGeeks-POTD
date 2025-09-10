---
title: "🔢 Largest Number in One Swap | GFG Solution 🔍"
keywords🏷️: ["🔢 largest number", "🔄 string swap", "📍 greedy algorithm", "📈 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Largest Number in One Swap problem: find lexicographically largest string by swapping at most one pair of characters using greedy approach. 🚀"
date: 📅 2025-09-10
---

# *10. Largest Number in One Swap*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1)

## **🧩 Problem Description**

Given a string `s`, return the **lexicographically largest string** that can be obtained by swapping **at most one pair** of characters in `s`.

The goal is to maximize the lexicographic value of the string with a single swap operation. If no beneficial swap exists, return the original string.

## **📘 Examples**

### Example 1

```cpp
Input: s = "768"
Output: "867"
Explanation: Swapping the 1st and 3rd characters (7 and 8 respectively), 
gives the lexicographically largest string.
```

### Example 2

```cpp
Input: s = "333"
Output: "333"
Explanation: Performing any swaps gives the same result i.e "333".
```

## **🔒 Constraints**

* $1 \le |s| \le 10^5$
* $'0' \le s[i] \le '9'$

## **✅ My Approach**

The optimal approach uses a **Greedy Single Pass Algorithm** that identifies the best swap opportunity by tracking the maximum character from right to left:

### **Greedy Single Pass Algorithm**

1. **Initialize Variables:**
   * `l = -1`, `r = -1`: Track positions for optimal swap
   * `maxIdx = n-1`: Index of maximum character seen from right
   * Traverse from right to left to find swap candidates

2. **Right-to-Left Traversal:**
   * For each position `i` from `n-2` to `0`:
     - If `s[i] > s[maxIdx]`: Update `maxIdx = i` (found larger character)
     - If `s[i] < s[maxIdx]`: Set `l = i`, `r = maxIdx` (potential beneficial swap)

3. **Key Insight:**
   * We want to place the largest possible digit as far left as possible
   * By traversing right-to-left, we ensure we get the rightmost occurrence of the maximum digit
   * This guarantees the lexicographically largest result

4. **Perform Swap:**
   * If `l != -1`, swap characters at positions `l` and `r`
   * Return the modified string

5. **Why This Works:**
   * We find the leftmost position where a smaller digit can be replaced
   * We replace it with the largest digit that appears to its right
   * If multiple occurrences of the largest digit exist, we choose the rightmost one

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We perform a single pass through the string from right to left, making constant time operations at each step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for tracking indices and variables, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size(), l = -1, r = -1, maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[maxIdx]) maxIdx = i;
            else if (s[i] < s[maxIdx]) l = i, r = maxIdx;
        }
        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>


## 📊 **2️⃣ Digit Frequency Approach**

### 💡 Algorithm Steps:

1. Count frequency and last occurrence of each digit.
2. For each position, check if a larger digit exists later.
3. Find the optimal swap by comparing digit frequencies.
4. Perform swap with rightmost occurrence of larger digit.

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        vector<int> last(10, -1);
        for (int i = 0; i < s.size(); i++) last[s[i] - '0'] = i;
        for (int i = 0; i < s.size(); i++) {
            for (int d = 9; d > s[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return s;
                }
            }
        }
        return s;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass with constant digit checks
* **Auxiliary Space:** 💾 O(1) - Fixed size array for 10 digits

### ✅ **Why This Approach?**

* Memory efficient with constant space usage
* Direct digit comparison without complex tracking
* Natural handling of duplicate digits


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Single Pass**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal time & space           | 🔧 Complex logic flow                |
| 🔢 **Digit Frequency**            | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Direct digit comparison        | 🔄 Multiple digit iterations         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Single Pass**                   | ★★★★★                     |
| 🔢 **Digit-focused problems**                         | 🥈 **Digit Frequency**               | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String largestSwap(String s) {
        char[] a = s.toCharArray();
        int n = a.length, l = -1, r = -1, maxIdx = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[maxIdx]) maxIdx = i;
            else if (a[i] < a[maxIdx]) { l = i; r = maxIdx; }
        }
        if (l != -1) { char t = a[l]; a[l] = a[r]; a[r] = t; }
        return new String(a);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def largestSwap(self, s):
        s = list(s)
        n, l, r, maxIdx = len(s), -1, -1, len(s) - 1
        for i in range(n - 2, -1, -1):
            if s[i] > s[maxIdx]: maxIdx = i
            elif s[i] < s[maxIdx]: l, r = i, maxIdx
        if l != -1: s[l], s[r] = s[r], s[l]
        return ''.join(s)
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




