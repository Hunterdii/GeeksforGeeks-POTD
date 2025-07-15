---
title: "➗ Divisible by 13 | GFG Solution 🔍"
keywords🏷️: ["➗ divisible by 13", "🔍 modular arithmetic", "📍 string processing", "📈 number theory", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to check if a large number (given as string) is divisible by 13 using modular arithmetic properties. 🚀"
date: 📅 2025-07-15
---

# *15. Divisible by 13*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/divisible-by-13/1)

## **🧩 Problem Description**

Given a number represented as a string `s` (which may be very large), check whether it is divisible by 13 or not.

Since the number can be extremely large (up to 10^5 digits), we cannot convert it to integer directly. We need to use modular arithmetic properties to solve this efficiently.

## **📘 Examples**

### Example 1

```cpp
Input: s = "2911285"
Output: true
Explanation: 2911285 ÷ 13 = 223945, which is a whole number with no remainder.
```

### Example 2

```cpp
Input: s = "27"
Output: false
Explanation: 27 / 13 ≈ 2.0769..., which is not a whole number (there is a remainder).
```

### Example 3

```cpp
Input: s = "169"
Output: true
Explanation: 169 ÷ 13 = 13, which is a whole number with no remainder.
```

## **🔒 Constraints**

* $1 \le \text{s.size()} \le 10^5$
* String `s` contains only digits

## **✅ My Approach**

The optimal approach uses **Modular Arithmetic** properties to process the large number digit by digit:

### **Modular Arithmetic Method**

1. **Key Insight:**
   * For a number ABCD, we can write it as: A×1000 + B×100 + C×10 + D
   * Using modular arithmetic: (A×1000 + B×100 + C×10 + D) % 13
   * This is equivalent to: ((A%13)×(1000%13) + (B%13)×(100%13) + (C%13)×(10%13) + (D%13)) % 13

2. **Algorithm Steps:**
   * Initialize remainder `r = 0`
   * For each digit from left to right:
     * Update remainder: `r = (r × 10 + digit) % 13`
   * If final remainder is 0, the number is divisible by 13

3. **Why This Works:**
   * We build the number incrementally while keeping track of remainder
   * At each step, we maintain: `r = (current_number_so_far) % 13`
   * The multiplication by 10 shifts the previous digits left by one position
   * Adding the new digit incorporates it into our running remainder

4. **Mathematical Foundation:**
   * If we have processed digits d₁d₂...dₖ with remainder r
   * Adding digit dₖ₊₁ gives us: new_remainder = (r × 10 + dₖ₊₁) % 13
   * This maintains the invariant that r represents the remainder of the number formed so far

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the length of the string. We process each digit exactly once in a single pass through the string.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space to store the remainder variable regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            r = (r * 10 + s[i] - '0') % 13;
        }
        return !r;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Optimized Index-Based Iteration**

### 💡 Algorithm Steps:

1. Use index-based loop for better cache locality
2. Combine digit conversion with modulo operation
3. Direct boolean return without comparison

```cpp
class Solution {
public:
    bool divby13(string &s) {
        int mod = 0;
        for (size_t i = 0; i < s.size(); mod = (mod * 10 + s[i++] - 48) % 13);
        return mod == 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - single pass through string
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Compact loop structure
* Direct ASCII conversion (48 = '0')
* Efficient memory access pattern

## 📊 **3️⃣ Reverse Iteration Approach**

### 💡 Algorithm Steps:

1. Process string from right to left
2. Use power of 10 modulo 13 for each position
3. Precomputed powers for optimization

```cpp
class Solution {
public:
    bool divby13(string &s) {
        int rem = 0, pow = 1;
        for (int i = s.length() - 1; i >= 0; --i) {
            rem = (rem + (s[i] - '0') * pow) % 13;
            pow = (pow * 10) % 13;
        }
        return rem == 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - single pass through string
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Mathematical approach using positional values
* Efficient modular arithmetic
* Alternative iteration pattern

## 📊 **4️⃣ Pointer-Based Optimization**

### 💡 Algorithm Steps:

1. Use char pointer for direct memory access
2. Eliminate bounds checking overhead
3. Compact arithmetic operations

```cpp
class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        const char* p = s.c_str();
        while (*p) r = (r * 10 + *p++ - '0') % 13;
        return !r;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - single pass through string
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Direct memory access via pointer
* Eliminates string bounds checking
* Highly optimized for performance

## 📊 **5️⃣ Range-Based Loop**

### 💡 Algorithm Steps:

1. Use modern C++ range-based for loop
2. Cleaner syntax and better readability
3. Compiler optimizations for iterators

```cpp
class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        for (char c : s) {
            r = (r * 10 + c - '0') % 13;
        }
        return r == 0;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - single pass through string
* **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

* Clean, modern C++ syntax
* Automatic iterator management
* Enhanced readability

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Standard Index Loop**        | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Clean, readable syntax        | 💾 Standard performance              |
| 🔺 **Optimized Index Loop**       | 🟢 O(n)                | 🟢 O(1)                 | 🔧 Compact loop structure        | 💾 Less readable                      |
| ⏰ **Reverse Iteration**          | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Mathematical elegance         | 🔄 Additional power calculation       |
| 📊 **Pointer-Based**             | 🟢 O(n)                | 🟢 O(1)                 | ⚡ Maximum performance           | 🔧 C-style, less safe                |
| 🎯 **Range-Based Loop**          | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Modern C++, clean syntax      | 💾 Iterator overhead                  |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Maximum performance**                         | 🥇 **Pointer-Based**                 | ★★★★★                     |
| 📊 **Balanced readability/performance**           | 🥈 **Range-Based Loop**              | ★★★★☆                     |
| 🎯 **Compact code**                               | 🥉 **Optimized Index Loop**          | ★★★★☆                     |
| 🚀 **Competitive programming**                    | 🏅 **Reverse Iteration**                | ★★★★★                     |
| 🔧 **Production code**                            | 🎖️ **Standard Index Loop**           | ★★★★☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public boolean divby13(String s) {
        int r = 0;
        for (int i = 0; i < s.length(); ++i) {
            r = (r * 10 + s.charAt(i) - '0') % 13;
        }
        return r == 0;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def divby13(self, s):
        r = 0
        for c in s:
            r = (r * 10 + int(c)) % 13
        return r == 0
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
