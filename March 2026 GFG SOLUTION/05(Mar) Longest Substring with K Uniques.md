---
title: "🔤 Longest Substring with K Uniques | GFG Solution 🎯"
keywords🏷️: ["🔤 substring", "🔍 sliding window", "📊 hash map", "📈 k distinct", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Longest Substring with K Uniques: find longest substring with exactly k distinct characters using sliding window technique. 🚀"
date: 📅 2025-03-05
---

# *05. Longest Substring with K Uniques*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1)

## **🧩 Problem Description**

You are given a string `s` consisting only of lowercase alphabets and an integer `k`. Your task is to find the length of the **longest substring** that contains **exactly k distinct characters**.

**Note:** If no such substring exists, return -1.

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

The optimal solution uses **Sliding Window with Hash Map**:

### **Sliding Window Strategy**

1. **Key Insight:**
   * Use two pointers to maintain a window of characters.
   * Track distinct character count in current window.
   * Expand window when distinct count < k, contract when > k.

2. **Hash Map Usage:**
   * Store character frequencies in the current window.
   * Map size gives count of distinct characters.
   * Remove characters when frequency becomes 0.

3. **Window Management:**
   * Expand: Add character at right pointer to map.
   * Contract: Remove character at left pointer from map.
   * Update result only when distinct count equals exactly k.

4. **Algorithm Steps:**
   * Initialize left and right pointers at 0.
   * Expand window by moving right pointer.
   * If distinct count > k, shrink from left.
   * Track maximum length when distinct count == k.
   * Return -1 if no valid substring found.

**Why This Works:** The sliding window ensures we check all possible substrings efficiently while maintaining exactly k distinct characters through dynamic expansion and contraction.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is visited at most twice (once by right pointer during expansion and once by left pointer during contraction).
* **Expected Auxiliary Space Complexity:** O(k), where k is the number of distinct characters allowed. In the worst case, the hash map stores at most k+1 characters (when we're about to shrink the window), which is O(k) space.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char, int> mp;
        int l = 0, res = -1;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                if (--mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k) res = max(res, r - l + 1);
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Frequency Array Approach**

### 💡 Algorithm Steps:

1. Use array of size 26 to track character frequencies.
2. Maintain count of distinct characters separately.
3. Expand window and update frequency array.
4. Contract window when distinct count exceeds k.

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        int maxi = -1;
        vector<int> fre(26, 0);
        while (j < n) {
            fre[s[j] - 'a']++;
            if (fre[s[j] - 'a'] == 1)
                cnt++;
            while (cnt > k) {
                fre[s[i] - 'a']--;
                if (fre[s[i] - 'a'] == 0)
                    cnt--;
                i++;
            }
            if (cnt == k) {
                maxi = max(maxi, j - i + 1);
            }
            j++;
        }
        return maxi;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with constant time operations
* **Auxiliary Space:** 💾 O(1) - Fixed size array of 26 elements

### ✅ **Why This Approach?**

* Space efficient with fixed array size
* Faster access than hash map (array indexing)
* Good for lowercase letters only

## 📊 **3️⃣ Brute Force Approach**

### 💡 Algorithm Steps:

1. Try all possible substrings starting from each position.
2. For each substring, count distinct characters using a set.
3. If distinct count equals k, update maximum length.
4. Return maximum length found or -1.

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size(), maxLen = -1;
        for (int i = 0; i < n; i++) {
            unordered_set<char> distinct;
            for (int j = i; j < n; j++) {
                distinct.insert(s[j]);
                if (distinct.size() == k)
                    maxLen = max(maxLen, j - i + 1);
                else if (distinct.size() > k)
                    break;
            }
        }
        return maxLen;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops for all substrings
* **Auxiliary Space:** 💾 O(k) - Set size bounded by k

### ✅ **Why This Approach?**

* Simple and straightforward
* Easy to understand and debug
* Good for small strings

## 📊 **4️⃣ Optimized Map with Early Termination**

### 💡 Algorithm Steps:

1. Check if string has at least k distinct characters first.
2. If not, return -1 immediately.
3. Apply sliding window with hash map.
4. Track maximum when window has exactly k distinct chars.

```cpp
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_set<char> allChars(s.begin(), s.end());
        if (allChars.size() < k) return -1;
        
        unordered_map<char, int> mp;
        int l = 0, res = -1;
        for (int r = 0; r < s.size(); r++) {
            mp[s[r]]++;
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k)
                res = max(res, r - l + 1);
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear with early termination check
* **Auxiliary Space:** 💾 O(k) - Map and set storage

### ✅ **Why This Approach?**

* Early termination saves time for invalid cases
* Optimized for cases where k > distinct chars
* Clear validation before processing

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Hash Map Sliding**           | 🟢 O(n)                | 🟡 O(k)                 | 🚀 Flexible, handles any chars    | 🔧 Hash map overhead                 |
| 📊 **Frequency Array**            | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Fastest, constant space        | 🔧 Limited to lowercase only         |
| 🔄 **Brute Force**                | 🔴 O(n²)               | 🟡 O(k)                 | 📖 Simple to understand           | 🐌 Quadratic time                    |
| 🔍 **Early Termination**          | 🟢 O(n)                | 🟡 O(k)                 | 🎯 Optimized for invalid cases    | 🔧 Extra initial check               |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **General case, any characters**                   | 🥇 **Hash Map Sliding**              | ★★★★★                     |
| ⚡ **Lowercase only, max performance**                | 🥈 **Frequency Array**               | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥉 **Brute Force**                   | ★★★☆☆                     |
| 🎯 **Many invalid inputs expected**                   | 🏅 **Early Termination**             | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int longestKSubstr(String s, int k) {
        HashMap<Character, Integer> mp = new HashMap<>();
        int l = 0, res = -1;
        for (int r = 0; r < s.length(); r++) {
            mp.put(s.charAt(r), mp.getOrDefault(s.charAt(r), 0) + 1);
            while (mp.size() > k) {
                mp.put(s.charAt(l), mp.get(s.charAt(l)) - 1);
                if (mp.get(s.charAt(l)) == 0) mp.remove(s.charAt(l));
                l++;
            }
            if (mp.size() == k) res = Math.max(res, r - l + 1);
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def longestKSubstr(self, s, k):
        mp = {}
        l = res = 0
        res = -1
        for r in range(len(s)):
            mp[s[r]] = mp.get(s[r], 0) + 1
            while len(mp) > k:
                mp[s[l]] -= 1
                if mp[s[l]] == 0:
                    del mp[s[l]]
                l += 1
            if len(mp) == k:
                res = max(res, r - l + 1)
        return res
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
