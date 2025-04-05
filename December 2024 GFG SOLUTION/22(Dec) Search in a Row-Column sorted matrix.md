# _22. Search in a Row-Column Sorted Matrix_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1)

## Problem Description

Given a 2D integer matrix `mat[][]` of size `n x m`, where every row and column is sorted in increasing order, and a number `x`, the task is to determine whether element `x` is present in the matrix.

### Examples:

**Input:**  
`mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62`  
**Output:**  
`false`

**Explanation:**  
62 is not present in the matrix, so output is false.

**Input:**  
`mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55`  
**Output:**  
`true`

**Explanation:**  
55 is present in the matrix.

**Input:**  
`mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3`  
**Output:**  
`true`

**Explanation:**  
3 is present in the matrix.

### Constraints:

- `1 <= n, m <= 1000`
- $`1 <= mat[i][j] <= 10^9`$
- $`1<= x <= 10^9`$

## My Approach

1. **Search in Sorted Matrix**:

   - The matrix is sorted both row-wise and column-wise, meaning the smallest element is at the top-left and the largest is at the bottom-right.
   - The key observation is that you can eliminate either a row or a column at each step depending on the value of `x`.
   - Start from the top-right corner of the matrix:
     - If the current element is equal to `x`, return `true`.
     - If the current element is greater than `x`, move left (decrease the column index).
     - If the current element is less than `x`, move down (increase the row index).
   - This approach takes advantage of the sorted property to reduce the search space efficiently.

2. **Steps:**
   - Initialize a pointer at the top-right corner of the matrix.
   - Traverse the matrix by comparing the current element with `x` and adjust the row or column pointer based on the comparison.
   - If you find `x`, return `true`; otherwise, continue until you exhaust the matrix.

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n + m), where `n` is the number of rows and `m` is the number of columns in the matrix. We make at most `n + m` steps (moving either left or down).
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of extra space for the row and column pointers.

## Code (Cpp)

```cpp
class Solution {
public:
    bool matSearch(vector<vector<int>>& mat, int x) {
        int r = 0, c = mat[0].size() - 1;
        while (r < mat.size() && c >= 0) {
            if (mat[r][c] == x) return true;
            else if (mat[r][c] > x) c--;
            else r++;
        }
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    public boolean matSearch(int[][] mat, int x) {
        int r = 0, c = mat[0].length - 1;
        while (r < mat.length && c >= 0) {
            if (mat[r][c] == x) return true;
            else if (mat[r][c] > x) c--;
            else r++;
        }
        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def matSearch(self, mat, x):
        r, c = 0, len(mat[0]) - 1
        while r < len(mat) and c >= 0:
            if mat[r][c] == x: return True
            elif mat[r][c] > x: c -= 1
            else: r += 1
        return False
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
