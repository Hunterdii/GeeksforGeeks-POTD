# _22. Stock Buy and Sell – Max One Transaction Allowed_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/buy-stock-2/1)

<div align="center">
  <h2>✨ LeetCode Problem of the Day (POTD) Solutions ✨</h2>
</div>

- Continuing the **LeetCode Problem of the Day (POTD)** journey! 🎯
- Today's problem is live:  
  **[1072. Flip Columns For Maximum Number of Equal Rows](https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1072.Flip%20Columns%20For%20Maximum%20Number%20of%20Equal%20Rows.md)**

<div align="center">
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1072.Flip%20Columns%20For%20Maximum%20Number%20of%20Equal%20Rows.md">
    <img src="https://img.shields.io/badge/LeetCode%20POTD-Solution%20Live-brightgreen?style=for-the-badge&logo=leetcode" alt="LeetCode POTD Solution" />
  </a>
  <a href="https://github.com/Hunterdii/Leetcode-POTD/blob/main/November%202024%20Leetcode%20Solution/1072.Flip%20Columns%20For%20Maximum%20Number%20of%20Equal%20Rows.md">
    <img src="https://img.shields.io/badge/Solutions-Up%20to%20Date-blue?style=for-the-badge" alt="Solutions Up-to-Date" />
  </a>
</div>

<br/>

## Problem Description

Given an array `prices[]` of length `n`, representing the prices of stocks on different days, find the **maximum profit** possible by buying and selling the stocks on different days, **with at most one transaction allowed** (1 buy + 1 sell). If no profit can be made, return 0.

**Note**: Stocks must be bought before being sold.

### Examples:

**Input:**  
`prices[] = [7, 10, 1, 3, 6, 9, 2]`  
**Output:**  
`8`

**Explanation:**  
Buy the stock on day 2 at price `1` and sell it on day 5 at price `9`. Profit is `9 - 1 = 8`.

**Input:**  
`prices[] = [7, 6, 4, 3, 1]`  
**Output:**  
`0`

**Explanation:**  
Prices decrease every day, so no profit is possible.

**Input:**  
`prices[] = [1, 3, 6, 9, 11]`  
**Output:**  
`10`

**Explanation:**  
Buy on day 1 (`price = 1`) and sell on the last day (`price = 11`). Profit is `11 - 1 = 10`.

### Constraints:

- `1 <= prices.size() <= 10^5`
- `0 <= prices[i] <= 10^4`

## My Approach

1. **One Pass Solution**:

   - Maintain a `buyPrice` to track the minimum price seen so far.
   - Track `maxProfit` by comparing the current price's profit (`currentPrice - buyPrice`) to the previous `maxProfit`.
   - Update `buyPrice` whenever a lower price is encountered.

2. **Steps**:
   - Start by initializing `buyPrice` as the first price and `maxProfit` as 0.
   - Traverse the array and update `buyPrice` and `maxProfit` accordingly.
   - The final `maxProfit` gives the maximum possible profit with one transaction.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), where `n` is the size of the array. Only one pass through the array is required.
- **Expected Auxiliary Space Complexity:** O(1), as the solution uses a constant amount of additional space.

## Code (C)

```c
int maximumProfit(int prices[], int pricesSize) {
    int buyPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > buyPrice) {
            maxProfit = (maxProfit > prices[i] - buyPrice) ? maxProfit : prices[i] - buyPrice;
        } else {
            buyPrice = prices[i];
        }
    }
    return maxProfit;
}
```

## Code (Cpp)

```cpp
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int buyPrice = prices[0], maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > buyPrice) {
                maxProfit = max(maxProfit, prices[i] - buyPrice);
            } else {
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
};
```

## Code (Java)

```java
class Solution {
    public int maximumProfit(int prices[]) {
        int buyPrice = prices[0], maxProfit = 0;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > buyPrice) {
                maxProfit = Math.max(maxProfit, prices[i] - buyPrice);
            } else {
                buyPrice = prices[i];
            }
        }
        return maxProfit;
    }
}
```

## Code (Python)

```python
class Solution:
    def maximumProfit(self, prices):
        buyPrice = prices[0]
        maxProfit = 0

        for i in range(1, len(prices)):
            if prices[i] > buyPrice:
                maxProfit = max(maxProfit, prices[i] - buyPrice)
            else:
                buyPrice = prices[i]

        return maxProfit
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
