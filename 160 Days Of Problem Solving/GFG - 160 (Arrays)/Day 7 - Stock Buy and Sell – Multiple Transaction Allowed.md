---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Arrays
---

# 🚀 _Day 7. Stock Buy and Sell – Multiple Transaction Allowed_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615)

## 💡 **Problem Description:**

You are given an array `prices[]` where each number represents the price of a stock on the corresponding day. You may buy and sell the stock multiple times. Find the maximum profit that you can achieve by performing multiple transactions (buying and selling the stock).

**Note:** A stock can only be sold if it has been bought previously and multiple stocks cannot be held on any given day.

## 🔍 **Example Walkthrough:**

**Input:**  
`prices[] = [100, 180, 260, 310, 40, 535, 695]`  
**Output:**  
`865`

**Explanation:**  
Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210.  
Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655.  
Maximum Profit = 210 + 655 = 865.

**Input:**  
`prices[] = [4, 2, 2, 2, 4]`  
**Output:**  
`2`

**Explanation:**  
Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2.  
Maximum Profit = 2.

### Constraints:

- `1 <= prices.size() <= 10^5`
- `0 <= prices[i] <= 10^4`

## 🎯 **My Approach:**

1. **Greedy Approach:**  
   The problem can be solved optimally by iterating through the array and accumulating profit whenever the price on the next day is greater than the price on the current day. This guarantees that we are maximizing profit by buying at the local minima and selling at the local maxima.

2. **Steps:**
   - Traverse the array starting from the second day.
   - If the price on the next day is higher than the current day, we calculate the profit and add it to the total.
   - Continue until the end of the array.

## 🕒 **Time and Auxiliary Space Complexity**📝

- **Expected Time Complexity:** O(n), where `n` is the size of the array. We are iterating through the array only once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

## 📝 **Solution Code**

## Code (C)

```c
int maximumProfit(int prices[], int n) {
    int profit = 0;

    for (int i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}
```

## Code (Cpp)

```cpp
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int profit = 0;
        int n = prices.size();

        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
```

## Code (Java)

```java
class Solution {
    public int maximumProfit(int prices[]) {
        int profit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
}
```

## Code (Python)

```python
from typing import List

class Solution:
    def maximumProfit(self, prices: List[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit
```

# 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
