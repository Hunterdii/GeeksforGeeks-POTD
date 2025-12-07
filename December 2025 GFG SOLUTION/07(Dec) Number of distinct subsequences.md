---
title: "🔤 Number of Distinct Subsequences | GFG Solution 🔍"
keywords🏷️: ["🔤 distinct subsequences", "🔍 dynamic programming", "📍 string manipulation", "📈 modular arithmetic", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Number of Distinct Subsequences problem: find the count of distinct subsequences of a string using dynamic programming with modulo arithmetic. 🚀"
date: 📅 2023-12-07
---

# *07. Number of Distinct Subsequences*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1)

## **🧩 Problem Description**

Given a string `str` consisting of lowercase English alphabets, the task is to find the number of distinct subsequences of the string.

**Note:** Answer can be very large, so output will be answer modulo 10^9+7.

A subsequence is a sequence that can be derived from another sequence by deleting zero or more elements without changing the order of the remaining elements. For example, "abc" is a subsequence of "aebdc" but "aec" is not.

## **📘 Examples**

### Example 1

```cpp
Input: str = "gfg"
Output: 7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg".
```

### Example 2

```cpp
Input: str = "ggg"
Output: 4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".
```

## **🔒 Constraints**

* $1 \le |str| \le 10^5$
* `str` contains lowercase English alphabets

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** to efficiently count distinct subsequences:

### **Dynamic Programming with Last Occurrence Tracking**

1. **Understanding Subsequences:**
   * For any string, the number of subsequences is 2^n (including empty string).
   * However, when characters repeat, some subsequences become identical.
   * We need to count only distinct subsequences.

2. **DP State Definition:**
   * Let `dp[i]` represent the number of distinct subsequences of the prefix ending at index i.
   * Initialize `dp[0] = 1` for the empty subsequence.

3. **Recurrence Relation:**
   * When adding a new character, we can either include it in existing subsequences or not.
   * This doubles the count of subsequences: `dp[i] = 2 * dp[i-1]`.
   * However, if the character has appeared before, we need to subtract the count of subsequences ending with the previous occurrence to avoid duplicates.
   * If `last[c]` represents the last index where character `c` appeared, then:
     `dp[i] = 2 * dp[i-1] - dp[last[c]-1]` (if character `c` has appeared before).

4. **Optimization:**
   * Instead of storing the entire DP array, we can optimize space by just keeping track of the current result.
   * We maintain an array `last` to store the last occurrence of each character.

5. **Modulo Operation:**
   * Since the result can be very large, we take modulo 10^9+7 at each step to prevent overflow.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We process each character exactly once.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a fixed-size array of 26 elements to track last occurrences, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int distinctSubseq(string& str) {
        int n = str.size(), mod = 1e9 + 7, res = 1;
        vector<int> last(26);
        for (int i = 0; i < n; i++) {
            int idx = str[i] - 'a';
            int cur = (2LL * res % mod - last[idx] + mod) % mod;
            last[idx] = res;
            res = cur;
        }
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ HashMap-Based Approach**

### 💡 Algorithm Steps:

1. Use unordered map to store last occurrence of each character dynamically.
2. Double the subsequence count at each step to include current character.
3. Subtract previously counted subsequences ending with same character to avoid duplicates.
4. Update map with current subsequence count for the character.

```cpp
class Solution {
public:
    int distinctSubseq(string& str) {
        int mod = 1e9 + 7, res = 1;
        unordered_map<char, int> mp;
        for (char c : str) {
            int cur = (2LL * res % mod - mp[c] + mod) % mod;
            mp[c] = res;
            res = cur;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through string
* **Auxiliary Space:** 💾 O(k) - Map stores unique characters only (k ≤ 26)

### ✅ **Why This Approach?**

* Works with any character set beyond lowercase letters
* Dynamic memory allocation based on actual characters present
* Cleaner code without fixed array size assumptions

## 📊 **3️⃣ DP Array Approach**

### 💡 Algorithm Steps:

1. Create DP array where dp[i] represents distinct subsequences up to index i.
2. Initialize dp[0] as 1 for empty subsequence base case.
3. For each position calculate by doubling previous count minus duplicates.
4. Track last occurrence separately to handle repeated characters correctly.

```cpp
class Solution {
public:
    int distinctSubseq(string& str) {
        int n = str.size(), mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[0] = 1;
        unordered_map<char, int> last;
        for (int i = 1; i <= n; i++) {
            dp[i] = (2 * dp[i - 1]) % mod;
            if (last.count(str[i - 1]))
                dp[i] = (dp[i] - dp[last[str[i - 1]] - 1] + mod) % mod;
            last[str[i - 1]] = i;
        }
        return dp[n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear traversal with constant operations
* **Auxiliary Space:** 💾 O(n) - DP array stores all intermediate states

### ✅ **Why This Approach?**

* Explicit DP state representation for clarity
* Easy to trace intermediate results for debugging
* Standard DP pattern for subsequence problems

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Array-Based**                | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Fastest with fixed array       | 🔧 Limited to lowercase letters      |
| 🗺️ **HashMap-Based**              | 🟢 O(n)                | 🟢 O(k)                 | 📖 Flexible character set         | 💾 Slight overhead from map          |
| 📊 **DP Array**                   | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Clear state representation     | 💾 Extra space for all states        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Competitive programming**                        | 🥇 **Array-Based**                   | ★★★★★                     |
| 📖 **Extended character sets**                        | 🥈 **HashMap-Based**                 | ★★★★☆                     |
| 🔧 **Learning DP patterns**                           | 🥉 **DP Array**                      | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int distinctSubseq(String str) {
        int n = str.length(), mod = 1000000007, res = 1;
        int[] last = new int[26];
        for (int i = 0; i < n; i++) {
            int idx = str.charAt(i) - 'a';
            int cur = (int)((2L * res % mod - last[idx] + mod) % mod);
            last[idx] = res;
            res = cur;
        }
        return res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def distinctSubseq(self, str):
        mod, res = 10**9 + 7, 1
        last = [0] * 26
        for c in str:
            idx = ord(c) - ord('a')
            cur = (2 * res - last[idx]) % mod
            last[idx] = res
            res = cur
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

