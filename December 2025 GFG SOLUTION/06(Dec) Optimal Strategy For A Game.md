---
title: "🎮 Optimal Strategy For A Game | GFG Solution 🧮"
keywords🏷️: ["🎮 game theory", "🧮 dynamic programming", "📍 optimal strategy", "📈 game analysis", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Optimal Strategy For A Game problem: find maximum amount of money you can win if you go first, assuming both players play optimally. 🚀"
date: 📅 2023-12-06
---

# *06. Optimal Strategy For A Game*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1)

## **🧩 Problem Description**

You are given an integer array `arr[]` of size `n` (even). The array elements represent `n` coins of values `v1, v2, ..., vn`. You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value.

You need to determine the maximum possible amount of money you can win if you go first.

**Note:** Both the players are playing optimally.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [5, 3, 7, 10]
Output: 15
Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.
```

### Example 2

```cpp
Input: arr[] = [8, 15, 3, 7]
Output: 22
Explanation: The user collects the maximum value as 22(7 + 15). It is guaranteed that we cannot get more than 22 by any possible moves.
```

## **🔒 Constraints**

* $2 \le n \le 10^3$
* $1 \le arr[i] \le 10^6$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming** to efficiently compute the maximum amount the first player can win:

### **1D DP Optimized Approach**

1. **Understanding the Game:**
   * Each player can choose either the first or last coin in their turn.
   * Both players play optimally, meaning they will always make the move that maximizes their own total.
   * We need to find the maximum amount the first player can collect.

2. **DP State Definition:**
   * Let `dp[i][j]` represent the maximum advantage the current player can get over the opponent for the subarray `arr[i...j]`.
   * This is the difference between the current player's total and the opponent's total for this subarray.

3. **Recurrence Relation:**
   * If the current player picks `arr[i]`, the opponent will then play optimally on the remaining subarray `arr[i+1...j]`.
     The current player's advantage would be `arr[i] - dp[i+1][j]`.
   * If the current player picks `arr[j]`, the opponent will then play optimally on the remaining subarray `arr[i...j-1]`.
     The current player's advantage would be `arr[j] - dp[i][j-1]`.
   * Therefore, `dp[i][j] = max(arr[i] - dp[i+1][j], arr[j] - dp[i][j-1])`.

4. **Optimization to 1D:**
   * Instead of using a 2D table, we can optimize space by using a 1D array.
   * We process the array from right to left, updating our DP values for each starting index.

5. **Calculating the Result:**
   * Let `sum` be the total sum of all coin values.
   * The maximum amount the first player can collect is `(sum + dp[0][n-1]) / 2`.
   * This is because `dp[0][n-1]` represents the difference between the first player's total and the second player's total.
   * If `first + second = sum` and `first - second = dp[0][n-1]`, then `first = (sum + dp[0][n-1]) / 2`.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n²), where n is the size of the array. We need to fill a DP table for all possible subarrays.
* **Expected Auxiliary Space Complexity:** O(n), as we only use a single array of size n to store intermediate DP values.

## **⚙️ Code (C)**

```c
int maximumAmount(int* arr, int n) {
    int s = 0, *dp = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        s += arr[i];
        for (int j = i; j < n; j++)
            dp[j] = (i == j) ? arr[j] : (arr[i] - dp[j] > arr[j] - dp[j - 1] ? arr[i] - dp[j] : arr[j] - dp[j - 1]);
    }
    int res = (s + dp[n - 1]) / 2;
    free(dp);
    return res;
}
```

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size(), s = 0;
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            s += arr[i];
            for (int j = i; j < n; j++)
                dp[j] = (i == j) ? arr[j] : max(arr[i] - dp[j], arr[j] - dp[j - 1]);
        }
        return (s + dp[n - 1]) / 2;
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ 2D DP Table Approach**

### 💡 Algorithm Steps:

1. Create a 2D DP table where `dp[i][j]` represents max advantage for subarray [i,j].
2. Fill diagonals first (single elements) then expand to larger subarrays.
3. At each step, player picks either first or last element optimally.
4. Calculate final amount by adding half of total sum and advantage.

```cpp
class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n));
        int s = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
            s += arr[i];
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
            }
        }
        return (s + dp[0][n - 1]) / 2;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Fill all cells in 2D table
* **Auxiliary Space:** 💾 O(n²) - 2D DP table storage

