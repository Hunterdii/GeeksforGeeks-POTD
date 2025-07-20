---
title: "📐 LCM Triplet | GFG Solution ⚙️"
keywords🏷️:
  [
    "📐 LCM triplet",
    "🧮 mathematical optimization",
    "📊 number theory",
    "🎯 greedy approach",
    "📘 GFG",
    "🏁 competitive programming",
    "📚 DSA",
  ]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the LCM Triplet problem: find maximum possible LCM by selecting three numbers ≤ n using mathematical optimization and greedy approach. 🚀"
date: 📅 2025-07-18
---

# _18. LCM Triplet_

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/lcm-triplet1501/1)

## **🧩 Problem Description**

Given a number `n`, find the **maximum possible LCM** that can be obtained by selecting three numbers less than or equal to `n`.

**Note:** LCM stands for Lowest Common Multiple.

The goal is to find three numbers ≤ n such that their LCM is maximized.

## **📘 Examples**

### Example 1

```cpp
Input: n = 9
Output: 504
Explanation: 504 is the maximum LCM that can be attained by any triplet of numbers less than or equal 9.
The triplet which has this LCM is {7, 8, 9}.
```

### Example 2

```cpp
Input: n = 7
Output: 210
Explanation: 210 is the maximum LCM that can be attained by any triplet of numbers less than or equal 7.
The triplet which has this LCM is {5, 6, 7}.
```

## **🔒 Constraints**

- $1 \le n \le 10^3$

## **✅ My Approach**

The optimal approach uses **Mathematical Optimization** with **Greedy Strategy** to maximize LCM:

### **Mathematical Analysis + Greedy Selection**

1. **Key Insight:**

   - To maximize LCM, we need to choose numbers that are as large as possible and have minimal common factors.
   - The LCM of three numbers is maximized when they are pairwise coprime (gcd = 1).

2. **Case Analysis:**

   - **Case 1:** `n < 3` → Return `n` (insufficient numbers for triplet)
   - **Case 2:** `n` is odd → Choose `{n, n-1, n-2}` (consecutive numbers have small gcds)
   - **Case 3:** `n` is even and `n % 3 ≠ 0` → Choose `{n, n-1, n-3}` (avoid n-2 which is even)
   - **Case 4:** `n` is even and `n % 3 = 0` → Choose `{n-1, n-2, n-3}` (avoid n which is divisible by 3)

3. **Mathematical Reasoning:**

   - When `n` is odd: `n` and `n-1` are coprime, `n-1` and `n-2` are coprime
   - When `n` is even: avoid consecutive even numbers to minimize common factors
   - When `n % 3 = 0`: avoid `n` to prevent factor of 3 from reducing LCM

4. **Optimization:**
   - Use bitwise operations for faster even/odd checks
   - Minimize conditional branches with ternary operators
   - Perform constant-time calculations regardless of input size

## 📝 Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of arithmetic operations and conditional checks regardless of the input value n.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for storing intermediate calculations.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int lcmTriplets(int n) {
        return n < 3 ? n : n & 1 ? n * (n - 1) * (n - 2) :
               n % 3 ? n * (n - 1) * (n - 3) : (n - 1) * (n - 2) * (n - 3);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Bit Manipulation Optimized**

### 💡 Algorithm Steps:

1. Use bitwise operations for even/odd checks
2. Minimize conditional branches
3. Leverage ternary operators for compact code
4. Eliminate redundant calculations

```cpp
class Solution {
public:
    int lcmTriplets(int n) {
        if (n < 3) return n;
        int p1 = n - 1, p2 = n - 2, p3 = n - 3;
        return (n & 1) ? n * p1 * p2 : (n % 3) ? n * p1 * p3 : p1 * p2 * p3;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(1)
- **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

- Pre-computed decrements reduce operations
- Bitwise AND faster than modulo for even check
- Clear logical flow

## 📊 **3️⃣ Lookup Table Optimization**

### 💡 Algorithm Steps:

1. Use function pointers for different cases
2. Eliminate conditional checks during runtime
3. Pre-determine calculation method
4. Efficient for repeated calls

```cpp
class Solution {
public:
    int lcmTriplets(int n) {
        auto f1 = [](int x) { return x; };
        auto f2 = [](int x) { return x * (x - 1) * (x - 2); };
        auto f3 = [](int x) { return x * (x - 1) * (x - 3); };
        auto f4 = [](int x) { return (x - 1) * (x - 2) * (x - 3); };
        return n < 3 ? f1(n) : (n & 1) ? f2(n) : (n % 3) ? f3(n) : f4(n);
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(1)
- **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

- Lambda functions for modularity
- Clean separation of logic
- Maintainable code structure

## 📊 **4️⃣ Explicit Conditional Approach **

### 💡 Algorithm Steps:

1. Use explicit if-else statements for clarity
2. Calculate each case separately
3. Optimize for readability over compactness
4. Easy to debug and modify _(Optional If Main Method Not understood)_

```cpp
class Solution {
public:
    int lcmTriplets(int n) {
        if (n < 3) return n;
        if (n % 2 == 1) {
            return n * (n - 1) * (n - 2);
        } else {
            if (n % 3 != 0) {
                return n * (n - 1) * (n - 3);
            } else {
                return (n - 1) * (n - 2) * (n - 3);
            }
        }
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(1)
- **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

- Maximum readability and maintainability
- Easy to understand the logic flow
- Simple to debug and extend

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**             | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                     | ⚠️ **Cons**                            |
| --------------------------- | ---------------------- | ----------------------- | ------------------------------- | -------------------------------------- |
| 🔍 **Ternary Chain**        | 🟢 O(1)                | 🟢 O(1)                 | 🚀 Minimal code, fast execution | 💾 Hard to read for complex logic      |
| 🔺 **Bit Manipulation**     | 🟢 O(1)                | 🟢 O(1)                 | 🔧 Optimized operations         | 💾 Requires bit manipulation knowledge |
| 📊 **Function Pointers**    | 🟢 O(1)                | 🟢 O(1)                 | ⚡ Modular and maintainable     | 🔧 Lambda overhead                     |
| 🎯 **Explicit Conditional** | 🟢 O(1)                | 🟢 O(1)                 | 📖 Maximum readability          | 💾 More verbose code                   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                | 🎖️ **Recommended Approach** | 🔥 **Performance Rating** |
| ------------------------------ | --------------------------- | ------------------------- |
| ⚡ **Competitive Programming** | 🥇 **Ternary Chain**        | ★★★★★                     |
| 📊 **Production Code**         | 🥈 **Bit Manipulation**     | ★★★★☆                     |
| 🚀 **Large Scale Systems**     | 🥉 **Function Pointers**    | ★★★★☆                     |
| 🎓 **Educational/Learning**    | 🎖️ **Explicit Conditional** | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int lcmTriplets(int n) {
        return n < 3 ? n : (n & 1) == 1 ? n * (n - 1) * (n - 2) :
               n % 3 != 0 ? n * (n - 1) * (n - 3) : (n - 1) * (n - 2) * (n - 3);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def lcmTriplets(self, n):
        return n if n < 3 else n * (n - 1) * (n - 2) if n & 1 else \
               n * (n - 1) * (n - 3) if n % 3 else (n - 1) * (n - 2) * (n - 3)
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
