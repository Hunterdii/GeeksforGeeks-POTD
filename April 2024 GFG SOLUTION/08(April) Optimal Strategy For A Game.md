## 08. Optimal Strategy for a Game

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1)

### Problem Description

You are given an array `arr` of size `n`. The elements of the array represent `n` coins of values \(v_1, v_2, ....v_n\). You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the value of the coin. You need to determine the maximum possible amount of money you can win if you go first. Note: Both the players are playing optimally.

**Example:**

Input:

```
n = 4
arr[] = {5, 3, 7, 10}
```

Output:

```
15
```

Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.

### My Approach

1. **Dynamic Programming:**

- We'll use a dynamic programming approach to solve this problem.
- Create a 2D vector `dp` of size \(n \times n\) to store the maximum possible amount of money we can win.
- Initialize the base cases:
  - When there is only one coin, the maximum amount we can win is the value of that coin.
  - When there are two coins, the player can choose the maximum of the two coins.
- Then, we'll iterate over all possible subarrays of length 3 and above, filling in the `dp` array with the maximum possible amount of money that can be won by the first player.
- At each step, the first player has two options:
  - Select the first coin and leave the opponent to play optimally on the remaining subarray. The first player gets `arr[i]` plus the maximum amount the opponent can win from the subarray `dp[i+1][j]`.
  - Select the last coin and leave the opponent to play optimally on the remaining subarray. The first player gets `arr[j]` plus the maximum amount the opponent can win from the subarray `dp[i][j-1]`.
- We'll fill the `dp` array from bottom-up, starting from smaller subarrays and moving towards larger ones.
- Finally, the maximum amount of money the first player can win will be stored in `dp[0][n-1]`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n^2), as we iterate over all possible subarrays of length 3 and above.
- **Expected Auxiliary Space Complexity:** O(n^2), as we use a 2D vector of size \(n \times n\) to store intermediate results.

### Code (C++)

```cpp
//Function to find the maximum possible amount of money we can win.
class Solution {
public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> dp(n, vector<long long>(n, 0));

        // Base cases
        for (int i = 0; i < n; ++i) {
            dp[i][i] = arr[i];
            if (i + 1 < n) dp[i][i + 1] = max(arr[i], arr[i + 1]);
        }

        // Fill the dp array
        for (int gap = 2; gap < n; ++gap) {
            for (int i = 0, j = gap; j < n; ++i, ++j) {
                long long chooseLeft = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                long long chooseRight = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                dp[i][j] = max(chooseLeft, chooseRight);
            }
        }

        return dp[0][n - 1];
    }
};
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
