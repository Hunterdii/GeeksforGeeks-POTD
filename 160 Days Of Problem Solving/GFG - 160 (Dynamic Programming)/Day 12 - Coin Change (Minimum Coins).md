---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
---

# 🚀 _Day 12. Coin Change (Minimum Coins)_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/number-of-coins1824)

## 💡 **Problem Description:**

Given an array `coins[]` of distinct denominations and an integer `sum`, determine the **minimum number of coins** required to make up the given sum.  
You have **an infinite supply** of each type of coin.  
If the sum **cannot be formed**, return `-1`.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
coins[] = [25, 10, 5]
sum = 30
```

#### **Output:**

```
2
```

#### **Explanation:**

The minimum number of coins required is **2** (25 + 5).

### **Example 2:**

#### **Input:**

```
coins[] = [9, 6, 5, 1]
sum = 19
```

#### **Output:**

```
3
```

#### **Explanation:**

The minimum number of coins required is **3** (9 + 9 + 1).

### **Example 3:**

#### **Input:**

```
coins[] = [5, 1]
sum = 0
```

#### **Output:**

```
0
```

#### **Explanation:**

For a target sum of **0**, no coins are needed.

### **Example 4:**

#### **Input:**

```
coins[] = [4, 6, 2]
sum = 5
```

#### **Output:**

```
-1
```

#### **Explanation:**

It's **not possible** to obtain a sum of `5` using the given coins.

### **Constraints:**

- $\(1 \leq \text{sum} \times \text{coins.size()} \leq 10^6\)$
- $\(0 \leq \text{sum} \leq 10^4\)$
- $\(1 \leq \text{coins}[i] \leq 10^4\)$
- $\(1 \leq \text{coins.size()} \leq 10^3\)$

## 🎯 **My Approach:**

## **Optimized Dynamic Programming**

### **Algorithm Steps:**

1. **Define `dp[j]`** as the minimum number of coins needed to obtain `sum = j`.
2. **Base Case:** `dp[0] = 0` (zero sum requires zero coins).
3. **Transition:**
   - For each `coin`, update `dp[j]` for all `j >= coin` using:  
     $\[
     dp[j] = \min(dp[j], dp[j - coin] + 1)
     $\]
4. **Final Check:** If `dp[sum] == ∞`, return `-1` (sum cannot be formed).

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N × sum), as we iterate over each coin and process all sums up to `sum`.
- **Expected Auxiliary Space Complexity:** O(sum), as we maintain a 1D DP array of size `sum + 1`.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int minCoins(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for (int c : coins)
            for (int j = c; j <= sum; j++)
                if (dp[j - c] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - c] + 1);
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(N×sum) Time, O(N×sum) Space) — 2D DP**

### **Algorithm Steps:**

1. Use a **2D DP table** where `dp[i][j]` represents the minimum coins needed to make sum `j` using the first `i` coins.
2. **Base Case:**
   - `dp[i][0] = 0` for all `i` (zero sum requires zero coins).
   - `dp[0][j] = ∞` for all `j > 0` (zero coins can't form positive sum).
3. **Recurrence Relation:**  
   $\[
   dp[i][j] = \min(dp[i-1][j], 1 + dp[i][j - coins[i-1]])
   $\]
   - Exclude the coin (`dp[i-1][j]`).
   - Include the coin (`dp[i][j - coins[i-1]] + 1`).

```cpp
class Solution {
  public:
    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MAX));
        for (int i = 0; i <= n; i++) dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i - 1]] + 1);
            }
        }
        return dp[n][sum] == INT_MAX ? -1 : dp[n][sum];
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **3️⃣ Recursive + Memoization (O(N×sum) Time, O(N×sum) Space)**

### **Algorithm Steps:**

1. **Recursive function** `minCoins(index, sum)` calculates the minimum coins needed using coins up to `index`.
2. **Base Case:**
   - If `sum == 0`, return `0` (no coins needed).
   - If `index < 0` or `sum < 0`, return `∞` (not possible).
3. **Recurrence Relation:**  
   $\[
   minCoins(index, sum) = \min(minCoins(index - 1, sum), 1 + minCoins(index, sum - coins[index]])
   $\]
   - Exclude the current coin.
   - Include the current coin.
4. **Use memoization (`dp[index][sum]`)** to avoid redundant calculations.

```cpp
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int sum) {
        if (sum == 0) return 0;
        if (i < 0 || sum < 0) return INT_MAX;
        if (dp[i][sum] != -1) return dp[i][sum];
        int exclude = solve(coins, i - 1, sum);
        int include = solve(coins, i, sum - coins[i]);
        if (include != INT_MAX) include += 1;
        return dp[i][sum] = min(exclude, include);
    }

    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        int res = solve(coins, n - 1, sum);
        return res == INT_MAX ? -1 : res;
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                  | ⚠️ **Cons**               |
| --------------------------- | ---------------------- | ----------------------- | ---------------------------- | ------------------------- |
| **1D Space Optimized DP**   | 🟡 `O(N × sum)`        | 🟢 `O(sum)`             | Most efficient space-wise    | Requires careful indexing |
| **2D DP (Tabulation)**      | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Easy to implement, intuitive | High space usage          |
| **Recursive + Memoization** | 🟡 `O(N × sum)`        | 🔴 `O(N × sum)`         | Natural recursion flow       | Stack overhead            |

✅ **Best Choice?**

- **If optimizing space:** Use **1D DP (Space-Optimized)**.
- **If space is not a concern:** Use **2D DP (Tabulation)** for easy understanding.
- **For recursion lovers:** Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    public int minCoins(int[] coins, int sum) {
        int[] dp = new int[sum + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int c : coins)
            for (int j = c; j <= sum; j++)
                if (dp[j - c] != Integer.MAX_VALUE)
                    dp[j] = Math.min(dp[j], dp[j - c] + 1);
        return dp[sum] == Integer.MAX_VALUE ? -1 : dp[sum];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def minCoins(self, coins, sum):
        dp = [float('inf')] * (sum + 1)
        dp[0] = 0
        for c in coins:
            for j in range(c, sum + 1):
                dp[j] = min(dp[j], dp[j - c] + 1)
        return -1 if dp[sum] == float('inf') else dp[sum]
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
