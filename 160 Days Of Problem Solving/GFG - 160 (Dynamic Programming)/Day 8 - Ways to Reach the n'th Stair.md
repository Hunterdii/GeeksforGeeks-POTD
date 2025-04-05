---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
  - sliding-window
  - Mathematical
---

# 🚀 _Day 8. Ways to Reach the n'th Stair_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/count-ways-to-reach-the-nth-stair-1587115620)

## 💡 **Problem Description:**

There are `n` stairs, and a person standing at the bottom wants to reach the top. The person can climb either **1 stair** or **2 stairs** at a time. Your task is to **count the number of ways** the person can reach the top (order matters).

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
n = 1
```

#### **Output:**

```
1
```

#### **Explanation:**

There is only one way to climb 1 stair — just **one step** of size 1.

### **Example 2:**

#### **Input:**

```
n = 2
```

#### **Output:**

```
2
```

#### **Explanation:**

There are two ways to reach the 2nd stair:

1. (1, 1)
2. (2)

### **Example 3:**

#### **Input:**

```
n = 4
```

#### **Output:**

```
5
```

#### **Explanation:**

There are five ways to climb 4 stairs:

1. (1, 1, 1, 1)
2. (1, 1, 2)
3. (1, 2, 1)
4. (2, 1, 1)
5. (2, 2)

### **Constraints:**

- $\(1 \le n \le 44\)$

## 🎯 **My Approach:**

### **Iterative (Space-Optimized DP)**

1. We know this is essentially the **Fibonacci sequence** shifted by one index.
2. Use **two variables** `a` and `b` to track the ways to climb `(n-1)` and `n` stairs.
3. Initially, `a = 1` and `b = 1`, representing ways to climb `0` or `1` stairs.
4. Update in a loop from `2` to `n`, computing `b = a + b` (the sum of ways to climb `(n-1)` and `(n-2)`), then shift `a` to the old `b`.

This approach eliminates the need for an entire DP array and uses only **constant space**.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(n)`, as we iterate from 2 to n once.
- **Expected Auxiliary Space Complexity:** `O(1)`, since we only use a constant amount of extra space (two variables).

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
public:
    long long countWays(int n) {
        long long a = 1, b = 1;
        for (int i = 2; i <= n; i++)
            tie(a, b) = make_tuple(b, a + b);
        return b;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **1️⃣ Iterative DP (O(N) Time, O(1) Space) — Efficient and Clean**

### **Algorithm Steps:**

- Maintain two variables, `a` and `b`, initialized to `1`.
- Iterate from `2` to `n`, updating `b` as `a + b` and shifting `a` to the old value of `b`.
- This efficient method eliminates the need for an array.

```cpp
class Solution {
public:
    long long countWays(int n) {
        long long a = 1, b = 1;
        while (n-- > 1) b += a, a = b - a;
        return b;
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(1)`

## **2️⃣ Dynamic Programming (Tabulation - O(N) Time, O(N) Space)**

### **Algorithm Steps:**

- Create an array `dp[]` where `dp[i]` stores the number of ways to reach the `i`-th step.
- Base cases:
  - `dp[0] = 1` (1 way to stay at the ground).
  - `dp[1] = 1` (1 way to take one step).
- Recurrence relation:
  $\[
\text{dp[i]} = \text{dp[i-1]} + \text{dp[i-2]}
\]$

```cpp
class Solution {
public:
    long long countWays(int n) {
        vector<long long> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **3️⃣ Matrix Exponentiation (O(log N) Time, O(1) Space) — Fastest Approach**

### **Algorithm Steps:**

- Fibonacci sequence can be efficiently calculated using matrix exponentiation.
- Matrix multiplication transforms the problem into logarithmic complexity.

### **Matrix Representation:**

| F(n)   | F(n-1) |
| ------ | ------ |
| F(n-1) | F(n-2) |

=
| 1 | 1 |
|---|---|
| 1 | 0 | ^(n-1)

```cpp
class Solution {
public:
    void multiply(long long F[2][2], long long M[2][2]) {
        long long x = F[0][0]*M[0][0] + F[0][1]*M[1][0];
        long long y = F[0][0]*M[0][1] + F[0][1]*M[1][1];
        long long z = F[1][0]*M[0][0] + F[1][1]*M[1][0];
        long long w = F[1][0]*M[0][1] + F[1][1]*M[1][1];
        F[0][0] = x; F[0][1] = y;
        F[1][0] = z; F[1][1] = w;
    }

    void power(long long F[2][2], int n) {
        if (n <= 1) return;
        long long M[2][2] = {{1, 1}, {1, 0}};
        power(F, n / 2);
        multiply(F, F);
        if (n % 2 != 0) multiply(F, M);
    }

    long long countWays(int n) {
        if (n == 0) return 1;
        long long F[2][2] = {{1, 1}, {1, 0}};
        power(F, n);
        return F[0][0];
    }
};
```

✅ **Time Complexity:** `O(log N)`  
✅ **Space Complexity:** `O(1)`

## **4️⃣ Recursive + Memoization (O(N) Time, O(N) Space)**

### **Algorithm Steps:**

- Use recursion with memoization to store previously computed results.
- Base cases:
  - `f(0) = 1`
  - `f(1) = 1`

```cpp
class Solution {
public:
    vector<long long> dp;
    long long countWays(int n) {
        if (dp.empty()) dp.resize(n + 1, -1); // Initialize only once
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = countWays(n - 1) + countWays(n - 2);
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## 📊 **Comparison of Approaches**

| **Approach**                         | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                         | ⚠️ **Cons**                     |
| ------------------------------------ | ---------------------- | ----------------------- | ----------------------------------- | ------------------------------- |
| **Iterative DP (Space Optimized)**   | 🟡 `O(N)`              | 🟢 `O(1)`               | Simple and fastest iterative method | Limited to Fibonacci logic only |
| **Dynamic Programming (Tabulation)** | 🟡 `O(N)`              | 🔴 `O(N)`               | Easy to understand and implement    | Consumes more space             |
| **Matrix Exponentiation**            | 🟢 `O(log N)`          | 🟢 `O(1)`               | Fastest for large values of `n`     | Slightly complex logic          |
| **Recursive + Memoization**          | 🟡 `O(N)`              | 🔴 `O(N)`               | Natural recursive logic             | Higher recursion overhead       |

## 💡 **Best Choice?**

✅ **For simplicity and efficiency:** Use **Iterative DP (Space Optimized)**.  
✅ **For fastest results in large inputs:** Use **Matrix Exponentiation**.  
✅ **For easier implementation with clear logic:** Use **Tabulation**.

</details>

## **Code (Java)**

```java
class Solution {
    public long countWays(int n) {
        long a = 1, b = 1;
        while (n-- > 1) {
            b += a;
            a = b - a;
        }
        return b;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def countWays(self, n):
        a, b = 1, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
