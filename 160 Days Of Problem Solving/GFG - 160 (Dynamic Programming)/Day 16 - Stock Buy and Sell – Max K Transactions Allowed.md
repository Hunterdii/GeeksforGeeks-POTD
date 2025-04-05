---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Dynamic Programming
---

# 🚀 _Day 16. Stock Buy and Sell – Max K Transactions Allowed_ 🧠

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/dynamic-programming-gfg-160/problem/maximum-profit4657)

## 💡 **Problem Description:**

In the stock market, a person can buy a stock and sell it on a future date. You are given an array **prices[]** representing stock prices on different days and a positive integer **k**.

Find out the **maximum profit** a person can make with **at most k transactions**.

A **transaction** consists of **buying** and subsequently **selling** a stock. A new transaction can only start after completing the previous one.

## 🔍 **Example Walkthrough:**

### **Example 1:**

#### **Input:**

```
prices = [10, 22, 5, 80]
k = 2
```

#### **Output:**

```
87
```

#### **Explanation:**

1. **Buy at 10, Sell at 22** → Profit = **12**
2. **Buy at 5, Sell at 80** → Profit = **75**  
   **Total Profit = 12 + 75 = 87**

### **Example 2:**

#### **Input:**

```
prices = [20, 580, 420, 900]
k = 3
```

#### **Output:**

```
1040
```

#### **Explanation:**

1. **Buy at 20, Sell at 580** → Profit = **560**
2. **Buy at 420, Sell at 900** → Profit = **480**  
   **Total Profit = 560 + 480 = 1040**

### **Example 3:**

#### **Input:**

```
prices = [100, 90, 80, 50, 25]
k = 1
```

#### **Output:**

```
0
```

#### **Explanation:**

- The stock price is **continuously decreasing**, so there is **no profit possible**.

### **Constraints:**

- $\(1 \leq \text{prices.size()} \leq 10^3\)$
- $\(1 \leq k \leq 200\)$
- $\(1 \leq \text{prices}[i] \leq 10^3\)$

## 🎯 **My Approach:**

## **Optimized Dynamic Programming**

1. If **2 \* k >= n**, it's optimal to perform **all profitable transactions**, similar to an **unlimited transactions problem**.
2. Otherwise, we use a **1D DP table** (`dp[2*k+1]`) to store the **best profit for different transaction states**:
   - **Odd indices** → Buying states
   - **Even indices** → Selling states
3. **Iterate through the stock prices** and update `dp[]` based on previous values:
   - If **buying**, maximize profit by either **holding** or **buying today**.
   - If **selling**, maximize profit by either **selling today** or **holding**.

### **Algorithm Steps:**

1. If `k == 0`, return **0** (no transactions allowed).
2. If **2 \* k >= n**, return the **sum of all upward price differences**.
3. Initialize `dp[2*k+1]` with `-∞` for buy states and `0` for the rest.
4. **Iterate through prices** and update `dp[j]` for **all transactions**.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(K × N), since we iterate over `prices[]` for each transaction.
- **Expected Auxiliary Space Complexity:** O(2K), since we only use a `dp[]` array of size `2K + 1`.

## 📝 **Solution Code**

## **Code (C++)**

