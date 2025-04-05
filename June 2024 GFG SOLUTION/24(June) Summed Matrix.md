## 24. Summed Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/print-bracket-number4058/1)

### Problem Description

A matrix is constructed of size \(n \times n\) and given an integer `q`. The value at every cell of the matrix is given as \(M(i,j) = i + j\), where \(M(i,j)\) is the value of a cell, \(i\) is the row number, and \(j\) is the column number. Return the number of cells having value `q`.

**Note:** Assume the matrix is 1-based indexing.

**Examples:**

Input:

```
n = 4, q = 7
```

Output:

```
2
```

Explanation:
Matrix becomes:

```
2 3 4 5
3 4 5 6
4 5 6 7
5 6 7 8
```

The count of 7 is 2.

### My Approach

1. **Conditions and Calculation:**

- If `q` is greater than `2 * n`, there are no cells with value `q` since the maximum possible value in the matrix is `2 * n`.
- If `q` is less than or equal to `n + 1`, the value `q` can appear in the cells forming a diagonal line in the upper triangle of the matrix, and the number of such cells is `q - 1`.
- If `q` is greater than `n + 1` but less than or equal to `2 * n`, the value `q` can appear in the cells forming a diagonal line in the lower triangle of the matrix, and the number of such cells is `2 * n - q + 1`.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(1), as we perform a constant number of operations regardless of the size of the matrix.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    long long sumMatrix(long long n, long long q) {
        if (q > 2 * n) {
            return 0;
        } else if (q <= n + 1) {
            return q - 1;
        } else {
            return 2 * n - q + 1;
        }
    }
};
```

### Code (Java)

```java
class Solution {
    static long sumMatrix(long n, long q) {
        if (q > 2 * n) {
            return 0;
        } else if (q <= n + 1) {
            return q - 1;
        } else {
            return 2 * n - q + 1;
        }
    }
}
```

### Code (Python)

```python
class Solution:
    def sumMatrix(self, n, q):
        if q > 2 * n:
            return 0
        elif q <= n + 1:
            return q - 1
        else:
            return 2 * n - q + 1
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
