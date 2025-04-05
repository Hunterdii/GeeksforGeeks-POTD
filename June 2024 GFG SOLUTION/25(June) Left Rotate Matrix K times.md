## 25. Left Rotate Matrix K times

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1)

### Problem Description

You are given an integer `k` and a matrix `mat`. Return a matrix where it is rotated left `k` times.

**Example:**

Input:

```
k = 1
mat = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]
```

Output:

```
2 3 1
5 6 4
8 9 7
```

Explanation:
After rotating the matrix by one position to the left, it becomes:

```
2 3 1
5 6 4
8 9 7
```

### My Approach

1. **Initialization:**

- Determine the number of rows (`n`) and columns (`m`) in the matrix `mat`.
- Create a new matrix `ans` of the same dimensions to store the result after rotation.

2. **Rotation Calculation:**

- Calculate the effective number of rotations needed using `k % m` to handle cases where `k` is larger than `m`.
- Iterate over each element in the original matrix `mat`, and determine its new position in the matrix `ans` after rotation.

3. **Return:**

- Return the matrix `ans` containing the elements after `k` left rotations.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), as we iterate over all elements in the matrix once.
- **Expected Auxiliary Space Complexity:** O(n \* m), as we use an additional matrix of the same size to store the rotated elements.

### Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        k %= m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newCol = (j - k + m) % m;
                ans[i][newCol] = mat[i][j];
            }
        }
        return ans;
    }
};
```

### Code (Java)

```java
class Solution {
    int[][] rotateMatrix(int k, int mat[][]) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] ans = new int[n][m];

        k %= m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newCol = (j - k + m) % m;
                ans[i][newCol] = mat[i][j];
            }
        }
        return ans;
    }
}
```

### Code (Python)

```python
class Solution:
    def rotateMatrix(self, k, mat):
        n = len(mat)
        m = len(mat[0])
        ans = [[0] * m for _ in range(n)]

        k %= m

        for i in range(n):
            for j in range(m):
                new_col = (j - k + m) % m
                ans[i][new_col] = mat[i][j]

        return ans
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
