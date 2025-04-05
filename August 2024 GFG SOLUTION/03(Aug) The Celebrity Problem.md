## 03. The Celebrity Problem

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/the-celebrity-problem/1)

### Problem Description

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix `mat` is used to represent people at the party such that if an element of row `i` and column `j` is set to 1, it means the `i`th person knows the `j`th person. You need to return the index of the celebrity at the party; if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

**Example:**

Input:

```
mat = [[0, 1, 0],
       [0, 0, 0],
       [0, 1, 0]]
```

Output:

```
1
```

Explanation:
0th and 2nd person both know 1. Therefore, 1 is the celebrity.

### My Approach

1. **Finding the Potential Celebrity:**

- Initialize the `potential_celebrity` to 0.
- Iterate through the matrix. If `mat[potential_celebrity][i]` is 1, it means the current `potential_celebrity` knows `i`, so update `potential_celebrity` to `i`.

2. **Validating the Potential Celebrity:**

- Iterate through the matrix again to confirm that the `potential_celebrity` doesn't know anyone and everyone knows the `potential_celebrity`.
- If any person doesn't know the `potential_celebrity` or the `potential_celebrity` knows someone, return -1.

3. **Return:**

- Return the `potential_celebrity` if they are confirmed as the celebrity; otherwise, return -1.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n), as we iterate through the matrix to find and confirm the celebrity.
- **Expected Auxiliary Space Complexity:** O(1), as we use a constant amount of additional space.

### Code (C++)

```cpp
class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int potential_celebrity = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[potential_celebrity][i] == 1) {
                potential_celebrity = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != potential_celebrity && (mat[potential_celebrity][i] == 1 || mat[i][potential_celebrity] == 0)) {
                return -1;
            }
        }
        return potential_celebrity;
    }
};
```

### Code (Java)

```java
class Solution {
    public int celebrity(int[][] mat) {
        int n = mat.length;
        int potentialCelebrity = 0;
        for (int i = 1; i < n; ++i) {
            if (mat[potentialCelebrity][i] == 1) {
                potentialCelebrity = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i != potentialCelebrity && (mat[potentialCelebrity][i] == 1 || mat[i][potentialCelebrity] == 0)) {
                return -1;
            }
        }
        return potentialCelebrity;
    }
}
```

### Code (Python)

```python
class Solution:
    def celebrity(self, mat):
        n = len(mat)
        a = 0
        b = n - 1

        while a < b:
            if mat[a][b] == 1:
                a += 1
            else:
                b -= 1

        for i in range(n):
            if i != a and (mat[a][i] == 1 or mat[i][a] == 0):
                return -1

        return a
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
