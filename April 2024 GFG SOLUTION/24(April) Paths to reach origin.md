## 24. Paths to Reach Origin

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1)

### Problem Description

Given two integers `x` and `y`, representing the coordinates of a point, find the number of paths from the point `(x, y)` to the origin `(0, 0)`. From each point, you are allowed to move either left or up, i.e., from each point `(x, y)`, you can move either to `(x-1, y)` or `(x, y-1)`.

**Example:**

Input:

```
x = 3, y = 6
```

Output:

```
84
```

Explanation:
There are a total of 84 possible paths from point `(3,6)` to the origin `(0,0)`.

### My Approach

1. **Dynamic Programming:**

   - We'll use a 2D array `dp` to store the number of paths from each point to the origin.
   - Initialize the base cases: `dp[0][j] = 1` and `dp[i][0] = 1` for all `i` and `j`.
   - Then, iterate through the array and calculate the number of paths to each point based on the number of paths to its left and up.

2. **Return:**
   - Return `dp[x][y]`, which represents the number of paths from point `(x, y)` to the origin.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(x*y), as we iterate through the 2D array of size `x*y`.
- **Expected Auxiliary Space Complexity:** O(x\*y), as we use a 2D array of the same size to store the number of paths.

### Code (C++)

```cpp
class Solution {
    const int MOD = 1000000007;
public:
    int ways(int x, int y) {
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));

        for (int i = 0; i <= x; ++i)
            dp[i][0] = 1;
        for (int j = 0; j <= y; ++j)
            dp[0][j] = 1;

        for (int i = 1; i <= x; ++i) {
            for (int j = 1; j <= y; ++j) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        return dp[x][y];
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
