---
title: "🔢 Count Numbers Containing Specific Digits | GFG Solution 🔍"
keywords🏷️: ["🔢 count numbers", "🔍 combinatorics", "📍 digit counting", "📈 complement counting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count Numbers Containing Specific Digits problem: find total n-digit numbers containing at least one digit from given array using complement counting technique. 🚀"
date: 📅 2025-07-20
---

# *20. Count Numbers Containing Specific Digits*

The problem can be found at the following link: 🔗 [Question Link](http://geeksforgeeks.org/problems/count-numbers-containing-specific-digits/1)

## **🧩 Problem Description**

You are given an integer `n` representing the number of digits in a number, and an array `arr[]` containing digits from 0 to 9. Your task is to count how many **n-digit positive integers** can be formed such that **at least one digit** from the array `arr[]` appears in the number.

An n-digit positive integer is a number that has exactly n digits and doesn't start with 0 (except when n=1, where single digit 0 is not considered a positive integer).

## **📘 Examples**

### Example 1

```cpp
Input: n = 1, arr[] = [1, 2, 3]
Output: 3
Explanation: Only the single-digit numbers [1, 2, 3] satisfy the condition.
```

### Example 2

```cpp
Input: n = 2, arr[] = [3, 5]
Output: 34
Explanation: There are a total of 34 two-digit numbers which contain at least one out of [3, 5].
```

## **🔒 Constraints**

* $1 \le n \le 9$
* $1 \le \text{arr.size()} \le 10$
* $0 \le \text{arr}[i] \le 9$

## **✅ My Approach**

The optimal approach uses **Complement Counting** technique with **Bit Manipulation** to efficiently calculate the result:

### **Complement Counting + Bit Manipulation**

1. **Core Insight:**
   * Instead of directly counting numbers with at least one digit from `arr[]`, we count numbers with **NO** digits from `arr[]` and subtract from total.
   * Formula: `Result = Total n-digit numbers - Numbers with forbidden digits only`

2. **Calculate Total n-digit Numbers:**
   * For n=1: Total = 9 (digits 1-9, excluding 0)
   * For n>1: Total = 9 × 10^(n-1) (first digit: 1-9, remaining: 0-9)

3. **Track Forbidden Digits:**
   * Use bit manipulation to mark allowed digits from `arr[]`
   * Count forbidden digits: `forbidden = 10 - |allowed_digits|`
   * Count non-zero forbidden digits: `nonZeroForbidden = 9 - |allowed_nonzero_digits|`

4. **Calculate Invalid Numbers:**
   * For n=1: Invalid = count of non-zero forbidden digits
   * For n>1: Invalid = nonZeroForbidden × forbidden^(n-1)

5. **Final Result:**
   * Return `Total - Invalid`

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n + |arr|), where n is the number of digits and |arr| is the size of the input array. We iterate through the array once to mark allowed digits and perform n-1 multiplications for power calculation.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for bit masks and counting variables, regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int mask = 0, nonZeroMask = 0;
        for (int d : arr) {
            mask |= (1 << d);
            if (d) nonZeroMask |= (1 << d);
        }
        int forbidden = __builtin_popcount(~mask & 1023);
        int nonZeroForbidden = __builtin_popcount(~nonZeroMask & 1022);
        
        int total = 9, pow = 1;
        for (int i = 1; i < n; i++) {
            pow *= 10;
            total *= 10;
        }
        
        int invalid = n == 1 ? nonZeroForbidden : nonZeroForbidden;
        for (int i = 1; i < n; i++) invalid *= forbidden;
        
        return total - invalid;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Bit Manipulation with Precomputed Powers**

### 💡 Algorithm Steps:

1. Use bit manipulation to track forbidden digits
2. Precompute powers to avoid repeated calculations
3. Single pass calculation for efficiency
4. Bitwise operations for faster digit checking

```cpp
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        bool allowed[10] = {};
        for (int x : arr) allowed[x] = true;
        
        int forbiddenCount = 0, nonZeroForbiddenCount = 0;
        for (int i = 0; i < 10; i++) {
            if (!allowed[i]) {
                forbiddenCount++;
                if (i != 0) nonZeroForbiddenCount++;
            }
        }
        
        int total = 9;
        int power = 1;
        for (int i = 1; i < n; i++) {
            power *= 10;
            total *= 10;
        }
        
        int invalid = (n == 1) ? nonZeroForbiddenCount : nonZeroForbiddenCount;
        for (int i = 1; i < n; i++) invalid *= forbiddenCount;
        
        return total - invalid;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + |arr|)
* **Auxiliary Space:** 💾 O(1) - constant space usage

### ✅ **Why This Approach?**

* Eliminates function call overhead
* Linear time power calculation
* Direct boolean array lookup

## 📊 **3️⃣ Mathematical Formula Approach**

### 💡 Algorithm Steps:

1. Calculate forbidden digits in single pass
2. Use mathematical formula for power calculation
3. Direct computation without loops
4. Optimized for competitive programming

```cpp
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        int goodMask = 0;
        for (int d : arr) goodMask |= (1 << d);
        
        int badDigits = 10 - __builtin_popcount(goodMask);
        int badNonZero = 9 - __builtin_popcount(goodMask & 0x3FE);
        
        long long total = 9;
        long long forbidden = badNonZero;
        
        for (int i = 1; i < n; i++) {
            total *= 10;
            forbidden *= badDigits;
        }
        
        return (int)(total - forbidden);
    }
};
```


### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(|arr| + log n) due to pow function
* **Auxiliary Space:** 💾 O(|arr|) for the unordered_set

### ✅ **Why This Approach?**

* Single bit mask for all digits
* Built-in popcount for efficiency
* Minimal memory footprint

## 📊 **4️⃣ Iterative Power Calculation**

### 💡 Algorithm Steps:

1. Count forbidden digits using array indexing
2. Iterative power calculation with accumulation
3. Early termination optimization
4. Cache-friendly memory access

```cpp
class Solution {
public:
    int countValid(int n, vector<int>& arr) {
        bool digit[10] = {};
        for (int x : arr) digit[x] = true;
        
        int f = 0, f0 = 0;
        for (int i = 0; i < 10; i++) {
            if (!digit[i]) {
                f++;
                if (i) f0++;
            }
        }
        
        long long total = 9, invalid = f0, base = 1;
        for (int i = 1; i < n; i++) {
            total *= 10;
            base *= f;
            if (i == n - 1) invalid *= base;
        }
        
        return (int)(total - invalid);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n + |arr|)
* **Auxiliary Space:** 💾 O(1) - fixed array size

### ✅ **Why This Approach?**

* Optimized loop structure
* Reduced multiplication operations
* Better cache locality

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🔍 **Bit Manipulation**           | 🟢 O(n + \|arr\|)     | 🟢 O(1)                 | 🚀 Fastest bit operations         | 💾 Requires bit manipulation knowledge|
| 🔺 **Precomputed Powers**         | 🟢 O(n + \|arr\|)     | 🟢 O(1)                 | 🔧 No function call overhead     | 💾 Slightly more complex logic       |
| ⏰ **Mathematical Formula**       | 🟡 O(\|arr\| + log n)   | 🟡 O(\|arr\|)             | 🚀 Minimal memory usage          | 🔄 Requires mathematical insight      |
| 📊 **Iterative Calculation**      | 🟢 O(n + \|arr\|)     | 🟢 O(1)                 | ⚡ Cache-friendly access         | 🔧 More complex loop structure        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Competitive Programming**                        | 🥇 **Bit Manipulation**              | ★★★★★                     |
| 📊 **General Purpose**                               | 🥈 **Precomputed Powers**            | ★★★★☆                     |
| 🎯 **Memory Constrained**                            | 🥉 **Mathematical Formula**          | ★★★★☆                     |
| 🚀 **Educational/Readable**                          | 🏅 **Iterative Calculation**         | ★★★☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int countValid(int n, int[] arr) {
        boolean[] allowed = new boolean[10];
        for (int d : arr) allowed[d] = true;
        
        int forbidden = 0, nonZeroForbidden = 0;
        for (int i = 0; i < 10; i++) {
            if (!allowed[i]) {
                forbidden++;
                if (i != 0) nonZeroForbidden++;
            }
        }
        
        long total = 9;
        for (int i = 1; i < n; i++) total *= 10;
        
        long invalid = (n == 1) ? nonZeroForbidden : nonZeroForbidden;
        for (int i = 1; i < n; i++) invalid *= forbidden;
        
        return (int)(total - invalid);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countValid(self, n, arr):
        allowed = [False] * 10
        for d in arr:
            allowed[d] = True
        
        forbidden = sum(1 for i in range(10) if not allowed[i])
        non_zero_forbidden = sum(1 for i in range(1, 10) if not allowed[i])
        
        total = 9 * (10 ** (n - 1))
        invalid = non_zero_forbidden * (forbidden ** (n - 1)) if n > 1 else non_zero_forbidden
        
        return total - invalid
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
