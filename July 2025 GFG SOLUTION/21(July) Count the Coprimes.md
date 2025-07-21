---
title: "🔢 Count the Coprimes | GFG Solution 🔍"
keywords🏷️: ["🔢 gcd", "🟰 co-prime pairs", "🔍 mobius function", "📈 number theory", "📍 inclusion exclusion", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Count the Coprimes problem: count pairs with GCD=1 using Möbius function and inclusion-exclusion principle for efficient computation. 🚀"
date: 📅 2025-07-21
---

# *21. Count the Coprimes*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/count-the-coprimes/1)

## **🧩 Problem Description**

You are given an array `arr[]` of positive integers. Your task is to count the number of pairs `(i, j)` such that:

- `0 ≤ i < j ≤ n-1`
- `gcd(arr[i], arr[j]) = 1`

In other words, count the number of unordered pairs of indices `(i, j)` where the elements at those positions are co-prime (their greatest common divisor is 1).

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [1, 2, 3]
Output: 3
Explanation: (0,1), (0,2), (1,2) are the pair of indices where gcd(arr[i], arr[j]) = 1
```

### Example 2

```cpp
Input: arr[] = [4, 8, 3, 9]
Output: 4
Explanation: (0,2), (0,3), (1,2), (1,3) are the pair of indices where gcd(arr[i], arr[j]) = 1
```

## **🔒 Constraints**

* $2 \le \text{arr.size()} \le 10^4$
* $1 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses the **Möbius Function** with **Inclusion-Exclusion Principle** to efficiently count coprime pairs without checking every pair individually:

### **Möbius Function + Inclusion-Exclusion**

1. **Core Insight:**
   * Instead of checking all pairs individually (O(n²) with GCD computation), we use number theory.
   * Count pairs with specific GCD values using inclusion-exclusion principle.
   * Möbius function helps eliminate overcounting in inclusion-exclusion.

2. **Algorithm Steps:**
   * **Step 1:** Find maximum element and create frequency array `cnt[]`.
   * **Step 2:** Compute Möbius function `mu[]` using sieve method.
   * **Step 3:** For each divisor `d`, count how many elements are divisible by `d` (store in `div[]`).
   * **Step 4:** Apply inclusion-exclusion: pairs with GCD=1 = total pairs - pairs with GCD>1.
   * **Step 5:** Use Möbius function to compute the final result efficiently.

3. **Möbius Function Properties:**
   * `μ(1) = 1`
   * `μ(n) = 0` if n has squared prime factor
   * `μ(n) = (-1)^k` if n is product of k distinct primes
   * Used to invert inclusion-exclusion formulas

4. **Mathematical Formula:**
   * For each divisor `d`: if `mu[d] ≠ 0` and `div[d] > 1`
   * Add `mu[d] * div[d] * (div[d] - 1) / 2` to result
   * This counts pairs where GCD is exactly 1 using inclusion-exclusion

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n log n), where n is the maximum element in array. The first term is for sieve-based Möbius computation, and the second term is for divisor counting across all elements.
* **Expected Auxiliary Space Complexity:** O(n), where n is the maximum element. We need arrays for frequency counting, divisor sums, Möbius function values, and visited markers during sieve computation.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> cnt(mx + 1), div(mx + 1), mu(mx + 1, 1);
        vector<bool> vis(mx + 1);
        
        for (int x : arr) cnt[x]++;

        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                div[i] += cnt[j];

        for (int i = 2; i <= mx; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= mx; j += i) {
                    mu[j] *= -1;
                    vis[j] = 1;
                }
                for (long long j = (long long)i * i; j <= mx; j += (long long)i * i)
                    mu[j] = 0;
            }
        }

        int ans = 0;
        for (int i = 1; i <= mx; ++i)
            if (mu[i] && div[i] > 1)
                ans += mu[i] * div[i] * (div[i] - 1) / 2;
        
        return ans;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Sieve-Based Möbius with Early Termination**

### 💡 Algorithm Steps:

1. Use sieve to compute Möbius function efficiently
2. Early termination when divisor count < 2
3. Optimized prime factorization
4. Single-pass frequency and divisor counting

```cpp
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = *max_element(arr.begin(), arr.end());
        vector<int> f(n + 1), d(n + 1), mu(n + 1, 1);
        vector<bool> vis(n + 1);
        
        for (int x : arr) f[x]++;
        
        for (int i = 2; i <= n; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= n; j += i) {
                    mu[j] *= -1;
                    vis[j] = 1;
                }
                for (long long j = (long long)i * i; j <= n; j += (long long)i * i)
                    mu[j] = 0;
            }
        }
        
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                d[i] += f[j];
        
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (mu[i] && d[i] > 1)
                res += mu[i] * d[i] * (d[i] - 1) / 2;
        return res;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)              
