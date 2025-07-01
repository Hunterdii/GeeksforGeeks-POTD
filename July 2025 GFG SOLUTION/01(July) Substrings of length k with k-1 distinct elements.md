---
title: "🪟 Substrings of Length K with K-1 Distinct Elements | GFG Solution 🔍"
keywords🏷️: ["🪟 substring count", "🔍 sliding window", "📍 frequency array", "📈 string processing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to find count of substrings of length k with exactly k-1 distinct characters using optimized sliding window technique. 🚀"
date: 📅 2025-07-01
---

# *01. Substrings of Length K with K-1 Distinct Elements*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1)

## **🧩 Problem Description**

Given a string `s` consisting only of **lowercase alphabets** and an integer `k`. Find the count of all substrings of length `k` which have exactly `k-1` distinct characters.

## **📘 Examples**

### Example 1

```cpp
Input: s = "abcc", k = 2
Output: 1
Explanation: Possible substrings of length k = 2 are:
- ab: 2 distinct characters
- bc: 2 distinct characters  
- cc: 1 distinct character ✓
Only one substring has exactly k-1 = 1 distinct character.
```

### Example 2

```cpp
Input: s = "aabab", k = 3
Output: 3
Explanation: Possible substrings of length k = 3 are:
- aab: 2 distinct characters ✓
- aba: 2 distinct characters ✓
- bab: 2 distinct characters ✓
All substrings have exactly k-1 = 2 distinct characters.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$
* $2 \le k \le 27$

## **✅ My Approach**

The optimal approach uses **Sliding Window with Frequency Array** technique to efficiently count substrings:

### **Sliding Window + Frequency Tracking**

1. **Initialize Window:**
   * Process first `k-1` characters to build initial frequency count.
   * Track distinct character count for the initial window.

2. **Slide the Window:**
   * Add one character to the right and remove one from the left.
   * Update frequency array and distinct count accordingly.
   * Check if current window has exactly `k-1` distinct characters.

3. **Count Valid Substrings:**
   * For each valid window (with `k-1` distinct characters), increment result.
   * Continue sliding until the entire string is processed.

4. **Frequency Management:**
   * Use array of size 26 for lowercase letters (constant space).
   * Increment distinct count when frequency becomes 1 (new character).
   * Decrement distinct count when frequency becomes 0 (character removed).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We traverse the string once with constant time operations per character.
* **Expected Auxiliary Space Complexity:** O(1), as we use a fixed-size frequency array of 26 elements regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        vector<int> cnt(26);
        int ans = 0, d = 0, n = s.length();
        for (int i = 0; i < k - 1; i++) if (++cnt[s[i]-'a'] == 1) d++;
        for (int i = k - 1; i < n; i++) {
            if (++cnt[s[i]-'a'] == 1) d++;
            if (d == k - 1) ans++;
            if (--cnt[s[i-k+1]-'a'] == 0) d--;
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap-Based Sliding Window**

### 💡 Algorithm Steps:

1. Use HashMap for character frequency tracking instead of fixed array.
2. Maintain sliding window of size k.
3. Count distinct characters and increment result when exactly k-1.

```cpp
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length()) return 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for (int i = 0; i < k - 1; i++) mp[s[i]]++;
        for (int i = k - 1; i < s.length(); i++) {
            mp[s[i]]++;
            if (mp.size() == k - 1) ans++;
            if (--mp[s[i - k + 1]] == 0) mp.erase(s[i - k + 1]);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(k) - For HashMap storage

### ✅ **Why This Approach?**

* Works with any character set, not just lowercase letters.
* More flexible for extended character ranges.

## 📊 **3️⃣ Optimized Single Pass**

### 💡 Algorithm Steps:

1. Use bitset for faster character tracking.
2. Single pass with optimized distinct character counting.
3. Early termination for impossible cases.

```cpp
class Solution {
public:
    int substrCount(string &s, int k) {
        if (k > s.length() || k <= 0) return 0;
        if (k == 1) return s.length();
        bitset<26> present;
        vector<int> cnt(26, 0);
        int ans = 0, distinct = 0;
        for (int i = 0; i < k - 1; i++) {
            int idx = s[i] - 'a';
            if (!present[idx]) {
                present[idx] = 1;
                distinct++;
            }
            cnt[idx]++;
        }
        for (int i = k - 1; i < s.length(); i++) {
            int addIdx = s[i] - 'a';
            int remIdx = s[i - k + 1] - 'a';
            if (!present[addIdx]) {
                present[addIdx] = 1;
                distinct++;
            }
            cnt[addIdx]++;
            if (distinct == k - 1) ans++;
            if (--cnt[remIdx] == 0) {
                present[remIdx] = 0;
                distinct--;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Bitset operations are faster for presence checking.
* Additional optimizations for edge cases.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Frequency Array**        | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest, minimal memory usage	  | 🧮 Limited to specific character set  |
| 🔄 **HashMap-Based**              | 🟢 O(n)                | 🟡 O(k)                 | 🔧 Works with any characters      | 💾 Extra space overhead              |
| 🪄 **Bitmask/Bitset Optimized**           | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Bitwise operations faster      | 🧮 More complex implementation       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------- | ------------------------- |
| ⚡ Maximum performance, lowercase letters only     | 🥇 **Frequency Array**     | ★★★★★                     |
| 🔧 Any character set, flexibility needed          | 🥈 **HashMap-Based**           | ★★★★☆                     |
| 🎯 Micro-optimizations required                   | 🥉 **Bitmask/Bitset Optimized**        | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int substrCount(String s, int k) {
        if (k > s.length()) return 0;
        int[] cnt = new int[26];
        int ans = 0, d = 0, n = s.length();
        for (int i = 0; i < k - 1; i++) if (++cnt[s.charAt(i)-'a'] == 1) d++;
        for (int i = k - 1; i < n; i++) {
            if (++cnt[s.charAt(i)-'a'] == 1) d++;
            if (d == k - 1) ans++;
            if (--cnt[s.charAt(i-k+1)-'a'] == 0) d--;
        }
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def substrCount(self, s, k):
        if k > len(s): return 0
        cnt = [0]*26
        ans = d = 0
        for i in range(k-1):
            if cnt[ord(s[i])-97] == 0: d += 1
            cnt[ord(s[i])-97] += 1
        for i in range(k-1, len(s)):
            if cnt[ord(s[i])-97] == 0: d += 1
            cnt[ord(s[i])-97] += 1
            if d == k - 1: ans += 1
            idx = ord(s[i-k+1])-97
            cnt[idx] -= 1
            if cnt[idx] == 0: d -= 1
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
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" alt="Visitor counter" />
</p>
