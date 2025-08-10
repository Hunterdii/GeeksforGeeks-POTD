---
title: "🔁 Palindrome SubStrings | GFG Solution 🎯"
keywords🏷️: ["🔁 palindrome substrings", "🎯 center expansion", "📍 two pointers", "🔍 string processing", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Palindrome SubStrings problem: count all palindromic substrings of length ≥ 2 using efficient center expansion technique. 🚀"
date: 📅 2025-08-10
---

# *10. Palindrome SubStrings*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1)

## **🧩 Problem Description**

You are given a string `s`. Your task is to count all **palindromic sub-strings** present in the string where the length of the palindromic sub-string must be **greater than or equal to 2**.

A substring is palindromic if it reads the same forwards and backwards. The goal is to efficiently count all such valid palindromic substrings.

## **📘 Examples**

### Example 1

```cpp
Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aba", "aa", "baab".
```

### Example 2

```cpp
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings (of length > 1) are: "aa", "aa", "aaa".
```

### Example 3

```cpp
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings (of length > 1) are: "bb", "abba", "aea", "eae".
```

## **🔒 Constraints**

* $2 \le s.size() \le 5 \times 10^3$
* $s$ contains only lowercase english characters

## **✅ My Approach**

The optimal approach uses the **Center Expansion** technique to efficiently find all palindromic substrings:

### **Center Expansion Technique**

1. **Core Idea:**
   * For each possible center position, expand outwards to find all palindromes.
   * Handle both odd-length (single center) and even-length (two adjacent centers) palindromes.

2. **Algorithm Steps:**
   * For each index `i` from 0 to n-1:
     * **Odd-length palindromes:** Expand around center `i` with left=i-1, right=i+1
     * **Even-length palindromes:** Expand around centers `i` and `i+1` with left=i, right=i+1
   * Continue expansion while characters match and boundaries are valid.
   * Count each valid palindrome found during expansion.

3. **Expansion Process:**
   * Start from potential center(s) and expand outwards.
   * While `left >= 0`, `right < n`, and `s[left] == s[right]`:
     * Increment count (valid palindrome found).
     * Move `left--` and `right++` to check longer palindromes.

4. **Why This Works:**
   * Every palindrome has a center (either single character or between two characters).
   * By checking all possible centers, we capture all palindromes.
   * Expansion ensures we find palindromes of all lengths from each center.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the length of the string. In the worst case (all characters same), each center can expand to create O(n) palindromes, and we have O(n) centers.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables like pointers and counters, regardless of input size.



## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        auto expand = [&](int l, int r) {
            while (l >= 0 && r < n && s[l--] == s[r++]) ans++;
        };
        for (int i = 0; i < n; i++) {
            expand(i - 1, i + 1); 
            expand(i, i + 1);     
        }
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Create a 2D DP table where dp[i][j] represents if substring from i to j is palindrome.
2. Fill two-character substrings first (skip single characters as we want length > 1).
3. For longer substrings, check if first and last characters match and inner substring is palindrome.
4. Count only palindromic substrings with length greater than 1.

```cpp
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) dp[i][i + 1] = true, ans++;
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Fill DP table for all substrings
* **Auxiliary Space:** 💾 O(n²) - 2D DP table storage

### ✅ **Why This Approach?**

* Systematic bottom-up approach
* Can be extended to find longest palindromic substring
* Clear state transitions and memoization

## 📊 **3️⃣ Manacher's Algorithm**

### 💡 Algorithm Steps:

1. Transform string by inserting '#' between characters to handle even/odd length uniformly.
2. Use previously computed palindrome information to avoid redundant checks.
3. Maintain rightmost boundary of discovered palindromes for optimization.
4. Count palindromes efficiently using symmetry properties.

```cpp
class Solution {
public:
    int countPS(string &s) {
        string t = "#";
        for (char c : s) t += c, t += '#';
        int n = t.size(), ans = 0, center = 0, right = 0;
        vector<int> p(n, 0);
        for (int i = 0; i < n; i++) {
            if (i < right) p[i] = min(right - i, p[2 * center - i]);
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && 
                   t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > right) center = i, right = i + p[i];
            ans += p[i] / 2;
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear time processing
* **Auxiliary Space:** 💾 O(n) - Transformed string and palindrome array

### ✅ **Why This Approach?**

* Optimal linear time complexity
* Handles both even and odd length palindromes uniformly
* Advanced algorithm for competitive programming

## 📊 **4️⃣ Brute Force with Optimizations**

### 💡 Algorithm Steps:

1. Check every possible substring for palindrome property.
2. Use early termination when characters don't match.
3. Optimize by checking from both ends simultaneously.
4. Skip obviously non-palindromic cases early.

```cpp
class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = i, r = j;
                bool isPalin = true;
                while (l < r) {
                    if (s[l] != s[r]) {
                        isPalin = false;
                        break;
                    }
                    l++, r--;
                }
                if (isPalin) ans++;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n³) - Three nested loops
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Simple and intuitive implementation
* Easy to understand and debug
* Good for small input sizes

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1120 test cases due to time constraints).


## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Center Expansion**           | 🟢 O(n²)               | 🟢 O(1)                 | 🚀 Optimal space, intuitive      | 🔧 Careful center handling needed    |
| 🔍 **Dynamic Programming**        | 🟢 O(n²)               | 🟡 O(n²)                | 📖 Clear state transitions       | 💾 Extra space for DP table          |
| 📊 **Manacher's Algorithm**       | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Linear time complexity        | 🐌 Complex implementation logic      |
| 🔄 **Brute Force**                | 🟡 O(n³)               | 🟢 O(1)                 | ⭐ Simple to implement            | 🔧 Inefficient for large inputs      |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal time-space balance**                 | 🥇 **Center Expansion**         | ★★★★★                     |
| 📖 **Need to find actual palindromes**            | 🥈 **Dynamic Programming**           | ★★★★☆                     |
| 🔧 **Large inputs, need linear time**             | 🥉 **Manacher's Algorithm**          | ★★★★★                     |
| 🎯 **Learning/Simple implementation**             | 🏅 **Brute Force**                   | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int countPS(String s) {
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; i++) {
            ans += expand(s, i - 1, i + 1); 
            ans += expand(s, i, i + 1);     
        }
        return ans;
    }

    private int expand(String s, int l, int r) {
        int cnt = 0, n = s.length();
        while (l >= 0 && r < n && s.charAt(l--) == s.charAt(r++)) cnt++;
        return cnt;
    }
}

```

## **🐍 Code (Python)**

```python
class Solution:
    def countPS(self, s):
        n, ans = len(s), 0
        def go(l, r):
            nonlocal ans
            while l >= 0 and r < n and s[l] == s[r]:
                ans += 1
                l -= 1
                r += 1
        for i in range(n):
            go(i-1, i+1)
            go(i, i+1)
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
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>
