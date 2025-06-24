---
title: "🦁 Lexicographically Largest String After K Deletions | GFG Solution 🔍"
keywords🏷️: ["🦁 lexicographically largest string", "🧹 remove k characters", "🧠 greedy approach", "📘 GFG", "📚 string problems", "🛠️ monotonic stack"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Lexicographically Largest String After K Deletions problem: remove exactly k characters to get the largest possible string using greedy approach. 🚀"
date: 📅 2025-06-24
---

# *24. Lexicographically Largest String After K Deletions*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1)

## **🧩 Problem Description**

Given a string `s` consisting of lowercase English letters and an integer `k`, your task is to remove exactly **k characters** from the string. The resulting string must be the **largest possible in lexicographical order**, while maintaining the **relative order** of the remaining characters.

## **📘 Examples**

### Example 1

```cpp
Input: s = "ritz", k = 2
Output: "tz"
Explanation: By removing two characters in all possible ways, we get: 
"ri", "rt", "rz", "it", "iz", and "tz". Among these, "tz" is lexicographically largest.
```

### Example 2

```cpp
Input: s = "zebra", k = 3
Output: "zr"
Explanation: Removing "e", "b", and "a" results in "zr", which is lexicographically largest.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$
* $0 \le k < \text{s.size()}$
* String consists of lowercase English letters only

## **✅ My Approach**

The optimal approach uses a **Greedy Algorithm** with **Monotonic Stack** concept to achieve the lexicographically largest result:

### **Greedy String Manipulation**

1. **Core Strategy:**
   * Remove smaller characters when a larger character appears, as long as we have deletions remaining.
   * This ensures we keep the largest possible characters in their relative positions.

2. **Algorithm Steps:**
   * Iterate through each character in the string.
   * While the result string is not empty, we have deletions left, and the last character in result is smaller than current character:
     - Remove the last character from result (this counts as one deletion).
   * Add the current character to the result.
   * After processing all characters, resize the result to final length (n - k).

3. **Key Insight:**
   * By removing smaller characters when larger ones appear, we maximize the lexicographical value of the remaining string.
   * The greedy choice at each step leads to the globally optimal solution.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. Each character is processed at most twice (once when added, once when potentially removed), resulting in linear time complexity.
* **Expected Auxiliary Space Complexity:** O(n), as we use a result string that can grow up to the size of the input string during processing.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    string maxSubseq(string &s, int k) {
        int n = s.length(), toRemove = k;
        string res;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res += c;
        }
        res.resize(n - k);
        return res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Greedy Selection Approach**

### 💡 Algorithm Steps:

1. Let `len = n - k` (final result length).
2. For each position `i` in the result (0 ≤ i < len), scan `s[start…k+i]` to pick the maximal character.
3. Append the maximal character to result, set `start` to its index + 1, and continue.
4. This ensures we always pick the largest possible character for each position while maintaining enough characters for remaining positions.

```cpp
class Solution {
public:
    string maxSubseq(string &s, int k) {
        int n = s.size(), len = n - k, start = 0;
        string res;
        for (int i = 0; i < len; ++i) {
            int mx = start;
            for (int j = start; j <= k + i; ++j)
                if (s[j] > s[mx]) mx = j;
            res += s[mx];
            start = mx + 1;
        }
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n·(n−k)) worst-case (O(n²))
* **Auxiliary Space:** 💾 O(1) - Only uses constant extra space

### ✅ **Why This Approach?**

* Simple "pick-max-in-window" logic that's easy to understand.
* No auxiliary data structures needed.
* Direct greedy selection without stack operations.

## 📊 **3️⃣ Stack-Based Monotonic Approach**

### 💡 Algorithm Steps:

1. Use a stack to maintain decreasing order of characters.
2. Pop smaller characters when a larger character is found and removals are available.
3. Handle remaining removals at the end by popping from stack.
4. Reconstruct result from stack (requires reversal).

```cpp
class Solution {
public:
    string maxSubseq(string &s, int k) {
        stack<char> st;
        int toRemove = k;
        for (char c : s) {
            while (!st.empty() && toRemove && st.top() < c) {
                st.pop();
                toRemove--;
            }
            st.push(c);
        }
        while (toRemove--) st.pop();
        string res;
        while (!st.empty()) res = st.top() + res, st.pop();
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - For stack storage

### ✅ **Why This Approach?**

* Clear stack-based implementation for monotonic sequence.
* Easier to visualize the greedy removal process.
* Classic data structure approach for such problems.

## 📊 **4️⃣ Deque-Based Sliding Window**

### 💡 Algorithm Steps:

1. Use deque to maintain potential candidates with flexible operations.
2. Remove smaller elements from back when larger element arrives.
3. Maintain size constraint throughout the process.
4. Extract final result from front of deque.

```cpp
class Solution {
public:
    string maxSubseq(string &s, int k) {
        deque<char> dq;
        int toRemove = k;
        for (char c : s) {
            while (!dq.empty() && toRemove && dq.back() < c) {
                dq.pop_back();
                toRemove--;
            }
            dq.push_back(c);
        }
        string res;
        for (int i = 0; i < s.length() - k; ++i) res += dq[i];
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - For deque storage

### ✅ **Why This Approach?**

* Flexible front and back operations.
* Natural sliding window behavior.
* Good for scenarios requiring both-end access.

## 📊 **5️⃣ Vector-Based Greedy with Index Tracking**

### 💡 Algorithm Steps:

1. Store characters with their original indices for complex tracking.
2. Apply greedy removal strategy while maintaining index information.
3. Reconstruct result maintaining original order.
4. Useful when index information is crucial for the solution.

```cpp
class Solution {
public:
    string maxSubseq(string &s, int k) {
        vector<char> res;
        int toRemove = k;
        for (char c : s) {
            while (!res.empty() && toRemove && res.back() < c) {
                res.pop_back();
                toRemove--;
            }
            res.push_back(c);
        }
        res.resize(s.length() - k);
        return string(res.begin(), res.end());
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n) - For vector storage

### ✅ **Why This Approach?**

* Explicit index tracking for complex scenarios.
* Vector operations are cache-friendly.
* Suitable when additional metadata is needed.

## 🆚 **🔍 Comprehensive Comparison of All Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | 🎯 **Best Use Case**                     | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | ---------------------------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **String Manipulation**        | 🟢 O(n)                | 🟢 O(n)                 | Competitive programming, optimal speed   | ⚡ Direct operations, minimal overhead | 🧮 String resize operations          |
| 🎯 **Greedy Selection**           | 🔴 O(n²)               | 🟢 O(1)                 | Small inputs, educational purposes       | 💾 No extra space, simple logic   | ⏰ Quadratic time complexity         |
| 🔄 **Stack-Based**                | 🟢 O(n)                | 🟡 O(n)                 | Learning data structures, clear visualization | 🔧 Clear monotonic logic        | 💾 Extra space, requires reversal   |
| 🔺 **Deque-Based**                | 🟢 O(n)                | 🟡 O(n)                 | Complex scenarios, flexible operations   | 🚀 Both-end access flexibility    | 💾 Deque operation overhead          |
| 🔍 **Vector with Index**          | 🟢 O(n)                | 🟡 O(n)                 | When index tracking is crucial          | ⚡ Cache-friendly, metadata support | 🧮 Complex pair management          |

### 🏆 **Best Choice Recommendations**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**    | 🔥 **Performance Rating** | 📝 **Notes** |
| -------------------------------------------------- | ------------------------------- | ------------------------- | ------------ |
| ⚡ Maximum performance, competitive programming    | 🥇 **String Manipulation**     | ★★★★★                     | Best overall choice |
| 🎓 Learning algorithms, understanding the logic    | 🥈 **Stack-Based**             | ★★★★☆                     | Most educational |
| 💾 Memory-constrained environments                 | 🥉 **Greedy Selection**        | ★★★☆☆                     | O(1) space but O(n²) time |
| 🔧 Complex requirements, debugging needed          | 🎖️ **Vector with Index**       | ★★★★☆                     | Easy to modify and debug |
| 📊 Flexible operations, both-end access needed     | 🏅 **Deque-Based**             | ★★★★☆                     | Good for complex scenarios |


</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static String maxSubseq(String s, int k) {
        int n = s.length(), toRemove = k;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n; i++) {
            while (toRemove > 0 && res.length() > 0 && res.charAt(res.length() - 1) < s.charAt(i)) {
                res.deleteCharAt(res.length() - 1);
                toRemove--;
            }
            res.append(s.charAt(i));
        }
        res.setLength(n - k);
        return res.toString();
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxSubseq(self, s, k):
        n, toRemove, res = len(s), k, []
        for c in s:
            while res and toRemove and res[-1] < c:
                res.pop()
                toRemove -= 1
            res.append(c)
        return ''.join(res[:n - k])
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
