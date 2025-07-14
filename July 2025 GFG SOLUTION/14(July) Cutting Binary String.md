---
title: "🔪 Cutting Binary String | GFG Solution ⚡"
keywords🏷️: ["🔪 binary string", "🔍 dynamic programming", "⚡ power of 5", "🎯 string splitting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Cutting Binary String problem: find minimum cuts to split binary string into substrings representing powers of 5 using dynamic programming. 🚀"
date: 📅 2025-07-14
---

# *14. Cutting Binary String*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/cutting-binary-string1342/1)

## **🧩 Problem Description**

You are given a binary string `s` consisting only of characters '0' and '1'. Your task is to split this string into the **minimum number of non-empty substrings** such that:

- Each substring represents a **power of 5** in decimal (e.g., 1, 5, 25, 125, ...).
- No substring should have **leading zeros**.

Return the minimum number of such pieces the string can be divided into.

**Note:** If it is not possible to split the string in this way, return -1.

## **📘 Examples**

### Example 1

```cpp
Input: s = "101101101"
Output: 3
Explanation: The string can be split into three substrings: "101", "101", and "101", 
each of which is a power of 5 with no leading zeros.
```

### Example 2

```cpp
Input: s = "1111101"
Output: 1
Explanation: The string can be split into one binary string "1111101" which is 125 
in decimal and a power of 5 with no leading zeros.
```

### Example 3

```cpp
Input: s = "00000"
Output: -1
Explanation: There is no substring that can be split into power of 5.
```

## **🔒 Constraints**

* $1 \le s.size() \le 30$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with **precomputed powers of 5** to efficiently find the minimum cuts:

### **Dynamic Programming + Hash Set**

1. **Early Validation:**
   * If the first character is '0', return -1 immediately (no valid split possible).

2. **Precompute Powers of 5:**
   * Generate all powers of 5 up to 10^9 (within reasonable limits for 30-bit strings).
   * Store them in a hash set for O(1) lookup.

3. **DP State Definition:**
   * `dp[i]` = minimum cuts needed to split substring from index `i` to end.
   * Base case: `dp[n] = 0` (empty string needs 0 cuts).

4. **DP Transition:**
   * For each position `i` from right to left:
     * Skip if current character is '0' (no valid substring can start with '0').
     * Try all possible substrings starting from `i`.
     * Convert binary substring to decimal using bit manipulation.
     * If the number is a power of 5, update `dp[i] = min(dp[i], 1 + dp[j+1])`.

5. **Optimization:**
   * Use bitwise operations for faster binary-to-decimal conversion.
   * Break early if the number exceeds 10^9 to avoid overflow.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the length of the string. For each starting position, we check all possible ending positions, and each check involves O(1) operations for power-of-5 validation.
* **Expected Auxiliary Space Complexity:** O(log n + n), where log n space is used for storing precomputed powers of 5 (approximately 14 powers for numbers up to 10^9), and O(n) space for the DP array.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        int n = s.size();
        unordered_set<long long> powers;
        for (long long p = 1; p <= 1e9; p *= 5) powers.insert(p);
        vector<int> dp(n + 1, n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            long long num = 0;
            for (int j = i; j < n && num <= 1e9; ++j) {
                num = (num << 1) + (s[j] & 1);
                if (powers.count(num) && dp[j + 1] < n + 1)
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Memoized Recursion with Pruning**

### 💡 Algorithm Steps:

1. Use memoization to avoid recomputation of subproblems.
2. Early pruning when number exceeds limit to prevent overflow.
3. Bitwise operations for faster binary-to-decimal conversion.
4. Direct power-of-5 checking using precomputed hash set.

```cpp
class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        unordered_set<long long> p5;
        for (long long x = 1; x <= 1e9; x *= 5) p5.insert(x);
        unordered_map<int, int> memo;
        function<int(int)> solve = [&](int pos) -> int {
            if (pos == s.size()) return 0;
            if (memo.count(pos)) return memo[pos];
            if (s[pos] == '0') return memo[pos] = 1e9;
            int res = 1e9;
            long long num = 0;
            for (int i = pos; i < s.size() && num <= 1e9; ++i) {
                num = (num << 1) + (s[i] & 1);
                if (p5.count(num)) {
                    int next = solve(i + 1);
                    if (next < 1e9) res = min(res, 1 + next);
                }
            }
            return memo[pos] = res;
        };
        int ans = solve(0);
        return ans >= 1e9 ? -1 : ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log n)
* **Auxiliary Space:** 💾 O(n) - for memoization table

### ✅ **Why This Approach?**

* Natural recursive structure makes logic clear.
* Memoization prevents redundant calculations.
* Easy to understand and debug step by step.

## 📊 **3️⃣ BFS with State Compression**

### 💡 Algorithm Steps:

1. Use BFS to find minimum cuts level by level.
2. Each state represents current position in string.
3. Explore all valid power-of-5 substrings from current position.
4. Level-order traversal ensures we find minimum cuts first.

```cpp
class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        int n = s.size();
        unordered_set<long long> pow5;
        for (long long p = 1; p <= 1e9; p *= 5) pow5.insert(p);
        queue<int> q;
        vector<bool> vis(n + 1, false);
        q.push(0);
        vis[0] = true;
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int t = 0; t < sz; ++t) {
                int pos = q.front();
                q.pop();
                if (pos == n) return level;
                if (s[pos] == '0') continue;
                long long num = 0;
                for (int i = pos; i < n && num <= 1e9; ++i) {
                    num = (num << 1) + (s[i] & 1);
                    if (pow5.count(num) && !vis[i + 1]) {
                        vis[i + 1] = true;
                        q.push(i + 1);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²)
* **Auxiliary Space:** 💾 O(n) - for queue and visited array

### ✅ **Why This Approach?**

* Guarantees finding minimum cuts first.
* Level-order exploration is intuitive.
* Natural BFS structure for shortest path problems.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **DP with Hash Set**            | 🟢 O(n²)              | 🟡 O(log n + n)        | 🚀 Optimal for most cases        | 💾 Hash table overhead               |
| 🔺 **Memoized Recursion**          | 🟡 O(n² log n)        | 🟡 O(n)                 | 🔧 Natural recursive structure    | 💾 Function call overhead            |
| ⏰ **BFS Approach**                | 🟢 O(n²)              | 🟡 O(n)                 | ⚡ Guarantees minimum cuts        | 🔧 Queue management overhead         |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **General purpose, balanced performance**          | 🥇 **DP with Hash Set**              | ★★★★★                     |
| 🎯 **Recursive thinking preference**                 | 🥈 **Memoized Recursion**            | ★★★★☆                     |
| 🚀 **Shortest path guarantee needed**                | 🥉 **BFS Approach**                  | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int cuts(String s) {
        if (s.charAt(0) == '0') return -1;
        int n = s.length();
        Set<Long> powers = new HashSet<>();
        for (long p = 1; p <= 1000000000L; p *= 5) powers.add(p);
        int[] dp = new int[n + 1];
        Arrays.fill(dp, n + 1);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') continue;
            long num = 0;
            for (int j = i; j < n && num <= 1000000000L; ++j) {
                num = (num << 1) + (s.charAt(j) - '0');
                if (powers.contains(num) && dp[j + 1] <= n)
                    dp[i] = Math.min(dp[i], 1 + dp[j + 1]);
            }
        }
        return dp[0] > n ? -1 : dp[0];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def cuts(self, s):
        if s[0] == '0': return -1
        n = len(s)
        powers = set()
        p = 1
        while p <= 10**9:
            powers.add(p)
            p *= 5
        dp = [n + 1] * (n + 1)
        dp[n] = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '0': continue
            num = 0
            for j in range(i, n):
                num = (num << 1) + int(s[j])
                if num > 10**9: break
                if num in powers and dp[j + 1] <= n:
                    dp[i] = min(dp[i], 1 + dp[j + 1])
        return -1 if dp[0] > n else dp[0]
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
