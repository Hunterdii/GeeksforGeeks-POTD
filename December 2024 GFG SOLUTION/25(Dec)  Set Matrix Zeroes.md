# _25. Set Matrix Zeroes_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/set-matrix-zeroes/1)

## **Problem Description**

You are given a 2D matrix `mat[][]` of size `n x m`. Modify the matrix in such a way that:

1. If any cell in the matrix `mat[i][j]` is `0`, then all the elements in the `i-th` row and `j-th` column are set to `0`.
2. Do this in-place, i.e., without using extra space for another matrix.

## **Examples**

### Example 1:

**Input:**  
`mat[][] = [[1, -1, 1], [-1, 0, 1], [1, -1, 1]]`

**Output:**  
`[[1, 0, 1], [0, 0, 0], [1, 0, 1]]`

**Explanation:**  
In the given matrix, `mat[1][1] = 0`. Thus, row 1 and column 1 are updated to zeroes.

### Example 2:

**Input:**  
`mat[][] = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]`

**Output:**  
`[[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]`

**Explanation:**  
In the given matrix, `mat[0][0]` and `mat[0][3]` are `0`. Therefore, row 0, column 0, and column 3 are updated to zeroes.

## **Constraints**

- `1 ≤ n, m ≤ 500`
- `-2^31 ≤ mat[i][j] ≤ 2^31 - 1`

## **My Approach**

1. **Efficient Space Management Using Markers**:

   - Instead of using additional space for row and column markers, leverage the first row and the first column of the matrix as markers to indicate whether a particular row or column needs to be set to zero.

2. **Steps**:
   - Traverse the matrix. If any cell `mat[i][j] == 0`, mark `mat[i][0]` and `mat[0][j]` as `0`.
   - Traverse the matrix again in reverse (from bottom-right to top-left). For each cell, check the marker values (`mat[i][0]` and `mat[0][j]`); if either is `0`, set the cell to `0`.
   - Use an additional variable `col0` to track if the first column needs to be zeroed.

## **Time and Auxiliary Space Complexity**

### **Expected Time Complexity:**

- **O(n \* m)**
  - We traverse the matrix twice: once to mark the rows and columns and another to update the cells.
  - Each traversal takes O(n \* m), where `n` is the number of rows and `m` is the number of columns.

### **Expected Auxiliary Space Complexity:**

- **O(1)**
  - The algorithm uses only a few extra variables (`col0`, `i`, `j`), regardless of the matrix size. No additional data structures are used.

## Code (C++)

```cpp
class Solution {
public:
    void setMatrixZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size(), col0 = 1;
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) col0 = 0;
            for (int j = 1; j < m; ++j)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 1; --j)
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            if (col0 == 0) mat[i][0] = 0;
        }
    }
};
```

## Code (Java)

```java
class Solution {
    public void setMatrixZeroes(int[][] mat) {
        int n = mat.length, m = mat[0].length, col0 = 1;
        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) col0 = 0;
            for (int j = 1; j < m; j++)
                if (mat[i][j] == 0)
                    mat[i][0] = mat[0][j] = 0;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 1; j--)
                if (mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            if (col0 == 0) mat[i][0] = 0;
        }
    }
}
```

## Code (Python)

```python
class Solution:
    def setMatrixZeroes(self, mat):
        n, m, col0 = len(mat), len(mat[0]), 1
        for i in range(n):
            if mat[i][0] == 0: col0 = 0
            for j in range(1, m):
                if mat[i][j] == 0:
                    mat[i][0] = mat[0][j] = 0
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, 0, -1):
                if mat[i][0] == 0 or mat[0][j] == 0:
                    mat[i][j] = 0
            if col0 == 0: mat[i][0] = 0
```

## **Contribution and Support**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
