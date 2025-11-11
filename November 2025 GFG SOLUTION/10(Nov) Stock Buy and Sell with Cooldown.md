---
title: "📈 Stock Buy and Sell with Cooldown | GFG Solution 💰"
keywords🏷️: ["📈 stock trading", "💰 dynamic programming", "🔄 state machine", "📊 optimization", "📘 GFG", "🏁 competitive programming", "📚 DSA"]
author: "✍️ Het Patel (Hunterdii)"
description: "✅ GFG solution to the Stock Buy and Sell with Cooldown problem: maximize profit from stock trading with mandatory cooldown period using dynamic programming state machine approach. 🚀"
date: 📅 2025-11-10
---

# *10. Stock Buy and Sell with Cooldown*

The problem can be found at the following link: 🔗 [Question Link](https://www.geeksforgeeks.org/problems/buy-stock-with-cooldown/1)

## **🧩 Problem Description**

You are given an array `arr[]` where the ith element represents the price of a stock on the ith day (all prices are non-negative integers). Your task is to find the **maximum profit** you can make by buying and selling stocks with the constraint that after selling a stock, you cannot buy again on the next day (i.e., there is a **one-day cooldown**).

You can perform multiple transactions (buy and sell multiple times), but you must sell the stock before buying again, and you must observe the cooldown period after each sale.

## **📘 Examples**

### Example 1

```cpp
Input: arr[] = [0, 2, 1, 2, 3]
Output: 3
Explanation: You first buy on day 1, sell on day 2 then cool down, then buy on day 4, and sell on day 5. 
The total profit earned is (2-0) + (3-2) = 3, which is the maximum achievable profit.
```

### Example 2

```cpp
Input: arr[] = [3, 1, 6, 1, 2, 4]
Output: 7
Explanation: You first buy on day 2 and sell on day 3 then cool down, then again you buy on day 5 
and then sell on day 6. Clearly, the total profit earned is (6-1) + (4-2) = 7, which is the maximum achievable profit.
```

## **🔒 Constraints**

* $1 \le \text{arr.size()} \le 10^5$
* $1 \le \text{arr}[i] \le 10^4$

## **✅ My Approach**

The optimal approach uses **Dynamic Programming with State Machine** tracking three distinct states at each day:

### **State Machine DP with Constant Space**

1. **Define States:**
   * `buy`: Maximum profit when we are ready to buy or holding a stock (can buy today).
   * `sell`: Maximum profit when we just sold stock (cannot buy tomorrow).
   * `cooldown`: Maximum profit when we are in cooldown period (can buy tomorrow).

2. **State Transitions:**
   * **Buy State**: Either continue holding previous buy state, or buy today using cooldown profit.
     * `buy = max(previous_buy, cooldown - arr[i])`
   * **Sell State**: Either continue with previous sell state, or sell today from buy state.
     * `sell = max(previous_sell, previous_buy + arr[i])`
   * **Cooldown State**: Take maximum of previous cooldown or previous sell (entering cooldown after selling).
     * `cooldown = max(previous_cooldown, previous_sell)`

3. **Initialization:**
   * Start with `buy = -arr[0]` (buying first stock).
   * `sell = 0` and `cooldown = 0` (no profit initially).

4. **Iterate Through Prices:**
   * For each day, calculate new states based on previous states.
   * Store previous states temporarily to avoid overwriting during calculation.

5. **Return Result:**
   * Maximum of `sell` and `cooldown` states gives the maximum achievable profit.

## 📝 Time and Auxiliary Space Complexity

* **Expected Time Complexity:** O(n), where n is the size of the array. We iterate through the array once, performing constant-time operations at each step to update the three states.
* **Expected Auxiliary Space Complexity:** O(1), as we only use three integer variables (`buy`, `sell`, `cooldown`) and their temporary copies, requiring constant additional space regardless of input size.

## **🧑‍💻 Code (C++)**

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        int buy = -arr[0], sell = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int prevBuy = buy, prevSell = sell;
            buy = max(buy, cooldown - arr[i]);
            sell = max(sell, prevBuy + arr[i]);
            cooldown = max(cooldown, prevSell);
        }
        return max(sell, cooldown);
    }
};
```

<details>
<summary><b>⚡ View Alternative Approaches with Code and Analysis</b></summary>

## 📊 **2️⃣ State Machine with Array Tracking**

### 💡 Algorithm Steps:

1. Track three states at each position: can buy, can sell after cooldown, and must cooldown.
2. Use arrays to store maximum profit achievable in each state.
3. Update states based on previous day's decisions and transitions.
4. Return maximum profit from sell or cooldown state at the end.

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        vector<int> hold(n), sold(n), rest(n);
        hold[0] = -arr[0];
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i-1], rest[i-1] - arr[i]);
            sold[i] = hold[i-1] + arr[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }
        return max(sold[n-1], rest[n-1]);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Single pass through array
* **Auxiliary Space:** 💾 O(n) - Three arrays for state tracking

### ✅ **Why This Approach?**

* Clear state transitions make logic easy to follow
* Natural extension for more complex state problems
* Good for understanding dynamic programming patterns

## 📊 **3️⃣ Classic DP Tabulation**

### 💡 Algorithm Steps:

1. Create DP table where each row represents transaction states.
2. Iterate through prices and update buy and sell states.
3. Account for cooldown by referencing states from two positions back.
4. Build solution bottom-up from base cases to final answer.

```cpp
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -arr[0];
        if (n > 1) {
            dp[1][0] = max(0, arr[1] - arr[0]);
            dp[1][1] = max(-arr[0], -arr[1]);
        }
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + arr[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - arr[i]);
        }
        return dp[n-1][0];
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Linear iteration through prices
* **Auxiliary Space:** 💾 O(n) - 2D DP table storage

