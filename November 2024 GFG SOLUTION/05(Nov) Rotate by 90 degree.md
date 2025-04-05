# _05. Rotate by 90 Degrees_

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/problems/rotate-by-90-degree0356/1)

## Problem Description

Given a square matrix `mat[][]`, the task is to rotate it by 90 degrees in a clockwise direction without using any extra space.

- The function should modify the matrix in place.
- The matrix size can be up to `1000 x 1000`.

#### Examples:

**Input:**  
`mat[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]`  
**Output:**  
`7 4 1`  
`8 5 2`  
`9 6 3`

**Input:**  
`mat[][] = [[1, 2], [3, 4]]`  
**Output:**  
`3 1`  
`4 2`

**Input:**  
`mat[][] = [[1]]`  
**Output:**  
`1`

**Constraints:**

- `1 ≤ mat.size() ≤ 1000`
- `1 ≤ mat[i][j] ≤ 100`

## My Approach

1. **Layer-by-Layer Rotation:**

   - Divide the matrix into layers, starting from the outermost layer and moving towards the inner layers.
   - For each element in the current layer, perform a four-way swap to rotate it 90 degrees clockwise.
   - Swap elements in groups of four, ensuring all elements are moved without using extra space.

2. **In-Place Rotation Logic:**
   - For each layer, iterate through the elements and apply the rotation logic by swapping:
     - `top` to `right`
     - `right` to `bottom`
     - `bottom` to `left`
     - `left` to `top`

## Time and Auxiliary Space Complexity

- **Expected Time Complexity:** `O(n^2)`, where `n` is the size of the matrix, as each element is visited once during the swap operations.
- **Expected Auxiliary Space Complexity:** `O(1)`, as the rotation is performed in place, using only a constant amount of space for the variables.

## Code (C)

```c
void rotate(int n, int mat[][n]) {
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}
```

## Code (C++)

```cpp
void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i - 1; ++j) {
            int temp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = temp;
        }
    }
}
```

## Code (Java)

```java
class GFG {
    static void rotate(int[][] mat) {
        int n = mat.length;
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n - j - 1][i];
                mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
                mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
                mat[j][n - i - 1] = temp;
            }
        }
    }
}
```

## Code (Python)

```python
def rotate(mat):
    n = len(mat)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            temp = mat[i][j]
            mat[i][j] = mat[n - j - 1][i]
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1]
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1]
            mat[j][n - i - 1] = temp
```

## Contribution and Support

For discussions, questions, or doubts related to this solution, please visit my LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Thank you for your input; together, we strive to create a space where learning is a collaborative endeavor.

⭐ Star this repository if you find it helpful or intriguing! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">   
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />  
</p>
