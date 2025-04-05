## 01. Spirally Traversing a Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1)

### Problem Description

You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

**Example:**

Input:

```
matrix = [[1, 2, 3, 4],
          [5, 6, 7, 8],
          [9, 10, 11, 12],
          [13, 14, 15, 16]]
```

Output:

```
[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
```

Explanation:
The matrix is traversed in spiral form, starting from the top-left corner and moving in a clockwise direction.

### My Approach

1. **Initialization:**

   - Define variables `top`, `bottom`, `left`, and `right` to represent the current bounds of the matrix.
   - Initialize an empty vector `output` to store the elements in spiral order.

2. **Spiral Traversal:**

   - Use a while loop to traverse the matrix as long as the current bounds are valid (`top <= bottom` and `left <= right`).
   - Traverse from left to right along the top boundary and update `top`.
   - Traverse from top to bottom along the right boundary and update `right`.
   - If there are still rows left, traverse from right to left along the bottom boundary and update `bottom`.
   - If there are still columns left, traverse from bottom to top along the left boundary and update `left`.

3. **Return:**
   - Return the vector `output` containing the elements in spiral order.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(n\*m), as we iterate through all the elements of the matrix once.
- **Expected Auxiliary Space Complexity:** O(n\*m), as we store all the elements of the matrix in the output vector.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0, bottom = r - 1, left = 0, right = c - 1;
        vector<int> output;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                output.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; ++i)
                output.push_back(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    output.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    output.push_back(matrix[i][left]);
                left++;
            }
        }

        return output;
    }
};
```

### Code (Java)

```java
class Solution {
    public ArrayList<Integer> spirallyTraverse(int matrix[][]) {
        ArrayList<Integer> output = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return output;
        }

        int r = matrix.length;
        int c = matrix[0].length;
        int top = 0, bottom = r - 1, left = 0, right = c - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                output.add(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; ++i)
                output.add(matrix[i][right]);
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    output.add(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    output.add(matrix[i][left]);
                left++;
            }
        }

        return output;
    }
}
```

### Code (Python)

```python
class Solution:
    def spirallyTraverse(self, matrix):
        output = []
        if not matrix or not matrix[0]:
            return output

        r = len(matrix)
        c = len(matrix[0])
        top, bottom = 0, r - 1
        left, right = 0, c - 1

        while top <= bottom and left <= right:
            for i in range(left, right + 1):
                output.append(matrix[top][i])
            top += 1

            for i in range(top, bottom + 1):
                output.append(matrix[i][right])
            right -= 1

            if top <= bottom:
                for i in range(right, left - 1, -1):
                    output.append(matrix[bottom][i])
                bottom -= 1

            if left <= right:
                for i in range(bottom, top - 1, -1):
                    output.append(matrix[i][left])
                left += 1

        return output
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
