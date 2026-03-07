---
title: "🔍 Smallest Window Containing All Characters | GFG Solution 🎯"
keywords🏷️: ["🔍 minimum window", "📊 sliding window", "📈 character frequency", "🔤 substring search", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Smallest Window Containing All Characters: find minimum window in string containing all characters of another string using sliding window technique. 🚀"
date: 📅 2025-03-06
---

# *06. Smallest Window Containing All Characters*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)

## **🧩 Problem Description**

Given two strings `s` and `p`, find the **smallest substring** in `s` consisting of all the characters (including duplicates) of the string `p`. Return empty string in case no such substring is present. If there are multiple such substrings of the same length, return the one with the **least starting index**.

## **📘 Examples**

### Example 1

```cpp
Input: s = "timetopractice", p = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.
```

### Example 2

```cpp
Input: s = "zoomlazapzo", p = "oza"
Output: "apzo"
Explanation: "apzo" is the smallest substring in which "oza" can be found.
```

### Example 3

```cpp
Input: s = "zoom", p = "zooe"
Output: ""
Explanation: No substring is present containing all characters of p.
```

## **🔒 Constraints**

* $1 \le \text{s.length()}, \text{p.length()} \le 10^6$
* s, p consists of lowercase English letters

## **✅ My Approach**

The optimal solution uses **Sliding Window with Character Frequency Tracking**:

### **Two-Pointer Sliding Window**

1. **Frequency Tracking:**
   * Store frequency of all characters in pattern `p`.
   * Track frequency of characters in current window of `s`.
   * Count how many required characters are satisfied.

2. **Window Expansion:**
   * Move right pointer to expand window.
   * Add character to window frequency.
   * If character is needed and not over-counted, increment match count.

3. **Window Contraction:**
   * When all characters are matched, try to minimize window.
   * Move left pointer while window still contains all characters.
   * Remove characters that are not needed or are in excess.

4. **Result Tracking:**
   * Track minimum window length and starting position.
   * Update when a smaller valid window is found.
   * Return substring if valid window exists, else empty string.

**Key Insight:** Use character frequency arrays for O(1) character operations. Match count tracks when all required characters are present in current window.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + m), where n is the length of string s and m is the length of string p. We make at most two passes through s (right pointer and left pointer), and one pass through p to build frequency map.
* **Expected Auxiliary Space Complexity:** O(1), as we use fixed-size arrays of 256 elements (for all ASCII characters) or 26 elements (for lowercase letters only), which is constant space regardless of input size.

## **🧑‍💻 Code (C)**