* **Auxiliary Space:** 💾 O(n) - for arrays

### ✅ **Why This Approach?**

* Sieve-based prime detection
* Efficient Möbius computation
* Early termination optimizations

## 📊 **3️⃣ GCD-Based Direct Counting**

### 💡 Algorithm Steps:

1. Use inclusion-exclusion principle
2. Count pairs with specific GCD values
3. Direct frequency-based computation
4. Optimized divisor iteration

```cpp
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> freq(mx + 1), cnt(mx + 1);
        
        for (int x : arr) freq[x]++;
        
        for (int g = 1; g <= mx; ++g) {
            for (int mul = g; mul <= mx; mul += g)
                cnt[g] += freq[mul];
        }
        
        vector<int> coprime(mx + 1);
        for (int g = mx; g >= 1; --g) {
            coprime[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int mul = g + g; mul <= mx; mul += g)
                coprime[g] -= coprime[mul];
        }
        
        return coprime[1];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log n)
* **Auxiliary Space:** 💾 O(n) - for frequency arrays

### ✅ **Why This Approach?**

* Direct GCD-based computation
* Bottom-up inclusion-exclusion
* No Möbius function needed


## 📊 **4️⃣ Optimized Divisor Sum Approach**

### 💡 Algorithm Steps:

1. Precompute smallest prime factors
2. Fast Möbius function calculation
3. Efficient divisor counting
4. Single-pass result computation

```cpp
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = *max_element(arr.begin(), arr.end());
        vector<int> spf(n + 1), f(n + 1), d(n + 1);
        
        iota(spf.begin(), spf.end(), 0);
        for (int i = 2; i * i <= n; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= n; j += i)
                    if (spf[j] == j) spf[j] = i;
        
        for (int x : arr) f[x]++;
        
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                d[i] += f[j];
        
        auto mobius = [&](int x) {
            int res = 1, prev = -1;
            while (x > 1) {
                int p = spf[x], cnt = 0;
                while (x % p == 0) x /= p, cnt++;
                if (cnt > 1) return 0;
                res *= -1;
            }
            return res;
        };
        
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i] > 1) {
                int mu = mobius(i);
                if (mu) ans += mu * d[i] * (d[i] - 1) / 2;
            }
        }
        return ans;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n log log n + n log n)
* **Auxiliary Space:** 💾 O(n) - for SPF and arrays

### ✅ **Why This Approach?**

* SPF-based factorization
* On-demand Möbius calculation
* Memory-efficient implementation


## 📊 **5️⃣ Brute Force Approach (For Reference)**

### 💡 Algorithm Steps:

1. Check every pair (i, j) where i < j
2. Compute GCD of arr[i] and arr[j]
3. Count pairs where GCD equals 1
4. Simple but inefficient for large inputs

