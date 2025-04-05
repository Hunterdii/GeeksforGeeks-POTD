# _20. Stock Buy and Sell – Max 2 Transactions Allowed_

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1)

## **Problem Description**

In daily share trading, a trader buys shares and sells them on the same day. Given an array **prices[]** representing stock prices throughout the day, find the **maximum profit** a trader could have made with at most **2 transactions**.

⚠ **Note:** The second transaction can only start after the first one is complete (**buy → sell → buy → sell**).

## **Examples**

### **Example 1:**

#### **Input:**

```cpp
prices[] = [10, 22, 5, 75, 65, 80]
```

#### **Output:**

```cpp
87
```

#### **Explanation:**

- Buy at **10**, sell at **22** → **Profit = 12**
- Buy at **5**, sell at **80** → **Profit = 75**
- **Total Profit = 12 + 75 = 87**

### **Example 2:**

#### **Input:**

```cpp
prices[] = [2, 30, 15, 10, 8, 25, 80]
```

#### **Output:**

```cpp
100
```

#### **Explanation:**

- Buy at **2**, sell at **30** → **Profit = 28**
- Buy at **8**, sell at **80** → **Profit = 72**
- **Total Profit = 28 + 72 = 100**

### **Constraints:**

- $1 \leq \text{prices.size()} \leq 10^5$
- $1 \leq \text{prices[i]} \leq 10^5$

## **My Approach**

### **Optimized Greedy Approach**

1. Use **four variables**:
   - `b1` (Best price to buy first stock)
   - `s1` (Best profit after first sale)
   - `b2` (Best price to buy second stock after first sale)
   - `s2` (Best profit after second sale)
2. Iterate through prices and update these variables accordingly.
3. Return `s2` (Maximum profit with at most two transactions).

### **Algorithm Steps:**

1. Initialize `b1 = ∞`, `s1 = 0`, `b2 = ∞`, `s2 = 0`.
2. **For each price `p` in the array:**
   - Update `b1` (Minimum price to buy first stock).
   - Update `s1` (Best profit after first sale).
   - Update `b2` (Best price to buy second stock).
   - Update `s2` (Best profit after second sale).
3. Return `s2`.

## **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(N), as we traverse the array once and perform a constant number of operations.
- **Expected Auxiliary Space Complexity:** O(1), as we use only four variables.

## **Code (C++)**

```cpp
class Solution {
  public:
    int maxProfit(vector<int>& a) {
        int b1 = INT_MAX, s1 = 0, b2 = INT_MAX, s2 = 0;
        for (int p : a) {
            b1 = min(b1, p);
            s1 = max(s1, p - b1);
            b2 = min(b2, p - s1);
            s2 = max(s2, p - b2);
        }
        return s2;
    }
};
```

<details>
<summary><h2 align="center">⚡ Alternative Approaches</h2></summary>

## **1️⃣ Dynamic Programming (O(N) Time, O(N) Space)**

### **Algorithm Steps:**

1. Define a `dp[i][j]` table where `dp[i][j]` represents the maximum profit achievable up to day `i` with `j` transactions.
2. **Recurrence Relation**:
   $\[
   dp[i][j] = \max(dp[i-1][j], \max_{k=0}^{i-1} (prices[i] - prices[k] + dp[k][j-1]))
   \]$
3. Use a space-optimized 1D DP array to reduce `O(N²)` complexity to `O(N)`.

