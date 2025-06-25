---
title: "🧪 Check if Frequencies Can Be Equal | GFG Solution 🔍"
keywords🏷️: ["🧪 frequency check", "🧮 character frequency", "🔠 string", "🗑️ remove one char", "📈 hash map", "🏁 competitive programming", "📘 GFG", "📚 DSA", "🧠 hashing"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Check if Frequencies Can Be Equal problem: determine if removing at most one character makes all character frequencies equal. 🚀"
date: 📅 2025-06-25
---

# *25. Check if Frequencies Can Be Equal*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/check-frequencies4211/1)

## **🧩 Problem Description**

Given a string `s` consisting only of **lowercase alphabetic characters**, check whether it is possible to **remove at most one character** such that the frequency of each distinct character in the string becomes the same. Return `true` if it is possible; otherwise, return `false`.

## **📘 Examples**

### Example 1

```cpp
Input: s = "xyyz"
Output: true
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
```

### Example 2

```cpp
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
```

### Example 3

```cpp
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency cannot be made same by removing at most one character.
```

## **🔒 Constraints**

* $1 \le s.size() \le 10^5$

## **✅ My Approach**

The optimal approach uses **Frequency Counting** followed by **Frequency Analysis**:

### **Frequency Map Analysis**

1. **Count Character Frequencies:**
   * Use frequency array to count occurrences of each character.
   * Store non-zero frequencies in a hash map with their counts.

2. **Analyze Frequency Distribution:**
   * **Case 1:** All characters have same frequency → Return `true`
   * **Case 2:** Exactly 2 different frequencies exist → Check validity
   * **Case 3:** More than 2 different frequencies → Return `false`

3. **Validate Two-Frequency Cases:**
   * One frequency is 1 and occurs once (remove that single character)
   * Two frequencies differ by 1 and higher frequency occurs once (reduce higher frequency)

4. **Return Result:**
   * Return `true` if any valid case is satisfied, otherwise `false`.


## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We iterate through the string once to count frequencies, then iterate through the frequency map (at most 26 entries) to analyze the distribution.
* **Expected Auxiliary Space Complexity:** O(1), as we use fixed-size arrays and hash maps with at most 26 entries for lowercase letters, which is constant space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool sameFreq(string& s) {
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;
        unordered_map<int, int> m;
        for (int f : freq) if (f) m[f]++;
        if (m.size() == 1) return true;
        if (m.size() == 2) {
            auto a = m.begin(), b = next(a);
            int f1 = a->first, c1 = a->second;
            int f2 = b->first, c2 = b->second;
            return (f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1) ||
                  (abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)));
        }
        return false;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Early Termination with Set**

### 💡 Algorithm Steps:

1. Count character frequencies in single pass.
2. Use set to track frequency distributions with early termination.
3. Sort frequencies for easier comparison logic.

```cpp
class Solution {
public:
    bool sameFreq(string& s) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        unordered_set<int> sfx;
        for (int i = 0; i < 26; i++) {
            if (f[i]) {
                sfx.insert(f[i]);
                if (sfx.size() > 2) return false;
            }
        }
        if (sfx.size() == 1) return true;
        vector<int> v(sfx.begin(), sfx.end());
        sort(v.begin(), v.end());
        int c1 = 0, c2 = 0;
        for (int i = 0; i < 26; i++) {
            if (f[i] == v[0]) c1++;
            else if (f[i] == v[1]) c2++;
        }
        return (v[0] == 1 && c1 == 1) || (v[1] - v[0] == 1 && c2 == 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + 26) = O(n)
* **Auxiliary Space:** 💾 O(1) - Fixed size array and set

### ✅ **Why This Approach?**

* Early termination saves computation when more than 2 frequencies exist.
* Array-based frequency counting offers better cache performance.

## 📊 **3️⃣ Bit Manipulation Optimization**

### 💡 Algorithm Steps:

1. Use bit manipulation to track unique frequencies efficiently.
2. Leverage bitwise operations for frequency comparison.
3. Minimize conditional branches for better performance.

```cpp
class Solution {
public:
    bool sameFreq(string& s) {
        int f[26] = {};
        for (char c : s) f[c - 'a']++;
        int m = 0, hi = 0, lo = INT_MAX;
        for (int x : f) {
            if (x) {
                m |= 1 << (x & 31);
                hi = max(hi, x);
                lo = min(lo, x);
            }
        }
        if (__builtin_popcount(m) == 1) return true;
        if (__builtin_popcount(m) != 2) return false;
        int c1 = 0, c2 = 0;
        for (int x : f) {
            if (x == lo) c1++;
            else if (x == hi) c2++;
        }
        return (lo == 1 && c1 == 1) || (hi - lo == 1 && c2 == 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Bit manipulation provides efficient frequency uniqueness tracking.
* Single-pass solution with minimal memory overhead.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **HashMap-Based Frequency Check** | 🟢 O(n)              | 🟡 O(1)                 | ⚡ Clean logic, readable          | 💾 HashMap operations overhead        |
| 🔄 **Early Termination with Set**    | 🟢 O(n)              | 🟢 O(1)                 | 🔧 Fast exit, cache-friendly     | 🧮 Extra sorting step required       |
| 🔍 **Bit Manipulation Optimization** | 🟢 O(n)              | 🟢 O(1)                 | ⚡ Minimal overhead, efficient    | 🧮 Complex bit operations            |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**         | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------ | ------------------------- |
| ⚡ Maximum performance, competitive programming    | 🥇 **HashMap-Based Frequency Check** | ★★★★★                     |
| 🔧 Production code, memory constraints             | 🥈 **Early Termination with Set**    | ★★★★☆                     |
| 🎯 Extreme optimization, embedded systems          | 🎖️ **Bit Manipulation Optimization** | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    boolean sameFreq(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        Map<Integer, Integer> map = new HashMap<>();
        for (int f : freq) if (f > 0) map.put(f, map.getOrDefault(f, 0) + 1);
        if (map.size() == 1) return true;
        if (map.size() == 2) {
            Iterator<Map.Entry<Integer, Integer>> it = map.entrySet().iterator();
            var a = it.next(); var b = it.next();
            int f1 = a.getKey(), c1 = a.getValue(), f2 = b.getKey(), c2 = b.getValue();
            return (f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1) ||
                   (Math.abs(f1 - f2) == 1 && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)));
        }
        return false;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def sameFreq(self, s: str) -> bool:
        from collections import Counter
        freq = Counter(s)
        count = Counter(freq.values())
        if len(count) == 1:
            return True
        if len(count) == 2:
            (f1, c1), (f2, c2) = count.items()
            return (f1 == 1 and c1 == 1) or (f2 == 1 and c2 == 1) or \
                   (abs(f1 - f2) == 1 and ((f1 > f2 and c1 == 1) or (f2 > f1 and c2 == 1)))
        return False
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
