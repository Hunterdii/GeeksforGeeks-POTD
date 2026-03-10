---
title: "🔢 Largest Number in One Swap | GFG Solution 🔍"
keywords🏷️: ["🔢 largest number", "🔍 greedy", "📍 string manipulation", "📈 digit tracking", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Largest Number in One Swap problem: find the lexicographically largest string by swapping at most one pair of characters using greedy last-occurrence tracking. 🚀"
date: 📅 2025-03-09
---

# *09. Largest Number in One Swap*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/largest-number-in-one-swap1520/1)

## **🧩 Problem Description**

Given a string `s` consisting of digit characters, return the **lexicographically largest** string that can be obtained by swapping **at most one pair** of characters in `s`.

If no beneficial swap exists (i.e., the string is already the largest possible), return the string as-is.

## **📘 Examples**

### Example 1

```
Input: s = "768"
Output: "867"
Explanation: Swapping the 1st and 3rd characters (7 and 8) gives the lexicographically largest string "867".
```

### Example 2

```
Input: s = "333"
Output: "333"
Explanation: All characters are identical; any swap yields the same result.
```

## **🔒 Constraints**

* $1 \le |s| \le 10^5$
* $\text{'0'} \le s[i] \le \text{'9'}$

## **✅ My Approach**

The optimal approach uses a **Greedy Last-Occurrence Array** strategy to find the best possible single swap in one pass:

### **Greedy + Last Occurrence Array**

1. **Precompute Last Positions:**
   * Build an array `last[0..9]` where `last[d]` stores the **last index** at which digit `d` appears in the string.
   * This allows O(1) lookup: "does digit `d` appear after position `i`?"

2. **Scan Left to Right:**
   * For each position `i`, try digits from `9` down to `s[i] + 1` (larger digits only).
   * If a digit `d` exists at some index `last[d] > i`, then swapping `s[i]` with `s[last[d]]` places the largest possible digit at the earliest possible position.

3. **Perform the Swap and Return:**
   * As soon as a valid beneficial swap is found, perform it and immediately return.
   * This greedy choice is optimal — we always maximise the most significant digit first.

4. **No Swap Needed:**
   * If no beneficial swap is found after scanning all positions, the string is already at its maximum; return it unchanged.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We make one linear pass to build the last-occurrence array and at most one more linear scan with a constant inner loop of 10 digits, giving O(10n) = O(n) overall.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed-size array of 10 elements to track digit positions, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        int last[10];
        fill(last, last + 10, -1);
        for (int i = 0; i < (int)s.size(); i++) last[s[i] - '0'] = i;
        for (int i = 0; i < (int)s.size(); i++)
            for (int d = 9; d > s[i] - '0'; d--)
                if (last[d] > i) { swap(s[i], s[last[d]]); return s; }
        return s;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Right-to-Left Max Tracking**

### 💡 Algorithm Steps:

1. Traverse from right to left, maintaining a running max digit and its index.
2. Whenever a digit smaller than the current max is found, record it as a candidate swap pair.
3. After full traversal, the last recorded pair gives the leftmost beneficial swap.
4. Perform the swap if a valid pair was found.

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        char mx = '0'; int mxi = -1, l = -1, r = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] > mx) { mx = s[i]; mxi = i; }
            else if (s[i] < mx) { l = i; r = mxi; }
        }
        if (l != -1) swap(s[l], s[r]);
        return s;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) – Single right-to-left pass through all characters
* **Auxiliary Space:** 💾 O(1) – Constant number of tracking variables only

### ✅ **Why This Approach?**

* Simple single-pass logic with no nested loops
* Minimal variable usage — no auxiliary arrays
* Excellent for interview whiteboard clarity

## 📊 **3️⃣ Digit Frequency Greedy**

### 💡 Algorithm Steps:

1. Count the frequency of each digit (0–9) in the string.
2. From left to right, at each position check if any larger digit exists anywhere after it using the frequency count.
3. Among all positions of that larger digit, prefer the rightmost one (to preserve future positions).
4. Perform the swap immediately and return.

```cpp
class Solution {
public:
    string largestSwap(string &s) {
        int cnt[10] = {};
        for (char c : s) cnt[c - '0']++;
        for (int i = 0; i < (int)s.size(); i++) {
            cnt[s[i] - '0']--;
            for (int d = 9; d > s[i] - '0'; d--) {
                if (!cnt[d]) continue;
                for (int j = s.size() - 1; j > i; j--) {
                    if (s[j] - '0' == d) { swap(s[i], s[j]); return s; }
                }
            }
        }
        return s;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(10n) = O(n) – Outer position loop with a constant 10-digit inner check
* **Auxiliary Space:** 💾 O(1) – Fixed-size digit frequency array of length 10

### ✅ **Why This Approach?**

* Explicit digit frequency reasoning makes the greedy logic very transparent
* Easy to extend for multi-swap variants
* Good for demonstrating greedy thinking step-by-step

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                  | ⏱️ **Time**   | 💾 **Space** | ✅ **Pros**                        | ⚠️ **Cons**                        |
| -------------------------------- | ------------- | ------------ | --------------------------------- | ---------------------------------- |
| 🏷️ **Last Occurrence Array**   | 🟢 O(n)       | 🟢 O(1)      | 🚀 Fastest single-pass greedy     | 🔧 Needs last-index precomputation |
| 🔄 **Right-to-Left Max Track**  | 🟢 O(n)       | 🟢 O(1)      | 📖 Intuitive single pass          | ⚠️ Subtle candidate update logic  |
| 🔢 **Digit Frequency Greedy**   | 🟢 O(n)       | 🟢 O(1)      | ⭐ Very explicit digit reasoning  | 🔧 More lines, nested loops        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                        | 🎖️ **Recommended Approach**        | 🔥 **Rating** |
| -------------------------------------- | ----------------------------------- | ------------- |
| 🏅 **Optimal performance**             | 🥇 **Last Occurrence Array**        | ★★★★★         |
| 📖 **Readability priority**            | 🥈 **Right-to-Left Max Track**      | ★★★★☆         |
| 🎯 **Interview / Competitive**         | 🏅 **Last Occurrence Array**        | ★★★★★         |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public String largestSwap(String s) {
        char[] a = s.toCharArray();
        int[] last = new int[10];
        java.util.Arrays.fill(last, -1);
        for (int i = 0; i < a.length; i++) last[a[i] - '0'] = i;
        for (int i = 0; i < a.length; i++)
            for (int d = 9; d > a[i] - '0'; d--)
                if (last[d] > i) { char t = a[i]; a[i] = a[last[d]]; a[last[d]] = t; return new String(a); }
        return s;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def largestSwap(self, s):
        a, last = list(s), [-1] * 10
        for i, c in enumerate(a): last[ord(c) - 48] = i
        for i in range(len(a)):
            for d in range(9, ord(a[i]) - 48, -1):
                if last[d] > i:
                    a[i], a[last[d]] = a[last[d]], a[i]
                    return ''.join(a)
        return s
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
