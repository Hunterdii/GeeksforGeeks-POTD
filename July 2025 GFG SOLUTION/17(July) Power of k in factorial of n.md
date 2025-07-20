---
title: "🧮 Power of k in factorial of n | GFG Solution 🔍"
keywords🏷️:
  [
    "🧮 power of k",
    "🔍 prime factorization",
    "📍 legendre's formula",
    "📈 factorial",
    "📘 GFG",
    "🏁 competitive programming",
    "📚 DSA",
  ]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to find the highest power of k that divides n! using prime factorization and Legendre's formula. 🚀"
date: 📅 2025-07-17
---

# _17. Power of k in factorial of n_

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/power-of-k-in-n-where-k-may-be-non-prime4206/1)

## **🧩 Problem Description**

Given two positive integers `n` and `k`, determine the highest value of `x` such that `k^x` divides `n!` (n factorial) completely (i.e., `n! % (k^x) == 0`).

The task is to find the maximum power of `k` that can divide `n!` without leaving a remainder.

## **📘 Examples**

### Example 1

```cpp
Input: n = 7, k = 2
Output: 4
Explanation: 7! = 5040, and 2^4 = 16 is the highest power of 2 that divides 5040.
```

### Example 2

```cpp
Input: n = 10, k = 9
Output: 2
Explanation: 10! = 3628800, and 9² = 81 is the highest power of 9 that divides 3628800.
```

## **🔒 Constraints**

- $1 \le n \le 10^5$
- $2 \le k \le 10^5$

## **✅ My Approach**

The optimal approach uses **Prime Factorization** combined with **Legendre's Formula** to efficiently calculate the highest power of k that divides n!:

### **Prime Factorization + Legendre's Formula**

1. **Prime Factorization of k:**

   - Decompose k into its prime factors: k = p₁^a₁ × p₂^a₂ × ... × pₘ^aₘ
   - For each prime factor pᵢ with exponent aᵢ, we need to find how many times pᵢ appears in n!

2. **Apply Legendre's Formula:**

   - For each prime p, the highest power of p that divides n! is:
   - `⌊n/p⌋ + ⌊n/p²⌋ + ⌊n/p³⌋ + ...`
   - This counts how many multiples of p, p², p³, etc. are ≤ n

3. **Calculate Maximum Power:**

   - For each prime factor pᵢ with exponent aᵢ in k:
   - Find legendre_count(n, pᵢ) using Legendre's formula
   - The contribution of this prime is `legendre_count(n, pᵢ) / aᵢ`

4. **Find Minimum:**
   - The answer is the minimum of all contributions from prime factors
   - This ensures k^x divides n! for the maximum possible x

## 📝 Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(√k + Σlog_p n), where the sum is over all prime factors p of k. We factorize k in O(√k) time and apply Legendre's formula for each prime factor in O(log_p n) time.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables, without storing the prime factors explicitly.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxKPower(int n, int k) {
        int res = INT_MAX;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) k /= i, cnt++;
                int fact = 0;
                for (int p = i; p <= n; p *= i) fact += n / p;
                res = min(res, fact / cnt);
            }
        }
        if (k > 1) {
            int fact = 0;
            for (int p = k; p <= n; p *= k) fact += n / p;
            res = min(res, fact);
        }
        return res == INT_MAX ? 0 : res;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Iterative Prime Factorization**

### 💡 Algorithm Steps:

1. Factor k by iterating through all potential divisors
2. Calculate Legendre's formula inline for each prime
3. Track minimum quotient across all prime factors
4. Single-pass optimization for better cache locality

