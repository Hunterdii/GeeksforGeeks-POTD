## 29. Geek and its Game of Coins

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1)

### Problem Description

Given three numbers `n`, `x`, and `y`, Geek and his friend are playing a coin game. In the beginning, there are `n` coins. In each move, a player can pick `x`, `y`, or `1` coin. Geek always starts the game. The player who picks the last coin wins the game. The task is to determine whether Geek will win the game or not if both players play optimally.

**Example 1:**

Input:

```
n = 5
x = 3
y = 4
```

Output:

```
1
```

Explanation:
There are 5 coins. Geek can win by picking 3 coins in the first move. Now 2 coins are left, so his friend will pick 1 coin, and then Geek can pick the last coin and win.

### My Approach

1. **Initialization:**

   - Create a vector `dp` of size `n + 1` initialized to 0. This vector will be used to determine if the current player can force a win starting with `i` coins.
   - Set `dp[1]` to 1 since with 1 coin, Geek can win by taking the coin.

2. **Dynamic Programming Calculation:**

   - Iterate from `i = 2` to `n`.
   - For each `i`, check if Geek can win by picking 1, `x`, or `y` coins:
     - If `dp[i - 1]` is 0, then picking 1 coin leaves the opponent in a losing position, so set `dp[i]` to 1.
     - If `i >= x` and `dp[i - x]` is 0, then picking `x` coins leaves the opponent in a losing position, so set `dp[i]` to 1.
     - If `i >= y` and `dp[i - y]` is 0, then picking `y` coins leaves the opponent in a losing position, so set `dp[i]` to 1.

3. **Return:**
   - Return `dp[n]` which will be 1 if Geek can force a win starting with `n` coins, otherwise 0.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the series up to the `n`th term.
- **Expected Auxiliary Space Complexity:** O(n), as we use a vector/array of size `n + 1` to store the dynamic programming results.

### Code

#### C++

```cpp
class Solution {
  public:
    int findWinner(int n, int x, int y) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            if (i >= 1 && dp[i - 1] == 0) dp[i] = 1;
            else if (i >= x && dp[i - x] == 0) dp[i] = 1;
            else if (i >= y && dp[i - y] == 0) dp[i] = 1;
        }
        return dp[n];
    }
};
```

#### Java

```java
class Solution {
    public int findWinner(int n, int x, int y) {
        int[] dp = new int[n + 1];
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            if (i >= 1 && dp[i - 1] == 0) {
                dp[i] = 1;
            } else if (i >= x && dp[i - x] == 0) {
                dp[i] = 1;
            } else if (i >= y && dp[i - y] == 0) {
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
        }

        return dp[n];
    }
}
```

#### Python

```python
class Solution:
    def findWinner(self, n: int, x: int, y: int) -> int:
        dp = [0] * (n + 1)
        dp[1] = 1

        for i in range(2, n + 1):
            if i >= 1 and dp[i - 1] == 0:
                dp[i] = 1
            elif i >= x and dp[i - x] == 0:
                dp[i] = 1
            elif i >= y and dp[i - y] == 0:
                dp[i] = 1
            else:
                dp[i] = 0

        return dp[n]
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