```c
#include <string.h>
#include <limits.h>

char* smallestWindow(char* s, char* p) {
    int n = strlen(s), m = strlen(p);
    if (n < m) return "";
    int fp[256] = {0}, fs[256] = {0};
    for (int i = 0; i < m; i++) fp[p[i]]++;
    int l = 0, cnt = 0, minLen = INT_MAX, start = -1;
    for (int r = 0; r < n; r++) {
        fs[s[r]]++;
        if (fp[s[r]] && fs[s[r]] <= fp[s[r]]) cnt++;
        while (cnt == m) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            fs[s[l]]--;
            if (fp[s[l]] && fs[s[l]] < fp[s[l]]) cnt--;
            l++;
        }
    }
    if (start == -1) return "";
    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + start, minLen);
    result[minLen] = '\0';
    return result;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string minWindow(string &s, string &p) {
        int n = s.size(), m = p.size();
        if (n < m) return "";
        vector<int> fp(256, 0), fs(256, 0);
        for (char c : p) fp[c]++;
        int l = 0, cnt = 0, minLen = INT_MAX, start = -1;
        for (int r = 0; r < n; r++) {
            fs[s[r]]++;
            if (fp[s[r]] && fs[s[r]] <= fp[s[r]]) cnt++;
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                fs[s[l]]--;
                if (fp[s[l]] && fs[s[l]] < fp[s[l]]) cnt--;
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start, minLen);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Hash Map Approach**

### 💡 Algorithm Steps:

1. Use unordered_map instead of fixed arrays for character frequencies.
2. Track required character count and formed character count.
3. Expand window until all characters found, then contract.
4. Update minimum window when valid window found.

```cpp
class Solution {
public:
    string minWindow(string &s, string &p) {
        if (s.length() < p.length()) return "";
        unordered_map<char, int> pCount, sCount;
        for (char c : p) pCount[c]++;
        int required = pCount.size(), formed = 0;
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0;
        
        while (r < s.length()) {
            char c = s[r];
            sCount[c]++;
            if (pCount.count(c) && sCount[c] == pCount[c])
                formed++;
            
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                char leftChar = s[l];
                sCount[leftChar]--;
                if (pCount.count(leftChar) && sCount[leftChar] < pCount[leftChar])
                    formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Linear time with hash operations
* **Auxiliary Space:** 💾 O(k) - Where k is unique characters in p

### ✅ **Why This Approach?**

* Flexible for any character set (not just ASCII)
* Clear separation of required vs formed counts
* Easy to extend for additional constraints

## 📊 **3️⃣ Optimized Array with Match Counting**

### 💡 Algorithm Steps:

1. Use array of size 128 for ASCII characters.
2. Track total matches needed and current matches.
3. Slide window with efficient match tracking.
4. Return smallest valid window found.

```cpp
class Solution {
public:
    string minWindow(string &s, string &p) {
        vector<int> map(128, 0);
        for (char c : p) map[c]++;
        int counter = p.size(), begin = 0, end = 0, minLen = INT_MAX, head = 0;
        
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            
            while (counter == 0) {
                if (end - begin < minLen) {
                    minLen = end - begin;
                    head = begin;
                }
                if (map[s[begin++]]++ == 0) counter++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + m) - Single pass through both strings
* **Auxiliary Space:** 💾 O(1) - Fixed size array

### ✅ **Why This Approach?**

* Most compact code
* Efficient counter-based matching
* Optimal for ASCII characters

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Array Sliding Window**       | 🟢 O(n + m)            | 🟢 O(1)                 | 🚀 Fastest, constant space        | 🔧 Limited to ASCII/lowercase        |
| 🔍 **Hash Map**                   | 🟢 O(n + m)            | 🟡 O(k)                 | 📖 Flexible for any charset       | 🔧 Hash map overhead                 |
| 📊 **Match Counter**              | 🟢 O(n + m)            | 🟢 O(1)                 | ⚡ Most compact code              | 🔧 Requires understanding counters   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Array Sliding Window**          | ★★★★★                     |
| 📖 **Any character set**                              | 🥈 **Hash Map**                      | ★★★★★                     |
| ⚡ **Most compact solution**                          | 🥉 **Match Counter**                 | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static String minWindow(String s, String p) {
        int n = s.length(), m = p.length();
        if (n < m) return "";
        int[] fp = new int[256], fs = new int[256];
        for (char c : p.toCharArray()) fp[c]++;
        int l = 0, cnt = 0, minLen = Integer.MAX_VALUE, start = -1;
        for (int r = 0; r < n; r++) {
            fs[s.charAt(r)]++;
            if (fp[s.charAt(r)] > 0 && fs[s.charAt(r)] <= fp[s.charAt(r)]) cnt++;
            while (cnt == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                fs[s.charAt(l)]--;
                if (fp[s.charAt(l)] > 0 && fs[s.charAt(l)] < fp[s.charAt(l)]) cnt--;
                l++;
            }
        }
        return start == -1 ? "" : s.substring(start, start + minLen);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minWindow(self, s, p):
        n, m = len(s), len(p)
        if n < m:
            return ""
        fp, fs = [0] * 256, [0] * 256
        for c in p:
            fp[ord(c)] += 1
        l = cnt = 0
        minLen, start = float('inf'), -1
        for r in range(n):
            fs[ord(s[r])] += 1
            if fp[ord(s[r])] and fs[ord(s[r])] <= fp[ord(s[r])]:
                cnt += 1
            while cnt == m:
                if r - l + 1 < minLen:
                    minLen = r - l + 1
                    start = l
                fs[ord(s[l])] -= 1
                if fp[ord(s[l])] and fs[ord(s[l])] < fp[ord(s[l])]:
                    cnt -= 1
                l += 1
        return "" if start == -1 else s[start:start + minLen]
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
