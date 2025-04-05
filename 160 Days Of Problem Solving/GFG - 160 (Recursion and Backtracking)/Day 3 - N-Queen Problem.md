---
Difficulty: Hard
Source: 160 Days of Problem Solving
Tags:
  - Backtracking
---

# 🚀 _Day 3. N-Queen Problem_ 🧠

The problem can be found at the following link: [Problem Link](https://www.geeksforgeeks.org/batch/gfg-160-problems/track/recursion-and-backtracking-gfg-160/problem/n-queen-problem0315)

## 💡 **Problem Description:**

The N-Queen problem is a classic combinatorial problem where you are tasked with placing `N` queens on an `N x N` chessboard such that no two queens threaten each other. This means:

- No two queens share the same row.
- No two queens share the same column.
- No two queens share the same diagonal.

Your task is to return a list of all possible solutions, where each solution represents the board configuration as a list of integers. Each integer in the list represents the column index (1-based) of the queen for each row.

![image](https://github.com/user-attachments/assets/ec8facf8-b951-4455-8a96-4e6dbdab1936)

## 🔍 **Example Walkthrough:**

### Example 1

**Input:**  
`N = 4`

**Output:**  
`[[2, 4, 1, 3], [3, 1, 4, 2]]`

**Explanation:**  
For `N = 4`, two solutions exist:

- Solution 1:
  ```
  . Q . .
  . . . Q
  Q . . .
  . . Q .
  ```
- Solution 2:
  ```
  . . Q .
  Q . . .
  . . . Q
  . Q . .
  ```

### Example 2

**Input:**  
`N = 1`

**Output:**  
`[[1]]`

**Explanation:**  
For `N = 1`, only one solution exists:

- Solution 1:
  ```
  Q
  ```

## **Constraints**

- `1 <= N <= 10`

## 🎯 **My Approach:**

The N-Queen problem can be efficiently solved using **bitwise operations** to track occupied columns and diagonals:

1. Use three bitmasks:
   - `cols`: Tracks occupied columns.
   - `d1`: Tracks occupied left diagonals (sum of row and column indices is constant).
   - `d2`: Tracks occupied right diagonals (difference of row and column indices is constant).
2. Backtrack recursively:
   - Place a queen in a valid column of the current row.
   - Mark the column and diagonals as occupied.
   - Move to the next row.
   - If a solution is found, add it to the result.
   - Backtrack by unmarking the column and diagonals.

This method reduces unnecessary checks and speeds up the solution.

## 🕒 **Time and Auxiliary Space Complexity**

- **Expected Time Complexity:**
- **O(N!)**, where **N** is the number of queens.  
  Each row has **N** possibilities initially, and this reduces with each row.
- **Worst-Case Time Complexity:** **O(N!)**

  - For the first queen, there are `N` choices.
  - For the second queen, there are `N-1` choices, and so on.
  - Thus, the total complexity is `O(N * (N-1) * (N-2) * ... * 1) = O(N!)`.

- **Expected Auxiliary Space Complexity:** **O(N)**, where **N** is the space used for recursive calls and the row configuration array.

## 📝 **Solution Code**

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n < 4 && n != 1) return {};
        vector<vector<int>> res;
        vector<int> row(n);

        auto solve = [&](auto&& self, int c, int cols, int d1, int d2) -> void {
            if (c == n) { res.push_back(row); return; }
            for (int r = 0, pos = 1; r < n; ++r, pos <<= 1)
                if (!(cols & pos || d1 & (pos << c) || d2 & (pos << (n - 1 - c))))
                    row[c] = r + 1, self(self, c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)));
        };

        solve(solve, 0, 0, 0, 0);
        return res;
    }
};
```

<details>
  <summary><h2 align='center'>👨‍💻 Alternative Approaches</h2></summary>

## **1️⃣ Bitmasking + Backtracking (Most Optimized)**

This approach uses **bitwise operations** to efficiently track columns and diagonals.

```cpp
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n == 2 || n == 3) return {};
        vector<vector<int>> result;
        vector<int> row(n);

        auto solve = [&](auto&& self, int c, int cols, int d1, int d2) -> void {
            if (c == n) { result.push_back(row); return; }
            for (int pos = ((1 << n) - 1) & ~(cols | d1 | d2); pos; pos &= pos - 1) {
                int r = __builtin_ctz(pos);
                row[c] = r + 1;
                self(self, c + 1, cols | (1 << r), (d1 | (1 << r)) << 1, (d2 | (1 << r)) >> 1);
            }
        };

        solve(solve, 0, 0, 0, 0);
        return result;
    }
};
```

### **Key Optimizations**

✅ **Bitwise tracking** of column, left-diagonal, and right-diagonal.  
✅ **Eliminates extra loops** for checking conflicts.  
✅ **Fastest pruning** using `__builtin_ctz(pos)` (extracts least significant set bit).

## **2️⃣ One-Dimensional Array + Backtracking**

This approach eliminates the need for extra space for diagonal checks.

```cpp
class Solution {
public:
    vector<vector<int>> nQueen(int n) {
        if (n == 2 || n == 3) return {};
        vector<vector<int>> result;
        vector<int> row(n);

        function<void(int, vector<bool>&, vector<bool>&, vector<bool>&)> solve = [&](int c, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2) {
            if (c == n) { result.push_back(row); return; }
            for (int r = 0; r < n; r++) {
                if (cols[r] || d1[c - r + n - 1] || d2[c + r]) continue;
                row[c] = r + 1;
                cols[r] = d1[c - r + n - 1] = d2[c + r] = true;
                solve(c + 1, cols, d1, d2);
                cols[r] = d1[c - r + n - 1] = d2[c + r] = false;
            }
        };

        vector<bool> cols(n, false), d1(2 * n - 1, false), d2(2 * n - 1, false);
        solve(0, cols, d1, d2);
        return result;
    }
};
```

### **Key Optimizations**

✅ Uses **three boolean arrays** instead of nested loops.  
✅ Reduces **O(n) conflict checks** per column to **O(1) using precomputed indices**.  
✅ **Backtracks efficiently** without unnecessary calculations.

### **Comparison of Approaches**

| Approaches                             | Time Complexity | Space Complexity | Best For            |
| -------------------------------------- | --------------- | ---------------- | ------------------- |
| **Bitmasking + Recursion (1️⃣)**        | **O(n!)**       | **O(n)**         | Large `n` (Fastest) |
| **Boolean Arrays (Backtracking) (2️⃣)** | **O(n!)**       | **O(n)**         | Simplicity          |

### **Final Recommendation**

- **For Competitive Coding** → Use **Bitmasking (1️⃣)**
- **For Readability + Optimization** → Use **Boolean Arrays (2️⃣)**

🚀 **The fastest approach for large `n` is 1️⃣ (Bitmasking + Backtracking).**

</details>

## Code (Java)

```java
class Solution {
    public ArrayList<ArrayList<Integer>> nQueen(int n) {
        if (n < 4 && n != 1) return new ArrayList<>();
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        int[] row = new int[n];
        solve(0, 0, 0, 0, n, row, res);
        return res;
    }

    private void solve(int c, int cols, int d1, int d2, int n, int[] row, ArrayList<ArrayList<Integer>> res) {
        if (c == n) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int r : row) temp.add(r + 1);
            res.add(temp);
            return;
        }
        for (int r = 0, pos = 1; r < n; ++r, pos <<= 1)
            if ((cols & pos) == 0 && (d1 & (pos << c)) == 0 && (d2 & (pos << (n - 1 - c))) == 0) {
                row[c] = r;
                solve(c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)), n, row, res);
            }
    }
}
```

## Code (Python)

```python
class Solution:
    def nQueen(self, n):
        if n < 4 and n != 1:
            return []
        res = []
        row = [0] * n

        def solve(c, cols, d1, d2):
            if c == n:
                res.append([r + 1 for r in row])
                return
            for r in range(n):
                pos = 1 << r
                if not (cols & pos or d1 & (pos << c) or d2 & (pos << (n - 1 - c))):
                    row[c] = r
                    solve(c + 1, cols | pos, d1 | (pos << c), d2 | (pos << (n - 1 - c)))

        solve(0, 0, 0, 0)
        return res
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