### ✅ **Why This Approach?**

* Intuitive visualization of subproblems
* Clear recursive structure with memoization
* Easy to trace and debug intermediate states

## 📊 **3️⃣ Recursive Memoization**

### 💡 Algorithm Steps:

1. Define recursive function for range [left, right] representing current game state.
2. Base case when left equals right, return that element value.
3. Recursively explore picking from left or right end optimally.
4. Memoize results to avoid recomputing same subproblems.

```cpp
class Solution {
    map<pair<int,int>, int> memo;
    int solve(vector<int>& arr, int l, int r) {
        if (l == r) return arr[l];
        if (l > r) return 0;
        auto key = make_pair(l, r);
        if (memo.count(key)) return memo[key];
        return memo[key] = max(arr[l] - solve(arr, l + 1, r), 
                                arr[r] - solve(arr, l, r - 1));
    }
public:
    int maximumAmount(vector<int>& arr) {
        int s = accumulate(arr.begin(), arr.end(), 0);
        return (s + solve(arr, 0, arr.size() - 1)) / 2;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Each subproblem computed once
* **Auxiliary Space:** 💾 O(n²) - Memoization map and recursion stack

### ✅ **Why This Approach?**

* Top-down approach mirrors natural problem thinking
* Easier to convert from brute force solution
* Good for understanding problem structure

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1010/1115 test cases due to time constraints).

## 📊 **4️⃣ Space Optimized Rolling Array**

### 💡 Algorithm Steps:

1. Optimize space by maintaining only current and previous row of DP.
2. Process diagonally from bottom-right to top-left of conceptual table.
3. Update single array by reusing previously computed values.
4. Reduce space from O(n²) to O(n) while maintaining correctness.

```cpp
class Solution {
public:
    int maximumAmount(vector<int>& arr) {
        int n = arr.size(), s = accumulate(arr.begin(), arr.end(), 0);
        vector<int> cur(n), pre(n);
        for (int i = 0; i < n; i++) cur[i] = arr[i];
        for (int len = 2; len <= n; len++) {
            swap(cur, pre);
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                cur[i] = max(arr[i] - pre[i + 1], arr[j] - pre[i]);
            }
        }
        return (s + cur[0]) / 2;
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n²) - Same computation as 2D approach
* **Auxiliary Space:** 💾 O(n) - Only two arrays of size n

### ✅ **Why This Approach?**

* Significant space optimization over 2D DP
* Maintains optimal time complexity
* Better cache performance with smaller memory footprint

## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🎯 **1D DP Optimized**            | 🟢 O(n²)               | 🟢 O(n)                 | 🚀 Best space efficiency          | 🔧 Less intuitive logic              |
| 📊 **2D DP Table**                | 🟢 O(n²)               | 🟡 O(n²)                | 📖 Clear visualization            | 💾 High memory usage                 |
| 🔄 **Recursive Memo**             | 🟢 O(n²)               | 🟡 O(n²)                | 🎯 Natural problem structure      | 📚 Recursion overhead                |
| ⚡ **Rolling Array**              | 🟢 O(n²)               | 🟢 O(n)                 | ⭐ Space optimized                | 🔧 Moderate implementation complexity|

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Production/Memory constrained**                  | 🥇 **1D DP Optimized**               | ★★★★★                     |
| 📖 **Learning/Understanding**                         | 🥈 **2D DP Table**                   | ★★★★★                     |
| 🔧 **Prototyping/Quick solution**                     | 🥉 **Recursive Memo**                | ★★★★☆                     |
| ⚡ **Balance of clarity & efficiency**               | 🏅 **Rolling Array**                 | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maximumAmount(int arr[]) {
        int n = arr.length, s = 0;
        int[] dp = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            s += arr[i];
            for (int j = i; j < n; j++)
                dp[j] = (i == j) ? arr[j] : Math.max(arr[i] - dp[j], arr[j] - dp[j - 1]);
        }
        return (s + dp[n - 1]) / 2;
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maximumAmount(self, arr):
        n, s = len(arr), 0
        dp = [0] * n
        for i in range(n - 1, -1, -1):
            s += arr[i]
            for j in range(i, n):
                dp[j] = arr[j] if i == j else max(arr[i] - dp[j], arr[j] - dp[j - 1])
        return (s + dp[n - 1]) // 2
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

