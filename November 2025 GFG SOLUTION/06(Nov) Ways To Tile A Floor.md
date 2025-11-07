---
title: "🧩 Ways To Tile A Floor | GFG Solution 🔍"
keywords🏷️: ["🧩 ways to tile a floor", "📊 dynamic programming", "📐 combinatorics", "📈 fibonacci relation", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Ways to Tile a Floor problem: compute the number of ways to fill a 2×n board using 2×1 tiles via dynamic programming or Fibonacci logic. 🚀"
date: 📅 2025-11-06
---

# *06. Ways To Tile A Floor*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1)

## **🧩 Problem Description**

Given a floor of dimensions **2 × n** and tiles of dimensions **2 × 1**, the task is to find the **number of ways** the floor can be tiled. A tile can either be placed:
- **Horizontally** (as 1 × 2 tile)
- **Vertically** (as 2 × 1 tile)

**Note:** Two tiling arrangements are considered different if the placement of at least one tile differs.

## **📘 Examples**

### Example 1

```cpp
Input: n = 3
Output: 3
Explanation: We need 3 tiles to tile the board of size 2 × 3.
We can tile in following ways:
1) Place all 3 tiles vertically.
2) Place first tile vertically and remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically.
```

### Example 2

```cpp
Input: n = 4
Output: 5
Explanation: We need 4 tiles to tile the board of size 2 × 4.
We can tile in following ways:
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal.
4) First 2 horizontal, remaining 2 vertical.
5) Corner 2 vertical, middle 2 horizontal.
```

## **🔒 Constraints**

* $1 \le n \le 45$

## **✅ My Approach**

This problem is a classic **Dynamic Programming** problem that follows the **Fibonacci sequence** pattern. The key insight is understanding the recurrence relation:

### **Iterative Dynamic Programming**

1. **Base Cases:**
   * If `n = 1`: Only 1 way (place one vertical tile).
   * If `n = 2`: 2 ways (either two vertical tiles or two horizontal tiles stacked).

2. **Recurrence Relation:**
   * For position `n`, we have two choices:
     - Place a **vertical tile** at position `n`, leaving `n-1` positions: `ways(n-1)`
     - Place **two horizontal tiles** at position `n`, leaving `n-2` positions: `ways(n-2)`
   * Therefore: `ways(n) = ways(n-1) + ways(n-2)`

3. **Space Optimization:**
   * Instead of maintaining entire DP array, use two variables to track previous two states.
   * This reduces space complexity from O(n) to O(1).

4. **Iterative Computation:**
   * Initialize `a = 1` (for n=1) and `b = 1` (for n=0, representing empty floor).
   * Iterate from position 2 to n, updating: `new_value = a + b`.
   * Shift variables: `a = b`, `b = new_value`.

5. **Result:**
   * After n iterations, `b` contains the answer.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), as we iterate through n positions once, performing constant time operations at each step.
* **Expected Auxiliary Space Complexity:** O(1), as we only use two variables to store previous states regardless of the input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        while (n-- > 1) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Use top-down recursive approach with base cases.
2. Store computed results in memoization array.
3. For each state check if already computed before recursing.
4. Return memoized value to avoid redundant calculations.

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
    int solve(int n, vector<int>& memo) {
        if (n <= 1) return 1;
        if (memo[n] != -1) return memo[n];
        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each subproblem solved once
* **Auxiliary Space:** 💾 O(n) - Memoization array and recursion stack

### ✅ **Why This Approach?**

* Natural recursive thinking pattern
* Easy to understand and debug
* Good for learning dynamic programming concepts

## 📊 **3️⃣ Tabulation with DP Array**

### 💡 Algorithm Steps:

1. Create DP array of size n+1 to store results.
2. Initialize base cases: dp[0] = 1, dp[1] = 1.
3. Fill array iteratively using recurrence relation.
4. Return dp[n] as final answer.

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(n) - DP array storage

### ✅ **Why This Approach?**

* Clear bottom-up approach
* Easy to trace computation steps
* Standard DP tabulation pattern

## 📊 **4️⃣ Binet's Formula (Mathematical)**

### 💡 Algorithm Steps:

1. Use closed-form mathematical formula for fibonacci numbers.
2. Apply golden ratio phi in the formula directly.
3. Compute result using power function and rounding.
4. Return the computed fibonacci value.

```cpp
class Solution {
public:
    int numberOfWays(int n) {
        double phi = (1 + sqrt(5)) / 2;
        return round(pow(phi, n + 1) / sqrt(5));
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(1) - Direct formula computation
* **Auxiliary Space:** 💾 O(1) - No extra space needed

### ✅ **Why This Approach?**

* Constant time complexity
* Mathematical elegance
* Shortest code implementation

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Iterative DP**              | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Space optimized, fast          | 🔧 Linear time for large n           |
| 📊 **Memoization**                | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Intuitive recursion            | 🐌 Extra space and stack overhead    |
| 🔄 **Tabulation**                 | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Clear bottom-up logic          | 💾 Array storage overhead            |
| 🔢 **Binet's Formula**            | 🟢 O(1)                | 🟢 O(1)                 | ⚡ Mathematical elegance          | 🔧 Floating point precision issues   |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance & space**                    | 🥇 **Iterative DP**                  | ★★★★★                     |
| 🔧 **Learning DP concepts**                           | 🥈 **Memoization**                   | ★★★★☆                     |
| 📖 **Understanding bottom-up DP**                     | 🥉 **Tabulation**                    | ★★★★☆                     |
| 🎯 **Mathematical/competitive programming**           | 🏅 **Binet's Formula**               | ★★★☆☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int numberOfWays(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1;
        while (n-- > 1) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def numberOfWays(self, n):
        if n <= 1: return 1
        a, b = 1, 1
        for _ in range(n - 1):
            a, b = b, a + b
        return b
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
