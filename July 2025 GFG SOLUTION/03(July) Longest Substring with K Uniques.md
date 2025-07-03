---
title: "🔤 Longest Substring with K Uniques | GFG Solution 🔍"
keywords🏷️: ["🔤 longest substring", "🔍 sliding window", "📍 two pointers", "📈 frequency array", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Longest Substring with K Uniques problem: find maximum length substring containing exactly k distinct characters using sliding window technique. 🚀"
date: 📅 2025-07-03
---

# *03. Longest Substring with K Uniques*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

## **🧩 Problem Description**

You are given a string `s` consisting only lowercase alphabets and an integer `k`. Your task is to find the length of the **longest substring** that contains **exactly k distinct characters**.

Note: If no such substring exists, return -1.

## **📘 Examples**

### Example 1

```cpp
Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", 
which includes 'c', 'b', and 'e'.
```

### Example 2

```cpp
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
```

### Example 3

```cpp
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', 
making it the longest valid substring.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$
* $1 \le k \le 26$

## **✅ My Approach**

The optimal approach uses the **Sliding Window** technique with a **Frequency Array** to efficiently track distinct characters and their frequencies:

### **Sliding Window + Frequency Array**

1. **Initialize Variables:**
   * Use two pointers: `i` (start of window) and `j` (end of window).
   * Maintain a frequency array `fre[26]` to store frequency of each character in current window.
   * Track `cnt` to count distinct characters and `maxi` to store the result.

2. **Expand Window:**
   * Move `j` pointer and increment frequency of `s[j]`.
   * If this is the first occurrence of `s[j]` (frequency was 0), increment `cnt`.

3. **Contract Window:**
   * If `cnt` exceeds `k` (more than k distinct characters), shrink window from left.
   * Decrement frequency of `s[i]` and if it becomes 0, decrement `cnt`.
   * Move `i` pointer forward.

4. **Update Result:**
   * Only when `cnt == k` (exactly k distinct characters), update `maxi` with current window size.

5. **Return Result:**
   * Return `maxi` if found, otherwise return -1.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is visited at most twice (once by right pointer and once by left pointer).
* **Expected Auxiliary Space Complexity:** O(1), as we use a fixed-size frequency array of 26 elements for lowercase alphabets, which is constant space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), i = 0, cnt = 0, maxi = -1;
        vector<int> fre(26, 0);
        for (int j = 0; j < n; j++) {
            if (fre[s[j] - 'a']++ == 0) cnt++;
            while (cnt > k) {
                if (--fre[s[i] - 'a'] == 0) cnt--;
                i++;
            }
            if (cnt == k) maxi = max(maxi, j - i + 1);
        }
        return maxi;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap Sliding Window Approach**

### 💡 Algorithm Steps:

1. Use an unordered_map to track character frequencies in the current window
2. Expand the window by moving the right pointer and adding characters
3. If distinct characters exceed k, shrink from left until exactly k remain
4. Track maximum window size when exactly k distinct characters are present

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int i = 0, maxLen = -1;
        for (int j = 0; j < s.size(); j++) {
            mp[s[j]]++;
            while (mp.size() > k) {
                if (--mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }
            if (mp.size() == k) maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) - for storing at most k distinct characters

### ✅ **Why This Approach?**

* Works for any character set, not just lowercase letters
* Clear and intuitive logic
* Efficient hash map operations

## 📊 **3️⃣ Two-Pass Approach**

### 💡 Algorithm Steps:

1. First pass: Find all possible starting positions for valid substrings
2. Second pass: For each starting position, extend as far as possible while maintaining exactly k distinct characters
3. Track the maximum length found across all valid substrings

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), maxLen = -1;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int distinct = 0;
            for (int j = i; j < n; j++) {
                if (freq[s[j] - 'a']++ == 0) distinct++;
                if (distinct == k) maxLen = max(maxLen, j - i + 1);
                else if (distinct > k) break;
            }
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²)
* **Auxiliary Space:** 💾 O(1) - constant space for frequency array

### ✅ **Why This Approach?**

* Simple nested loop structure
* Easy to understand and implement
* Good for small input sizes

## 📊 **4️⃣ Optimized Array-Based Tracking**

### 💡 Algorithm Steps:

1. Use a boolean array to track which characters are present in the current window
2. Use a separate frequency array to count occurrences
3. Maintain count of distinct characters manually
4. Slide window efficiently with single pass

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int freq[26] = {0}, distinct = 0, left = 0, maxLen = -1;
        for (int right = 0; right < s.size(); right++) {
            if (freq[s[right] - 'a']++ == 0) distinct++;
            while (distinct > k) {
                if (--freq[s[left] - 'a'] == 0) distinct--;
                left++;
            }
            if (distinct == k) maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1) - constant space for fixed-size array

### ✅ **Why This Approach?**

* Fastest execution due to array access
* Minimal memory overhead
* Cache-friendly access pattern

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Array-Based Sliding Window** | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest, minimal space         | 📝 Limited to lowercase letters      |
| 🔄 **HashMap Sliding Window**     | 🟢 O(n)                | 🟡 O(k)                 | 🚀 Works with any characters      | 💾 HashMap overhead                   |
| 🔺 **Two-Pass Approach**          | 🟡 O(n²)               | 🟢 O(1)                 | 🔧 Simple logic, easy to debug   | ⏰ Slower for large inputs           |
| ⏰ **Optimized Array Tracking**   | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Cache-friendly, efficient     | 📝 Limited character set             |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Maximum performance, lowercase letters only**    | 🥇 **Array-Based Sliding Window**    | ★★★★★                     |
| 🔧 **General purpose, any character set**             | 🥈 **HashMap Sliding Window**        | ★★★★☆                     |
| 📊 **Educational purposes, simple logic**             | 🥉 **Two-Pass Approach**             | ★★★☆☆                     |
| 🎯 **Balanced performance and clarity**               | 🎖️ **Optimized Array Tracking**     | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int longestKSubstr(String s, int k) {
        int[] freq = new int[26];
        int i = 0, cnt = 0, max = -1;
        for (int j = 0; j < s.length(); j++) {
            if (freq[s.charAt(j) - 'a']++ == 0) cnt++;
            while (cnt > k) {
                if (--freq[s.charAt(i) - 'a'] == 0) cnt--;
                i++;
            }
            if (cnt == k) max = Math.max(max, j - i + 1);
        }
        return max;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestKSubstr(self, s, k):
        freq = [0] * 26
        i = cnt = maxi = 0
        for j in range(len(s)):
            if freq[ord(s[j]) - ord('a')] == 0:
                cnt += 1
            freq[ord(s[j]) - ord('a')] += 1
            while cnt > k:
                freq[ord(s[i]) - ord('a')] -= 1
                if freq[ord(s[i]) - ord('a')] == 0:
                    cnt -= 1
                i += 1
            if cnt == k:
                maxi = max(maxi, j - i + 1)
        return maxi if maxi > 0 else -1
```

## 🧠 Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
