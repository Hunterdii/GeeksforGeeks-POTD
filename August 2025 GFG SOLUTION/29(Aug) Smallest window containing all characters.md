---
title: "🔤 Smallest Window Containing All Characters | GFG Solution 🪟"
keywords🏷️: ["🔤 smallest window", "🪟 sliding window", "📍 two pointers", "📈 frequency array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Smallest Window Containing All Characters problem: find minimum length substring containing all characters of pattern using sliding window technique. 🚀"
date: 📅 2025-08-29
---

# *29. Smallest Window Containing All Characters*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1)

## **🧩 Problem Description**

You are given two strings `s` and `p`. Your task is to find the **smallest substring** in `s` that contains **all characters** (including duplicates) of the string `p`. Return an empty string if no such substring exists.

If there are multiple substrings of the same minimum length, return the one with the **least starting index**.

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
* `s`, `p` consists of lowercase english letters

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique with **Frequency Arrays** to efficiently find the minimum window containing all pattern characters:

### **Sliding Window + Frequency Tracking**

1. **Initialize Frequency Arrays:**
   * Create frequency array for pattern `p` to store required character counts.
   * Create window frequency array to track characters in current window.
   * Calculate total unique characters required from pattern.

2. **Expand Window:**
   * Move `right` pointer and add `s[right]` to window frequency.
   * If character frequency matches required frequency, increment `formed` counter.

3. **Contract Window:**
   * When all required characters are formed, try to minimize window size.
   * Move `left` pointer forward while maintaining validity.
   * Update minimum window if current window is smaller.

4. **Track Optimal Window:**
   * Store the starting position and length of the smallest valid window.
   * Continue until `right` pointer reaches end of string.

5. **Return Result:**
   * Return the substring of minimum length, or empty string if no valid window exists.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(|s| + |p|), where |s| and |p| are the lengths of strings s and p respectively. Each character in s is visited at most twice (once by right pointer and once by left pointer), and we process pattern p once for frequency calculation.
* **Expected Auxiliary Space Complexity:** O(1), as we use fixed-size arrays of length 256 (constant space for ASCII characters) regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        int m = s.size(), n = p.size();
        if (m < n) return "";
        int freq[256] = {0}, window[256] = {0};
        for (char c : p) freq[c]++;
        int formed = 0, required = 0;
        for (int i = 0; i < 256; i++) if (freq[i] > 0) required++;
        int l = 0, r = 0, minLen = INT_MAX, minStart = 0;
        while (r < m) {
            window[s[r]]++;
            if (freq[s[r]] > 0 && window[s[r]] == freq[s[r]]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                window[s[l]]--;
                if (freq[s[l]] > 0 && window[s[l]] < freq[s[l]]) formed--;
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap-Based Approach**

### 💡 Algorithm Steps:

1. Use unordered maps to track character frequencies for pattern and current window.
2. Expand window by moving right pointer until all pattern characters are included.
3. Contract window from left while maintaining validity to find minimum length.
4. Track the smallest valid window found during the process.

```cpp
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        if (s.empty() || p.empty() || s.size() < p.size()) return "";
        unordered_map<char, int> patternCount, windowCount;
        for (char c : p) patternCount[c]++;
        int left = 0, minStart = 0, minLen = INT_MAX, matched = 0;
        for (int right = 0; right < s.size(); right++) {
            windowCount[s[right]]++;
            if (patternCount.count(s[right]) && windowCount[s[right]] == patternCount[s[right]]) {
                matched++;
            }
            while (matched == patternCount.size()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }
                windowCount[s[left]]--;
                if (patternCount.count(s[left]) && windowCount[s[left]] < patternCount[s[left]]) {
                    matched--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(|s| + |p|) - Single pass with sliding window
* **Auxiliary Space:** 💾 O(k) - Where k is unique characters in pattern

### ✅ **Why This Approach?**

* More intuitive with explicit hash map operations
* Easier to debug and understand logic flow
* Better for scenarios with large character sets

## 📊 **3️⃣ Optimized Counter Approach**

### 💡 Algorithm Steps:

1. Use single counter to track how many pattern characters need to be satisfied.
2. Maintain frequency arrays for both pattern and current window.
3. Use counter decrement/increment to efficiently track window validity.
4. Slide window optimally by expanding right and contracting left pointers.

```cpp
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        vector<int> need(128, 0);
        for (char c : p) need[c]++;
        int missing = p.size(), start = 0, minStart = 0, minLen = INT_MAX;
        for (int end = 0; end < s.size(); end++) {
            if (need[s[end]]-- > 0) missing--;
            while (!missing) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                if (++need[s[start++]] > 0) missing++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(|s|) - Optimized single pass
* **Auxiliary Space:** 💾 O(1) - Fixed size array

### ✅ **Why This Approach?**

* Most concise implementation
* Minimal memory overhead
* Excellent for competitive programming

## 📊 **4️⃣ Two-Pass Sliding Window**

### 💡 Algorithm Steps:

1. First pass: Build frequency map for pattern characters.
2. Second pass: Use sliding window with careful frequency management.
3. Expand window until all characters are covered, then contract to minimize.
4. Keep track of best window found so far.

```cpp
class Solution {
public:
    string smallestWindow(string &s, string &p) {
        unordered_map<char, int> pCount;
        for (char c : p) pCount[c]++;
        int required = pCount.size(), formed = 0;
        int l = 0, r = 0, minLen = INT_MAX, minL = 0;
        unordered_map<char, int> windowCount;
        while (r < s.length()) {
            char c = s[r];
            windowCount[c]++;
            if (pCount.count(c) && windowCount[c] == pCount[c]) formed++;
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minL = l;
                }
                char leftChar = s[l];
                windowCount[leftChar]--;
                if (pCount.count(leftChar) && windowCount[leftChar] < pCount[leftChar]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(|s| + |p|) - Linear scan with amortized operations
* **Auxiliary Space:** 💾 O(k) - Where k is distinct characters in pattern

### ✅ **Why This Approach?**

* Clear separation of logic phases
* Easy to modify for different requirements
* Good balance between readability and efficiency

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Array-Based Tracking**       | 🟢 O(s + p)           | 🟢 O(1)                 | 🚀 Fast array access, minimal space | 🔧 Limited to ASCII characters       |
| 🔍 **HashMap-Based**              | 🟢 O(s + p)           | 🟡 O(k)                 | 📖 Clear logic, supports Unicode    | 💾 Extra space for hash maps         |
| ⚡ **Optimized Counter**          | 🟢 O(s)               | 🟢 O(1)                 | 🎯 Most efficient, compact code     | 🤔 Less intuitive logic              |
| 🔄 **Two-Pass Sliding Window**    | 🟢 O(s + p)           | 🟡 O(k)                 | 📚 Educational clarity              | 🐌 Slightly more overhead            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive Programming**                        | 🥇 **Array-Based Tracking**          | ★★★★★                     |
| 📖 **Interview/Learning**                             | 🥈 **HashMap-Based**                 | ★★★★☆                     |
| 🌐 **Production Code**                                | 🥉 **Optimized Counter**             | ★★★★☆                     |
| 🎓 **Educational Understanding**                       | 🎖️ **Two-Pass Sliding Window**       | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public static String smallestWindow(String s, String p) {
        int m = s.length(), n = p.length();
        if (m < n) return "";
        int[] need = new int[256];
        for (char c : p.toCharArray()) need[c]++;
        int missing = n, start = 0, minStart = 0, minLen = Integer.MAX_VALUE;
        for (int end = 0; end < m; end++) {
            if (need[s.charAt(end)]-- > 0) missing--;
            while (missing == 0) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                }
                if (++need[s.charAt(start++)] > 0) missing++;
            }
        }
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minStart, minStart + minLen);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def smallestWindow(self, s, p):
        m, n = len(s), len(p)
        if m < n: return ""
        need = [0] * 256
        for c in p: need[ord(c)] += 1
        missing, start, min_start, min_len = n, 0, 0, float('inf')
        for end in range(m):
            if need[ord(s[end])] > 0: missing -= 1
            need[ord(s[end])] -= 1
            while missing == 0:
                if end - start + 1 < min_len:
                    min_len = end - start + 1
                    min_start = start
                need[ord(s[start])] += 1
                if need[ord(s[start])] > 0: missing += 1
                start += 1
        return "" if min_len == float('inf') else s[min_start:min_start + min_len]
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
