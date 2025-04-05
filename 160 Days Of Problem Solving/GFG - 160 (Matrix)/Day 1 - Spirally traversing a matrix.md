---
Difficulty: Medium
Source: 160 Days of Problem Solving
Tags:
  - Arrays
  - Matrix
---

# 🚀 _Day 1. Spirally Traversing a Matrix_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/matrix-gfg-160/problem/spirally-traversing-a-matrix-1587115621)

## 💡 **Problem Description:**

You are given a rectangular matrix `mat[][]` of size `n x m`. Your task is to return an array while traversing the matrix in a spiral form.

## 🔍 **Example Walkthrough:**

**Input:**  
`mat[][] = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]`  
**Output:**  
`[1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]`

<img src="https://github.com/user-attachments/assets/2ed3085d-e462-4b42-aecd-109e4ed636f8" width="48%">

**Input:**  
`mat[][] = [[1, 2, 3, 4, 5, 6], [7, 8, 9, 10, 11, 12], [13, 14, 15, 16, 17, 18]]`  
**Output:**  
`[1, 2, 3, 4, 5, 6, 12, 18, 17, 16, 15, 14, 13, 7, 8, 9, 10, 11]`

**Input:**  
`mat[][] = [[32, 44, 27, 23], [54, 28, 50, 62]]`  
**Output:**  
`[32, 44, 27, 23, 62, 50, 28, 54]`

### Constraints:

- `1 <= n, m <= 1000`
- `0 <= mat[i][j] <= 100`

## 🎯 **My Approach:**

1. **Spiral Traversal Algorithm**:  
   The problem can be efficiently solved by following the four main directions in a loop:

   - Traverse the top row from left to right.
   - Traverse the rightmost column from top to bottom.
   - Traverse the bottom row from right to left.
   - Traverse the leftmost column from bottom to top.  
     After traversing one complete cycle (i.e., the outermost layer), shrink the matrix (i.e., update the boundaries) and repeat until all elements are visited.

2. **Steps:**
   - Define boundaries (`top`, `left`, `bottom`, `right`) to represent the four edges of the matrix.
   - Continue the traversal while the top boundary is less than or equal to the bottom boundary and the left boundary is less than or equal to the right boundary.
   - After each traversal step, adjust the respective boundary.
   - Add elements to the result array and continue until all elements are visited.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(n \* m), where `n` is the number of rows and `m` is the number of columns in the matrix. We traverse each element exactly once.
- **Expected Auxiliary Space Complexity:** O(1), as we only use a constant amount of additional space (for the boundary variables).

## 📝 **Solution Code**

## Code (C)

```c
void spirallyTraverse(int** mat, int r, int c) {
    int top = 0, left = 0, bottom = r - 1, right = c - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; printf("%d ", mat[top][i++]));
        top++;
        for (int i = top; i <= bottom; printf("%d ", mat[i++][right]));
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; printf("%d ", mat[bottom][i--]));
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; printf("%d ", mat[i--][left]));
        left++;
    }
    printf("\n");
}
```

## Code (C++)

```cpp
class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        int top = 0, left = 0, bottom = mat.size() - 1, right = mat[0].size() - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; result.push_back(mat[top][i++]));
            top++;
            for (int i = top; i <= bottom; result.push_back(mat[i++][right]));
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; result.push_back(mat[bottom][i--]));
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; result.push_back(mat[i--][left]));
            left++;
        }
        return result;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

## Layered Spiral Traversal

```cpp

class Solution {
public:
    vector<int> spirallyTraverse(vector<vector<int>>& mat) {
        vector<int> result;
        int rows = mat.size(), cols = mat[0].size();
        int top = 0, left = 0, bottom = rows - 1, right = cols - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i)
                result.push_back(mat[top][i]);
            top++;
            for (int i = top; i <= bottom; ++i)
                result.push_back(mat[i][right]);
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; --i)
                    result.push_back(mat[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i)
                    result.push_back(mat[i][left]);
                left++;
            }
        }
        return result;
    }
};
```

</details>

## Code (Java)

```java
class Solution {
    public ArrayList<Integer> spirallyTraverse(int[][] mat) {
        ArrayList<Integer> result = new ArrayList<>();
        int top = 0, left = 0, bottom = mat.length - 1, right = mat[0].length - 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) result.add(mat[top][i]);
            top++;
            for (int i = top; i <= bottom; i++) result.add(mat[i][right]);
            right--;
            if (top <= bottom)
                for (int i = right; i >= left; i--) result.add(mat[bottom][i]);
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; i--) result.add(mat[i][left]);
            left++;
        }
        return result;
    }
}
```

## Code (Python)

```python
class Solution:
    def spirallyTraverse(self, mat):
        result = []
        top, left, bottom, right = 0, 0, len(mat) - 1, len(mat[0]) - 1

        while top <= bottom and left <= right:
            for i in range(left, right + 1):
                result.append(mat[top][i])
            top += 1
            for i in range(top, bottom + 1):
                result.append(mat[i][right])
            right -= 1
            if top <= bottom:
                for i in range(right, left - 1, -1):
                    result.append(mat[bottom][i])
                bottom -= 1
            if left <= right:
                for i in range(bottom, top - 1, -1):
                    result.append(mat[i][left])
                left += 1

        return result
```

## 🎯 **Contribution and Support:**

For discussions, questions, or doubts related to this solution, feel free to connect on LinkedIn: [Any Questions](https://www.linkedin.com/in/patel-hetkumar-sandipbhai-8b110525a/). Let’s make this learning journey more collaborative!

⭐ If you find this helpful, please give this repository a star! ⭐

---

<div align="center">
  <h3><b>📍Visitor Count</b></h3>
</div>

<p align="center">
  <img src="https://profile-counter.glitch.me/Hunterdii/count.svg" />
</p>