```cpp
class Solution {
public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        for (int d = 2; d * d <= k; d++) {
            int exp = 0;
            while (k % d == 0) k /= d, exp++;
            if (exp) {
                int leg = 0;
                for (int pw = d; pw <= n; pw *= d) leg += n / pw;
                ans = min(ans, leg / exp);
            }
        }
        if (k > 1) {
            int leg = 0;
            for (int pw = k; pw <= n; pw *= k) leg += n / pw;
            ans = min(ans, leg);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(√k + log_p n) for each prime p
- **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

- Eliminates vector storage overhead
- Better cache performance with inline calculations
- Reduced memory allocations

## 📊 **3️⃣ Optimized Sieve-Based Approach**

### 💡 Algorithm Steps:

1. Use trial division up to √k only
2. Handle remaining prime factor efficiently
3. Minimize function calls and loops
4. Early termination when result becomes 0

```cpp
class Solution {
public:
    int maxKPower(int n, int k) {
        int result = INT_MAX;
        for (int i = 2; i * i <= k && k > 1; i++) {
            if (k % i == 0) {
                int count = 0;
                while (k % i == 0) k /= i, count++;
                int legendre = 0;
                for (long long p = i; p <= n; p *= i) legendre += n / p;
                result = min(result, legendre / count);
                if (result == 0) return 0;
            }
        }
        if (k > 1) {
            int legendre = 0;
            for (long long p = k; p <= n; p *= k) legendre += n / p;
            result = min(result, legendre);
        }
        return result == INT_MAX ? 0 : result;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(√k + Σlog_p n) for primes p|k
- **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

- Early termination optimization
- Long long prevents overflow in multiplication
- Efficient prime factorization

## 📊 **4️⃣ Bit Manipulation Optimization**

### 💡 Algorithm Steps:

1. Handle powers of 2 separately using bit operations
2. Process odd factors with optimized loop
3. Use bit shifts for efficient division by 2
4. Combine results for final answer

```cpp
class Solution {
public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        if (k % 2 == 0) {
            int twos = __builtin_ctz(k);
            k >>= twos;
            int leg = n - __builtin_popcount(n);
            ans = min(ans, leg / twos);
        }
        for (int i = 3; i * i <= k; i += 2) {
            if (k % i == 0) {
                int exp = 0;
                while (k % i == 0) k /= i, exp++;
                int leg = 0;
                for (int p = i; p <= n; p *= i) leg += n / p;
                ans = min(ans, leg / exp);
            }
        }
        if (k > 1) {
            int leg = 0;
            for (int p = k; p <= n; p *= k) leg += n / p;
            ans = min(ans, leg);
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

- **Time:** ⏱️ O(√k + log n) optimized for powers of 2
- **Auxiliary Space:** 💾 O(1) - constant space

### ✅ **Why This Approach?**

- Efficient handling of powers of 2
- Reduced iterations for odd numbers only
- Built-in functions for bit counting

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**               | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                  | ⚠️ **Cons**                 |
| ----------------------------- | ---------------------- | ----------------------- | ---------------------------- | --------------------------- |
| 🔍 **Inline Factorization**   | 🟢 O(√k + Σlog_p n)    | 🟢 O(1)                 | 🚀 Minimal memory usage      | 💾 Repeated calculations    |
| 🔺 **Iterative Optimization** | 🟢 O(√k + Σlog_p n)    | 🟢 O(1)                 | 🔧 Better cache locality     | 💾 Similar performance      |
| ⏰ **Sieve-Based Early Exit** | 🟢 O(√k + Σlog_p n)    | 🟢 O(1)                 | 🚀 Early termination         | 🔄 Overflow handling needed |
| 📊 **Bit Manipulation**       | 🟢 O(√k + log n)       | 🟢 O(1)                 | ⚡ Optimized for powers of 2 | 🔧 Complex bit operations   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                | 🎖️ **Recommended Approach**   | 🔥 **Performance Rating** |
| ------------------------------ | ----------------------------- | ------------------------- |
| ⚡ **General purpose**         | 🥇 **Inline Factorization**   | ★★★★★                     |
| 📊 **Large k values**          | 🥈 **Sieve-Based Early Exit** | ★★★★☆                     |
| 🎯 **Powers of 2 heavy**       | 🥉 **Bit Manipulation**       | ★★★★☆                     |
| 🚀 **Competitive programming** | 🏅 **Iterative Optimization** | ★★★★★                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public int maxKPower(int n, int k) {
        int res = Integer.MAX_VALUE;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) {
                int cnt = 0;
                while (k % i == 0) { k /= i; cnt++; }
                int fact = 0;
                for (int p = i; p <= n; p *= i) fact += n / p;
                res = Math.min(res, fact / cnt);
            }
        }
        if (k > 1) {
            int fact = 0;
            for (int p = k; p <= n; p *= k) fact += n / p;
            res = Math.min(res, fact);
        }
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxKPower(self, n, k):
        res = float('inf')
        i = 2
        while i * i <= k:
            if k % i == 0:
                cnt = 0
                while k % i == 0:
                    k //= i
                    cnt += 1
                fact = 0
                p = i
                while p <= n:
                    fact += n // p
                    p *= i
                res = min(res, fact // cnt)
            i += 1
        if k > 1:
            fact = 0
            p = k
            while p <= n:
                fact += n // p
                p *= k
            res = min(res, fact)
        return res if res != float('inf') else 0
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
