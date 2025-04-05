## 10. Largest Square Formed in a Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1)

### Problem Description

Given a binary matrix `mat` of size `n * m`, find out the maximum length of a side of a square sub-matrix with all 1s.

**Example:**

Input:

```
n = 6, m = 5
mat = [[0, 1, 1, 0, 1],
       [1, 1, 0, 1, 0],
       [0, 1, 1, 1, 0],
       [1, 1, 1, 1, 0],
       [1, 1, 1, 1, 1],
       [0, 0, 0, 0, 0]]
```

Output:

```
3
```

Explanation:
The maximum length of a side of the square sub-matrix is 3 where every element is 1.

### My Approach

1. **Initialization:**

- Create a vector `dp` of size `m` to store the lengths of square sides ending at each column of the current row.
- Initialize `maxsize` to 0 to keep track of the maximum length of the square sub-matrix found.
- Use `prev` to store the value of `dp[j]` from the previous row during the iteration.

2. **Square Calculation:**

- Iterate through each element of the matrix:
  - For the first row and the first column, set `dp[j]` to `mat[i][j]`.
  - For other elements, if `mat[i][j]` is 1, calculate the minimum of `dp[j]`, `dp[j - 1]`, and `prev`, then add 1 to get the side length of the square ending at `mat[i][j]`.
  - Update `maxsize` if `dp[j]` is larger than the current `maxsize`.
  - Update `prev` to the value of `dp[j]` before the current update.

3. **Return:**

- Return `maxsize`, which is the maximum length of the side of the square sub-matrix with all 1s.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), as we iterate through each element of the matrix.
- **Expected Auxiliary Space Complexity:** O(m), as we use a vector of size `m` to store intermediate results.

### Code (C++)

```cpp
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>>& mat) {
        vector<int> dp(m, 0);
        int maxsize = 0, prev = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = dp[j];
                if (i == 0 || j == 0) {
                    dp[j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    dp[j] = min({ dp[j], dp[j - 1], prev }) + 1;
                } else {
                    dp[j] = 0;
                }
                maxsize = max(maxsize, dp[j]);
                prev = temp;
            }
        }
        return maxsize;
    }
};
```

### Code (Java)

```java
class Solution {
    static int maxSquare(int n, int m, int mat[][]) {
        int[] dp = new int[m];
        int maxsize = 0, prev = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int temp = dp[j];
                if (i == 0 || j == 0) {
                    dp[j] = mat[i][j];
                } else if (mat[i][j] == 1) {
                    dp[j] = Math.min(Math.min(dp[j], dp[j - 1]), prev) + 1;
                } else {
                    dp[j] = 0;
                }
                maxsize = Math.max(maxsize, dp[j]);
                prev = temp;
            }
        }
        return maxsize;
    }
}
```

### Code (Python)

```python
from typing import List

class Solution:
    def maxSquare(self, n: int, m: int, mat: List[List[int]]) -> int:
        dp = [0] * m
        maxsize = 0
        prev = 0

        for i in range(n):
            for j in range(m):
                temp = dp[j]
                if i == 0 or j == 0:
                    dp[j] = mat[i][j]
                elif mat[i][j] == 1:
                    dp[j] = min(dp[j], dp[j - 1], prev) + 1
                else:
                    dp[j] = 0
                maxsize = max(maxsize, dp[j])
                prev = temp

        return maxsize
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
