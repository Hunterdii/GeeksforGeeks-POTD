---
title: "🧮 Get Minimum Squares | GFG Solution 🔍"
keywords🏷️: ["🧮 perfect squares", "📏 dynamic programming", "📉 BFS", "💭 Lagrange theorem", "🔢 number theory",  "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution for Get Minimum Squares problem: find the minimum number of perfect squares that sum up to n using mathematical theorem and alternative DP approaches. 🚀"
date: 📅 2025-11-05
---


# **05. Get Minimum Squares**

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/get-minimum-squares0538/1)

## **🧩 Problem Description**

Given a positive integer `n`, find the minimum number of perfect squares (square of an integer) that sum up to `n`.

**Note:** Every positive integer can be expressed as a sum of square numbers since 1 is a perfect square, and any number can be represented as 1*1 + 1*1 + 1*1 + ....

## **📘 Examples**

### Example 1

```cpp
Input: n = 100
Output: 1
Explanation: 10 * 10 = 100
```

### Example 2

```cpp
Input: n = 6
Output: 3
Explanation: 1 * 1 + 1 * 1 + 2 * 2 = 6
```

## **🔒 Constraints**

* $1 \le n \le 10^4$

## **✅ My Approach**

The optimal approach uses **Lagrange's Four Square Theorem** combined with mathematical optimization to efficiently determine the minimum number of perfect squares needed:

### **Mathematical Optimization (Lagrange's Theorem)**

1. **Check for Perfect Square (Answer = 1):**
   * Calculate the square root of n and verify if it's a perfect square.
   * If yes, return 1 immediately.

2. **Check for Sum of Two Squares (Answer = 2):**
   * Iterate through all perfect squares up to √n.
   * For each square i², check if (n - i²) is also a perfect square.
   * If found, return 2.

3. **Check for Answer = 4 (Based on Lagrange's Theorem):**
   * Remove all factors of 4 from n by repeatedly dividing.
   * If the resulting number follows the form (8k + 7), return 4.
   * This is based on the mathematical property that numbers of form 4^a(8b + 7) require exactly 4 squares.

4. **Default Answer = 3:**
   * If none of the above conditions are met, return 3.
   * By Lagrange's theorem, every positive integer can be expressed as sum of at most 4 perfect squares.

## **📝 Time and Auxiliary Space Complexity**

* **Expected Time Complexity:** O(√n), as we iterate up to the square root of n to check for sum of two squares, and perform constant time operations for other checks.
* **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space for variables regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int minSquares(int n) {
        if(int s = sqrt(n); s * s == n) return 1;
        for(int i = 1; i * i <= n; i++)
            if(int r = sqrt(n - i * i); r * r == n - i * i) return 2;
        while(n % 4 == 0) n /= 4;
        return n % 8 == 7 ? 4 : 3;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Dynamic Programming Approach**

### 💡 Algorithm Steps:

1. Create a DP array where dp[i] represents minimum squares for number i.
2. Initialize dp[0] = 0 as base case.
3. For each number, try all perfect squares less than it.
4. Take minimum of all possible combinations to build the number.

```cpp
class Solution {
public:
    int minSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], dp[i - j * j] + 1);
        return dp[n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n√n) - Nested loops with square root boundary
* **Auxiliary Space:** 💾 O(n) - DP array storage

### ✅ **Why This Approach?**

* Solves all subproblems systematically
* Can be extended to find actual square numbers
* Works for any positive integer

## 📊 **3️⃣ BFS Level-Order Approach**

### 💡 Algorithm Steps:

1. Use BFS to explore all reachable numbers by subtracting perfect squares.
2. Each level represents using one more perfect square.
3. First time we reach 0 gives us the minimum count.
4. Track visited numbers to avoid redundant computations.

```cpp
class Solution {
public:
    int minSquares(int n) {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(n);
        vis[n] = true;
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                int cur = q.front();
                q.pop();
                for(int i = 1; i * i <= cur; i++) {
                    int next = cur - i * i;
                    if(next == 0) return level;
                    if(!vis[next]) {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
        }
        return level;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n√n) - BFS exploration with square root iterations
* **Auxiliary Space:** 💾 O(n) - Queue and visited array

### ✅ **Why This Approach?**

* Guarantees shortest path to solution
* Intuitive level-based counting
* Natural fit for finding minimum operations

## 📊 **4️⃣ Mathematical Optimization**

### 💡 Algorithm Steps:

1. Check if n is perfect square - return 1.
2. Remove all factors of 4 from n.
3. If remaining number ≡ 7 (mod 8), return 4.
4. Otherwise check for sum of two squares, else return 3.

```cpp
class Solution {
public:
    int minSquares(int n) {
        int s = sqrt(n);
        if(s * s == n) return 1;
        int temp = n;
        while(temp % 4 == 0) temp /= 4;
        if(temp % 8 == 7) return 4;
        for(int i = 1; i * i <= n; i++)
            if(s = sqrt(n - i * i); s * s == n - i * i) return 2;
        return 3;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(√n) - Only checking up to square root
* **Auxiliary Space:** 💾 O(1) - Constant space usage

### ✅ **Why This Approach?**

* Based on Lagrange's Four Square Theorem
* Eliminates impossible cases early
* Most efficient for single query

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **Lagrange Theorem**           | 🟢 O(√n)               | 🟢 O(1)                 | ⚡ Fastest single query           | 🧮 Requires mathematical insight     |
| 📊 **Dynamic Programming**        | 🟡 O(n√n)              | 🟡 O(n)                 | 🔄 Reusable for multiple queries  | 🐌 Slower for large n                |
| 🔍 **BFS Level-Order**            | 🟡 O(n√n)              | 🟡 O(n)                 | 🎯 Intuitive minimum path         | 💾 High memory usage                 |
| 🧮 **Math Optimization**          | 🟢 O(√n)               | 🟢 O(1)                 | 🏆 Optimal complexity             | 🔧 Complex theorem application       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Single query optimization**                  | 🥇 **Lagrange Theorem**              | ★★★★★                     |
| 🔄 **Multiple queries**                           | 🥈 **Dynamic Programming**           | ★★★★☆                     |
| 📖 **Learning/Interview**                         | 🥉 **BFS Approach**                  | ★★★★☆                     |
| 🎯 **Competitive Programming**                    | 🏅 **Math Optimization**             | ★★★★★                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int minSquares(int n) {
        int s = (int)Math.sqrt(n);
        if(s * s == n) return 1;
        for(int i = 1; i * i <= n; i++) {
            int r = (int)Math.sqrt(n - i * i);
            if(r * r == n - i * i) return 2;
        }
        while(n % 4 == 0) n /= 4;
        return n % 8 == 7 ? 4 : 3;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def minSquares(self, n):
        s = int(n ** 0.5)
        if s * s == n: return 1
        for i in range(1, int(n ** 0.5) + 1):
            r = int((n - i * i) ** 0.5)
            if r * r == n - i * i: return 2
        while n % 4 == 0: n //= 4
        return 4 if n % 8 == 7 else 3
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


