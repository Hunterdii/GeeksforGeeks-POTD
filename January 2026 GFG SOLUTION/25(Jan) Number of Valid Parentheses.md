---
title: "🧮 Number of Valid Parentheses | GFG Solution 🔗"
keywords🏷️: ["🧮 valid parentheses", "🔢 catalan numbers", "📐 combinatorics", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Number of Valid Parentheses problem using Catalan numbers, binomial coefficient optimization, and dynamic programming. 🚀"
date: 📅 2025-01-25
---

# *25. Number of Valid Parentheses*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/valid-number-of-parenthesis/1)

## **🧩 Problem Description**

You are given a number `n`, your task is to find the number of all the **valid parentheses expressions** of that length using only "(" and ")" brackets.

An input string of parentheses is valid if:
- Open brackets must be closed in correct order.
- Every close bracket has a corresponding open bracket.

For example - "()()" or "(())" are valid while ")()(" or "))((" are invalid parentheses expressions.

## **📘 Examples**

### Example 1

```cpp
Input: n = 2
Output: 1
Explanation: There is only one possible valid expression of length 2 i.e., "()".
```

### Example 2

```cpp
Input: n = 4
Output: 2
Explanation: Possible valid expressions of length 4 are "(())" and "()()".
```

### Example 3

```cpp
Input: n = 6
Output: 5
Explanation: Possible valid expressions of length 6 are "((()))", "(())()", "()(())", "()()()" and "(()())".
```

## **🔒 Constraints**

* $1 \le n \le 20$

## **✅ My Approach**

The problem of counting valid parentheses expressions is directly related to **Catalan Numbers**. The n-th Catalan number represents the number of valid ways to arrange n pairs of parentheses.

### **Binomial Coefficient Formula (Optimized)**

1. **Check Validity:**
   * If `n` is odd, return 0 immediately (valid parentheses always have even length).
   * Divide `n` by 2 to get the number of pairs.

2. **Calculate Catalan Number:**
   * Use the formula: C(n) = C(2n, n) / (n + 1)
   * Where C(2n, n) is the binomial coefficient "2n choose n".

3. **Efficient Computation:**
   * Calculate C(2n, n) iteratively using: res = res * (2n - i) / (i + 1)
   * This approach avoids overflow by alternating multiplication and division.

4. **Final Result:**
   * Divide the binomial coefficient by (n + 1) to get the Catalan number.

## 📝 **Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(n), as we perform a single loop that runs n/2 times to calculate the binomial coefficient, where n is the input length.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space with variables for calculation.

## **⚙️ Code (C)**

```c
int findWays(int n) {
    if (n & 1) return 0;
    n >>= 1;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        res = res * (2 * n - i) / (i + 1);
    }
    return res / (n + 1);
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        long long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        return res / (n + 1);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Create a DP array where dp[i] represents the i-th Catalan number.
2. Use the recurrence relation: C(n) = Σ C(i) * C(n-1-i) for i from 0 to n-1.
3. Build up from base case C(0) = 1 to compute C(n/2).
4. Return the computed Catalan number which represents valid parentheses count.

```cpp
class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Nested loops for DP computation
* **Auxiliary Space:** 💾 O(n) - DP array storage

### ✅ **Why This Approach?**

* Demonstrates the recursive nature of Catalan numbers
* Useful for computing multiple Catalan numbers
* Intuitive understanding of parentheses nesting

## 📊 **3️⃣ Direct Formula Approach**

### 💡 Algorithm Steps:

1. Use the direct formula: C(n) = (2n)! / ((n+1)! * n!)
2. Simplify to avoid large factorial computations.
3. Calculate using iterative multiplication and division.
4. Return the final Catalan number.

```cpp
class Solution {
public:
    int findWays(int n) {
        if (n & 1) return 0;
        n >>= 1;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            res = res * (n + i) / i;
        }
        return res / (n + 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single loop iteration
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Mathematically elegant solution
* Optimal space complexity
* Efficient computation without recursion

## 📊 **4️⃣ Recursive Memoization**

### 💡 Algorithm Steps:

1. Define recursive function: catalan(n) = Σ catalan(i) * catalan(n-1-i).
2. Use memoization to store computed values.
3. Base case: catalan(0) = 1.
4. Return memoized result for n/2.

```cpp
class Solution {
public:
    unordered_map<int, long long> memo;
    
    long long catalan(int n) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res += catalan(i) * catalan(n - 1 - i);
        }
        return memo[n] = res;
    }
    
    int findWays(int n) {
        if (n & 1) return 0;
        return catalan(n >> 1);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Recursive calls with memoization
* **Auxiliary Space:** 💾 O(n) - Memoization map and recursion stack

### ✅ **Why This Approach?**

* Natural recursive formulation
* Avoids recomputation with memoization
* Good for understanding problem structure

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Binomial Direct**           | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Fastest execution              | 🔧 Overflow risk if not careful      |
| 🔍 **Dynamic Programming**        | 🟡 O(n²)               | 🟡 O(n)                 | 📖 Clear recurrence pattern       | 🐌 Slower for large n                |
| 📊 **Direct Formula**             | 🟢 O(n)                | 🟢 O(1)                 | 🎯 Mathematically clean           | 🔢 Division order matters            |
| 🔄 **Recursive Memoization**      | 🟡 O(n²)               | 🟡 O(n)                 | ⭐ Natural formulation            | 🔧 Stack overflow for large n        |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Binomial Direct**               | ★★★★★                     |
| 📖 **Learning Catalan numbers**                       | 🥈 **Dynamic Programming**           | ★★★★☆                     |
| 🔧 **Mathematical elegance**                          | 🥉 **Direct Formula**                | ★★★★★                     |
| 🎯 **Interview/Competitive**                          | 🏅 **Binomial Direct**               | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    int findWays(int n) {
        if ((n & 1) == 1) return 0;
        n >>= 1;
        long res = 1;
        for (int i = 0; i < n; i++) {
            res = res * (2 * n - i) / (i + 1);
        }
        return (int)(res / (n + 1));
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def findWays(self, n):
        if n & 1: return 0
        n >>= 1
        res = 1
        for i in range(n):
            res = res * (2 * n - i) // (i + 1)
        return res // (n + 1)
```

## 🧠 **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [📬 Any Questions?](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let's make this learning journey more collaborative!

⭐ **If you find this helpful, please give this repository a star!** ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://visitor-badge.laobi.icu/badge?page_id=Hunterdii.GeeksforGeeks-POTD" alt="Visitor counter" />
</p>



