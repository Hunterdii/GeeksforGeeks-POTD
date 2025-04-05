## 09. Minimum Initial Points to Reach Destination

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1)

### Problem Description

Given a \(m \times n\) grid with each cell consisting of positive, negative, or zero points. We can move across a cell only if we have positive points. Whenever we pass through a cell, points in that cell are added to our overall points. The task is to find the minimum initial points required to reach cell \((m-1, n-1)\) from \((0, 0)\) by following these certain set of rules:

1. From a cell \((i, j)\), we can move to \((i + 1, j)\) or \((i, j + 1)\).
2. We cannot move from \((i, j)\) if our overall points at \((i, j)\) are \(\leq 0\).
3. We have to reach at \((n-1, m-1)\) with minimum positive points i.e., \(> 0\).

**Example 1:**

Input:

```
m = 3, n = 3
points = {{-2,-3,3},
          {-5,-10,1},
          {10,30,-5}}
```

Output:

```
7
```

Explanation:
7 is the minimum value to reach the destination with positive points throughout the path. Below is the path:
\((0,0) \rightarrow (0,1) \rightarrow (0,2) \rightarrow (1, 2) \rightarrow (2, 2)\).
We start from \((0, 0)\) with 7, we reach \((0, 1)\) with 5, \((0, 2)\) with 2, \((1, 2)\) with 5, \((2, 2)\) with and finally we have 1 point (we needed greater than 0 points at the end).

### My Approach

- We'll create a 2D vector `dp` of size \(M \times N\) to store the minimum initial points required to reach each cell.
- We'll start filling the `dp` matrix from the bottom-right cell \((M-1, N-1)\) and move upwards and leftwards.
- At each cell \((i, j)\), the minimum initial points required to reach \((M-1, N-1)\) will depend on the points required to reach either the cell below \((i+1, j)\) or the cell on the right \((i, j+1)\). We'll take the minimum of these two options and subtract the points present at the current cell.
- Finally, the minimum initial points required to reach cell \((0, 0)\) will be stored at \((0, 0)\) in the `dp` matrix.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \times m), as we iterate through each cell of the \(M \times N\) grid.
- **Expected Auxiliary Space Complexity:** O(n \times m), as we use a 2D vector of size \(M \times N\) to store the dynamic programming array.

### Code (C++)

```cpp
class Solution{
public:
    int minPoints(int M, int N, vector<vector<int>> points) {
        vector<vector<int>> dp(M, vector<int>(N, 0));

        for (int i = M - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (i == M - 1 && j == N - 1)
                    dp[i][j] = max(1, 1 - points[i][j]);
                else if (i == M - 1)
                    dp[i][j] = max(1, dp[i][j + 1] - points[i][j]);
                else if (j == N - 1)
                    dp[i][j] = max(1, dp[i + 1][j] - points[i][j]);
                else
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - points[i][j]);
            }
        }

        return dp[0][0];
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
