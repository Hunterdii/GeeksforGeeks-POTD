---
title: "🔢 Nine Divisors | GFG Solution 🔍"
keywords🏷️:
  [
    "🔢 nine divisors",
    "🔍 number theory",
    "📍 sieve",
    "📈 prime factors",
    "📘 GFG",
    "🏁 competitive programming",
    "📚 DSA",
  ]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Nine Divisors problem: count numbers ≤ n having exactly 9 divisors using sieve and prime factorization technique. 🚀"
date: 📅 2025-07-16
---

# _16. Nine Divisors_

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/nine-divisors3751/1)

## **🧩 Problem Description**

Given a positive integer `n`, you need to count the numbers less than or equal to `n` having exactly **9 divisors**.

### 📌 Key Insight:

A number has exactly 9 divisors if and only if its prime factorization fits into one of the following patterns:

- $p^8$ → 9 divisors (as $(8 + 1) = 9$)
- $p^2 \cdot q^2$ → 9 divisors (as $(2 + 1)(2 + 1) = 9$), where $p \ne q$

## **📘 Examples**

### Example 1

```cpp
Input: n = 100
Output: 2
Explanation: Numbers which have exactly 9 divisors are 36 and 100.
36 = 2^2 * 3^2 (divisors: 1, 2, 3, 4, 6, 9, 12, 18, 36)
100 = 2^2 * 5^2 (divisors: 1, 2, 4, 5, 10, 20, 25, 50, 100)
```

### Example 2

```cpp
Input: n = 200
Output: 3
Explanation: Numbers which have exactly 9 divisors are 36, 100, 196.
196 = 2^2 * 7^2 (divisors: 1, 2, 4, 7, 14, 28, 49, 98, 196)
```

## **🔒 Constraints**

- $1 \le n \le 10^9$

## **✅ My Approach**

The optimal approach uses **Sieve of Eratosthenes** to find smallest prime factors and then checks for two specific forms that yield exactly 9 divisors:

### **Number Theory + Sieve Analysis**

1. **Mathematical Foundation:**

   - A number has exactly 9 divisors if it's of the form `p^8` or `p^2 * q^2` where p, q are distinct primes
   - For `p^8`: divisors are `1, p, p^2, ..., p^8` (total: 9)
   - For `p^2 * q^2`: divisors follow `(2+1) * (2+1) = 9` pattern

2. **Sieve Implementation:**

   - Build smallest prime factor (SPF) array up to `√n`
   - Use modified sieve to efficiently find prime factors

3. **Count Valid Numbers:**

   - Check each number i from 2 to √n:
     - If `i = p * q` where p, q are distinct primes: count it
     - If `i` is prime and `i^8 ≤ n`: count it

4. **Optimization:**
   - Only iterate up to √n since larger factors would exceed n
   - Use SPF array for O(1) prime factorization

## 📝 Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(√n log log √n), where the sieve construction takes O(√n log log √n) time and the counting phase takes O(√n) time.
- **Expected Auxiliary Space Complexity:** O(√n), for storing the smallest prime factor array up to √n.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int countNumbers(int n) {
        int c = 0, lim = sqrt(n);
        vector<int> spf(lim + 1);
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= lim; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= lim; j += i)
                    if (spf[j] == j) spf[j] = i;
        for (int i = 2; i <= lim; ++i) {
            int p = spf[i], q = spf[i / p];
            if (p * q == i && p != q && q != 1) ++c;
            else if (spf[i] == i && pow(i, 8) <= n) ++c;
        }
        return c;
    }
};
```

## **🧑‍💻 Code (Java)**

```java
class Solution {
    public static int countNumbers(int n) {
        int c = 0, lim = (int)Math.sqrt(n);
        int[] spf = new int[lim + 1];
        for (int i = 2; i <= lim; i++) spf[i] = i;
        for (int i = 2; i * i <= lim; i++)
            if (spf[i] == i)
                for (int j = i * i; j <= lim; j += i)
                    if (spf[j] == j) spf[j] = i;
        for (int i = 2; i <= lim; i++) {
            int p = spf[i], q = spf[i / p];
            if (p * q == i && p != q && q != 1) c++;
            else if (spf[i] == i && Math.pow(i, 8) <= n) c++;
        }
        return c;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def countNumbers(self, n):
        from math import isqrt
        c, lim = 0, isqrt(n)
        spf = list(range(lim + 1))
        for i in range(2, isqrt(lim) + 1):
            if spf[i] == i:
                for j in range(i*i, lim + 1, i):
                    if spf[j] == j: spf[j] = i
        for i in range(2, lim + 1):
            p, q = spf[i], spf[i // spf[i]]
            if p * q == i and p != q and q != 1: c += 1
            elif spf[i] == i and i**8 <= n: c += 1
        return c
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
