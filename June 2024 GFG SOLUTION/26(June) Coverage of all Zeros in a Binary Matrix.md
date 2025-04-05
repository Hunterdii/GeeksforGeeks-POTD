## 26. Coverage of All Zeros in a Binary Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1)

### Problem Description

Given a binary matrix having `n` rows and `m` columns, your task is to find the sum of the coverage of all zeros in the matrix. The coverage for a particular 0 is defined as the total number of ones around it in the left, right, up, and bottom directions.

**Examples:**

Input:

```
matrix = [[0, 1, 0],
          [0, 1, 1],
          [0, 0, 0]]
```

Output:

```
6
```

### My Approach

1. **Initialization:**

- Initialize a variable `cnt` to 0 to keep track of the sum of the coverage of all zeros.

2. **Checking Coverage:**

- Define a helper function `checkAndCount(i, j)` to check the presence of 1s around the cell at position `(i, j)`. The function will increment `cnt` for each 1 found to the left, right, above, or below the zero.

3. **Iterating Over the Matrix:**

- Iterate over each element in the matrix using nested loops.
- If the current element is 0, call the helper function to check its coverage.

4. **Return:**

- Return the final count `cnt` which represents the total coverage of all zeros in the matrix.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), as we iterate through each element of the matrix.
- **Expected Auxiliary Space Complexity:** O(1), as we use only a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int FindCoverage(vector<vector<int>>& mat) {
        int cnt = 0;
        int m = mat.size(), n = mat[0].size();

        auto checkAndCount = [&](int i, int j) {
            if (j < n - 1 && mat[i][j + 1] == 1) ++cnt; // Right
            if (j > 0 && mat[i][j - 1] == 1) ++cnt; // Left
            if (i < m - 1 && mat[i + 1][j] == 1) ++cnt; // Down
            if (i > 0 && mat[i - 1][j] == 1) ++cnt; // Up
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    checkAndCount(i, j);
                }
            }
        }

        return cnt;
    }
};
```

### Code (Java)

```java
class Solution {
    public int FindCoverage(int[][] matrix) {
        int cnt = 0;
        int m = matrix.length, n = matrix[0].length;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    if (j < n - 1 && matrix[i][j + 1] == 1) cnt++; // Right
                    if (j > 0 && matrix[i][j - 1] == 1) cnt++; // Left
                    if (i < m - 1 && matrix[i + 1][j] == 1) cnt++; // Down
                    if (i > 0 && matrix[i - 1][j] == 1) cnt++; // Up
                }
            }
        }
        return cnt;
    }
}
```

### Code (Python)

```python
class Solution:
    def FindCoverage(self, matrix):
        cnt = 0
        m, n = len(matrix), len(matrix[0])

        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    if j < n - 1 and matrix[i][j + 1] == 1:
                        cnt += 1  # Right
                    if j > 0 and matrix[i][j - 1] == 1:
                        cnt += 1  # Left
                    if i < m - 1 and matrix[i + 1][j] == 1:
                        cnt += 1  # Down
                    if i > 0 and matrix[i - 1][j] == 1:
                        cnt += 1  # Up

        return cnt
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