```cpp
class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        if (2 * k >= n) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }
        vector<int> dp(2 * k + 1, INT_MIN);
        dp[0] = 0;
        for (int price : prices)
            for (int j = 1; j <= 2 * k; j++)
                dp[j] = j % 2 ? max(dp[j], dp[j - 1] - price) : max(dp[j], dp[j - 1] + price);
        return dp[2 * k];
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **2️⃣ Dynamic Programming (O(K×N) Time, O(K×N) Space) — 2D DP**

### **Algorithm Steps:**

1. Use a **2D DP table**, where `dp[i][j]` represents the maximum profit at day `j` with at most `i` transactions.
2. **Base Case:**
   - `dp[0][j] = 0` (No transactions, no profit).
   - `dp[i][0] = 0` (At day 0, profit is zero).
3. **Recurrence Relation:**  
   $\[
   dp[i][j] = \max(dp[i][j-1], prices[j] + \max(dp[i-1][p] - prices[p]) \quad \text{for } 0 \leq p < j
   \]$
   - `dp[i][j-1]`: No transaction on day `j`.
   - `prices[j] + max(dp[i-1][p] - prices[p])`: Buy at some `p`, sell at `j`.

```cpp
class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;
        vector<vector<int>> dp(k + 1, vector<int>(n, 0));
        for (int i = 1; i <= k; i++) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][n - 1];
    }
};
```

✅ **Time Complexity:** `O(K × N)`  
✅ **Space Complexity:** `O(K × N)`

## **3️⃣ Recursive + Memoization (O(K×N) Time, O(K×N) Space)**

### **Algorithm Steps:**

1. Define a **recursive function** `solve(i, t, holding)`, where:
   - `i` is the current index (day).
   - `t` is the number of transactions left.
   - `holding` is `true` if we own a stock.
2. **Base Cases:**
   - If `i == n` or `t == 0`, return `0`.
3. **Recurrence Relation:**
   - If `holding`:
     - Sell: `prices[i] + solve(i + 1, t - 1, false)`.
     - Hold: `solve(i + 1, t, true)`.
   - If **not holding**:
     - Buy: `-prices[i] + solve(i + 1, t, true)`.
     - Skip: `solve(i + 1, t, false)`.
4. **Use Memoization (`dp[i][t][holding]`)** to store computed values.

```cpp
class Solution {
  public:
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int i, int t, bool holding) {
        if (i == prices.size() || t == 0) return 0;
        if (dp[i][t][holding] != -1) return dp[i][t][holding];
        int skip = solve(prices, i + 1, t, holding);
        if (holding)
            return dp[i][t][holding] = max(skip, prices[i] + solve(prices, i + 1, t - 1, false));
        else
            return dp[i][t][holding] = max(skip, -prices[i] + solve(prices, i + 1, t, true));
    }

    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        dp.assign(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(prices, 0, k, false);
    }
};
```

✅ **Time Complexity:** `O(K × N)`  
✅ **Space Complexity:** `O(K × N) (recursion stack)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                   | ⚠️ **Cons**          |
| --------------------------- | ---------------------- | ----------------------- | ----------------------------- | -------------------- |
| **1D DP (Space Optimized)** | 🟡 `O(K × N)`          | 🟢 `O(2K)`              | Best space-efficient solution | Harder to understand |
| **2D DP (Tabulation)**      | 🟡 `O(K × N)`          | 🔴 `O(K × N)`           | Intuitive approach            | High space usage     |
| **Recursive + Memoization** | 🟡 `O(K × N)`          | 🔴 `O(K × N)`           | Natural recursion flow        | Stack overhead       |

✅ **Best Choice?**

- **If optimizing space:** Use **1D DP (Space-Optimized)**.
- **If space is not a concern:** Use **2D DP (Tabulation)** for easier understanding.
- **For recursion lovers:** Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    public static int maxProfit(int[] prices, int k) {
        int n = prices.length;
        if (n == 0 || k == 0) return 0;
        if (2 * k >= n) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                profit += Math.max(0, prices[i] - prices[i - 1]);
            return profit;
        }
        int[] dp = new int[2 * k + 1];
        Arrays.fill(dp, Integer.MIN_VALUE);
        dp[0] = 0;
        for (int price : prices)
            for (int j = 1; j <= 2 * k; j++)
                dp[j] = (j % 2 == 1) ? Math.max(dp[j], dp[j - 1] - price) : Math.max(dp[j], dp[j - 1] + price);
        return dp[2 * k];
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxProfit(self, prices, k):
        n = len(prices)
        if n == 0 or k == 0:
            return 0
        if 2 * k >= n:
            return sum(max(0, prices[i] - prices[i - 1]) for i in range(1, n))
        dp = [-float('inf')] * (2 * k + 1)
        dp[0] = 0
        for price in prices:
            for j in range(1, 2 * k + 1):
                dp[j] = max(dp[j], dp[j - 1] - price) if j % 2 else max(dp[j], dp[j - 1] + price)
        return dp[2 * k]
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
