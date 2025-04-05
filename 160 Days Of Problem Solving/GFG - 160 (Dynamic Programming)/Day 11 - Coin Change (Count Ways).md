---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
  - Arrays
---

# 🚀 _Day 11. Coin Change (Count Ways)_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/coin-change2448)

## 💡 **Problem Description:**

Given an integer array **coins[]** representing different denominations of currency and an integer **sum**, find the **number of ways** to make `sum` using any number of coins.  
🔹 **Note:** You have an **infinite** supply of each type of coin.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```plaintext
coins = [1, 2, 3], sum = 4
```

#### **Output:**

```plaintext
4
```

#### **Explanation:**

There are **4 ways** to make `4` using given coins:

1. `[1, 1, 1, 1]`
2. `[1, 1, 2]`
3. `[2, 2]`
4. `[1, 3]`

### **Example 2:**

#### **Input:**

```plaintext
coins = [2, 5, 3, 6], sum = 10
```

#### **Output:**

```plaintext
5
```

#### **Explanation:**

There are **5 ways** to make `10`:

1. `[2, 2, 2, 2, 2]`
2. `[2, 2, 3, 3]`
3. `[2, 2, 6]`
4. `[2, 3, 5]`
5. `[5, 5]`

### **Constraints:**

- $1 \leq \text{Number of Coins} \leq 10^3$
- $1 \leq \text{sum} \leq 10^6$
- $1 \leq \text{coins}[i] \leq 10^3$

## 🎯 **My Approach:**

## **Optimized Dynamic Programming**

### **Algorithm Steps:**

1. Use a **1D DP array** `dp[]`, where `dp[i]` stores the **number of ways** to make sum `i`.
2. **Base Case:**
   - `dp[0] = 1` (There is **one way** to make sum `0`: choose nothing).
3. **Transition:**
   - For each `coin`, update all sums from `coin` to `sum`.
   - `dp[j] += dp[j - coin]` (Include current coin).

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** `O(N × sum)`, where `N` is the number of coins.
- **Expected Auxiliary Space Complexity:** `O(sum)`, as we only store a 1D DP array.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
            for (int j = coin; j <= sum; j++)
                dp[j] += dp[j - coin];
        return dp[sum];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(N×sum) Time, O(N×sum) Space) — 2D DP**

### **Algorithm Steps:**

1. Use a **2D DP table** where `dp[i][j]` represents the number of ways to make sum `j` using the first `i` coins.
2. **Base Case:**
   - `dp[0][0] = 1` (one way to make sum `0` with zero coins).
   - `dp[i][0] = 1` for all `i` (only one way to make sum `0`: choose nothing).
3. **Recurrence Relation:**  
   $\[
   \text{dp}[i][j] = \text{dp}[i-1][j] + \text{dp}[i][j - \text{coins}[i-1]]
   $\]
   - Exclude the coin (`dp[i-1][j]`).
   - Include the coin (`dp[i][j - coins[i-1]]`).

```cpp
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][sum];
    }
};
```

✅ **Time Complexity:** `O(N × sum)`  
✅ **Space Complexity:** `O(N × sum)`

## **3️⃣ Recursive + Memoization (O(N×sum) Time, O(N×sum) Space)**

### **Algorithm Steps:**

1. **Recursive function** `countWays(index, sum)` calculates the number of ways using coins up to `index`.
2. **Base Case:**
   - If `sum == 0`, return `1` (valid way found).
   - If `index < 0` or `sum < 0`, return `0` (invalid case).
3. **Recurrence Relation:**  
   $\[
   \text{countWays(index, sum)} = \text{countWays(index - 1, sum)} + \text{countWays(index, sum - coins[index])}
   $\]
   - Exclude the current coin.
   - Include the current coin.
4. **Use memoization (`dp[index][sum]`)** to avoid redundant calculations.

```cpp
class Solution {
  public:
    vector<vector<int>> dp;
    int solve(vector<int>& coins, int i, int sum) {
        if (sum == 0) return 1;
        if (i < 0 || sum < 0) return 0;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = solve(coins, i - 1, sum) + solve(coins, i, sum - coins[i]);
    }

    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        dp.assign(n, vector<int>(sum + 1, -1));
        return solve(coins, n - 1, sum);
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
    public int count(int[] coins, int sum) {
        int[] dp = new int[sum + 1];
        dp[0] = 1;
        for (int coin : coins)
            for (int j = coin; j <= sum; j++)
                dp[j] += dp[j - coin];
        return dp[sum];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def count(self, coins, sum):
        dp = [0] * (sum + 1)
        dp[0] = 1
        for coin in coins:
            for j in range(coin, sum + 1):
                dp[j] += dp[j - coin]
        return dp[sum]
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
