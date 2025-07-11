---
title: "1️⃣ Trail of Ones | GFG Solution 🔍"
keywords🏷️: ["1️⃣ binary strings", "🔍 dynamic programming", "📍 consecutive ones", "📈 bit manipulation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Trail of Ones problem: count binary strings of length n with at least one pair of consecutive 1's using dynamic programming approach. 🚀"
date: 📅 2025-07-11
---

# *11. Trail of Ones*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/trail-of-ones3242/1)

## **🧩 Problem Description**

Given an integer `n`, the task is to count the number of binary strings of length `n` that contains **at least one pair of consecutive 1's**.

A binary string is a sequence made up of only 0's and 1's. We need to find how many such strings of length `n` have at least one occurrence of "11" as a substring.

## **📘 Examples**

### Example 1

```cpp
Input: n = 2
Output: 1
Explanation: There are 4 strings of length 2, the strings are 00, 01, 10, and 11. 
Only the string 11 has consecutive 1's.
```

### Example 2

```cpp
Input: n = 3
Output: 3
Explanation: There are 8 strings of length 3, the strings are 000, 001, 010, 011, 100, 101, 110 and 111. 
The strings with consecutive 1's are 011, 110 and 111.
```

### Example 3

```cpp
Input: n = 5
Output: 19
Explanation: There are 19 strings having at least one pair of consecutive 1's.
```

## **🔒 Constraints**

* $2 \le n \le 30$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** with a complementary counting strategy. Instead of directly counting strings with consecutive 1's, we count strings **without** consecutive 1's and subtract from the total.

### **Dynamic Programming Approach**

1. **Key Insight:**
   * Total binary strings of length n = 2^n
   * Strings with at least one consecutive 1's = Total - Strings with no consecutive 1's

2. **State Definition:**
   * Let `a` = number of valid strings ending with 0
   * Let `b` = number of valid strings ending with 1

3. **Recurrence Relation:**
   * For strings ending with 0: we can append 0 to any valid string (both ending with 0 or 1)
   * For strings ending with 1: we can only append 1 to strings ending with 0 (to avoid consecutive 1's)
   * `new_a = a + b` (append 0 to any valid string)
   * `new_b = a` (append 1 only to strings ending with 0)

4. **Base Cases:**
   * For n=1: a=1 (string "0"), b=1 (string "1")
   * Total valid strings without consecutive 1's = a + b

5. **Final Answer:**
   * Answer = 2^n - (a + b)

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the binary string. We iterate through n positions once, performing constant time operations at each step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing the two variables `a` and `b`, regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countConsec(int n) {
        int a = 0, b = 0;
        for (int i = n; i; i--) {
            int tmp = a + b;
            b = a + (1 << (n - i));
            a = tmp;
        }
        return a;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Single Variable Approach**

### 💡 Algorithm Steps:

1. Use single accumulator for space optimization
2. Compute powers of 2 inline using bit shifting
3. Minimize memory allocations
4. Direct bit manipulation for efficiency

```cpp
class Solution {
public:
    int countConsec(int n) {
        int curr = 0, next = 0;
        for (int i = 0; i < n; i++) {
            int temp = curr + next;
            next = curr + (1 << i);
            curr = temp;
        }
        return curr;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Zero extra space allocation
* Direct bit shifting operations
* Optimal register usage

## 📊 **3️⃣ Fibonacci-Based Approach**

### 💡 Algorithm Steps:

1. Recognize that strings without consecutive 1's follow Fibonacci pattern
2. Use iterative Fibonacci calculation
3. Subtract from total possible strings

```cpp
class Solution {
public:
    int countConsec(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        int fib1 = 1, fib2 = 2; 
        for (int i = 3; i <= n + 1; i++) {
            int temp = fib1 + fib2;
            fib1 = fib2;
            fib2 = temp;
        }
        return (1 << n) - fib2; 
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Clear mathematical foundation
* Easy to understand and verify
* Direct Fibonacci relationship

## 📊 **4️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Define recursive function for counting valid strings
2. Use memoization to avoid redundant calculations
3. Calculate complement to get final answer

```cpp
class Solution {
private:
    unordered_map<string, int> memo;
    int countValid(int pos, int lastBit, int n) {
        if (pos == n) return 1;
        string key = to_string(pos) + "_" + to_string(lastBit);
        if (memo.find(key) != memo.end()) return memo[key];
        int result = 0;
        result += countValid(pos + 1, 0, n); 
        if (lastBit != 1) { 
            result += countValid(pos + 1, 1, n);
        }
        return memo[key] = result;
    }
public:
    int countConsec(int n) {
        memo.clear();
        int validStrings = countValid(0, -1, n);
        return (1 << n) - validStrings;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n)
* **Auxiliary Space:** 💾 O(n)

### ✅ **Why This Approach?**

* Intuitive recursive thinking
* Memoization prevents redundant work
* Easy to extend for variations

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Two Variable DP**            | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space usage           | 💾 Bit manipulation complexity        |
| 🔺 **Single Variable**            | 🟢 O(n)                | 🟢 O(1)                 | 🔧 Minimal operations            | 💾 Still requires loop               |
| 🔄 **Fibonacci-Based**            | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Clear mathematical foundation  | 🧮 Requires Fibonacci knowledge      |
| 🔑 **Recursive + Memoization**    | 🟢 O(n)                | 🟡 O(n)                 | 🔧 Intuitive approach            | 💾 Extra space for memoization       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 📊 **Balanced efficiency**                          | 🥇 **Two Variable DP**               | ★★★★★                     |
| 🎯 **Memory constrained**                           | 🥈 **Single Variable**               | ★★★★☆                     |
| 🔧 **Educational/Clear logic**                      | 🥉 **Fibonacci-Based**               | ★★★★☆                     |
| 📚 **Learning recursion**                           | 🎖️ **Recursive + Memoization**       | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countConsec(int n) {
        int a = 0, b = 0;
        for (int i = n; i > 0; i--) {
            int tmp = a + b;
            b = a + (1 << (n - i));
            a = tmp;
        }
        return a;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countConsec(self, n: int) -> int:
        a = b = 0
        for i in range(n, 0, -1):
            a, b = a + b, a + (1 << (n - i))
        return a
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