```cpp
class Solution {
public:
    int cntCoprime(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (__gcd(arr[i], arr[j]) == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n² log(max_element))
* **Auxiliary Space:** 💾 O(1)

### ✅ **Why This Approach?**

* Simple and intuitive
* Easy to understand and implement
* Good for small inputs or educational purposes

> **Note:** This approach results in **Time Limit Exceeded (TLE)** for large inputs _(fails ~1010/1120 test cases due to time constraints)_.

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                      | ⏱️ **Time Complexity**      | 💾 **Space Complexity** | ✅ **Pros**                          | ⚠️ **Cons**                        |
| ------------------------------------ | --------------------------- | ----------------------- | ----------------------------------- | ---------------------------------- |
| 🔍 **Optimized Möbius**            | 🟢 O(n log n)              | 🟡 O(n)                 | 🚀 Fastest for large inputs        | 💾 Multiple array allocations     |
| 🔺 **Sieve-Based Möbius**          | 🟢 O(n log n)              | 🟡 O(n)                 | 🔧 Better prime detection          | 💾 Additional boolean array        |
| ⏰ **GCD-Based Direct**            | 🟢 O(n log n)              | 🟡 O(n)                 | 🚀 No Möbius function needed       | 🔄 Backward iteration required     |
| 📊 **SPF Divisor Sum**             | 🟢 O(n log log n + n log n)| 🟡 O(n)                 | ⚡ On-demand calculations           | 🔧 Complex factorization logic     |
| 🐌 **Brute Force (TLE)**           | 🔴 O(n² log(max))          | 🟢 O(1)                 | 🔧 Simple to understand            | ⏰ Too slow for large inputs       |


### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| ⚡ **Large arrays, high performance**             | 🥇 **Optimized Möbius**              | ★★★★★                     |
| 📊 **Balanced memory usage**                      | 🥈 **GCD-Based Direct**              | ★★★★☆                     |
| 🎯 **Educational/interview purposes**             | 🥉 **Sieve-Based Möbius**           | ★★★★☆                     |
| 🚀 **Competitive programming**                    | 🏅 **SPF Divisor Sum**              | ★★★★★                     |
| 📚 **Small inputs, learning**                     | 🎖️ **Brute Force (TLE)**                   | ★★☆☆☆                     |

</details>

## **🧑‍💻 Code (Java)**

```java
class Solution {
    int cntCoprime(int[] arr) {
        int mx = Arrays.stream(arr).max().orElse(0);
        int[] cnt = new int[mx + 1], div = new int[mx + 1], mu = new int[mx + 1];
        boolean[] vis = new boolean[mx + 1];
        
        for (int x : arr) cnt[x]++;
        
        Arrays.fill(mu, 1);
        for (int i = 2; i <= mx; ++i) {
            if (!vis[i]) {
                for (int j = i; j <= mx; j += i) {
                    mu[j] *= -1;
                    vis[j] = true;
                }
                for (long j = (long)i * i; j <= mx; j += (long)i * i)
                    mu[(int)j] = 0;
            }
        }
        
        for (int i = 1; i <= mx; ++i)
            for (int j = i; j <= mx; j += i)
                div[i] += cnt[j];
        
        int ans = 0;
        for (int i = 1; i <= mx; ++i)
            if (mu[i] != 0 && div[i] > 1)
                ans += mu[i] * div[i] * (div[i] - 1) / 2;
        
        return ans;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def cntCoprime(self, arr):
        mx = max(arr)
        cnt, div, mu = [0] * (mx + 1), [0] * (mx + 1), [1] * (mx + 1)
        vis = [False] * (mx + 1)
        
        for x in arr:
            cnt[x] += 1
        
        for i in range(2, mx + 1):
            if not vis[i]:
                for j in range(i, mx + 1, i):
                    mu[j] *= -1
                    vis[j] = True
                for j in range(i * i, mx + 1, i * i):
                    mu[j] = 0
        
        for i in range(1, mx + 1):
            for j in range(i, mx + 1, i):
                div[i] += cnt[j]
        
        ans = 0
        for i in range(1, mx + 1):
            if mu[i] and div[i] > 1:
                ans += mu[i] * div[i] * (div[i] - 1) // 2
        
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
