---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Backtracking
  - Matrix
---

# 🚀 _Day 4. Solve the Sudoku_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/solve-the-sudoku-1587115621)

## 💡 **Problem Description:**

Given an incomplete Sudoku configuration in terms of a 9x9 2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

## 🔍 **Example Walkthrough:**

**Input:** `mat[][] =`

<img src="https://github.com/user-attachments/assets/f17f12e1-7ad0-4026-9d5f-453b76c4e8fa" width="40%">

**Output:**

<img src="https://github.com/user-attachments/assets/85db2375-479d-42c9-b00c-cad83d827f43" width="40%">

**Explanation:** Each row, column and 3 x 3 box of the output matrix contains unique numbers.

**Input:** `mat[][] =`

<img src="https://github.com/user-attachments/assets/370558ae-aeb0-4121-82c2-d815d30a47d7" width="40%">

**Output:**

<img src="https://github.com/user-attachments/assets/f4c0d26e-b082-4454-974a-fbd44f2d7540" width="40%">

**Explanation:** Each row, column and 3 x 3 box of the output matrix contains unique numbers.

### Constraints:

- `mat.size() = 9`
- `mat[i].size() = 9`
- `0 ≤ mat[i][j] ≤ 9`
- The board is always a 9×9 grid.
- Each row, column, and 3×3 sub-grid must contain digits from 1 to 9 without repetition.

## 🎯 **My Approach:**

1. **Backtracking Algorithm**:  
   The problem can be efficiently solved using a backtracking approach:

   - Identify an empty cell.
   - Try placing numbers from 1 to 9 in that cell.
   - Check if the placement is valid (no duplicates in the row, column, or 3×3 sub-grid).
   - If valid, recursively solve the rest of the board.
   - If an invalid state is encountered, backtrack and try a different number.

2. **Optimizations:**
   - Use bitwise operations (`1 << num`) to track used numbers efficiently in rows, columns, and sub-grids.
   - Reduce redundant computations by pruning early.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:** O(9^(n)), where `n` is the number of empty cells. In the worst case, each empty cell can take one of nine values.
- **Expected Auxiliary Space Complexity:** O(1), as we modify the board in-place with constant extra storage.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    void solveSudoku(vector<vector<int>> &board) {
        vector<int> row(9, 0), col(9, 0), box(9, 0);
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j])
                    row[i] |= 1 << board[i][j], col[j] |= 1 << board[i][j], box[i / 3 * 3 + j / 3] |= 1 << board[i][j];
        solve(board, row, col, box, 0, 0);
    }

private:
    bool solve(vector<vector<int>> &board, vector<int> &row, vector<int> &col, vector<int> &box, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(board, row, col, box, i + 1, 0);
        if (board[i][j]) return solve(board, row, col, box, i, j + 1);
        for (int num = 1; num <= 9; num++) {
            int mask = 1 << num, idx = i / 3 * 3 + j / 3;
            if (row[i] & mask || col[j] & mask || box[idx] & mask) continue;
            board[i][j] = num, row[i] |= mask, col[j] |= mask, box[idx] |= mask;
            if (solve(board, row, col, box, i, j + 1)) return true;
            board[i][j] = 0, row[i] &= ~mask, col[j] &= ~mask, box[idx] &= ~mask;
        }
        return false;
    }
};
```

## Code (Java)

```java
class Solution {
    static void solveSudoku(int[][] b) {
        int[] r = new int[9], c = new int[9], box = new int[9];
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (b[i][j] != 0) {
                    int m = 1 << b[i][j], idx = i / 3 * 3 + j / 3;
                    r[i] |= m; c[j] |= m; box[idx] |= m;
                }
        solve(b, r, c, box, 0, 0);
    }

    static boolean solve(int[][] b, int[] r, int[] c, int[] box, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(b, r, c, box, i + 1, 0);
        if (b[i][j] != 0) return solve(b, r, c, box, i, j + 1);
        for (int num = 1, m; num <= 9; num++) {
            m = 1 << num;
            int idx = i / 3 * 3 + j / 3;
            if ((r[i] & m) != 0 || (c[j] & m) != 0 || (box[idx] & m) != 0) continue;
            b[i][j] = num; r[i] |= m; c[j] |= m; box[idx] |= m;
            if (solve(b, r, c, box, i, j + 1)) return true;
            b[i][j] = 0; r[i] &= ~m; c[j] &= ~m; box[idx] &= ~m;
        }
        return false;
    }
}
```

## Code (Python)

```python
class Solution:
    def solveSudoku(self, b):
        r, c, box = [0] * 9, [0] * 9, [0] * 9
        for i in range(9):
            for j in range(9):
                if b[i][j]:
                    m = 1 << b[i][j]
                    r[i] |= m; c[j] |= m; box[i // 3 * 3 + j // 3] |= m
        self.solve(b, r, c, box, 0, 0)

    def solve(self, b, r, c, box, i, j):
        if i == 9: return True
        if j == 9: return self.solve(b, r, c, box, i + 1, 0)
        if b[i][j]: return self.solve(b, r, c, box, i, j + 1)
        for num in range(1, 10):
            m = 1 << num
            idx = i // 3 * 3 + j // 3
            if r[i] & m or c[j] & m or box[idx] & m: continue
            b[i][j] = num; r[i] |= m; c[j] |= m; box[idx] |= m
            if self.solve(b, r, c, box, i, j + 1): return True
            b[i][j] = 0; r[i] &= ~m; c[j] &= ~m; box[idx] &= ~m
        return False
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