```cpp
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<vector<int>> dp(3, vector<int>(prices.size(), 0));
        for (int t = 1; t <= 2; t++) {
            int maxDiff = -prices[0];
            for (int d = 1; d < prices.size(); d++) {
                dp[t][d] = max(dp[t][d-1], prices[d] + maxDiff);
                maxDiff = max(maxDiff, dp[t-1][d] - prices[d]);
            }
        }
        return dp[2][prices.size()-1];
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **2️⃣ Greedy + Prefix/Suffix Array (O(N) Time, O(N) Space)**

### **Algorithm Steps:**

1. Use **prefix max profit** (`left[i]`) to track max profit from **0 to i**.
2. Use **suffix max profit** (`right[i]`) to track max profit from **i to N-1**.
3. Merge results to get the maximum of `left[i] + right[i+1]`.

```cpp
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> left(n, 0), right(n, 0);

        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i-1], prices[i] - minPrice);
        }

        int maxPrice = prices[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i+1], maxPrice - prices[i]);
        }

        for (int i = 0; i < n; i++)
            maxProfit = max(maxProfit, left[i] + right[i]);

        return maxProfit;
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N)`

## **3️⃣ Recursive + Memoization (O(N) Time, O(N×2) Space)**

### **Algorithm Steps:**

1. Use a **recursive function** `maxProfit(index, transactions, holding)` that computes:
   - If you are **holding a stock**, you can sell or keep it.
   - If you **don't have a stock**, you can buy or skip.
2. **Memoization (`dp[i][j][h]`)**:
   - `i`: Day index.
   - `j`: Transactions used (max 2).
   - `h`: Holding status (`0` or `1`).

```cpp
class Solution {
  public:
    int dp[100005][3][2];

    int solve(vector<int>& prices, int i, int t, int h) {
        if (i == prices.size() || t == 0) return 0;
        if (dp[i][t][h] != -1) return dp[i][t][h];

        int doNothing = solve(prices, i + 1, t, h);
        int doTrade = h ? (prices[i] + solve(prices, i + 1, t - 1, 0)) : (-prices[i] + solve(prices, i + 1, t, 1));

        return dp[i][t][h] = max(doNothing, doTrade);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, 2, 0);
    }
};
```

✅ **Time Complexity:** `O(N)`  
✅ **Space Complexity:** `O(N×2)`

## **Comparison of Approaches**

| **Approach**                | ⏱️ **Time Complexity** | 🗂️ **Space Complexity** | ✅ **Pros**                  | ⚠️ **Cons**                    |
| --------------------------- | ---------------------- | ----------------------- | ---------------------------- | ------------------------------ |
| **Greedy (Optimized)**      | 🟢 O(N)                | 🟢 O(1)                 | Best for large inputs        | Hard to intuitively understand |
| **DP (2D Table)**           | 🟢 O(N)                | 🔴 O(N)                 | Easy to implement, intuitive | Higher space usage             |
| **Prefix-Suffix Arrays**    | 🟢 O(N)                | 🟡 O(N)                 | Easier to understand         | Extra space usage              |
| **Recursive + Memoization** | 🟢 O(N)                | 🔴 O(N×2)               | Intuitive recursion approach | High memory usage              |

✅ **Best Choice?**

- If you want **best efficiency**: Use **Greedy (Optimized)** approach.
- If you prefer **DP-style tabulation**: Use **2D DP Approach**.
- If you like **prefix-suffix tricks**: Use **Prefix-Suffix Arrays**.
- If you like **recursion**: Use **Recursive + Memoization**.

</details>

## **Code (Java)**

```java
class Solution {
    public static int maxProfit(int[] a) {
        int b1 = Integer.MAX_VALUE, s1 = 0, b2 = Integer.MAX_VALUE, s2 = 0;
        for (int p : a) {
            b1 = Math.min(b1, p);
            s1 = Math.max(s1, p - b1);
            b2 = Math.min(b2, p - s1);
            s2 = Math.max(s2, p - b2);
        }
        return s2;
    }
}
```

## **Code (Python)**

```python
class Solution:
    def maxProfit(self, a):
        b1, s1, b2, s2 = float('inf'), 0, float('inf'), 0
        for p in a:
            b1, s1, b2, s2 = min(b1, p), max(s1, p - b1), min(b2, p - s1), max(s2, p - b2)
        return s2
```

## **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
