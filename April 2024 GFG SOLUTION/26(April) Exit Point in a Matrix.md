## 26. Exit Point in a Matrix

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1)

### Problem Description

Given a matrix of size \(n \times m\) with 0’s and 1’s, you enter the matrix at cell (0,0) in the left-to-right direction. Whenever you encounter a 0, you retain it in the same direction. If you encounter a 1, you have to change the direction to the right of the current direction and change that 1 value to 0. You have to find out from which index you will leave the matrix at the end.

**Example:**

Input:

```
n = 3, m = 3
matrix = {{0, 1, 0},
          {0, 1, 1},
          {0, 0, 0}}
```

Output:

```
{1, 0}
```

Explanation:
Enter the matrix at (0, 0):

- then move towards (0, 1): 1 is encountered
- turn right towards (1, 1): again 1 is encountered
- turn right again towards (1, 0)
- now, the boundary of the matrix will be crossed, hence, exit point reached at (1, 0).

**Your Task:**

You don't need to read or print anything. Your task is to complete the function `FindExitPoint()` which takes the matrix as an input parameter and returns a list containing the exit point.

**Expected Time Complexity:** O(n \* m), where \(n\) is the number of rows and \(m\) is the number of columns.
**Expected Space Complexity:** O(1)

### My Approach

1. **Initialization:**

- Initialize variables `i`, `j`, and `k` to track the current position and direction.
- Define two vectors `dx` and `dy` to represent the changes in row and column indexes for each direction.

2. **Traverse the Matrix:**

- While the current position is within the matrix boundaries, iterate through the matrix.
- If the current cell value is 1, change the direction to the right of the current direction and update the cell value to 0.
- Update the current position based on the direction.

3. **Return Exit Point:**

- Return the coordinates of the exit point, which are the coordinates before leaving the matrix.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0, j = 0, k = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        while (i >= 0 && j >= 0 && i < n && j < m) {
            if (matrix[i][j] == 1) {
                matrix[i][j] = 0;
                k = (k + 1) % 4;
            }
            i += dx[k];
            j += dy[k];
        }
        return {i - dx[k], j - dy[k]};
    }
};
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