### ✅ **Why This Approach?**

* Standard DP pattern for stock problems
* Easy to visualize state transitions
* Straightforward to extend for variations

## 📊 **4️⃣ Recursive with Memoization**

### 💡 Algorithm Steps:

1. Define recursive function that explores buy and sell decisions at each position.
2. Use memoization map to cache results for state combinations.
3. For buy state, consider buying current stock or skipping.
4. For sell state, consider selling and entering cooldown or skipping.

```cpp
class Solution {
public:
    int solve(int i, int canBuy, vector<int>& arr, map<pair<int,int>,int>& memo) {
        if (i >= arr.size()) return 0;
        if (memo.count({i, canBuy})) return memo[{i, canBuy}];
        int profit = 0;
        if (canBuy) {
            profit = max(-arr[i] + solve(i+1, 0, arr, memo), solve(i+1, 1, arr, memo));
        } else {
            profit = max(arr[i] + solve(i+2, 1, arr, memo), solve(i+1, 0, arr, memo));
        }
        return memo[{i, canBuy}] = profit;
    }
    int maxProfit(vector<int>& arr) {
        map<pair<int,int>,int> memo;
        return solve(0, 1, arr, memo);
    }
};
```

### 📝 **Complexity Analysis:**

* **Time:** ⏱️ O(n) - Each state computed once with memoization
* **Auxiliary Space:** 💾 O(n) - Recursion stack and memoization map

### ✅ **Why This Approach?**

* Intuitive top-down thinking process
* Natural representation of decision tree
* Useful for complex constraint problems

> Note: This approach results in Time Limit Exceeded (TLE) for large inputs (fails ~1110 /1121 test cases due to time constraints).



## 🆚 **🔍 Comparison of Approaches**

| 🚀 **Approach**                    | ⏱️ **Time Complexity** | 💾 **Space Complexity** | ✅ **Pros**                        | ⚠️ **Cons**                           |
| ---------------------------------- | ---------------------- | ----------------------- | --------------------------------- | ------------------------------------- |
| 🏷️ **Constant Space Variables**   | 🟢 O(n)                | 🟢 O(1)                 | 🚀 Optimal space usage            | 🔧 Requires careful state management  |
| 🔍 **State Machine Arrays**       | 🟢 O(n)                | 🟡 O(n)                 | 📖 Clear state visualization      | 💾 Extra space for arrays            |
| 📊 **Classic DP Table**           | 🟢 O(n)                | 🟡 O(n)                 | 🎯 Standard pattern               | 💾 2D table overhead                 |
| 🔄 **Recursive Memoization (TLE)**      | 🟢 O(n)                | 🟡 O(n)                 | ⭐ Intuitive logic flow           | 🐌 Recursion overhead                |

### 🏆 **Best Choice Recommendation**

| 🎯 **Scenario**                                    | 🎖️ **Recommended Approach**          | 🔥 **Performance Rating** |
| -------------------------------------------------- | ------------------------------------- | ------------------------- |
| 🏅 **Optimal performance needed**                     | 🥇 **Constant Space Variables**      | ★★★★★                     |
| 📖 **Readability priority**                           | 🥈 **State Machine Arrays**          | ★★★★☆                     |
| 🔧 **Learning DP patterns**                           | 🥉 **Classic DP Table**              | ★★★★☆                     |
| 🎯 **Interview/Problem solving**                      | 🏅 **Recursive Memoization**         | ★★★★☆                     |

</details>

## **☕ Code (Java)**

```java
class Solution {
    public int maxProfit(int arr[]) {
        int n = arr.length;
        if (n <= 1) return 0;
        int buy = -arr[0], sell = 0, cooldown = 0;
        for (int i = 1; i < n; i++) {
            int prevBuy = buy, prevSell = sell;
            buy = Math.max(buy, cooldown - arr[i]);
            sell = Math.max(sell, prevBuy + arr[i]);
            cooldown = Math.max(cooldown, prevSell);
        }
        return Math.max(sell, cooldown);
    }
}
```

## **🐍 Code (Python)**

```python
class Solution:
    def maxProfit(self, arr):
        n = len(arr)
        if n <= 1: return 0
        buy, sell, cooldown = -arr[0], 0, 0
        for i in range(1, n):
            prev_buy, prev_sell = buy, sell
            buy = max(buy, cooldown - arr[i])
            sell = max(sell, prev_buy + arr[i])
            cooldown = max(cooldown, prev_sell)
        return max(sell, cooldown)
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
