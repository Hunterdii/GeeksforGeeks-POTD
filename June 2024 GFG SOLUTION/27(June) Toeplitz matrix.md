## 27. Toeplitz Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/toeplitz-matrix/1)

### Problem Description

A Toeplitz (or diagonal-constant) matrix is a matrix in which each descending diagonal from left to right is constant, i.e., all elements in a diagonal are the same. Given a rectangular matrix `mat`, your task is to complete the function `isToeplitz` which returns 1 if the matrix is Toeplitz, otherwise it returns 0.

**Example:**

Input:

```
mat = [[6, 7, 8],
       [4, 6, 7],
       [1, 4, 6]]
```

Output: 1

Explanation:
The test case represents a 3x3 matrix:

```
6 7 8
4 6 7
1 4 6
```

Output: 1 (True) as values in all downward diagonals from left to right contain the same elements.

Input:

```
mat = [[1, 2, 3],
       [4, 5, 6]]
```

Output: 0

Explanation:
Matrix of order 2x3:

```
1 2 3
4 5 6
```

Output: 0 (False) as values in all diagonals are different.

### My Approach

1. **Initialization:**

- Create a map to store the first element of each diagonal. The key will be the difference between the row and column indices (`i - j`).

2. **Matrix Traversal:**

- Iterate through each element in the matrix.
- Calculate the diagonal key as `i - j`.
- Check if the key already exists in the map.
  - If it exists, compare the current element with the stored value. If they differ, the matrix is not Toeplitz.
  - If it doesn't exist, store the current element in the map with the diagonal key.

3. **Return:**

- Return 1 if all diagonals have constant values, otherwise return 0.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n \* m), as we iterate through each matrix element.
- **Expected Auxiliary Space Complexity:** O(n + m), where `n` is the number of rows and `m` is the number of columns, for storing the diagonals in the map.

### Code

#### C++

```cpp
bool isToeplitz(vector<vector<int>>& mat) {
        unordered_map<int, int> mp;
        int m = mat.size(), n = mat[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j;
                if (mp.find(diff) != mp.end()) {
                    if (mp[diff] != mat[i][j])
                        return false;
                } else {
                    mp[diff] = mat[i][j];
                }
            }
        }

        return true;
}
```

#### Java

```java
class GfG {
    boolean isToeplitz(int mat[][]) {
        Map<Integer, Integer> map = new HashMap<>();
        int m = mat.length, n = mat[0].length;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j;
                if (map.containsKey(diff)) {
                    if (!map.get(diff).equals(mat[i][j]))
                        return false;
                } else {
                    map.put(diff, mat[i][j]);
                }
            }
        }

        return true;
    }
}
```

#### Python

```python
def isToeplitz(mat):
    mp = {}
    m, n = len(mat), len(mat[0])

    for i in range(m):
        for j in range(n):
            diff = i - j
            if diff in mp:
                if mp[diff] != mat[i][j]:
                    return False
            else:
                mp[diff] = mat[i][j]

    return True
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
