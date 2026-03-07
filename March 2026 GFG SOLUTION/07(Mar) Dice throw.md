---
title: "🎲 Dice Throw | GFG Solution 🎯"
keywords🏷️: ["🎲 dice throw", "📊 dynamic programming", "📈 combinatorics", "🔢 ways counting", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to Dice Throw: count number of ways to get target sum using n dice with m faces using dynamic programming. 🚀"
date: 📅 2025-03-07
---

# *07. Dice Throw*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/dice-throw5349/1)

## **🧩 Problem Description**

Given `n` dice each with `m` faces, find the number of ways to get sum `x` which is the summation of values on each face when all the dice are thrown.

## **📘 Examples**

### Example 1

```cpp
Input: m = 6, n = 3, x = 12
Output: 25
Explanation: There are 25 total ways to get the sum 12 using 3 dice with faces from 1 to 6.
```

### Example 2

```cpp
Input: m = 2, n = 3, x = 6
Output: 1
Explanation: There is only 1 way to get the sum 6 using 3 dice with faces from 1 to 2. 
All the dice will have to land on 2.
```

### Example 3

```cpp
Input: m = 6, n = 2, x = 7
Output: 6
Explanation: Ways are (1,6), (2,5), (3,4), (4,3), (5,2), (6,1).
```

## **🔒 Constraints**

* $1 \le m, n, x \le 50$

## **✅ My Approach**

The optimal solution uses **Space-Optimized Dynamic Programming**:

### **1D DP with Backward Iteration**

1. **DP State Definition:**
   * `dp[j]` = number of ways to get sum `j` using current number of dice.
   * Start with base case: `dp[0] = 1` (one way to get sum 0 with 0 dice).

2. **Transition Logic:**
   * For each die (1 to n), update all possible sums.
   * For each sum `j`, consider all possible face values (1 to m).
   * `dp[j] = sum of dp[j-k]` for all valid face values k.

3. **Backward Iteration:**
   * Process sums from high to low to avoid overwriting values we still need.
   * This allows using single array instead of two arrays.

4. **Optimization:**
   * Space: O(x) instead of O(n × x) by reusing array.
   * After processing each die, reset `dp[0] = 0` as we can't get sum 0 with dice.

**Key Insight:** The problem is similar to coin change but with constraints on minimum (1) and maximum (m) values per item (die).

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n × x × m), where n is the number of dice, x is the target sum, and m is the number of faces per die. For each of n dice, we process x possible sums, and for each sum, we check m face values.
* **Expected Auxiliary Space Complexity:** O(x), as we use a single 1D array of size x+1 to store the DP states, which is much more space-efficient than a 2D approach.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<int> dp(x + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= 1; j--) {
                dp[j] = 0;
                for (int k = 1; k <= m && k <= j; k++)
                    dp[j] += dp[j - k];
            }
            dp[0] = 0;
        }
        return dp[x];
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ 2D DP Approach**

### 💡 Algorithm Steps:

1. Create 2D array `dp[i][j]` where i = dice count, j = sum.
2. Initialize base case: `dp[0][0] = 1`.
3. For each die, calculate ways for each sum.
4. Return `dp[n][x]`.

```cpp
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= x; j++) {
                for (int k = 1; k <= m && k <= j; k++) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        return dp[n][x];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × x × m) - Three nested loops
* **Auxiliary Space:** 💾 O(n × x) - 2D array storage

### ✅ **Why This Approach?**

* Clear state representation
* Easy to understand transitions
* Good for learning DP concepts

## 📊 **3️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Define recursive function: ways(dice, sum).
2. Base cases: dice=0 and sum=0 → return 1, else 0.
3. For each face value, recursively calculate ways.
4. Use memoization to avoid recomputation.

```cpp
class Solution {
public:
    int solve(int m, int n, int x, vector<vector<int>>& memo) {
        if (x < 0 || n < 0) return 0;
        if (n == 0) return x == 0 ? 1 : 0;
        if (memo[n][x] != -1) return memo[n][x];
        
        int ways = 0;
        for (int face = 1; face <= m; face++) {
            ways += solve(m, n - 1, x - face, memo);
        }
        return memo[n][x] = ways;
    }
    
    int noOfWays(int m, int n, int x) {
        vector<vector<int>> memo(n + 1, vector<int>(x + 1, -1));
        return solve(m, n, x, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × x × m) - With memoization
* **Auxiliary Space:** 💾 O(n × x) - Recursion stack + memoization

### ✅ **Why This Approach?**

* Natural recursive thinking
* Memoization prevents recomputation
* Top-down approach easier for some

## 📊 **4️⃣ Optimized DP with Prefix Sum**

### 💡 Algorithm Steps:

1. Use prefix sum to optimize inner loop.
2. Instead of summing dp[j-1] to dp[j-m], use prefix difference.
3. Maintain running sum for O(1) range sum queries.
4. Update DP values efficiently.

```cpp
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        vector<int> dp(x + 1, 0);
        for (int i = 1; i <= min(m, x); i++) dp[i] = 1;
        
        for (int dice = 2; dice <= n; dice++) {
            vector<int> temp(x + 1, 0);
            for (int sum = dice; sum <= x; sum++) {
                for (int face = 1; face <= m && face <= sum; face++) {
                    temp[sum] += dp[sum - face];
                }
            }
            dp = temp;
        }
        return dp[x];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n × x × m) - Standard DP time
* **Auxiliary Space:** 💾 O(x) - Single extra array

### ✅ **Why This Approach?**

* Clean separation of dice iterations
* Easy to understand state transitions
* Good balance of clarity and efficiency

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **1D DP Backward**             | 🟢 O(n×x×m)            | 🟢 O(x)                 | 🚀 Most space efficient           | 🔧 Backward iteration confusing      |
| 📊 **2D DP**                      | 🟢 O(n×x×m)            | 🔴 O(n×x)               | 📖 Clear state representation     | 💾 High space usage                  |
| 🔄 **Memoization**                | 🟢 O(n×x×m)            | 🔴 O(n×x)               | 🎯 Natural recursion              | 🔧 Stack overflow risk               |
| 📈 **Optimized DP**               | 🟢 O(n×x×m)            | 🟢 O(x)                 | ⚡ Clean code structure           | 🔧 Uses two arrays alternately       |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Space-constrained environment**                  | 🥇 **1D DP Backward**                | ★★★★★                     |
| 📖 **Learning DP concepts**                           | 🥈 **2D DP**                         | ★★★★★                     |
| 🎯 **Prefer recursion**                               | 🥉 **Memoization**                   | ★★★★☆                     |
| 🔧 **Code clarity**                                   | 🏅 **Optimized DP**                  | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    static int noOfWays(int m, int n, int x) {
        int[] dp = new int[x + 1];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = x; j >= 1; j--) {
                dp[j] = 0;
                for (int k = 1; k <= m && k <= j; k++)
                    dp[j] += dp[j - k];
            }
            dp[0] = 0;
        }
        return dp[x];
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def noOfWays(self, m, n, x):
        dp = [0] * (x + 1)
        dp[0] = 1
        for i in range(1, n + 1):
            for j in range(x, 0, -1):
                dp[j] = 0
                for k in range(1, min(m, j) + 1):
                    dp[j] += dp[j - k]
            dp[0] = 0
        return dp[x]
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
